#include <iostream>
#include <sstream>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/

class Student
{
private:
    int age{ 0 };
    int standard{ 0 };
    string first_name{};
    string last_name{};

public:
    void set_age(const int a)
    {
        age = a;
    }

    const int get_age() const
    {
        return age;
    }

    void set_standard(const int s)
    {
        standard = s;
    }

    const int get_standard() const
    {
        return standard;
    }

    void set_last_name(const string& s)
    {
        last_name = s;
    }

    const string get_last_name() const
    {
        return last_name;
    }

    void set_first_name(const string& s)
    {
        first_name = s;
    }

    const string get_first_name() const
    {
        return first_name;
    }

    const string to_string()
    {
        return (std::to_string(age) + ',' + first_name + ',' + last_name + ',' + std::to_string(standard) + '\n');
    }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();

    return 0;
}