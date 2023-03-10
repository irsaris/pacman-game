#pragma once
#include "Animation.h"
#include "EntityManager.h"


class Player: public Entity{

    private:
        int health;
        int score;
        bool canMove;
        int speed = 8;
        bool walking = false;
        FACING facing = DOWN;
        ofImage up, down, left, right;
        Animation *walkUp;
        Animation *walkDown;
        Animation *walkLeft;
        Animation *walkRight;
        EntityManager* em;

        //added variables
        int startX, startY;
        ofSoundPlayer myMusic, powerUp;
        bool canEat = false;

    public:
        Player(int, int, int , int, EntityManager*);
        int getHealth();
        int getScore(){return this->score;}
        void tick();
        void render();
        void keyPressed(int);
        void keyReleased(int);
        void damage(Entity* damageSource);
        void mousePressed(int, int, int);
        void reset();
        void setFacing(FACING facing);
        void checkCollisions();

        //added functions
        void die();
        bool isOver();
        int timer = 240;
};