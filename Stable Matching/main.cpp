#include <iostream>
#include <chrono>
#include "StableMatching.hpp"



void problem2()
{
	Man m1({ 0, 1, 2, 3 }, 0);
	Man m2({ 0, 1, 2, 3 }, 1);
	Man m3({ 0, 1, 2, 3 }, 2);
	Man m4({ 0, 1, 2, 3 }, 3);
	std::vector<Man> men = { m4, m3, m2, m1 };

	Woman w1({ 0, 1, 2, 3 }, 0);
	Woman w2({ 0, 1, 2, 3 }, 1);
	Woman w3({ 0, 1, 2, 3 }, 2);
	Woman w4({ 0, 1, 2, 3 }, 3);

	std::vector<Woman> women = { w4, w3, w2, w1 };

	StableMatching sm(men, women);

	int count = 0, num_perms = 0;
	std::vector<size_t> male_matches = { 0, 1, 2, 3 };
	std::vector<size_t> female_matches = { 0, 1, 2, 3 };
	std::vector<std::pair<size_t, size_t>> matches(male_matches.size());

	do{
		num_perms++;
		for (int i = 0; i < male_matches.size(); ++i)
		{
			matches[i].first = male_matches[i];
			matches[i].second = female_matches[i];
		}
		if (sm.isStable(matches, sm.get_men(), sm.get_women()))
			count++;
	} while (std::next_permutation(male_matches.begin(), male_matches.end()));

	std::cout << "Total number of permutations examined: " << num_perms << std::endl;
	std::cout << "Total number of Stable Mathings: " << count << std::endl;
	
}

void problem3()
{

	Man m1({ 0, 1, 2, 3, 4 }, 0);
	Man m2({ 1, 0, 3, 4, 2 }, 1);
	Man m3({ 2, 0, 1, 3, 4 }, 2);
	Man m4({ 3, 2, 0, 1, 4 }, 3);
	Man m5({ 3, 0, 1, 4, 2 }, 4);

	std::vector<Man> men = { m5, m4, m3, m2, m1 };

	Woman w1({ 3, 1, 2, 0, 4 }, 0);
	Woman w2({ 2, 4, 1, 0, 3 }, 1);
	Woman w3({ 2, 1, 3, 4, 0 }, 2);
	Woman w4({ 0, 3, 1, 2, 4 }, 3);
	Woman w5({ 1, 4, 0, 2, 3 }, 4);

	std::vector<Woman> women = { w5, w4, w3, w2, w1 };

	StableMatching sm(men, women);
	sm.findMatching();
	auto v = sm.get_men();
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i].id << " " << v[i].betrothed << std::endl;

	std::cout << "Matching is Stable: " << std::boolalpha << sm.isStable() << std::endl;
}

int main()
{
	problem2();
	problem3();

	/*auto time = std::chrono::high_resolution_clock::now();

	sm.findMatching();

	auto elapsed = std::chrono::high_resolution_clock::now() - time;
	auto v = sm.get_men();
	
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i].id << " " << v[i].betrothed << std::endl;

	std::cout << "Matching is Stable: " << std::boolalpha << sm.isStable() << std::endl;
	std::cout << "Elapsed time for Stable Match: " << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << " ms." <<std::endl;
	*/



	system("pause");
	return 0;
}