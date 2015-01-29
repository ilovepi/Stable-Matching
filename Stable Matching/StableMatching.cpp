#include "StableMatching.hpp"



StableMatching::StableMatching(size_t n)
{
	men.reserve(n);
	temp_men.reserve(n);
	women.reserve(n);

	for (size_t i = 0; i < n; ++i)
	{
		men.emplace_back(n, i);
		women.emplace_back(n, i);
	}

	temp_men = men;
}

StableMatching::~StableMatching(){}

bool StableMatching::findMatching()
{	
	while (!men.empty())
	{
		Man temp = men.back();
		men.pop_back();
		size_t i = 0;
		while (!temp.engaged && i < temp.preference.size())
			temp.engaged = propose(temp.id, temp.preference[i++]);		
	}
	men = temp_men;
	return true;
}

bool StableMatching::propose(size_t man, size_t woman)
{
	Woman* w = &women[woman];
	Man* m = &temp_men[man];
	if (w->engaged)
	{
		if (w->preference[man] < w->preference[w->betrothed])
		{
			men.push_back(temp_men[w->betrothed]);
		}
		else
		{
			return false;
		}
	}
	
	m->engaged = w->engaged = true;
	m->betrothed = woman;
	w->betrothed = man;
	return true;
}