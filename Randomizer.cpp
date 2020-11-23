#include "Randomizer.h"

#include <unistd.h>
#include <random>
#include <iostream>

using namespace std;

namespace {
size_t get_seed()
{
	random_device entropy;
	return entropy();
}
} // namespace

Randomizer::Randomizer(std::shared_ptr<DataProvider> dataProvider) : mDataProvider(dataProvider) {}

void Randomizer::run() {
	mMembersList.clear();
	mResults.clear();
	mDataProvider->fillList(mMembersList);
	while (makePairs() != 0)
	makePairs();
	printResults();
}

int Randomizer::makePairs() {
	auto recipientsList = mMembersList;
	mResults.clear();
	for (FamilyMember fm : mMembersList) {
        mResults[fm.getId()] = getPair(fm, recipientsList);
		if (mResults[fm.getId()] == -1) {
			return 1;
		}
    }
	return 0;
}

int Randomizer::getPair(FamilyMember& fm, list<FamilyMember>& recipientsList) {
	vector<int> possibleRecipientsIds;
	mt19937 gen(get_seed());

	for (auto recipient : recipientsList) {
		if (recipient.getId() != fm.getId() && !fm.checkIfExcluded(recipient.getId())) {
			possibleRecipientsIds.push_back(recipient.getId());
		}
	}

	if (possibleRecipientsIds.empty()) {
		return -1;
	}

	uniform_int_distribution<mt19937::result_type> dist(0, possibleRecipientsIds.size());
	return possibleRecipientsIds[dist(gen)];
}

void Randomizer::printResult(string name) {

}

void Randomizer::printResults() {
	cout << "Wyniki losowania:\n";
	for (auto result : mResults) {
		cout << mDataProvider->getName(result.first) << " kupuje present dla " << mDataProvider->getName(result.second) << endl;
	}
	cout << endl;
}