#include <iostream>
#include <chrono>
#include "StableMatching.hpp"



void problem2()
{
	std::cout << "Problem 2\n\n";
	int num = 4;
	std::vector<Man> men;
	men.reserve(num);
	std::vector<Woman> women;
	women.reserve(num);

	std::vector<size_t> m_preference(num);
		
	for (int i = 0; i < num; ++i)
		m_preference[i] = i;
	std::vector<size_t> w_preference(m_preference);

	
	for (int i = 0; i < m_preference.size(); ++i)
	{			
		men.emplace_back(m_preference, i);		
		women.emplace_back(w_preference, i);
	}

	int count, num_perms;

	do{
		do{
			do{
				do{
					do{
						do{
							do{
								do{
									count = 0;
									num_perms = 0;
									StableMatching sm(men, women);					
									std::vector<size_t> male_matches(m_preference);
									std::vector<size_t> female_matches(w_preference);
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

									if (count >= 4)
									{
										std::cout << "Total number of permutations examined: " << num_perms << std::endl;
										std::cout << "Total number of Stable Mathings: " << count << std::endl;
										std::cout << "Number of men and women: " << num << std::endl;

										std::cout << "Matching:\n";
										for (auto i = 0; i < num; ++i)										
											std::cout << matches[i].first << " " << matches[i].second << std::endl;											
										
										std::cout << std::endl;
										for (auto i = 0; i < men.size(); ++i)
										{
											std::cout << "Man " << i << " preferences: ";
											for (auto p : men[i].preference)
												std::cout << p << ", ";
											std::cout << "\b\b\n";
										}

										for (auto i = 0; i < men.size(); ++i)
										{
											std::cout << "Woman " << i << " preferences: ";
											for (auto p : women[i].preference)
												std::cout << p << ", ";
											std::cout << "\b\b\n";
										}
										std::cout << std::endl;
										return;
									}
								} while (std::next_permutation(women[3].preference.begin(), women[3].preference.end()));
							} while (std::next_permutation(women[2].preference.begin(), women[2].preference.end()));
						} while (std::next_permutation(women[1].preference.begin(), women[1].preference.end()));
					} while (std::next_permutation(women[0].preference.begin(), women[0].preference.end()));
				} while (std::next_permutation(men[3].preference.begin(), men[3].preference.end()));
			} while (std::next_permutation(men[2].preference.begin(), men[2].preference.end()));
		} while (std::next_permutation(men[1].preference.begin(), men[1].preference.end()));	
	} while (std::next_permutation(men[0].preference.begin(), men[0].preference.end()));

	std::cout << "No group found ...\n";		
}

void problem3()
{
	std::cout << "\nProblem 3\n";
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
	std::cout << "Matching is Stable: " << std::boolalpha << sm.findMatching() << std::endl;
	auto v = sm.get_men();
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i].id << " " << v[i].betrothed << std::endl;

	std::cout << "Matching is Stable: " << std::boolalpha << sm.isStable() << std::endl;
}


void checker()
{

	std::cout << "\nProblem 2\n";
	Man m1({ 0, 1, 2, 3 }, 0);
	Man m2({ 0, 1, 2, 3 }, 1);
	Man m3({ 0, 1, 2, 3 }, 2);
	Man m4({ 3, 2, 1, 0 }, 3);
	

	std::vector<Man> men = { m4, m3, m2, m1 };

	
	Woman w1({ 1, 2, 3, 0 }, 0);
	Woman w2({ 0, 2, 3, 1 }, 1);
	Woman w3({ 0, 1, 3, 2 }, 2);
	Woman w4({ 0, 1, 2, 3 }, 3);
	

	std::vector<Woman> women = { w4, w3, w2, w1 };

	StableMatching sm(men, women);
	std::vector<size_t> prefs;
	for (int i = 0; i < women.size(); ++i)
		prefs.push_back(i);

	std::vector<size_t> male_matches(prefs);
	std::vector<size_t> female_matches(prefs);
	std::vector<std::pair<size_t, size_t>> matches(male_matches.size());
	int count = 0, num_perms = 0;
	do{
		num_perms++;
		for (int i = 0; i < prefs.size(); ++i)
		{
			matches[i].first = male_matches[i];
			matches[i].second = female_matches[i];
		}
		if (sm.isStable(matches, sm.get_men(), sm.get_women()))
		{
			count++;
			std::cout << "Matching:\n";
			for (auto i = 0; i < matches.size(); ++i)
				std::cout << matches[i].first << " " << matches[i].second << std::endl;
			std::cout << std::endl;
		}
			
	} while (std::next_permutation(female_matches.begin(), female_matches.end()));

}


void problem5()
{
	std::cout << "\nProblem 5\n";
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
	std::vector<size_t> prefs;
	for (int i = 0; i < women.size(); ++i)
		prefs.push_back(i);

	std::vector<size_t> male_matches(prefs);
	std::vector<size_t> female_matches(prefs);
	std::vector<std::pair<size_t, size_t>> matches(male_matches.size());
	int count = 0, num_perms = 0;

	do{
		num_perms++;
		for (int i = 0; i < prefs.size(); ++i)
		{
			matches[i].first = male_matches[i];
			matches[i].second = female_matches[i];
		}
		
		if (sm.isStable(matches, sm.get_men(), sm.get_women()))		
			count++;
	} while (std::next_permutation(female_matches.begin(), female_matches.end()));

	std::cout << "Number of permutations examined: " << num_perms << std::endl;
	std::cout << "Number of Stable Matchings: " << count << std::endl;

}



int main()
{
	checker();
	//problem2();
	problem3();
	problem5();

	
	system("pause");
	return 0;
}