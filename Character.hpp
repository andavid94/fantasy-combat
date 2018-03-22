/*
 ** Description: This program contains the function prototypes for the Character.cpp class
 */

#ifndef Character_hpp
#define Character_hpp
#include <string>

class Character {
protected:
	std::string type;
	int attack;
	int defense;
	int armor;
	int strengthPoints;
public:
	Character();
	virtual ~Character();
	std::string getType();
	int getAttack();
	int getDefense();
	int getArmor();
	int getStrengthPoints();
	void setStrengthPoints(int);
	bool isDead();
	virtual void rollAttack() = 0;
	virtual void rollDefense() = 0;
	virtual int attackFoe(Character*);
	virtual void defend(int);
};

#endif
