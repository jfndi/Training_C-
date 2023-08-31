#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int vector_size{};

    cin >> vector_size;
    vector<int> input_vec(vector_size);
    for (int i = 0; i < vector_size; i++)
        cin >> input_vec[i];

    int to_erase{};
    cin >> to_erase;
    input_vec.erase(input_vec.begin() + to_erase - 1);

    
    vector<int> to_erase_vec(2);
    for (int i = 0; i < to_erase_vec.size(); i++)
        cin >> to_erase_vec[i];
    input_vec.erase(input_vec.begin() + to_erase_vec[0] - 1, input_vec.begin() + to_erase_vec[1] - 1);

    cout << input_vec.size() << endl;
    for (auto entry : input_vec)
        cout << entry << " ";
    cout << endl;

    return 0;
}