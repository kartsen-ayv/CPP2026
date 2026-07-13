#include <iostream>
#include <vector>
#include <iomanip>
using std::cout,
    std::cin,
    std::fixed,
    std::setprecision;

int main()
{
    double sum{0};
    int count{1};
    double x{0};

    cin >> x;
    sum += x;
    double min{x}, max{x};

    while (cin >> x)
    {
        sum += x;
        ++count;
        if (x < min)
            min = x;
        if (x > max)
            max = x;
    }

    cout << "Dist:\t" << sum << "\n"
         << "Min:\t" << min << "\n"
         << "Max:\t" << max << "\n"
         << fixed << setprecision(2)
         << "Average:\t" << sum / count << "\n";

    return 0;
}
