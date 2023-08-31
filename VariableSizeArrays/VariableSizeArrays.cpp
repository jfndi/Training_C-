#include <cmath>
#include <cstdio>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string line;
    int num_arrays, num_queries;

    /*
     * Creates variable size array of arrays.
     */
    getline(cin, line);
    istringstream iss(line);
    iss >> num_arrays >> num_queries;
    vector<vector<int>> arr(num_arrays);

    /*
     * For each line, read the query entry size and store
     * the correpsonding data.
     */
    for (int query = 0; query < num_queries; query++)
    {
        int query_index_size;
        
        getline(cin, line);
        iss = istringstream(line);
        iss >> query_index_size;
        vector<int> temp(query_index_size, 0);
        for (int k = 0; k < query_index_size; k++)
            iss >> temp[k];

        arr[query] = temp;
    }

    /*
     * Now lets create the vector containing the idexes to be dumped. 
     */
    vector<vector<int>> dump(num_queries);
    for (int query = 0; query < num_queries; query++)
    {
        dump[query] = vector<int>(2, 0);
        getline(cin, line);
        iss = istringstream(line);
        iss >> dump[query][0];
        iss >> dump[query][1];
    }

    /*
     * Print the values. 
     */
    for (auto& d : dump)
        cout << arr[d[0]][d[1]] << endl;

    return 0;
}