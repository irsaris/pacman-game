#include "Map.h"
#include "EntityManager.h"

Map::Map(EntityManager* em){
    entityManager = em;
}

void Map::tick(){
	entityManager->tick();
	player->tick();
	ghostSpawner->tick();

}
void Map::render(){
    ofSetBackgroundColor(0, 0, 0);
	entityManager->render();
	player->render();
}

void Map::keyPressed(int key){
	player->keyPressed(key);
}

void Map::mousePressed(int x, int y, int button){
	player->mousePressed(x, y, button);
}

void Map::keyReleased(int key){
	player->keyReleased(key);
	ghostSpawner->keyReleased(key);
}

void Map::addBlock(Block* e){
    entityManager->blocks.push_back(e);
}

void Map::addEntity(Entity* e){
	entityManager->entities.push_back(e);
}

void Map::setPlayer(Player* p){
    player = p;
}

void Map::setGhost(GhostSpawner* g){
    ghostSpawner = g;
}
