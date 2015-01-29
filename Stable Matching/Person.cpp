#include "Person.hpp"


Person::Person(size_t n, size_t id) : engaged(false), betrothed(-1), id(id)
{
	preference.reserve(n);
	initalize_preference(n);
}

Person::~Person(){}


void Person::initalize_preference(size_t n)
{
	for (int i = 0; i < n; ++i)
		preference.push_back(i);
	assert(preference.size() == n);
	std::random_shuffle(preference.begin(), preference.end());
}

Man::Man(size_t n, size_t id) : Person(n, id){}
Woman::Woman(size_t n, size_t id) : Person(n, id){}
Man::~Man(){};
Woman::~Woman(){};
