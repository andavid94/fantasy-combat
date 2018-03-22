/*
 ** Description: This program contains function prototypes for the Barbarian.cpp class
 */

#ifndef Barbarian_hpp
#define Barbarian_hpp
#include "Character.hpp"
#include "Die.hpp"
#include <iostream>

class Barbarian : public Character {
public:
	Barbarian();
	Die attack1;
	Die attack2;
	Die defense1;
	Die defense2;
	virtual void rollAttack();
	virtual void rollDefense();
};

#endif
