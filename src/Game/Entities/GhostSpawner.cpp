#include "GhostSpawner.h"


GhostSpawner::GhostSpawner(int x, int y, int width, int height, ofImage i, EntityManager* em, Player* pacman) : Entity(x, y, width, height){
    this->em = em;
    this->pacman = pacman;
    ghost1.cropFrom(i,456,64,16,16);
    ghost2.cropFrom(i,456,81,16,16);
    ghost3.cropFrom(i,456,97,16,16);
    ghost4.cropFrom(i,456,113,16,16);
    darkBlueGhost.cropFrom(i,584,64,16,16);
    cyanGhost.cropFrom(i,616,64,16,16);
    em->entities.push_back(new Ghost(x, y, width, height, vector<ofImage>{ghost1, darkBlueGhost, cyanGhost}, em));
    em->entities.push_back(new Ghost(x, y, width, height, vector<ofImage>{ghost2, darkBlueGhost, cyanGhost}, em));
    em->entities.push_back(new Ghost(x, y, width, height, vector<ofImage>{ghost3, darkBlueGhost, cyanGhost}, em));
    em->entities.push_back(new Ghost(x, y, width, height, vector<ofImage>{ghost4, darkBlueGhost, cyanGhost}, em));
}

void GhostSpawner::tick(){
    if(em->deadGhostCounter > 0 && pacman->timer == 0){
        keyReleased('g');
        em->deadGhostCounter--;
    }
}

void GhostSpawner::render(){
    
}

void GhostSpawner::keyPressed(int key){
    
}

void GhostSpawner::keyReleased(int key){
    switch(key){
        case 'g':
            switch(int(ofRandom(4))){
                case 0:
                    em->entities.push_back(new Ghost(x, y, width, height, vector<ofImage>{ghost1, darkBlueGhost, cyanGhost}, em));
                    break;
                case 1:
                    em->entities.push_back(new Ghost(x, y, width, height, vector<ofImage>{ghost2, darkBlueGhost, cyanGhost}, em));
                    break;
                case 2:
                    em->entities.push_back(new Ghost(x, y, width, height, vector<ofImage>{ghost3, darkBlueGhost, cyanGhost}, em));
                    break;
                case 3:
                    em->entities.push_back(new Ghost(x, y, width, height, vector<ofImage>{ghost4, darkBlueGhost, cyanGhost}, em));
                    break;
            }
            break;
    }
}
