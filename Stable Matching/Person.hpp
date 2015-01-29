#ifndef PERSON_HPP_
#define PERSON_HPP_
#include <vector>
#include <algorithm>
#include <cassert>




class Person
{


public:
	bool engaged;
	size_t betrothed;
	size_t id;	
	std::vector<int> preference;	

	Person(size_t n, size_t id);
	virtual ~Person();
	void initalize_preference(size_t n);

};


class Man : public Person
{
public:
	Man(size_t n, size_t id);
	virtual ~Man();
	//bool propose(Woman& p);
	
};


class Woman: public Person
{
public:
	Woman(size_t n, size_t id);
	~Woman();
	//bool accept_proposal(Man& p);
};


#endif