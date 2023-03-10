#pragma once
#include "EntityManager.h"
#include "Ghost.h"

void EntityManager::tick(){
    std::vector<int> toRemove;
    for(int i=0;i<entities.size();i++){
        if(!entities[i]->remove){
            entities[i]->tick();

        }else{
            toRemove.push_back(i);
            if(dynamic_cast<Ghost*>(entities[i])){
                deadGhostCounter++;
            }
        }
    }
    for(Block* block: blocks){
        block->tick();
    }
    for(unsigned int removable: toRemove){
        entities.erase(entities.begin() + removable);
    }
}

void EntityManager::render(){
    for(Entity* entity: entities){
        if(dynamic_cast<Ghost*>(entity) == NULL){
            entity->render();
        }
    }
    for(Block* block: blocks){
        block->render();
    }
    for(Entity* entity: entities){
        if(dynamic_cast<Ghost*>(entity)){
            entity->render();
        }
    }
}