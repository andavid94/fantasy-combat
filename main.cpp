/*
 ** Author: David An
 ** Date: Feb 13 2018
 ** Description: This program is used to simulate a game with different characters
 ** 			 with unique abilities
 */

#include <iostream>
#include <cstdlib>
#include "menu.hpp"

int main() {
	
	std::cout << "Welcome to my fantasy combat game.\n\n";
	
	// generate different random numbers every time
	srand(static_cast<unsigned int>(time(NULL)));
	begin();
	
	return 0;
}
