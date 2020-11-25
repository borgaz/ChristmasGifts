#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include "DataProvider.h"

#include <memory>

class Randomizer {
private:
	std::shared_ptr<DataProvider> mDataProvider = nullptr;
	std::map<int, FamilyMember> mFamilyMembers;
	std::map<int, int> mResults;

	int makePairs();
	int getPair(std::pair<const int, FamilyMember>& fm, std::map<int, FamilyMember>& recipients);

public:
	Randomizer(std::shared_ptr<DataProvider> dataProvider);
	void run();
	void printResult(std::string name);
	void printResults();
};
#endif
