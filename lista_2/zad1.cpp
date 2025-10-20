#include <bits/stdc++.h>
using namespace std;
int main()
{
    set<double> s;
    for (int sign : {-1, 1})
    {
        for (int bits = 0; bits < 16; bits++)
        {
            double mant = 0.5;
            for (int i = 0; i < 4; i++)
            {
                if (bits >> (3 - i) & 1)
                    mant += pow(2.0, -(2 + i));
            }
            for (int c = 0; c <= 1; c++)
            {
                for (int sgn_exp : {-1, 1})
                {
                    int exp = sgn_exp * c;
                    double x = sign * mant * pow(2.0, exp);
                    s.insert(x);
                }
            }
        }
    }
    cout << "count: " << s.size() << endl;
    cout << "min: " << *s.begin() << "\tmax: " << *s.rbegin() << endl;

    for (double x : s)
        cout << setprecision(20) << x << endl;

    double x = sqrt(DBL_MAX) * 2;
    double y = x;
    cout << x * x - y * y << endl;
    cout << (x - y) * (x + y) << endl;
    return 0;
}