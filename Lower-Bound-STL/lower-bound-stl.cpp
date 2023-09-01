#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */

    /*
     * Get the number of sorted integers 
     */
    int n{};
    cin >> n;
    vector<int> array(n);

    /*
     * Get the sorted entries. 
     */
    for (auto i = 0; i < n; ++i)
        cin >> array[i];

    /*
     * Get the number of queries.
     */
    int q{};
    cin >> q;

    for (auto i = 0; i < q; ++i)
    {
        /*
         * Get the ith value.
         */
        int value{};
        cin >> value;

        auto result = lower_bound(array.begin(), array.end(), value);

        int index{ (int)(result - array.begin()) };
        if (value == array[index])
            cout << "Yes ";
        else
            cout << "No ";
        cout << index + 1 << endl;
    }

    return 0;
}