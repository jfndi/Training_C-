#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
protected:
    string name;
    int age;
public:
    Person() : name{}, age{ 0 } {}
    virtual void getdata() {};
    virtual void putdata() {};
    virtual ~Person() {}
};

class Professor : public Person
{
private:
    int publications;
    static int id;
    int cur_id;

public:

    Professor() : Person(),
        publications{ 0 },
        cur_id{ 0 }
    {
        cur_id = (++id);
    }

    virtual ~Professor() {}

    virtual void getdata() override
    {
        cin >> name >> age >> publications;
    }

    virtual void putdata() override
    {
        cout << name << " " << age << " " << publications << " " << cur_id << endl;
    }
};

int Professor::id = 0;

class Student : public Person
{
private:
    vector<int> marks;
    int cur_id;
    static int id;

public:
    Student() : cur_id{ 0 }, marks(6)
    {
        cur_id = ++id;
    }
    virtual ~Student() {}

    virtual void getdata() override
    {
        cin >> name >> age;
        for (int i = 0; i < 6; i++)
            cin >> marks[i];
    }

    virtual void putdata() override
    {
        int total = 0;

        cout << name << " " << age;
        for (int i = 0; i < 6; i++)
            total += marks[i];
        cout << " " << cur_id << endl;
    }
};

int Student::id = 0;
int main() {

    int n, val;
    cin >> n; //The number of objects that is going to be created.
#ifdef _MSC_VER
    vector<Person*> per(n);
#else
    Person* per[n];
#endif

    for (int i = 0; i < n; i++) {

        cin >> val;
        if (val == 1) {
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for (int i = 0; i < n; i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
