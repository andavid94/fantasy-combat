/*
 ** Author: David An
 ** Date: Feb 13 2018
 ** Description: This program contains the function prototypes
 ** 			 for the Die.cpp class
 */

#ifndef Die_hpp
#define Die_hpp

class Die {
	
private:
	int sides;
	
public:
	Die();
	Die(int numOfSides);
	int roll();
	static int roll2(Die& die1, Die& die2);
	static int roll3(Die& die1, Die& die2, Die&die3);
	int getNumOfSides();
};

#endif
