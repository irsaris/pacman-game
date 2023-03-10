#include "GameOverState.h"

GameOverState::GameOverState(){
	Player scoreGetter();
	//initialized variables
	frameSelector = 0;
	frameSelector2 = 0;
	decCounter = 0;
	requiredCrops = 98;
	frameLink = "images/GameOverFrames/frame_apngframe01.png";
	GOSFrameLoader.load(frameLink);
	GOSFrame.cropFrom(GOSFrameLoader, 0, 0, 600, 338);
	for(int i = 1; i<=requiredCrops; i++){
		GOStateFrames.push_back(GOSFrame);
		if(frameSelector <= 9){
		frameSelector += 1;
		}
		else{
			frameSelector = 0;
			frameSelector2++;
			decCounter++;
		}
		if(decCounter >= 1){
		frameLink.replace(0, 49, "images/GameOverFrames/frame_apngframe" + to_string(frameSelector2) + to_string(frameSelector) + ".png");
		GOSFrameLoader.load(frameLink);
		GOSFrame.cropFrom(GOSFrameLoader, 0, 0, 600, 338);
		}
		if(decCounter == 0){
		frameLink.replace(0, 49, "images/GameOverFrames/frame_apngframe0" + to_string(frameSelector) + ".png");
		GOSFrameLoader.load(frameLink);
		GOSFrame.cropFrom(GOSFrameLoader, 0, 0, 600, 338);
		}
	}
	GOStateBackground = new Animation(2, GOStateFrames);
}

void GameOverState::tick() {
	GOStateBackground->tick();
}
void GameOverState::render() {
	ofSetColor(250,250,250);
	GOStateBackground->getCurrentFrame().draw(0, 0, 1027, 773);
}

void GameOverState::keyPressed(int key){
	if(key == ' '){
		setNextState("Menu");
		setFinished(true);
	}
}

void GameOverState::mousePressed(int x, int y, int button){
}

void GameOverState::reset(){
	setFinished(false);
	setNextState("");
}