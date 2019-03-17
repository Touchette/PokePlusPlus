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

	// +-----------+
	// | Functions |
	// +-----------+
	bool checkCollision(sf::Vector2f source, sf::Vector2f destination);

  private: // functions
	// +--------------+
	// | Initializers |
	// +--------------+
	void initVariables();
	void initKeybinds();
	void initTextures();
	void initPlayer();
	void initBackground();
	void initCollisionMap();

  private: // variables
	sf::Texture backgroundTexture;
	sf::Sprite background;
	std::vector<std::vector<unsigned short>> collisionData;

	Player *player;

	sf::View *windowView;
};

#endif
