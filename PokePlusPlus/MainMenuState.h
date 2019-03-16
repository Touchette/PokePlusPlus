#pragma once

#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

#include "GameState.h"
#include "Button.h"


class MainMenuState : public State {
  public: // functions
	// +--------------------------+
	// | Constructor / Destructor |
	// +--------------------------+
	MainMenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states);
	virtual ~MainMenuState();

	// +------------------------+
	// | Pure Virtual Functions |
	// +------------------------+
	void update(const float &dt);
	void render(sf::RenderTarget *target = nullptr);
	void renderButtons(sf::RenderTarget *target = nullptr);

	void endState();

	void updateInput(const float &dt);
	void updateButtons();

  private: // functions
	// +--------------+
	// | Initializers |
	// +--------------+
	void initVariables();
	void initKeybinds();
	void initBackground();
	void initFonts();
	void initButtons();

  private: // variables
	sf::RectangleShape background;
	sf::Font font;

	std::map<std::string, Button *> buttons;
	Button *gamestateButton;

	std::string currentSelection;
};

#endif
