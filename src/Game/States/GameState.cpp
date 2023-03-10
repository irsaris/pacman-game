#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);
	endscreen.load("UndertaleGameover.mp3");
	endscreen.setLoop(true);
}
void GameState::tick() {
	map->tick();

	if(map->getPlayer()->isOver()){
		ofSoundStopAll();
		endscreen.play();
        setNextState("GameOver");
        setFinished(true);
    }
}
void GameState::render() {
	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}

int GameState::getScore(){
	return map->getPlayer()->getScore();
}