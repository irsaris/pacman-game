#include "ofApp.h"
#include "Images.h"

int score;

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofSetWindowTitle("Undertale_But_Make_It_Pacman.exe");
	//States
	menuState = new MenuState();
	gameState = new GameState();
	gameOverState = new GameOverState();
	// Initial State
	currentState = menuState;

	ofSoundStopAll();
	currentState->background.load("UndertaleLoop.mp3");
	currentState->background.setLoop(true);
	currentState->background.play();
}

//--------------------------------------------------------------
void ofApp::update(){
	if(currentState == gameState){
		score = gameState->getScore();
	}
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				currentState = menuState;
			}
			else if(currentState->getNextState() == "GameOver"){
				currentState = gameOverState;
			}
			else if(currentState->getNextState() == "Game"){
				currentState = gameState;
			}
			currentState->reset();
		}
	}
	if(gameOverState->hasFinished()){
	setup();
	}	

	ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr){
		currentState->render();
	}
	if(currentState == gameOverState){
		string highScore = "HIGH SCORE: " + to_string(score);
		ofDrawBitmapString(highScore, ofGetWidth()/2-highScore.length()*4, ofGetHeight()/2);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}
