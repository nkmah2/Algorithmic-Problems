#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct Event
{
	int start, finish;
};

struct Endpoint 
{
	int time;
	bool is_start;
	
	bool operator<(const Endpoint &e)const
	{
		return time != e.time ? time < e.time : (is_start && !e.is_start);
	}
};


int FindMaxSimultaneaousEvents(vector<Event> A) 
{
	vector<Endpoint> E;
	for (const Event e : A) 
	{
		E.emplace_back(Endpoint{ e.start, true });
		E.emplace_back(Endpoint{ e.finish, false });
	}
	sort(E.begin(), E.end());

	int maxSimutaneousEvents = 0, simultaneousEvents=0;
	for (Endpoint e : E) 
	{
		if (e.is_start) 
		{
			simultaneousEvents = simultaneousEvents + 1;
			maxSimutaneousEvents = max(maxSimutaneousEvents, simultaneousEvents);
		}
		else 
		{
			simultaneousEvents = simultaneousEvents - 1;
		}
	}
	
	return maxSimutaneousEvents;
}

int main() 
{
	vector<Event> A = { { 1, 5 },{ 2, 7 },{ 4, 5 },{ 6, 10 },{ 8, 9 },{ 9, 17 },{ 11, 13 },{ 12, 15 },{ 14, 15 } };
	cout << FindMaxSimultaneaousEvents(A) << endl;
	A = { { 1, 5 },{ 2, 7 },{ 4, 5 },{ 6, 10 },{ 8, 9 }, { 9, 17 },{ 11, 13 },{ 12, 15 },{ 14, 15 },{ 9, 10 } };
	cout << FindMaxSimultaneaousEvents(A) << endl;
	cin.get();
	return 0;
}