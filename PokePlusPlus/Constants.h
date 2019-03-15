#pragma once

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SFML\Graphics.hpp>

// The directions the player can move in, rows in a character's
// sprite sheets
enum Direction {
	down, right, up, left
};

// The types of sprite animation, columns in a character's 
// sprite sheets
enum Step {
	idle, leftFoot, null, rightFoot
};

#endif
