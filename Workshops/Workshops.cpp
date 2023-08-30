#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

struct Workshop
{
    int start;
    int duration;
    int end;
};

struct Available_Workshops
{
    int n; // Number of workshops.
    Workshop* workshops;
};

Available_Workshops* initialize(int start_time[], int duration[], int n)
{
    Workshop* workshops = nullptr;
    Available_Workshops* available = nullptr;

    try
    {
        available = new Available_Workshops;
        workshops = new Workshop[n];
    }
    catch (bad_alloc)
    {
        if (workshops)
            delete[] workshops;
        if (available)
            delete available;

        return nullptr;
    }

    available->n = n;
    available->workshops = workshops;

    for (int i = 0; i < n; i++)
    {
        workshops[i].start = start_time[i];
        workshops[i].duration = duration[i];
        workshops[i].end = start_time[i] + duration[i];
    }
    return available;
}

int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    Workshop* workshops;

    auto compare = [](Workshop w1, Workshop w2)
        {
            return (w1.end < w2.end);
        };

    workshops = ptr->workshops;
    sort(workshops, workshops + ptr->n, compare);

    int max = 0;
    int last_workshop_end = 0;
    for (int i = 0; i < ptr->n; ++i)
    {
        if (workshops[i].start >= last_workshop_end)
        {
            max++;
            last_workshop_end = workshops[i].end;
        }
    }

    return max;
}

int main(int argc, char* argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> duration[i];
    }

    Available_Workshops* ptr;
    ptr = initialize(start_time, duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}