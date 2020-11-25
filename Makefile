christmasgifts: main.o Randomizer.o DataProvider.o FamilyMember.o
	g++ main.o Randomizer.o DataProvider.o FamilyMember.o -o ChristmasGifts

main.o: main.cpp Randomizer.h DataProvider.h
	g++ -std=c++17 -c main.cpp

Randomizer.o: Randomizer.cpp Randomizer.h DataProvider.h
	g++ -std=c++17 -c Randomizer.cpp

DataProvider.o: DataProvider.cpp DataProvider.h FamilyMember.h
	g++ -std=c++17 -c DataProvider.cpp

FamilyMember.o: FamilyMember.cpp FamilyMember.h
	g++ -std=c++17 -c FamilyMember.cpp