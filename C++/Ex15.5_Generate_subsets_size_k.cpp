#include <algorithm>
#include <cassert>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::endl;
using std::make_unique;
using std::random_device;
using std::stoi;
using std::uniform_int_distribution;
using std::vector;
using std::cin;

void DirectCombns(int, int, int, vector<int>*, vector<vector<int>>*);

vector<vector<int>>Combns(int n, int m) 
{
	vector<vector<int>> result;
	DirectCombns(n, m, 1, make_unique<vector<int>>().get(), &result);
	return result;
}

void DirectCombns(int n, int m, int step, vector<int>* tempCombn, vector<vector<int>> *storeCombns)
{
	if (tempCombn->size() == m) 
	{
		storeCombns->emplace_back(*tempCombn);
		return;
	}

	// Generate the combinations
	const int remaining = m - tempCombn->size();
	for (int i = step; i <= n && remaining <= n - i + 1; i++) 
	{
		tempCombn->emplace_back(i);
		DirectCombns(n, m, i + 1, tempCombn, storeCombns);
		tempCombn->pop_back();
	}
}



int main() 
{
	auto result = Combns(4, 2);
	vector<vector<int>> test_result = { { 1, 2 },{ 1, 3 },{ 1, 4 },{ 2, 3 },{ 2, 4 },{ 3, 4 } };
	assert(equal(result.begin(), result.end(), test_result.begin(),test_result.end()));
	cin.get();
	return 0;
}
