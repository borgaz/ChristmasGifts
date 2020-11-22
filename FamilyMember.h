#ifndef FAMILY_MEMBER_H
#define FAMILY_MEMBER_H

#include <string>
#include <list>

class FamilyMember {
private:
    int memberId;
    std::string mName;
    std::list<int> mExcludedMembersIds;

public:
    FamilyMember(int id, std::string name, std::initializer_list<int> excludedMembersIds);
};
#endif
