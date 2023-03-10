#include "MenuState.h"

MenuState::MenuState() {
	startButton = new Button(315, 61, 390, 220, " ");
	start.load("StartPressSound.mp3");
	//initialized variables
	frameSelector = 0;
	frameSelector2 = 0;
	decCounter = 0;
	requiredCrops = 12;
	frameLink = "images/StartScreenFrames/frame_00_delay-0.1s.png";
	MSFrameLoader.load(frameLink);
	MSFrame.cropFrom(MSFrameLoader, 0, 0, 600, 338);
	for(int i = 1; i<=requiredCrops; i++){
		menuStateFrames.push_back(MSFrame);
		if(frameSelector <= 9){
		frameSelector += 1;
		}
		else{
			frameSelector = 0;
			frameSelector2++;
			decCounter++;
		}
		if(decCounter == 1){
		frameLink.replace(0, 49, "images/StartScreenFrames/frame_0" + to_string(frameSelector) + "_delay-0.1s.png");
		frameLink.replace(0, 49, "images/StartScreenFrames/frame_" + to_string(frameSelector2) + to_string(frameSelector) + "_delay-0.1s.png");
		MSFrameLoader.load(frameLink);
		MSFrame.cropFrom(MSFrameLoader, 0, 0, 600, 338);
		}
		if(decCounter == 0){
		frameLink.replace(0, 49, "images/StartScreenFrames/frame_0" + to_string(frameSelector) + "_delay-0.1s.png");
		MSFrameLoader.load(frameLink);
		MSFrame.cropFrom(MSFrameLoader, 0, 0, 600, 338);
		}
	}
	menuStateBackground = new Animation(3, menuStateFrames);
}
void MenuState::tick() {
	startButton->tick();
	//added animation
	menuStateBackground->tick();
	
	if(startButton->wasPressed()){
		start.play();
		setNextState("Game");
		setFinished(true);
	}
}

void MenuState::render() {
	startButton->render();
	menuStateBackground->getCurrentFrame().draw(0, 0, 1027, 773);
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}