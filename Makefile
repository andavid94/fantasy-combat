output: main.o Die.o menu.o Character.o BlueMen.o Vampire.o HarryPotter.o Medusa.o Barbarian.o inputValidation.o
	g++ main.o Die.o menu.o Character.o BlueMen.o Vampire.o HarryPotter.o Medusa.o Barbarian.o inputValidation.o -o output

main.o: main.cpp
	g++ -c main.cpp

Die.o: Die.cpp
	g++ -c Die.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

Character.o: Character.cpp
	g++ -c Character.cpp

BlueMen.o: BlueMen.cpp
	g++ -c BlueMen.cpp

Vampire.o: Vampire.cpp
	g++ -c Vampire.cpp

HarryPotter.o: HarryPotter.cpp
	g++ -c HarryPotter.cpp

Medusa.o: Medusa.cpp
	g++ -c Medusa.cpp

Barbarian.o: Barbarian.cpp
	g++ -c Barbarian.cpp

inputValidation.o: inputValidation.cpp
	g++ -c inputValidation.cpp

clean:
	rm *.o output
