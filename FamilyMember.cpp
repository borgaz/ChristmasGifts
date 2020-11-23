#include "FamilyMember.h"

FamilyMember::FamilyMember(int id, std::string name, std::initializer_list<int> excludedMembersIds) : 
		memberId(id), mName(name), mExcludedMembersIds(excludedMembersIds) {}

int FamilyMember::getId() {
	return memberId;
}

std::string FamilyMember::getName() {
	return mName;
}

bool FamilyMember::checkIfExcluded(int id) {
	for (auto excludedId : mExcludedMembersIds) {
		if (id == excludedId) {
			return true;
		}
	}
	return false;
}

std::string FamilyMember::toString() {
	return std::string(std::to_string(memberId) + mName);
}