#include "Player.h"
#include "EntityManager.h"
#include "Dot.h"
#include "BigDot.h"
#include "Ghost.h"
#include "GhostSpawner.h"

Player::Player(int x, int y, int width, int height, EntityManager* em) : Entity(x, y, width, height){
    sprite.load("images/pacman.png");
    down.cropFrom(sprite, 0, 48, 16, 16);
    up.cropFrom(sprite, 0, 32, 16, 16);
    left.cropFrom(sprite, 0, 16, 16, 16);
    right.cropFrom(sprite, 0, 0, 16, 16);
    
    vector<ofImage> downAnimframes;
    vector<ofImage> upAnimframes;
    vector<ofImage> leftAnimframes;
    vector<ofImage> rightAnimframes;
    ofImage temp;
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 48, 16, 16);
        downAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 32, 16, 16);
        upAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 16, 16, 16);
        leftAnimframes.push_back(temp);
    }
    for(int i=0; i<3; i++){
        temp.cropFrom(sprite, i*16, 0, 16, 16);
        rightAnimframes.push_back(temp);
    }
    walkDown = new Animation(1,downAnimframes);
    walkUp = new Animation(1,upAnimframes);
    walkLeft = new Animation(1,leftAnimframes);
    walkRight = new Animation(1,rightAnimframes);

    this->em = em;
    
    //initialized variables
    score = 0;
    health = 3;
    startX = x;
    startY = y;
	myMusic.load("UndertaleDie.mp3");
    powerUp.load("UndertalePowerup.mp3");
}

void Player::tick(){
    canMove = true;
    checkCollisions();
    isOver();

    if(canEat && timer > 0){
        timer--;
    }
    else{
        canEat = false;
        for(Entity* entity2:em->entities){
            Ghost* g = dynamic_cast<Ghost*>(entity2);
            if(g != NULL){
                g->canEat = false;
                g->timer = 0;
            }
        }
    }

    if(canMove){
        if(facing == UP){
            y-= speed;
            walkUp->tick();
        }else if(facing == DOWN){
            y+=speed;
            walkDown->tick();
        }else if(facing == LEFT){
            x-=speed;
            walkLeft->tick();
        }else if(facing == RIGHT){
            x+=speed;
            walkRight->tick();
        }
    }
}

void Player::render(){
    ofDrawBitmapString("SCORE: " + to_string(score), ofGetWidth()*.85, ofGetHeight()*.1);
    ofDrawBitmapString("LIVES: " + to_string(health), ofGetWidth()*.85, ofGetHeight()*.15);

    ofSetColor(256,256,256);
    // ofDrawRectangle(getBounds());
    if(facing == UP){
        walkUp->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == DOWN){
        walkDown->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == LEFT){
        walkLeft->getCurrentFrame().draw(x, y, width, height);
    }else if(facing == RIGHT){
        walkRight->getCurrentFrame().draw(x, y, width, height);
    }
}

void Player::die(){
    myMusic.play();

    setFacing(DOWN);
    walkDown->reset();
    walkUp->reset();
    walkLeft->reset();
    walkRight->reset();

    health--;
    x = startX;
    y = startY;
}

bool Player::isOver(){
    return health <= 0;
}

void Player::keyPressed(int key){
    switch(key){
        case 'w':
        case 'W':
            setFacing(UP);
            break;
        case 's':
        case 'S':
            setFacing(DOWN);
            break;
        case 'a':
        case 'A':
            setFacing(LEFT);
            break;
        case 'd':
        case 'D':
            setFacing(RIGHT);
            break;
        case 'n':
        case 'N':
            die();
            break;
        case 'm':
        case 'M':
            health++;
            break;
    }
}

void Player::keyReleased(int key){
    if(key == 'w' || key =='s' || key == 'a' || key == 'd'){
        walking = false;
    }
}
void Player::mousePressed(int x, int y, int button){

}

void Player::setFacing(FACING facing){
    this->facing = facing;
}

void Player::checkCollisions(){
    for(Block* block: em->blocks){
        switch(facing){
            case UP:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case DOWN:
                if(this->getBounds(x, y+speed).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case LEFT:
                if(this->getBounds(x-speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
            case RIGHT:
                if(this->getBounds(x+speed, y).intersects(block->getBounds())){
                    canMove = false;
                }
                break;
        }
    }
    for(Entity* entity:em->entities){
        if(collides(entity)){
            if(dynamic_cast<Dot*>(entity)){
                entity->remove = true;
                score += 5;
            }
            if(dynamic_cast<BigDot*>(entity)){
                powerUp.play();

                canEat = true;
                timer = 240;
                for(Entity* entity2:em->entities){
                    Ghost* g = dynamic_cast<Ghost*>(entity2);
                    if(g != NULL){
                        g->canEat = true;
                    }
                }
                entity->remove = true;
                score += 10;
            }
            if(dynamic_cast<Ghost*>(entity)){
                if(canEat){
                    entity->remove = true;
                    score += 25;
                }
                else{
                    die();
                }
            }
        }
    }
}
