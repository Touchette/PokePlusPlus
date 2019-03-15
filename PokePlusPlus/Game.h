#pragma once

#ifndef GAME_H
#define GAME_H

#include "MainMenuState.h"

class Game {

  public: // functions
	// +--------------------------+
	// | Constructor / Destructor |
	// +--------------------------+
	Game();
	virtual ~Game();

	// +--------------------------+
	// | Main Game Loop Functions |
	// +--------------------------+
	void run();
	void update();
	void render();
	void updateDt();
	void endApplication();
	void updateSFMLEvents();

  private: // functions
	// +--------------------------+
	// | Initialization Functions |
	// +--------------------------+
	void initWindow();
	void initKeys();
	void initStates();
	
  private: // variables
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt; // deltaTime

	std::stack<State *> states;
	std::map<std::string, int> supportedKeys;
};

#endif
