#include <iostream>
#include <chrono>
#include "StableMatching.hpp"


int main()
{
	StableMatching sm(1000);	
	auto time = std::chrono::high_resolution_clock::now();

	sm.findMatching();

	auto elapsed = std::chrono::high_resolution_clock::now() - time;
	auto v = sm.get_men();
	/*
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << "Man: " << v[i].id << " Preferences: ";
		for (auto pref : v[i].preference)
			std::cout << pref << ", ";
		std::cout << std::endl;
	}

	auto w = sm.get_women();
	for (size_t i = 0; i < v.size(); ++i)
	{
		std::cout << "Woman: "<< w[i].id  << " Preferences: ";
		for (auto pref : w[i].preference)
			std::cout << pref << ", ";
		std::cout << std::endl;
	}
	*/
	for (size_t i = 0; i < v.size(); ++i)
		std::cout << v[i].id << " " << v[i].betrothed << std::endl;


	std::cout << "Elapsed time for Stable Match: " << std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count() << " ms." <<std::endl;
	system("pause");
	return 0;
}