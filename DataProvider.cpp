#include "DataProvider.h"

#include <map>

using namespace std;

namespace {
	list<FamilyMember> familyMembers = {
							FamilyMember(0, "Agnieszka", {1}),
							FamilyMember(1, "Jakub", {0}),
							FamilyMember(2, "Ewa", {3}),
							FamilyMember(3, "Rafal", {2}),
							FamilyMember(4, "Mama", {5}),
							FamilyMember(5, "Tata", {4}),
							FamilyMember(6, "Monika", {7}),
							FamilyMember(7, "Simon", {6}),
							FamilyMember(8, "Daria", {}),
							FamilyMember(9, "Emilia", {}),
							FamilyMember(10, "Kornelia", {})};

	map<int, string> idNameMap = {
							make_pair(0, "Agnieszka"),
							make_pair(1, "Jakub"),
							make_pair(2, "Ewa"),
							make_pair(3, "Rafal"),
							make_pair(4, "Mama"),
							make_pair(5, "Tata"),
							make_pair(6, "Monika"),
							make_pair(7, "Simon"),
							make_pair(8, "Daria"),
							make_pair(9, "Emilia"),
							make_pair(10, "Kornelia")};
}

DataProvider::DataProvider() {}

void DataProvider::fillList(list<FamilyMember>& membersList) {
	membersList.assign(familyMembers.begin(),familyMembers.end());
}

string DataProvider::getName(int id) {
	return idNameMap[id];
}