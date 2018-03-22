/*
 ** Description: This class represents a Blue Men object and inherits behavior
 ** 			 from the Character.cpp class
 */

#include "BlueMen.hpp"
#include "Die.hpp"

BlueMen::BlueMen() {
	type = "Blue Men";
	strengthPoints = 12;
	armor = 3;
	attack1 = Die(10);
	attack2 = Die(10);
	defense1 = Die();
	defense2 = Die();
	defense3 = Die();
}

/*
 ** Description: simulate die rolls and set them as the character's attack value
 */
void BlueMen::rollAttack() {
	this -> attack = Die::roll2(attack1, attack2);
}

/*
 ** Description: simulate die rolls and set them as the character's defense value
 */
void BlueMen::rollDefense() {
	int damageCount = this -> getStrengthPoints();			// retrieve current strength points
	if (damageCount <= 4) {
		this -> defense = defense1.roll();								// roll 1 die if less than 4
	} else if (damageCount > 4 && damageCount <= 8) {
		this -> defense = Die::roll2(defense1, defense2);				// roll 2 if between 4 and 8
	} else {
		this -> defense = Die::roll3(defense1, defense2, defense3);		// roll 3 if greater than 8
	}
}
