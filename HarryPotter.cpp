/*
 ** Description: HarryPotter.cpp represents a Harry Potter object which inherits behavior
 ** 			 from the Character.cpp class
 */

#include "HarryPotter.hpp"
#include "Die.hpp"
#include <iostream>

HarryPotter::HarryPotter() {
	type = "Harry Potter";
	hasDied = false;
	strengthPoints = 10;
	armor = 0;
	attack1 = Die();
	attack2 = Die();
	defense1 = Die();
	defense2 = Die();
}

/*
 ** Description: modify defend function to incorporate 'Hogwarts' ability
 */
void HarryPotter::defend(int incomingAttack) {
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
	
	// if Harry is dead for the first time, revive and set SP to 20
	if ((hasDied == false) && (this -> getStrengthPoints() <= 0)) {
		std::cout << "Harry Potter used Hogwarts! He has been revived with 20 SP!\n\n";
		hasDied = true;
		this -> setStrengthPoints(20);
	}
}

void HarryPotter::rollAttack() {
	this -> attack = Die::roll2(attack1, attack2);
}

void HarryPotter::rollDefense() {
	this -> defense = Die::roll2(defense1, defense2);
}
