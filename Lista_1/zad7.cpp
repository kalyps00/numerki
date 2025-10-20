#include <bits/stdc++.h>
using namespace std;

int main()
{
    double x = M_PI / 3;
    double cos_taylor = 1.0;
    double last = 1.0;
    const int max = 20;

    for (int n = 1; n < max; n++)
    {
        last *= -x * x / ((2 * n - 1) * (2 * n));
        cos_taylor += last;
    }

    cout << setprecision(20) << "taylor cos(x) = " << cos_taylor << endl;
    cout << setprecision(20) << "cos(x) in cmath = " << cos(x) << endl;
}
