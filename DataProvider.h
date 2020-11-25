#ifndef DATA_PROVIDER_H
#define DATA_PROVIDER_H

#include "FamilyMember.h"

#include <map>

class DataProvider {
private:
	std::map<int, FamilyMember> mMembers;
	std::map<std::string, int> mNameToIds;

public:
	DataProvider();
	void initData();
	void getData(std::map<int,FamilyMember>& familyMembers);
	std::string getNameById(int id);
};
#endif
