#pragma once

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.h"

class GameState : public State {
  public: // functions
	// +--------------------------+
	// | Constructor / Destructor |
	// +--------------------------+
	GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states);
	virtual ~GameState();

	// +------------------------+
	// | Pure Virtual Functions |
	// +------------------------+
	void update(const float &dt);
	void render(sf::RenderTarget *target = nullptr);

	void updateInput(const float &dt);

  private: // functions
	// +--------------+
	// | Initializers |
	// +--------------+
	void initVariables();
	void initKeybinds();
	void initTextures();
	void initPlayer();
	void initBackground();

  private: // variables
	sf::RectangleShape background;
	sf::Texture backgroundTexture;

	Player *player;

	sf::View *windowView;
};

#endif
