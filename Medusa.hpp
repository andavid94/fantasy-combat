/*
 ** Description: This program contains the function prototypes for the Medusa.cpp class
 */

#ifndef Medusa_hpp
#define Medusa_hpp
#include "Character.hpp"
#include "Die.hpp"

class Medusa : public Character {
protected:
	bool glare;
public:
	Medusa();
	Die attack1;
	Die attack2;
	Die defense1;
	virtual void rollAttack();
	virtual void rollDefense();
	virtual int attackFoe(Character*);
};

#endif
