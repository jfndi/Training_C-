#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

// Define specializations for the Traits class template here.
template <>
struct Traits<Fruit>
{
    static string name(int f)
    {
        string s{};

        switch ((Fruit)f)
        {
        case Fruit::apple:
            s = "apple";
            break;
        case Fruit::orange:
            s = "orange";
            break;
        case Fruit::pear:
            s = "pear";
            break;
        default:
            s = "unknown";
            break;
        }
        return s;
    }
};

template <>
struct Traits<Color>
{
    static string name(int c)
    {
        string s{};

        switch ((Color)c)
        {
        case Color::red:
            s = "red";
            break;
        case Color::green:
            s = "green";
            break;
        case Color::orange:
            s = "orange";
            break;
        default:
            s = "unknown";
            break;
        }
        return s;
    }
};

int main()
{
    int t = 0; std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}