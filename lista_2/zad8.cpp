// plik: L2_8.cpp
#include <iostream>
#include <cmath>
#include <iomanip>

int main()
{
    std::cout << std::setprecision(15);
    std::cout << "i     x                     f_orig(double)       f_stable(double)    remark\n";
    for (int i = 11; i <= 20; ++i)
    {
        double x = std::pow(10.0, -i);

        // oryginalna postac (moze sie skalic źle)
        double f_orig = 162.0 * (1.0 - std::cos(5.0 * x)) / (x * x);

        // stabilna postac
        double t = 2.5 * x; // = 5x/2
        double sinc = 1.0;
        if (t != 0.0)
        {
            sinc = std::sin(t) / t; // sin(t)/t
        }
        double f_stable = 2025.0 * (sinc * sinc);

        std::cout << std::setw(2) << i << "  "
                  << std::scientific << std::setw(13) << x << "  "
                  << std::fixed << std::setw(18) << f_orig << "  "
                  << std::setw(18) << f_stable << "  ";
        if (std::fabs(f_stable - 2025.0) < 1e-12)
        {
            std::cout << "≈2025 (OK)";
        }
        else
        {
            std::cout << "diff=" << (f_stable - 2025.0);
        }
        std::cout << "\n";
    }
    return 0;
}
