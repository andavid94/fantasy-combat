/*
 ** Description: This program contains the function prototypes for BlueMen.cpp
 */

#ifndef BlueMen_hpp
#define BlueMen_hpp
#include "Character.hpp"
#include "Die.hpp"

class BlueMen : public Character {
public:
	BlueMen();
	Die attack1;
	Die attack2;
	Die defense1;
	Die defense2;
	Die defense3;
	virtual void rollAttack();
	virtual void rollDefense();
};
#endif
