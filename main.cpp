#include "Randomizer.h"
#include "DataProvider.h"

#include <iostream>

int main() {
	std::shared_ptr<DataProvider> dataProvider (new DataProvider());
	Randomizer randomizer(dataProvider);
	randomizer.run();

	return 0;
}
