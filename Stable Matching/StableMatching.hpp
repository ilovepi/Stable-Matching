#ifndef STABLE_MATCHING_HPP_
#define STABLE_MATCHING_HPP_
#include <vector>
#include <exception>
#include <utility>
#include "Person.hpp"



class StableMatching
{
private:
	std::vector<Man> men, orig_men;
	std::vector<Woman> women;
	std::vector<std::pair<size_t, size_t>> matching;

public:
	StableMatching(size_t n);
	StableMatching(std::vector<Man> men, std::vector<Woman> women);
	virtual ~StableMatching();

	bool findMatching();
	bool propose(size_t man, size_t woman);
	std::vector<Man> get_men(){ return men; }
	std::vector<Woman> get_women(){ return women; }

	bool isStable();
	std::vector<std::pair<size_t, size_t>>& getMatching(){ return matching; };
	static bool isStable(std::vector<std::pair<size_t, size_t>> aMatching, std::vector<Man> men, std::vector<Woman> women);

};// end class StableMatching






#endif //end StableMatching.hpp