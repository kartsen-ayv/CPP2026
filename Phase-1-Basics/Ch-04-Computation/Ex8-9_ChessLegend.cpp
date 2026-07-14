#include <iostream>
using namespace std;

int ln(unsigned long long num)
{
    unsigned short ln{0};
    for (; num > 0; ++ln, num = num >> 1)
        ;
    return ln;
}

int main()
{
    // чтобы вычислить клетки больше 63, меняй тип на double или __int128_t (и в функции тоже)
    unsigned long long corns{0};

    cout << "Enter the desired number of grains: ";
    if (!(cin >> corns) || corns <= 0)
    {
        cout << "Error! Incorrect input...";
        return 1;
    }

    cout << "You need " << ln(corns) << " cells for " << corns << " corns";

    return 0;
}
