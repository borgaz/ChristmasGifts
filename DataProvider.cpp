#include "DataProvider.h"

using namespace std;

namespace {
    list<FamilyMember> familyMembers = {
                            new FamilyMember(0, "Aga", {1}),
                            new FamilyMember(1, "Kuba", {0}),
                            new FamilyMember(2, "Ewa", {3}),
                            new FamilyMember(3, "Rafal", {2}),
                            new FamilyMember(4, "Mama", {5}),
                            new FamilyMember(5, "Tata", {4}),
                            new FamilyMember(6, "Monia", {7}),
                            new FamilyMember(7, "Simon", {6}),
                            new FamilyMember(8, "Daria", {}),
                            new FamilyMember(9, "Emila", {}),
                            new FamilyMember(10, "Nela", {})}
}

DataProvider::DataProvider() {}

void DataProvider::fillList(shared_ptr<list<FamilyMember>> membersList) {
    // for (int i = 0, i < familyMembers.size() , i++) {
        membersList->assign(familyMembers.begin(),familyMembers.end());
    // }
}