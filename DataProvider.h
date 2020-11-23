#ifndef DATA_PROVIDER_H
#define DATA_PROVIDER_H

#include "FamilyMember.h"

#include <list>

class DataProvider {
public:
	DataProvider();
	void fillList(std::list<FamilyMember>& membersList);
	std::string getName(int id);
};
#endif
