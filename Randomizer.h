#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include "DataProvider.h"

#include <memory>
#include <map>

class Randomizer {
private:
	std::shared_ptr<DataProvider> mDataProvider = nullptr;
	std::list<FamilyMember> mMembersList;
	std::map<int, int> mResults;

	int makePairs();
	int getPair(FamilyMember& fm, std::list<FamilyMember>& recipientsList);

public:
	Randomizer(std::shared_ptr<DataProvider> dataProvider);
	void run();
	void printResult(std::string name);
	void printResults();
};
#endif
