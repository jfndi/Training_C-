#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    int number_queries{};
    cin >> number_queries;

    map<string, int> marks_map{};
    for (int i = 0; i < number_queries; i++)
    {
        int type{};
        cin >> type;

        string name{};
        cin >> name;
        switch (type)
        {
        case 1:
        {
            int mark{};
            cin >> mark;
            if (marks_map.find(name) == marks_map.end())
                marks_map.insert(make_pair(name, mark));
            else
                marks_map[name] += mark;
            break;
        }
        case 2:
        {
            marks_map.erase(name);
            break;
        }
        case 3:
        {
            if (marks_map.find(name) == marks_map.end())
                cout << 0;
            else
                cout << marks_map[name];
            cout << endl;
            break;
        }
        }
    }

    return 0;
}