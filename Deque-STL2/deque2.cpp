#include <iostream>
#include <deque>

using namespace std;

/*
 * Algorithm
 * ---------
 * We build the first k-sized window and we store on the fly the index
 * of the current maximum.
 * Once done we treat the rest of the array an element at a time.
 * First, we print the current maximum.
 * If the current element in the array will be part of a new window, we 
 * check that the elements at the beginning of the deque are stil part of
 * it. If not we throw them away.
 * If the current array element is in the k-sized window, we compare it
 * with the most recently added element in the deque and if it is greater
 * we just through away that deque element as there is absolutely no chances
 * that it becomes a maximum of one of the following window it will be member
 * of.
 */
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