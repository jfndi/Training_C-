#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix
{
public:
    vector<vector<int>> a;

    Matrix() : a{} {}
    Matrix(Matrix& rhs) : a{ rhs.a } {}

    Matrix& operator=(Matrix& rhs)
    {
        if (this == &rhs)
            return *this;

        a = rhs.a;
        return *this;
    }

    Matrix& operator=(Matrix&& rhs) noexcept
    {
        if (this == &rhs)
            return *this;

        a = move(rhs.a);
        return *this;
    }

    Matrix operator+(Matrix& rhs)
    {
        Matrix res{};

        for (int i = 0; i < rhs.a.size(); i++)
        {
            vector<int> partial_res{};

            for (int j = 0; j < a[i].size(); j++)
            {
                partial_res.push_back(a[i][j] + rhs.a[i][j]);
            }
            res.a.push_back(partial_res);
        }

        return res;
    }
};

int main() {
    int cases, k;
    cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        cin >> n >> m;
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}