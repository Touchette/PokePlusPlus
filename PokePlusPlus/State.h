#pragma once

#ifndef STATE_H
#define STATE_H

#include "Entity.h"

class State {
  public: // functions
	// +--------------------------+
	// | Constructor / Destructor |
	// +--------------------------+
	State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states);
	virtual ~State();

	// +------------------------+
	// | Pure Virtual Functions |
	// +------------------------+
	virtual void update(const float &dt) = 0;
	virtual void render(sf::RenderTarget *target = nullptr) = 0;

	const bool & getQuit() const;
	virtual void checkForQuit();
	virtual void endState() = 0;

	virtual void updateInput(const float &dt) = 0;

  protected: // functions
	virtual void initKeybinds() = 0;

  protected: // variables
	bool quit;
	sf::RenderWindow *window;
	std::map<std::string, int> *supportedKeys;
	std::map<std::string, int> keybinds;

	// The universal stack pointer from Game
	std::stack<State *> *states;

	// Resources
	std::vector<sf::Texture *> textures;

  private: // variables
	//
};

#endif
