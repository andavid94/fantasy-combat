/*
 ** Description: This is an abstract class that contains basic attributes and
 ** 			 behavior for other characters
 */

#include "Character.hpp"
#include <iostream>
#include <string>
#include <sstream>

Character::Character() {}

Character::~Character() {}

std::string Character::getType() {
	return type;
}

int Character::getAttack() {
	return attack;
}

int Character::getDefense() {
	return defense;
}

int Character::getArmor() {
	return armor;
}

int Character::getStrengthPoints() {
	return strengthPoints;
}

void Character::setStrengthPoints(int strengthIn) {
	strengthPoints = strengthIn;
}

/*
 ** Description: returns true if the Character is dead, returns false otherwise
 */
bool Character::isDead() {
	if (getStrengthPoints() <= 0) {
		return true;
	} else {
		return false;
	}
}

/*
 ** Description: performs the attack calculations on the passed Character variable
 */
int Character::attackFoe(Character* foe) {
	this -> rollAttack();						// set attack based on die rolls
	int damage = this -> getAttack();			// record the attack value
	
	std::cout << this -> getType() << " attacked " << foe -> getType() << std::endl;
	std::cout << foe -> getType() << "'s armor: " << foe -> getArmor() << std::endl;
	std::cout << foe -> getType() << "'s strength points: " << foe -> getStrengthPoints()
	<< std::endl << std::endl;
	std::cout << this -> getType() << " attacks with a roll of " << damage << std::endl;
	
	return damage;			// return the damage attacked
}

/*
 ** Description: rolls the Character's defense dies and stores the values as its defense value
 */
void Character::defend(int incomingAttack) {
	
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
}

