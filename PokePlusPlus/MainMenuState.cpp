#include "MainMenuState.h"


// +--------------------------+
// | Constructor / Destructor |-
MainMenuState::MainMenuState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states)
	: State(window, supportedKeys, states) {
	sf::Texture mainMenuBackground;
	mainMenuBackground.loadFromFile("Sprites/main-menu.png");

	this->initKeybinds();
	this->initFonts();
	this->initButtons();

	// Creating a blank background for the main menu... for now, this will eventually be the
	// menu that displays after a title card asking for a new game / load / etc
	this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
	this->background.setTexture(&mainMenuBackground);

	this->currentSelection = "GAMESTATE";
}


MainMenuState::~MainMenuState() {
	// Clean up the buttons
	auto it = this->buttons.begin();
	for (; it != this->buttons.end(); ++it) {
		delete it->second;
	}
}


// +------------------------+
// | Pure Virtual Functions |
// +------------------------+
void MainMenuState::update(const float &dt) {
	// We always pass deltaTime into these functions to keep
	// the framerate and tickrate consistent across all computers
	this->updateInput(dt);
	this->updateButtons();
}

void MainMenuState::render(sf::RenderTarget *target) {
	// Make sure that the primary rendering target is the main window
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
	this->renderButtons(target);
}

void MainMenuState::renderButtons(sf::RenderTarget *target) {
	for (auto item : this->buttons) {
		item.second->render(target);
	}
}

void MainMenuState::endState() {
	std::cout << "Ending Main Menu state\n";
}

void MainMenuState::updateInput(const float &dt) {
	this->checkForQuit();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))) && currentSelection == "GAMESTATE") {
		this->currentSelection = "OPTIONS";
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))) && currentSelection == "OPTIONS") {
		this->currentSelection = "GAMESTATE";
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("ENTER")))) {
		if (currentSelection == "GAMESTATE") {
			this->states->push(new GameState(this->window, this->supportedKeys, this->states));
		}
		if (currentSelection == "OPTIONS") {
			this->quit = true;
		}
	}
}

void MainMenuState::updateButtons() {
	for (auto item : this->buttons) {
		if (item.first == currentSelection) {
			item.second->update(true);
		} else {
			item.second->update(false);
		}
	}
}


void MainMenuState::initVariables()
{
}

// +--------------+
// | Initializers |
// +--------------+
void MainMenuState::initKeybinds() {
	std::ifstream keys("Settings/mainmenu_keybinds.ini");

	// Initialize the keybindings from a file instead of hard
	// coding it, just reads them into a dictionary
	if (keys.is_open()) {
		std::string key = "";
		std::string key_value = "";

		while (keys >> key >> key_value) {
			this->keybinds[key] = this->supportedKeys->at(key_value);
		}
	}

	keys.close();
}

void MainMenuState::initBackground()
{
}

void MainMenuState::initFonts() {
	// Load the Pokemon Red font... Not all characters, might have to make
	// some of them
	if (!this->font.loadFromFile("Fonts/PKMN_RBYGSC.ttf")) {
		std::cerr << "Could not load the game font!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void MainMenuState::initButtons() {
	this->buttons["GAMESTATE"] = new Button(
		7, 15, 100, 20,
		"NEW   GAME", &this->font,
		sf::Color::White, sf::Color::Red, sf::Color::White);

	this->buttons["OPTIONS"] = new Button(
		3, 35, 100, 20,
		"OPTIONS", &this->font,
		sf::Color::White, sf::Color::Red, sf::Color::White);
}

