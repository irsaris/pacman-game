#include "State.h"
#include "Player.h"
#include "MapBuilder.h"

class GameState: public State{
    public: 
        GameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);

		//added functions
		Map* getMap(){ return map; }
		int getScore();
	
	private:
		ofImage mapImage;
		Map* map;
};