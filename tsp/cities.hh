/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <math.h>
#include <algorithm>

using namespace std;

// Representation of an ordering of cities
class Cities
{
public:	
	using coord_t = std::pair<int, int>;

	// An ordering of cities. Each value represents a unique index
	// into the current city ordering in some container.
	using permutation_t = std::vector<unsigned int>;
	Cities() {};
	Cities(permutation_t p);

	~Cities() = default;


	// A pair of integral coordinates for each city


	std::vector<coord_t> cities;
	std::pair<int,int> temp;
	permutation_t random_p;
	// Given a permutation, return a new Cities object where the order of the
	// cities reflects the original order of this class after reordering with
	// the given ordering. So for example, the ordering { 1, 0 } simply swaps
	// the first two elements (coordinates) in the new Cities object.
	Cities reorder(const permutation_t &ordering) const;


	// For a given permutation of the cities in this object,
	// compute how long (distance) it would take to traverse all the cities in the
	// order of the permutation, and then returning to the first city.
	// The distance between any two cities is computed as the Euclidean
	// distance on a plane between their coordinates.
	double total_path_distance(const permutation_t &ordering) const;

	permutation_t random_permutation(unsigned len);

	friend std::istream& operator>>(std::istream& is, Cities& C);

	friend std::ostream& operator<<(std::ostream& os, Cities& C);
};
