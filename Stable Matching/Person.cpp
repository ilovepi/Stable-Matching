#include "Person.hpp"


Person::Person(size_t n, size_t id) : engaged(false), betrothed(0), id(id)
{
	preference.reserve(n);
	initalize_preference(n);
}

Person::Person(std::vector<size_t> pref, size_t id):engaged(false), betrothed(0), id(id), preference(pref){}

Person::~Person(){}


void Person::initalize_preference(size_t n)
{
	for (int i = 0; i < n; ++i)
		preference.push_back(i);
	assert(preference.size() == n);
	std::random_shuffle(preference.begin(), preference.end());
}

Man::Man(size_t n, size_t id) : Person(n, id){}
Man::Man(std::vector<size_t> pref, size_t id) : Person(pref, id){}
Man::~Man(){};
Woman::Woman(size_t n, size_t id) : Person(n, id){}
Woman::Woman(std::vector<size_t> pref, size_t id) : Person(pref, id){}
Woman::~Woman(){};

std::ostream& operator<<(std::ostream& stream, const Person& p)
{
	stream << "Person: " << p.id << " betrothed: " << p.betrothed << " preference: ";
	for (auto item : p.preference)
		stream << item << ", ";
	stream << std::endl;
	return stream;
}


std::ostream& operator <<(std::ostream& stream, Man& m)
{
stream << "Man, " << (Person)m;
return stream;
}

std::ostream& operator <<(std::ostream& stream, Woman& w)
{
	stream << "Woman, " << (Person)w;
	return stream;
}