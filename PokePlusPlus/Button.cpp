#include "Button.h"


// +--------------------------+
// | Constructor / Destructor |
// +--------------------------+
Button::Button(float x, float y, float width, float height, std::string text, sf::Font *font, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor) {
	sf::Texture cursorTexture;
	cursorTexture.loadFromFile("Sprites/cursor.png");
	
	// Positioning and initializing the shape of the button
	this->shape.setPosition(sf::Vector2f(x, y));
	this->shape.setSize(sf::Vector2f(width, height));
	this->shape.setFillColor(idleColor);

	// Text initialization
	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);
	this->text.setFillColor(sf::Color::Black);
	this->text.setCharacterSize(8);

	// Text position offset
	this->text.setPosition(
		this->shape.getPosition().x + (this->shape.getGlobalBounds().width / 2.0f) - this->text.getGlobalBounds().width / 2.0f,
		this->shape.getPosition().y + (this->shape.getGlobalBounds().height / 2.0f) - this->text.getGlobalBounds().height / 2.0f
	);

	// Set up the cursor
	this->cursor.setPosition(this->text.getPosition().x, this->text.getPosition().y - 10);
	this->cursor.setSize(sf::Vector2f());
	this->cursor.setTexture(&cursorTexture);

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
	}
}

void Button::render(sf::RenderTarget *target) {
	target->draw(this->shape);
	target->draw(this->text);
	if (selected) {
		target->draw(this->cursor);
	}
}


// +-------------------+
// | Getters & Setters |
// +-------------------+
const bool Button::isPressed() const {
	return false;
}
