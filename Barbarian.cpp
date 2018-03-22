/*
 ** Description: This class represents a Barbarian object and inherits behavior
 ** 			 from the Character.cpp class
 */

#include "Barbarian.hpp"
#include "Character.hpp"
#include "Die.hpp"
#include <iostream>

Barbarian::Barbarian() {
	type = "Barbarian";
	strengthPoints = 12;
	armor = 0;
	attack1 = Die();
	attack2 = Die();
	defense1 = Die();
	defense2 = Die();
}

/*
 ** Description: set attack to the sum of 2 die rolls
 */
void Barbarian::rollAttack() {
	this -> attack = Die::roll2(attack1, attack2);
}

/*
 ** Description: set defense to the sum of 2 die rolls
 */
void Barbarian::rollDefense() {
	this -> defense = Die::roll2(defense1, defense2);
}



