#ifndef STABLE_MATCHING_HPP_
#define STABLE_MATCHING_HPP_
#include <vector>
#include "Person.hpp"



class StableMatching
{
private:
	std::vector<Man> men, temp_men;
	std::vector<Woman> women;

public:
	StableMatching(size_t n);
	virtual ~StableMatching();

	bool findMatching();
	bool propose(size_t man, size_t woman);
	std::vector<Man> get_men(){ return men; }
	std::vector<Woman> get_women(){ return women; }

};// end class StableMatching






#endif //end StableMatching.hpp