#include <iostream>

using namespace std;

class Box
{
	int l, b, h;
public:
	/*
	 * Constructors.
	 */
	Box() : l{ 0 }, b{ 0 }, h{ 0 } {}
	Box(int length, int breadth, int height) : l{ length }, b{ breadth }, h{ height } {}
	Box(const Box& box) : l{ box.l }, b{ box.b }, h{ box.h } {}

	int getLength() const
	{
		return l;
	}

	int getBreadth() const
	{
		return b;
	}

	int getHeight() const
	{
		return h;
	}

	long long CalculateVolume()
	{
		long long volume;

		volume = (long long)l * b * h;
		return volume;
	}

	bool operator<(const Box& B) const
	{
		bool result = false;

		if ((l < B.l) ||
			((b < B.b) && (l == B.l)) ||
			((h < B.h) && (b == B.b) && (l == B.l)))
			result = true;

		return result;
	}

	friend ostream& operator<<(ostream& os, const Box& B)
	{
		return os << B.l << " " << B.b << " " << B.h;
	}
};

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}