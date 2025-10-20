// l2_7.cpp
#include <bits/stdc++.h>
using namespace std;
double f_naive(double x)
{
    return (sqrt(12150.0 * pow(x, 15) + 9.0) - 3.0) / pow(x, 15);
}
double f_stable(double x)
{
    return 12150.0 / (sqrt(12150.0 * pow(x, 15) + 9.0) + 3.0);
}
int main()
{
    double x = 0.01;
    cout << "naive: " << f_naive(x) << "\n";
    cout << "stable: " << f_stable(x) << "\n";
    return 0;
}
