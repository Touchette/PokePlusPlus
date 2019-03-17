#include "GameState.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
GameState::GameState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states)
	: State(window, supportedKeys, states) {
	this->initVariables();
	this->initKeybinds();
	this->initTextures();
	this->initCollisionMap();
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

	// Collision detection
	sf::Vector2f position = this->player->getPosition();
	sf::Vector2f position2 = position + sf::Vector2f(1.0f, 1.0f);
 	if (this->checkCollision(position, position2)) {
		std::cerr << "Collision detected! At: " << position.x << "x" << position.y
			<< ", " << position2.x << "x" << position2.y << std::endl;
		this->player->stopMove();
	}

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
	if (!this->textures["PALLET_TOWN"].loadFromFile("Sprites/pallet-town.png")) {
		std::cerr << "Failed to load Game State background texture!" << std::endl;
		exit(EXIT_FAILURE);
	}
}

void GameState::initPlayer() {
	this->player = new Player(32, 32, this->textures["PLAYER_IDLE"]);
}

void GameState::initBackground() {
	this->background.setTexture(this->textures["PALLET_TOWN"]);
}

void GameState::initCollisionMap() {
	sf::Image collisionMap;
	unsigned int height, width;

	if (!collisionMap.loadFromFile("Sprites/pallet-town-collisions.png")) {
		std::cerr << "Failed to load Game State collision map!" << std::endl;
	}

	std::ofstream log;
	log.open("log.txt");

	sf::Vector2u size = collisionMap.getSize();
	for (height = 0; height < size.y; height+=16) {
		std::vector<unsigned short> row;
		for (width = 0; width < size.x; width+=16) {
			sf::Color currentPixel = collisionMap.getPixel(width, height);
			if (currentPixel.toInteger() == 255) {
				row.push_back(1);
			} else {
				row.push_back(0);
			}
		}
		this->collisionData.push_back(row);
		if (log.is_open()) {
			log << "<";
			for (auto it : row) {
				log << it;
			}
			log << ">" << std::endl;
		}
	}

	log.close();
}

void printCollisionMap() {
	
}

bool GameState::checkCollision(sf::Vector2f source, sf::Vector2f destination) {
	unsigned int source_x = static_cast<unsigned int>(source.x / 16);
	unsigned int source_y = static_cast<unsigned int>(source.y / 16);

	unsigned int dest_x = static_cast<unsigned int>(destination.x / 16);
	unsigned int dest_y = static_cast<unsigned int>(destination.y / 16);

	return ((this->collisionData[source_y][source_x] == 1) or (this->collisionData[dest_y][dest_x] == 1));
}
