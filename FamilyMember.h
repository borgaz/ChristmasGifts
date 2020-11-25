#ifndef FAMILY_MEMBER_H
#define FAMILY_MEMBER_H

#include <string>
#include <list>

class FamilyMember {
private:
	std::string mName;
	std::list<int> mExcludedMembersIds;

public:
	FamilyMember(std::string name, std::initializer_list<int> excludedMembersIds);
	std::string getName();
	std::list<int> getExcludedMembersIds();
	bool checkIfExcluded(int id);
};
#endif
