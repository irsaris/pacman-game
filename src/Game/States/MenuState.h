#pragma once

#include "State.h"
#include "Button.h"
#include "Animation.h"

class MenuState : public State {
private:
	ofImage img1;
	Button *startButton;

public:
	MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();

	//added variables
	string frameLink;
	int frameSelector, frameSelector2, decCounter, requiredCrops;
	ofImage MSFrame, MSFrameLoader;
	vector <ofImage> menuStateFrames;
	Animation *menuStateBackground;

};
