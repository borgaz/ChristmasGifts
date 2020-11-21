CXX = 

christmasgifts: main.o FamilyMember.o Randomizer.o
	$(CXX) main.o FamilyMember.o Randomizer.o -o CristmasGifts

main.o: main.cpp Randomizer.h FamilyMember.h
    $(CXX) main.cpp

Randomizer.o: Randomizer.cpp Randomizer.h FamilyMember.h
    $(CXX) Randomizer.cpp

FamilyMember.o: FamilyMember.cpp FamilyMember.h
    $(CXX) FamilyMember.cpp

clean:
	-rm *.o *~ 