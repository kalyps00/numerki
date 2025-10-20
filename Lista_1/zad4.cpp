#include <bits/stdc++.h>
using namespace std;
int main()
{
    double y0 = 1.0, y1 = -1.0 / 9.0, y2;
    for (int i = 0; i < 20; i++)
    {
        y2 = 98.0 / 9.0 * y1 + 11.0 / 9.0 * y0;
        y0 = y1;
        y1 = y2;
        cout << setprecision(20) << y2 << endl;
    }
}