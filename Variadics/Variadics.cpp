#include <iostream>
using namespace std;

// Enter your code for reversed_binary_value<bool...>()

template<bool arg0>
int reversed_binary_value()
{
    return arg0;
}

template<bool arg0, bool arg1, bool... args>
int reversed_binary_value()
{
    return (2 * reversed_binary_value<arg1, args...>()) + arg0;
}


template <int n, bool...digits>
struct CheckValues {
    static void check(int x, int y)
    {
        CheckValues<n - 1, 0, digits...>::check(x, y);
        CheckValues<n - 1, 1, digits...>::check(x, y);
    }
};

template <bool...digits>
struct CheckValues<0, digits...> {
    static void check(int x, int y)
    {
        int z = reversed_binary_value<digits...>();
        std::cout << (z + 64 * y == x);
    }
};

int main()
{
    int t; std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int x, y;
        cin >> x >> y;
        /*
         * Check the values between 64 * x + y
         * (64 = 1 << 6) That explains the six below.
         */
        CheckValues<6>::check(x, y);
        cout << "\n";
    }
}