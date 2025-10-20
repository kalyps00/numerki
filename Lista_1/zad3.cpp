#include <bits/stdc++.h>
using namespace std;
float ff(float x)
{
    return 162 * ((1 - cos(5 * x)) / (x * x));
}
double fd(double x)
{
    return 162 * ((1 - cos(5 * x)) / (x * x));
}
int main()
{
    for (int i = 1; i <= 20; i++)
    {
        float x = pow(10, -i);
        long double xd = pow(10, -i);
        cout << setprecision(20) << "float " << ff(x) << " " << "double " << fd((double)xd) << endl;
    }
    // cos(5 * x) wedlug komutera ten cosinus jest rowny 1  dla x>10^-10
    // wiec wyniki sa niepoprawne poniewaz ten cosinus jest rowny 0  tylko dla x = 0
}