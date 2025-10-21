// plik: zad9_nowy.cpp
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    cout << fixed;
    const int Kmax = 25; // policzymy x_1 ... x_Kmax
    const long double PI = acosl(-1.0L);

    // wektory indeksowane naturalnie: indeks 1..Kmax
    vector<long double> direct(Kmax + 1, 0.0L);
    vector<long double> stable(Kmax + 1, 0.0L);

    // poczatek
    direct[1] = 2.0L;
    stable[1] = 2.0L;

    // obliczamy kolejne wyrazy: dla k = 1..Kmax-1 liczymy x_{k+1}
    for (int k = 1; k <= Kmax - 1; ++k)
    {
        // pow2 = 2^k (zgodnie z wzorem x_{k+1} = 2^k * sqrt( 2(1 - sqrt(1 - (x_k / 2^k)^2)) ) )
        long double pow2 = powl(2.0L, (long double)k);

        // ------- ORYGINALNA POSTAĆ (może być numerycznie niebezpieczna) -------
        long double ratio = direct[k] / pow2;       // x_k / 2^k
        long double inside1 = 1.0L - ratio * ratio; // 1 - (x_k / 2^k)^2
        // drobne zabezpieczenie - jeżeli inside1 jest bardzo małe ujemne z powodu błędu
        if (inside1 < 0.0L && inside1 > -1e-30L)
            inside1 = 0.0L;
        long double sqrt1 = (inside1 >= 0.0L) ? sqrtl(inside1) : 0.0L; // sqrt(1 - (x_k/2^k)^2)

        // ORYGINAL: x_{k+1} = 2^k * sqrt( 2 * (1 - sqrt1) )
        long double val_direct = 0.0L;
        long double term = 1.0L - sqrt1; // = 1 - sqrt(1 - (x_k/2^k)^2)
        if (term < 0.0L && term > -1e-30L)
            term = 0.0L;
        if (term >= 0.0L)
        {
            val_direct = pow2 * sqrtl(2.0L * term);
        }
        else
        {
            // jeśli z jakiegoś powodu term < 0 (silny błąd num.) ustaw 0
            val_direct = 0.0L;
        }
        direct[k + 1] = val_direct;

        // ------- STABILNA POSTAĆ (unika odejmowania bliskich liczb) -------
        // eps = (x_k / 2^k)^2  (to jest ratio^2)
        long double eps = ratio * ratio;
        long double inside2 = 1.0L - eps;
        if (inside2 < 0.0L && inside2 > -1e-30L)
            inside2 = 0.0L;
        long double sqrt2 = (inside2 >= 0.0L) ? sqrtl(inside2) : 0.0L; // sqrt(1 - eps)

        // STABILNA: x_{k+1} = sqrt(2) * x_k / sqrt( 1 + sqrt(1 - eps) )
        long double denom = sqrtl(1.0L + sqrt2);
        long double val_stable = 0.0L;
        if (denom != 0.0L)
        {
            val_stable = sqrtl(2.0L) * stable[k] / denom;
        }
        else
        {
            val_stable = 0.0L;
        }
        stable[k + 1] = val_stable;
    }

    // Wypiszemy tabelę: k, direct[k], stable[k], |direct-pi|, |stable-pi|
    cout << "k   direct[k]              stable[k]              |direct-pi|           |stable-pi|\n";
    cout << setprecision(18);
    for (int k = 1; k <= Kmax; ++k)
    {
        long double d = fabsl(direct[k] - PI);
        long double s = fabsl(stable[k] - PI);
        cout << setw(2) << k << ": "
             << setw(22) << scientific << direct[k] << "  "
             << setw(22) << scientific << stable[k] << "  "
             << setw(20) << scientific << d << "  "
             << setw(20) << scientific << s << "\n";
    }

    return 0;
}
