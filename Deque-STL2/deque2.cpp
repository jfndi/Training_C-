#include <iostream>
#include <deque>

using namespace std;

struct MaxDescriptor
{
    int index;
    int value;
};

void printKMax(int arr[], int n, int k) {
    //Write your code here.
    deque<MaxDescriptor> index_window_max{};
    int i = 0;

    MaxDescriptor md{};
    for (i = 0; i < k; i++) {
        if (md.value < arr[i])
        {
            md.index = i;
            md.value = arr[i];
            if (!index_window_max.empty())
                index_window_max.pop_back();
            index_window_max.push_back(md);
        }
    }

    int start_index = 1;
    for (; i < n; i++)
    {
        cout << arr[index_window_max.front().index] << " ";

        if (index_window_max.front().index < start_index)
            index_window_max.pop_back();

        if (index_window_max.empty() || index_window_max.front().value < arr[i])
        {
            md.index = i;
            md.value = arr[i];
            if (!index_window_max.empty())
                index_window_max.pop_back();
            index_window_max.push_back(md);
        }
        start_index++;
    }

    cout << arr[index_window_max.front().index] << endl;
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