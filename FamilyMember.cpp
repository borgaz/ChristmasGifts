#include "FamilyMember.h"

FamilyMember::FamilyMember(std::string name, std::initializer_list<int> excludedMembersIds) : 
		mName(name), mExcludedMembersIds(excludedMembersIds) {}

std::string FamilyMember::getName() {
	return mName;
}

std::list<int> FamilyMember::getExcludedMembersIds() {
	return mExcludedMembersIds;
}

bool FamilyMember::checkIfExcluded(int id) {
	for (auto excludedId : mExcludedMembersIds) {
		if (id == excludedId) {
			return true;
		}
	}
	return false;
}
