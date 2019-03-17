#include "GameState.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states)
	: State(window, supportedKeys, states) {
	this->initVariables();
	this->initKeybinds();
	this->initTextures();
	this->initBackground();
	this->initPlayer();

	sf::View view(sf::FloatRect(-0.0f, -0.0f, 160.0f, 144.0f));
	this->window->setView(view);
}

GameState::~GameState() {
	sf::View view(sf::FloatRect(-0.0f, -0.0f, 320.0f, 288.0f));
	this->window->setView(view);
	delete this->player;
}


// +------------------------+
// | Pure Virtual Functions |
// +------------------------+
void GameState::update(const float &dt) {
	// We always pass deltaTime into these functions to keep
	// the framerate and tickrate consistent across all computers
	this->updateInput(dt);

	this->player->update(dt);
}

void GameState::render(sf::RenderTarget *target) {
	// Make sure that the primary rendering target is the main window
	if (!target) {
		target = this->window;
	}

	target->draw(this->background);
	this->player->render(this->window);
}

void GameState::updateInput(const float &dt) {
	// Update the player input for movement, this works based on the keybindings
	// we set up in the initKeybinds function which reads from a file
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
		this->player->startMovement(UP);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
		this->player->startMovement(DOWN);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT")))) {
		this->player->startMovement(LEFT);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT")))) {
		this->player->startMovement(RIGHT);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) {
		this->endState();
	}
}


// +--------------+
// | Initializers |
// +--------------+
void GameState::initVariables() {
	//
}

void GameState::initKeybinds() {
	std::ifstream keys("Settings/gamestate_keybinds.ini");

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

void GameState::initTextures() {
	if (!this->textures["PLAYER_IDLE"].loadFromFile("Sprites/clefairy-idle.png")) {
		std::cerr << "Could not load player texture!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void GameState::initPlayer() {
	this->player = new Player(8, 8, this->textures["PLAYER_IDLE"]);
}

void GameState::initBackground() {
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(this->window->getSize().x),
			static_cast<float>(this->window->getSize().y)
		)
	);

	if (!this->backgroundTexture.loadFromFile("Sprites/pallet-town.png")) {
		std::cerr << "Failed to load Game State background texture!" << std::endl;
		exit(EXIT_FAILURE);
	}

	this->background.setTexture(&this->backgroundTexture);
}
