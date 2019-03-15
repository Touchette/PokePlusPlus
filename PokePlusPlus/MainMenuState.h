#pragma once

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"


class MainMenuState : public State {
  public: // functions
	// +--------------------------+
	// | Constructor / Destructor |
	// +--------------------------+
	MainMenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys);
	virtual ~MainMenuState();

	// +------------------------+
	// | Pure Virtual Functions |
	// +------------------------+
	void update(const float &dt);
	void render(sf::RenderTarget *target = nullptr);

	void endState();

	void updateInput(const float &dt);

  private: // functions
	void initKeybinds();

  private: // variables
	sf::RectangleShape background;
};

#endif
