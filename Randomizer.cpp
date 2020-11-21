#include "Randomizer.h"

namespace {
size_t get_seed()
{
	random_device entropy;
	return entropy();
}
} // namespace

void Randomizer::Randomizer() {
    ;
}

void Randomizer::run() {
    auto members = getFamilyMembers();
    ;
}
