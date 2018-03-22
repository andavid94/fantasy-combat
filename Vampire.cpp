/*
 ** Description: Vampire.cpp represents a Vampire object which inherits behavior
 ** 			 from the Character.cpp class
 */

#include "Vampire.hpp"
#include "Die.hpp"
#include <iostream>
#include <cstdlib>

Vampire::Vampire() {
	type = "Vampire";
	strengthPoints = 18;
	armor = 1;
	attack1 = Die(12);
	defense1 = Die();
}

void Vampire::rollAttack() {
	this -> attack = attack1.roll();
}

void Vampire::rollDefense() {
	this -> defense = defense1.roll();
}

/*
 ** Description: modified defend function that incorporates 'Charm' ability
 */
void Vampire::defend(int incomingAttack) {
	int decider = rand() % 2;			// generate random int between 0 and 1
	if (decider == 1) {					// proceed with ordinary defend() function
		this -> rollDefense();						// set defense based on rolls
		int rolledDefense = this -> getDefense();	// record the defense value
		std::cout << this -> getType() << " defends with a roll of " << this -> getDefense()
		<< std::endl;
		
		// perform damage calculation
		int currentDamage = (incomingAttack - (this -> getArmor()) - rolledDefense);
		if (currentDamage < 0) {
			currentDamage = 0;			// set currentDamage to 0 if it is a negative value
		}
		
		// update the Character's strength value
		this -> setStrengthPoints(this -> getStrengthPoints() - currentDamage);
		
		std::cout << "Total inflicted damage: " << currentDamage << std::endl;
		std::cout << this -> getType() << "'s new strength point amount: " << this -> getStrengthPoints()
		<< std::endl << std::endl;
	} else {							// attack is not registered 
		std::cout << "Vampire used Charm! No attack was made!\n\n";
	}
}


