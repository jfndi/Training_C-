#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int vector_size;

    cin >> vector_size;
    vector<int> vec(vector_size);

    for (int i = 0; i < vector_size; i++)
    {
        int temp;

        cin >> temp;
        vec[i] = temp;
    }

    sort(vec.begin(), vec.end());
    for (auto entry : vec)
        cout << entry << " ";
    cout << endl;

    return 0;
}
