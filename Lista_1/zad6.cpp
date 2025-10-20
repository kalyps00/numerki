#include <bits/stdc++.h>
using namespace std;
int main()
{
    double pi = 0;
    for (int i = 0; i < 20; i++)
    {
        pi += i % 2 ? -1.0 / (2 * i + 1) : 1.0 / (2 * i + 1);
    }
    pi *= 4;
    cout << setprecision(20) << "   pi = " << pi << endl;
    cout << setprecision(20) << "M_PI = " << M_PI << endl;
}