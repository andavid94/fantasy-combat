/*
 ** Description: Medusa.cpp represents a Medusa object which inherits behavior
 ** 			 from the Character.cpp class
 */

#include "Medusa.hpp"
#include "Die.hpp"
#include <iostream>

Medusa::Medusa() {
	type = "Medusa";
	strengthPoints = 8;
	armor = 3;
	attack1 = Die();
	attack2 = Die();
	defense1 = Die();
}

/*
 ** Description: modify attackFoe method to incorporate 'Glare' ability
 */
int Medusa::attackFoe(Character* foe) {
	this -> rollAttack();						// set attack based on die rolls
	int damage = this -> getAttack();			// record the attack value
	
	if (damage == 12) {				// if a 12 is rolled
		std::cout << this -> getType() << " attacked " << foe -> getType() << std::endl;
		std::cout << foe -> getType() << "'s armor: " << foe -> getArmor() << std::endl;
		std::cout << foe -> getType() << "'s strength points: " << foe -> getStrengthPoints()
		<< std::endl << std::endl;
		std::cout << this -> getType() << " attacks with a roll of " << damage << std::endl;
		std::cout << "Medusa used Glare! " << foe -> getType() << " has turned to stone!\n";
		return 100;					// guaruntee a victory for Medusa
	} else {
		std::cout << this -> getType() << " attacked " << foe -> getType() << std::endl;
		std::cout << foe -> getType() << "'s armor: " << foe -> getArmor() << std::endl;
		std::cout << foe -> getType() << "'s strength points: " << foe -> getStrengthPoints()
		<< std::endl << std::endl;
		std::cout << this -> getType() << " attacks with a roll of " << damage << std::endl;
	
		return damage;			// return the damage attacked
	}
}

void Medusa::rollAttack() {
	this -> attack = Die::roll2(attack1, attack2);
	if (this -> attack == 12) {
		this -> glare = true;
	}
}

void Medusa::rollDefense() {
	this -> defense = defense1.roll();
}
