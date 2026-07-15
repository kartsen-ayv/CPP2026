#include <iostream>
#include <cmath>

using std::cout,
    std::cerr,
    std::cin,
    std::abs;

double calc_discriminant(double a, double b, double c)
{
    return b * b - 4.0 * a * c;
}

int main()
{
    constexpr double eps{1e-9};

    double a{0}, b{0}, c{0};
    cout << "Enter a (not zero): ";
    if (!(cin >> a))
    {
        cerr << "Error: Invalid input.\n";
        return 1;
    }

    if (abs(a) < eps)
    {
        cerr << "Error: 'a' cannot be zero in a quadratic equation.\n";
        return 1;
    }

    cout << "Enter b: ";
    if (!(cin >> b))
    {
        cerr << "Error: Invalid input.\n";
        return 1;
    }
    cout << "Enter c: ";
    if (!(cin >> c))
    {
        cerr << "Error: Invalid input.\n";
        return 1;
    }

    double d = calc_discriminant(a, b, c);
    cout << "D = " << d << "\n";

    if (abs(d) < eps) // almost 0
    {
        cout << "x = " << -b / (2 * a) << "\n";
    }
    else if (d > 0.0)
    {
        cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << "\n";
        cout << "x2 = " << (-b - sqrt(d)) / (2 * a) << "\n";
    }
    else
    {
        cout << "No real roots...\n";
    }

    return 0;
}
