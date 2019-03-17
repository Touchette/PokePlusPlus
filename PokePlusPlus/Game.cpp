#include "Game.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
Game::Game() {
	this->initVariables();
	this->initWindow();
	this->initKeys();
	this->initStates();
}

Game::~Game() {
	// Clean up the window
	delete this->window;

	// Clean up the states
	while (!this->states.empty()) {
		delete this->states.top();
		this->states.pop();
	}
}


// +------------------+
// | Static Functions |
// +------------------+


// +--------------------------+
// | Initialization Functions |
// +--------------------------+
void Game::initVariables() {
	this->window = nullptr;
	this->dt = 0.0f;
}

void Game::initWindow() {
	std::string title = "NULL";
	sf::VideoMode window_bounds(160, 144);
	unsigned framerate_limit = 30;
	bool vsync_enabled = 0;
	sf::Image icon;

	// Read from the window settings file...
	std::ifstream settings("Settings/window.ini");
	// ...And into some variables for use in setting up the window later
	if (settings.is_open()) {
		std::getline(settings, title);
		settings >> window_bounds.width >> window_bounds.height;
		settings >> framerate_limit;
		settings >> vsync_enabled;
	}

	// Create the main SFML Window and set up some settings for rendering
	this->window = new sf::RenderWindow(window_bounds, title, sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(framerate_limit);
	this->window->setVerticalSyncEnabled(vsync_enabled);

	// Loading and setting the icon
	if (!icon.loadFromFile("Sprites/icon.png")) {
		std::cerr << "Could not load icon file!" << std::endl;
		exit(EXIT_FAILURE);
	}
	else { // set the window icon
		const sf::Uint8 *iconPixels = icon.getPixelsPtr();
		this->window->setIcon(12, 12, iconPixels);
	}

	this->view = new sf::View(sf::FloatRect(-0.0f, -0.0f, 320.0f, 288.0f));
	window->setView(*view);

	settings.close();
}

void Game::initKeys() {
	std::ifstream keys("Settings/supported_keys.ini");

	// Initialize the supported keys from a file instead of hard
	// coding it, just reads them into a dictionary. In this case, all keys
	// are supported for binding in the settings files.
	if (keys.is_open()) {
		std::string key = "";
		int key_value = 0;

		while (keys >> key >> key_value) {
			this->supportedKeys[key] = key_value;
		}
	}

	keys.close();
}

void Game::initStates() {
	// Push the various states onto the state stack.
	this->states.push(new MainMenuState(this->window, this->view, &this->supportedKeys, &this->states));
}


// +--------------------------+
// | Main Game Loop Functions |
// +--------------------------+
void Game::run() {
	// Here we go! Main game loop
	while (this->window->isOpen()) {
		this->updateDt();
		this->update();
		this->render();
	}
}

void Game::update() {
	// Update our event handler to check for input, etc
	this->updateSFMLEvents();

	if (!this->states.empty()) {
		this->states.top()->update(this->dt);
		
		// If a state wants to quit, delete it and go to the next one. Every state
		// has a function to check if it wants to quit or not.
		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	} else { // End the application
		this->endApplication();
		this->window->close();
	}
}

void Game::render() {
	this->window->clear();

	// Rendering goes here. We only render the top state at any given time
	// so that the game doesn't have to draw everything on top of other stuff
	if (!this->states.empty()) {
		this->states.top()->render(this->window);
	}

	this->window->display();
}

void Game::updateDt() {
	// Update the game clock to ensure that the tick rate is consistent.
	// This is passed to every single update function to ensure that they happen
	// consistently.
	this->dt = this->dtClock.restart().asSeconds();
}

void Game::endApplication() {
	//
}

void Game::updateSFMLEvents() {
	// Handles the stock SFML events like closing the main window.
	while (this->window->pollEvent(this->sfEvent)) {
		switch (this->sfEvent.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
		}
	}
}
