#include "FamilyMember.h"

FamilyMember::FamilyMember(int id, std::string name, std::initializer_list<int> excludedMembersIds) : 
        memberId(id), mName(name), mExcludedMembersIds(excludedMembersIds) {}