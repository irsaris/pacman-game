#pragma once
#include "State.h"
#include "Player.h"
#include "Animation.h"

class GameOverState : public State {
private:
	ofImage GameOverScreen;

public:
	GameOverState();
	void tick();
	void render();
	void keyPressed(int key);
	void reset();
	void mousePressed(int x, int y, int button);

	//added variables
	string frameLink;
	int frameSelector, frameSelector2, decCounter, requiredCrops, imageCrop; //imageCrop is used to cut or add pixels from a desired amount
	ofImage GOSFrame, GOSFrameLoader;
	vector <ofImage> GOStateFrames;
	Animation *GOStateBackground;
	Player *scoreGetter;
};