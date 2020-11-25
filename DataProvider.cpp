#include "DataProvider.h"

using namespace std;

DataProvider::DataProvider() {
	initData();
}

void DataProvider::getData(map<int,FamilyMember>& familyMembers) {
	familyMembers = mMembers;
}

string DataProvider::getNameById(int id) {
	return mMembers.at(id).getName();
}

void DataProvider::initData() {
	mMembers.emplace(0, FamilyMember("Agnieszka", {1}));
	mMembers.emplace(1, FamilyMember("Jakub", {0}));
	mMembers.emplace(2, FamilyMember("Ewa", {3}));
	mMembers.emplace(3, FamilyMember("Rafal", {2}));
	mMembers.emplace(4, FamilyMember("Mama", {5}));
	mMembers.emplace(5, FamilyMember("Tata", {4}));
	// mMembers.emplace(6, FamilyMember("Monika", {7}));
	// mMembers.emplace(7, FamilyMember("Simon", {6}));
	mMembers.emplace(8, FamilyMember("Daria", {}));
	mMembers.emplace(9, FamilyMember("Emilia", {}));
	mMembers.emplace(10, FamilyMember("Kornelia", {}));

	for (auto member : mMembers) {
		mNameToIds.emplace(member.second.getName(), member.first);
	}
}