#include "StableMatching.hpp"

StableMatching::StableMatching(size_t n)
{
	men.reserve(n);
	orig_men.reserve(n);
	women.reserve(n);
	matching.reserve(n);

	for (size_t i = 0; i < n; ++i)
	{
		men.emplace_back(n, i);
		women.emplace_back(n, i);
		matching.emplace_back(0, 0);
	}
	orig_men = men;
}

StableMatching::StableMatching(std::vector<Man> pmen, std::vector<Woman> pwomen) : men(pmen), women(pwomen), orig_men(pmen), matching(pmen.size())
{	
	if (men.size() != women.size())
	{
		std::exception e("StableMatching requires the number of men and women to be the same!\n");
		throw e;		
	}	
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
	men = orig_men;
	for (auto i = 0; i < orig_men.size(); ++i)
	{
		matching[i].first = orig_men[i].id;
		matching[i].second = orig_men[i].betrothed;		
	}
	return true;
}

bool StableMatching::propose(size_t man, size_t woman)
{
	Woman* w = &women[woman];
	Man* m = &orig_men[man];
	if (w->engaged)
	{
		if (w->preference[man] < w->preference[w->betrothed])
		{
			orig_men[w->betrothed].engaged = false;
			men.push_back(orig_men[w->betrothed]);
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

bool StableMatching::isStable()
{
	return isStable(matching, men, women);
}

bool StableMatching::isStable(std::vector<std::pair<size_t, size_t>> aMatching, std::vector<Man> men, std::vector<Woman> women)
{
	if (aMatching.size() != men.size() || men.size() != women.size())
	{
		std::exception e("Input list of different size to population!\n");
		throw e;
	}

	// set the men and women to be engaged based on the matching (its all copies, so its ok)
	for (int i = 0; i < aMatching.size(); ++i)
	{
		auto man_it = std::find_if(men.begin(), men.end(), [aMatching, i](const Man& m){return aMatching[i].first == m.id; });
		auto fem_it = std::find_if(women.begin(), women.end(), [aMatching, i](const Woman& w){return aMatching[i].second == w.id; });
		man_it->betrothed = aMatching[i].second;
		man_it->engaged = true;
		fem_it->betrothed = aMatching[i].first;
		fem_it->engaged = true;
	}


	for (int i = 0; i < men.size(); ++i)
	{
		//get the betrothed rank for each man
		int betrothed_rank;
		for (int j = 0; i < men[i].preference.size(); ++j)
		{
			if (men[i].preference[j] == men[i].betrothed)
			{
				betrothed_rank = j;
				break;
			}
		}

		// see if any woman that a man would prefer would also prefer her to her betrothed
		for (int j = 0; i < men[i].preference.size(); ++j)
		{	
			// if the betrothed is the best, then stop
			if (betrothed_rank <= j)
				break;

			auto w = women[men[i].preference[j]]; // a woman that the man preferes
			if (w.betrothed > w.preference[i])
				return false;
		}
	}
	return true;
}