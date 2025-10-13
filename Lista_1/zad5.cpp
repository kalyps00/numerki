#include <bits/stdc++.h>
using namespace std;
int main()
{
    double In[20];
    In[0] = log(2026.0 / 2025.0);
    cout << setprecision(20) << 2025.0 * In[0] << endl;
    for (int i = 1; i < 20; i++)
    {
        In[i] = 1.0 / i - 2025.0 * In[i - 1];
    }
    for (int i = 0; i < 20; i += 2)
    {
        cout << setprecision(20) << "P" << i / 2.0 << " " << In[i] << endl;
    }
    for (int i = 1; i < 20; i += 2)
    {
        cout << setprecision(20) << "NP" << i / 2.0 << " " << In[i] << endl;
    }
}