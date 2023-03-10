#include "Ghost.h"

Ghost::Ghost(int x, int y, int width, int height, vector<ofImage> ghostImage, EntityManager *em): Entity(x, y, width, height){
    spriteVector = ghostImage;
    this->em = em;
}

void Ghost::setFacing(FACING facing){
    this->facing = facing;
}

void Ghost::tick(){
    checkCollisions();

    if(canEat){
        timer++;
    }

    if(facing == UP){
        y-= speed;
    }else if(facing == DOWN){
        y+=speed;
    }else if(facing == LEFT){
        x-=speed;
    }else if(facing == RIGHT){
        x+=speed;
    }
    
}

void Ghost::render(){
    ofSetColor(256,256,256);
    
    if(canEat){
        if(timer%10 == 0){
            isBlue = !isBlue;
            timer = 0;
        }
        spriteVector[(isBlue ? 1 : 2)].draw(x, y, width, height);
    }
    else{
        spriteVector[0].draw(x, y, width, height);
    }
}

bool Ghost::checkCollisionLeft(){
    for(Block* block: em->blocks){
        if(this->getBounds(x-speed, y).intersects(block->getBounds())){
            return true;
        }
    }
    return false;
}

bool Ghost::checkCollisionRight(){
    for(Block* block: em->blocks){
        if(this->getBounds(x+speed, y).intersects(block->getBounds())){
            return true;
        }
    }
    return false;
}

bool Ghost::checkCollisionUp(){
    for(Block* block: em->blocks){
        if(this->getBounds(x, y-speed).intersects(block->getBounds())){
            return true;
        }
    }
    return false;
}

bool Ghost::checkCollisionDown(){
    for(Block* block: em->blocks){
        if(this->getBounds(x, y+speed).intersects(block->getBounds())){
            return true;
        }
    }
    return false;
}

void Ghost::checkCollisions(){
    bool left, right, up, down;

    for(Block* block: em->blocks){
        switch(facing){
            case 0:
                if(this->getBounds(x, y-speed).intersects(block->getBounds())){

                    left = checkCollisionLeft();
                    right = checkCollisionRight();

                    if(!left && !right){
                        switch(int(ofRandom(2))){
                            case 0:
                                setFacing(LEFT);
                                break;
                            case 1:
                                setFacing(RIGHT);
                                break;
                        }
                    }
                    else if(!left){
                        setFacing(LEFT);
                    }
                    else{
                        setFacing(RIGHT);
                    }
                }
                break;
            case 1:
                if(this->getBounds(x, y+speed).intersects(block->getBounds())){

                    left = checkCollisionLeft();
                    right = checkCollisionRight();

                    if(!left && !right){
                        switch(int(ofRandom(2))){
                            case 0:
                                setFacing(LEFT);
                                break;
                            case 1:
                                setFacing(RIGHT);
                                break;
                        }
                    }
                    else if(!left){
                        setFacing(LEFT);
                    }
                    else{
                        setFacing(RIGHT);
                    }
                }
                break;
            case 2:
                if(this->getBounds(x-speed, y).intersects(block->getBounds())){
                    
                    up = checkCollisionUp();
                    down = checkCollisionDown();

                    if(!up && !down){
                        switch(int(ofRandom(2))){
                            case 0:
                                setFacing(UP);
                                break;
                            case 1:
                                setFacing(DOWN);
                                break;
                        }
                    }
                    else if(!up){
                        setFacing(UP);
                    }
                    else{
                        setFacing(DOWN);
                    }
                }
                break;
            case 3:
                if(this->getBounds(x+speed, y).intersects(block->getBounds())){

                    up = checkCollisionUp();
                    down = checkCollisionDown();

                    if(!up && !down){
                        switch(int(ofRandom(2))){
                            case 0:
                                setFacing(UP);
                                break;
                            case 1:
                                setFacing(DOWN);
                                break;
                        }
                    }
                    else if(!up){
                        setFacing(UP);
                    }
                    else{
                        setFacing(DOWN);
                    }
                }
                break;
        }
    }
}