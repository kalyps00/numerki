#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

void pierwsza_wersja()
{
    long double wyniki[41] = {0.0L};
    wyniki[1] = 2.0L;
    for (int k = 2; k <= 40; k++)
    {
        long double pow2 = powl(2.0L, (long double)(k - 1)); // 2^{k-1}
        long double ratio = wyniki[k - 1] / pow2;
        long double inside = 1.0L - ratio * ratio;
        if (inside < 0.0L && inside > -1e-30L)
            inside = 0.0L;
        long double sqrtInside = (inside >= 0.0L) ? sqrtl(inside) : 0.0L;

        wyniki[k] = pow2 * sqrtl(2.0L) * (1.0L - sqrtInside);
    }

    cout << scientific << setprecision(18);
    for (int i = 1; i <= 40; ++i)
    {
        cout << i << ": " << wyniki[i] << '\n';
    }
}

void druga_wersja()
{
    long double wyniki[400] = {0.0L};
    wyniki[1] = 2.0L;
    for (int k = 2; k < 400; k++)
    {
        long double pow2 = powl(2.0L, (long double)(k - 1)); // 2^{k-1}
        long double ratio = wyniki[k - 1] / pow2;
        long double eps = ratio * ratio;
        long double inside = 1.0L - eps;
        if (inside < 0.0L && inside > -1e-30L)
            inside = 0.0L;
        long double sqrtInside = (inside >= 0.0L) ? sqrtl(inside) : 0.0L;

        long double numerator = sqrtl(2.0L) * wyniki[k - 1] * wyniki[k - 1];
        long double denominator = pow2 * (1.0L + sqrtInside);
        if (denominator != 0.0L)
            wyniki[k] = numerator / denominator;
        else
            wyniki[k] = 0.0L;
    }

    const long double PI = acosl(-1.0L);
    cout << scientific << setprecision(18);
    for (int i = 1; i <= 60; i++)
    {
        long double d = fabsl(wyniki[i] - PI);
        cout << i << ": " << wyniki[i] << "   |x-pi|=" << d << '\n';
    }
}

int main()
{
    cout << "=== wersja bezposrednia (pierwsza_wersja) ===\n";
    pierwsza_wersja();

    cout << "\n=== wersja stabilna (druga_wersja) ===\n";
    druga_wersja();

    return 0;
}
