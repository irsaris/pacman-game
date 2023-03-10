#pragma once
#include "EntityManager.h"
#include "Ghost.h"
#include "Player.h"

class GhostSpawner: public Entity{
    public:
        GhostSpawner(int, int, int, int, ofImage, EntityManager*, Player*);
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);

        EntityManager* em;
        Player* pacman;
        ofImage pacmanSpriteSheet;
        ofImage ghost1, ghost2, ghost3, ghost4, darkBlueGhost, cyanGhost;
        int ghostCounter;

};