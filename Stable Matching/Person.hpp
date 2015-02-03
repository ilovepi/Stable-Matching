#ifndef PERSON_HPP_
#define PERSON_HPP_
#include <vector>
#include <algorithm>
#include <cassert>
#include <iostream>




class Person
{
public:
	bool engaged;
	size_t betrothed;
	size_t id;	
	std::vector<size_t> preference;	

	Person(size_t n, size_t id);
	Person(std::vector<size_t> pref, size_t id);

	virtual ~Person();
	void initalize_preference(size_t n);

	friend std::ostream& operator<< (std::ostream& stream, const Person& p);
};




class Man : public Person
{
public:
	Man(size_t n, size_t id);
	Man(std::vector<size_t> pref, size_t id);
	virtual ~Man();	
	friend std::ostream& operator <<(std::ostream& stream, Man& m);
	
};


class Woman: public Person
{
public:
	Woman(size_t n, size_t id);
	Woman(std::vector<size_t> pref, size_t id);
	~Woman();
	friend std::ostream& operator <<(std::ostream& stream, Woman& w);
	
};


#endif