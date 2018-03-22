/*
 ** Description: This program contains the function prototypes for the HarryPotter.cpp class
 */

#ifndef HarryPotter_hpp
#define HarryPotter_hpp
#include "Character.hpp"
#include "Die.hpp"

class HarryPotter : public Character {
	
private:
	bool hasDied;
public:
	HarryPotter();
	Die attack1;
	Die attack2;
	Die defense1;
	Die defense2;
	virtual void rollAttack();
	virtual void rollDefense();
	virtual void defend(int);
};
#endif
