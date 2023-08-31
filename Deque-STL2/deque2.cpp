#include <iostream>
#include <deque>

using namespace std;

void printKMax(int arr[], int n, int k) {
    //Write your code here.
    deque<int> index_window_max;
    int i = 0;

    for (i = 0; i < k; i++) {
        while ((!index_window_max.empty()) && arr[i] >= arr[index_window_max.back()])
            index_window_max.pop_back();
        index_window_max.push_back(i);
    }

    for (int j = i; j < n; ++j) {
        cout << arr[index_window_max.front()] << " ";
        while ((!index_window_max.empty()) && index_window_max.front() <= j - k)
            index_window_max.pop_front();

        while ((!index_window_max.empty() && arr[j] >= arr[index_window_max.back()]))
            index_window_max.pop_back();
        index_window_max.push_back(j);
    }
    cout << arr[index_window_max.front()] << endl;
}

int main() {

    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
#ifdef _MSC_VER
        int* arr = new int[n];
#else
        int arr[n];
#endif
        for (i = 0; i < n; i++)
            cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}