/*
 ** Description: This program displays instructions to have the user choose two
 ** 			 characters to fight eachother. 
 */

#include <iostream>
#include "menu.hpp"
#include "inputValidation.hpp"
#include "Character.hpp"
#include "BlueMen.hpp"
#include "Vampire.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"


/*
 ** Description: intitializes the game and records the character selections for the user
 */
void begin() {
	Character* player1;		// declare player1 Character variable
	Character* player2;		// declare player2 Character variable
	
	// display character selection menu for player 1
	std::cout << "Player 1, please choose your character.\n\n";
	std::cout << "1. Vampire (Special Ability: Charm)\n";
	std::cout << "2. Barbarian\n";
	std::cout << "3. Blue Men (Special Ability: Mob)\n";
	std::cout << "4. Medusa (Special Ability: Glare)\n";
	std::cout << "5. Harry Potter (Special Ability: Hogwarts)\n";
	
	int character1 = inputValidation(1, 5);		// validate input
	
	// update player1 variable with corresponding character selection
	if (character1 == 1) {
		std::cout << "Player 1 chose to play as the vampire.\n\n";
		player1 = new Vampire();
	} else if (character1 == 2) {
		std::cout << "Player 1 chose to play as the Barbarian.\n";
		player1 = new Barbarian();
	} else if (character1 == 3) {
		std::cout << "Player 1 chose to play as the Blue Men.\n";
		player1 = new BlueMen();
	} else if (character1 == 4) {
		std::cout << "Player 1 chose to play as Medusa.\n";
		player1 = new Medusa();
	} else {
		std::cout << "Player 1 chose to play as Harry Potter.\n";
		player1 = new HarryPotter();
	}
	
	// display character selection menu for player 2
	std::cout << "\nPlayer 2, please choose your character.\n";
	std::cout << "1. Vampire (Special Ability: Charm)\n";
	std::cout << "2. Barbarian\n";
	std::cout << "3. Blue Men (Special Ability: Mob)\n";
	std::cout << "4. Medusa (Special Ability: Glare)\n";
	std::cout << "5. Harry Potter (Special Ability: Hogwarts)\n";
	
	int character2 = inputValidation(1, 5);		// validate input
	
	// update player2 variable with corresponding character selection
	if (character2 == 1) {
		std::cout << "Player 2 chose to play as the vampire.\n";
		player2 = new Vampire();
	} else if (character2 == 2) {
		std::cout << "Player 2 chose to play as the Barbarian.\n";
		player2 = new Barbarian();
	} else if (character2 == 3) {
		std::cout << "Player 2 chose to play as the Blue Men.\n";
		player2 = new BlueMen();
	} else if (character2 == 4) {
		std::cout << "Player 2 chose to play as Medusa.\n";
		player2 = new Medusa();
	} else {
		std::cout << "Player 2 chose to play as Harry Potter.\n";
		player2 = new HarryPotter();
	}
	
	battle(player1, player2);		// initiate battle between the two characters
	delete player1;
	delete player2;
	
	return;
}

/*
 ** Description: simulates the battle phase of the game
 */
void battle(Character* p1, Character* p2) {
	
	// loop through battle sequence until one of the characters is dead
	while (!(p1 -> isDead()) && !(p2 -> isDead())) {
		int p1Damage = p1 -> attackFoe(p2);
		p2 -> defend(p1Damage);
		int p2Damage = p2 -> attackFoe(p1);
		p1 -> defend(p2Damage);
	}
	
	// display results of the battle
	if (p1 -> isDead() && !(p2 -> isDead())) {
		std::cout << p1 -> getType() << " is dead. " << p2 -> getType()
				<< " (Player 2) wins!\n";
	} else if (!(p1 -> isDead()) && p2 -> isDead()) {
		std::cout << p2 -> getType() << " is dead. " << p1 -> getType()
				<< " (Player 1) wins!\n";
	} else {
		std::cout << "There has been a tie! Both characters are dead!\n";
	}
	
	// prompt user to replay or exit the game
	std::cout << "To play again, enter 1.\n";
	std::cout << "To exit, enter 2.\n";
	int response = inputValidation(1, 2);
	if (response == 1) {
		begin();
	} else {
		return;
	}
}
