#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> parseInts(string str) {
    // Complete this function
    stringstream ss{ str };
    auto compare = [](char c)
        {
            if (c == ',')
                return true;
            return false;
        };

    auto count = count_if(str.begin(), str.end(), compare);
    vector<int> vec(count + 1);

    /*
     * Something wrong with the VS2022 debugger here!! 
     * The following code is not getting executed.
     * Runs correctly without debugging :-(
     */
    for (int i = 0; i < vec.size(); i++)
    {
        char c;

        if (i)
            ss >> c;

        ss >> vec[i];
    }

    return vec;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}