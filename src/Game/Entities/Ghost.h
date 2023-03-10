#pragma once
#include "Entity.h"
#include "EntityManager.h"
#include "Block.h"

class Ghost: public Entity{
    private:
        FACING facing = UP;
        bool canMove;
        int speed = 4;
        EntityManager* em;
        vector<ofImage> spriteVector;
        
        
        bool isBlue = false;

    public:
        Ghost(int, int, int, int, vector<ofImage>, EntityManager*);
        void tick();
        void render();
        void setFacing(FACING facing);
        void checkCollisions();

        bool checkCollisionLeft();
        bool checkCollisionRight();
        bool checkCollisionUp();
        bool checkCollisionDown();
        bool canEat = false;
        int timer = 0;
};