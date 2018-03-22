/*
 ** Description: This program contains the function prototypes for the Vampire.cpp class
 */

#ifndef Vampire_hpp
#define Vampire_hpp
#include "Character.hpp"
#include "Die.hpp"

class Vampire : public Character {
public:
	Vampire();
	Die attack1;
	Die defense1;
	virtual void rollAttack();
	virtual void rollDefense();
	virtual void defend(int);
};
#endif
