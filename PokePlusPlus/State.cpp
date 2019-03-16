#include "State.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
State::State(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys, std::stack<State *> *states) {
	// Set up the base state that will apply to all children. They all need the
	// window to render to, as well as which keys are supported for their bindings.
	this->window = window;
	this->supportedKeys = supportedKeys;
	this->states = states;
	this->quit = false;
}


State::~State() {
	//
}

const bool & State::getQuit() const {
	return this->quit;
}

void State::checkForQuit() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))) {
		this->quit = true;
	}
}
