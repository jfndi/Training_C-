#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
	set<int> test_set{};

	int query_number{};
	cin >> query_number;

	for (int i = 0; i < query_number; i++)
	{
		int query_type{};
		int value{};

		cin >> query_type >> value;
		switch (query_type)
		{
		case 1:
		{
			auto result = test_set.insert(value);
			break;
		}
		case 2:
		{
			auto result = test_set.erase(value);
			break;
		}
		case 3:
		{
			auto result = test_set.find(value);
			if (result != test_set.end())
				cout << "Yes";
			else
				cout << "No";
			cout << endl;
		}

		}
	}
    return 0;
}