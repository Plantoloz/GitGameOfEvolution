
#include "Species.h"


Species::Species(int index) {
	this->index = index;
}
void Species::exists() {
	cout << this->index << endl;
}