#include "Player.h"
#include "GhostSpawner.h"

class Map{
    public:
      Map(EntityManager*);
      void addBlock(Block*);
      void addEntity(Entity*);
      void setPlayer(Player*);
      void tick();
      void render();
      void keyPressed(int key);
		  void mousePressed(int x, int y, int button);
		  void keyReleased(int key);

      //added functions
      void setGhost(GhostSpawner*);
      GhostSpawner* getGhostSpawner(){ return ghostSpawner; }
      Player* getPlayer(){ return player; }

    private:
      EntityManager *entityManager;
      Player *player;
      GhostSpawner *ghostSpawner;
};