christmasgifts: main.o FamilyMember.o Randomizer.o
	g++ main.o FamilyMember.o Randomizer.o -o ChristmasGifts

main.o: main.cpp Randomizer.h FamilyMember.h
	g++ -std=c++17 -c main.cpp

Randomizer.o: Randomizer.cpp Randomizer.h FamilyMember.h
	g++ -std=c++17 -c Randomizer.cpp

FamilyMember.o: FamilyMember.cpp FamilyMember.h
	g++ -std=c++17 -c FamilyMember.cpp