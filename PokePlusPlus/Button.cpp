#include "Button.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
Button::Button(float x, float y, float width, float height, std::string text, sf::Font *font, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {
	// Positioning and initializing the shape of the button
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idleColor);

	// Text initialization
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::Black);
	this->text.setCharacterSize(12);

	// Text position offset
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.0f) - this->text.getGlobalBounds().width / 2.0f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.0f) - this->text.getGlobalBounds().height / 2.0f
	);

	// Set up the cursor
	this->initCursor();

	// Color initialization
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;

	selected = false;
}

Button::~Button() {
	//
}


// +-----------+
// | Functions |
// +-----------+
void Button::update(bool highlighted) {
	// Updates the booleans for hover and pressed
	if (highlighted) {
		this->shape.setFillColor(this->hoverColor);
		this->selected = true;
	} else {
		this->shape.setFillColor(this->idleColor);
		this->selected = false;
	}
}

void Button::render(sf::RenderTarget *target) {
	target->draw(this->shape);
	target->draw(this->text);
	if (selected) {
		target->draw(this->cursor);
	}
}


// +--------------+
// | Initializers |
// +--------------+
void Button::initCursor() {
	this->cursor.setSize(sf::Vector2f(6.0f, 7.0f));

	if (!this->cursorTexture.loadFromFile("Sprites/cursor.png")) {
		std::cerr << "Failed to load cursor texture!" << std::endl;
		exit(EXIT_FAILURE);
	}

	this->cursor.setTexture(&this->cursorTexture);
	this->cursor.setPosition(this->text.getPosition().x - 10, this->text.getPosition().y);
}

// +-------------------+
// | Getters & Setters |
// +-------------------+
const bool Button::isPressed() const {
	return false;
}
