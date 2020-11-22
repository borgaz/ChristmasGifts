#ifndef DATA_PROVIDER_H
#define DATA_PROVIDER_H

#include "FamilyMember.h"
#include <memory>

#include <list>

class DataProvider {
public:
    DataProvider();
    void fillList(std::shared_ptr<std::list<FamilyMember>> list);
};
#endif
