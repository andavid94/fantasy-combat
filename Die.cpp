/*
 ** Author: David An
 ** Date: Feb 13 2018
 ** Description: This class contains all of the Die class's methods
 ** 			 that are used by the game
 */

#include "Die.hpp"
#include <string>
#include <cstdlib>

// if number of sides is not passed, construct a standard 6-sided die
Die::Die() {
	sides = 6;
}

// constructs a regular die using the given number of sides
Die::Die(int numOfSides) {
	sides = numOfSides;
}

// returns a random integer between 1 and the number of sides of the die
int Die::roll() {
	int result = rand() % sides + 1;
	return result;
}

// returns the sum of two die rolls
int Die::roll2(Die& die1, Die& die2) {
	int rollSum = die1.roll() + die2.roll();
	return rollSum;
}

// returns the sum of three die rolls
int Die::roll3(Die& die1, Die& die2, Die& die3) {
	int rollSum = die1.roll() + die2.roll() + die3.roll();
	return rollSum;
}

// returns the number of sides
int Die::getNumOfSides() {
	return sides;
}
