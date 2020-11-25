#include "Randomizer.h"

#include <unistd.h>
#include <random>
#include <iostream>

// #define DEBUG

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
	mFamilyMembers.clear();
	mDataProvider->getData(mFamilyMembers);
	int status;
	while (makePairs() != 0) {}
	printResults();
}

int Randomizer::makePairs() {
	auto recipients = mFamilyMembers;

	for (auto fm : mFamilyMembers) {
		auto recipient = getPair(fm, recipients);
		if (recipient == -1) {
			return 1;
		} else {
			recipients.erase(recipient);
		}
		// using recipient makes us sure that there will be no double
        mResults[recipient] = fm.first;
#ifdef DEBUG
		cout << "choosen recipient: " << recipient << " <== " << fm.first << endl;
		cout << "recipients size: " << recipients.size() << endl;
		cout << "mResults size: " << mResults.size() << endl << endl;
#endif
    }
	if (mResults.size() != mFamilyMembers.size()) {
		return -1;
	}

	return 0;
}

int Randomizer::getPair(pair<const int, FamilyMember>& fm, map<int,FamilyMember>& recipients) {
	vector<int> possibleRecipientsIds;
	mt19937 gen(get_seed());

	for (auto recipient : recipients) {
		if (recipient.first != fm.first && !fm.second.checkIfExcluded(recipient.first)) {
			possibleRecipientsIds.push_back(recipient.first);
#ifdef DEBUG
			cout << "possibleRecipientsIds push: " << recipient.first << endl;
#endif
		}
	}
#ifdef DEBUG
	cout << "possibleRecipientsIds.size(): " << possibleRecipientsIds.size() << endl;
#endif

	if (possibleRecipientsIds.empty()) {
		return -1;
	}

	uniform_int_distribution<mt19937::result_type> dist(1, possibleRecipientsIds.size());
	return possibleRecipientsIds[dist(gen)-1];
}

void Randomizer::printResult(string name) {
	return ;
}

void Randomizer::printResults() {
	cout << "Wyniki losowania:\n";
	for (auto result : mResults) {
		cout << mDataProvider->getNameById(result.second) << " => " << mDataProvider->getNameById(result.first) << endl;
	}
	cout << endl;
}