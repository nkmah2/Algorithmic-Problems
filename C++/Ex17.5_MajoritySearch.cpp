#include<iostream>
#include<vector>
#include<string>
#include<cassert>

using std::string;


char MajorityElement(char c[] , int n) 
{
	
	char candidate;
	int count = 0;

	for (int i = 0; i < n; i++) 
	{
		char t = c[i];
		if (count == 0) 
		{
			candidate = t;
			count = 1;
		}

		else if (candidate == t) 
		{
			count++;
		}
		else 
		{
			count--;
		}
	
	}
	
	return candidate;
}


int main() 
{

	char c [] = { 'a','b', 'a','a','a','c'};
	assert(MajorityElement(c, 6) == 'a');
	return 0;

}