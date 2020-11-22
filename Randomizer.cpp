#include "Randomizer.h"
#include <unistd.h>
#include <random>

using namespace std;

namespace {
size_t get_seed()
{
	random_device entropy;
	return entropy();
}
} // namespace

void Randomizer::run(shared_ptr<DataProvider> dataProvider) {
	shared_ptr<list<FamilyMember>> membersList;
	dataProvider.fillList(membersList);
	shared_ptr<map<int, int>> results;
	while ()
	makePairs(membersList, results);
}

int Randomizer::makePairs(shared_ptr<list<FamilyMember>> membersList, shared_ptr<map<int, int>> results) {
	auto reciversList = membersList;
	results->clear();
	for (FamilyMember fm : *membersList) {
        
    }

}

int Randomizer::getPair(shared_ptr<list<FamilyMember>> reciversList, ) 