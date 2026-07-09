#include <iostream>
using std::cout, std::cin;

int main()
{
    constexpr double dif = 1.609;

    double miles = 0.0, km = 0.0;
    int choose = 0;

    cout << "[1] miles to km\n[2] km to miles\nChoose an option: ";
    cin >> choose;

    switch (choose)
    {
    case 1:
        cout << "Enter the count of miles: ";
        cin >> miles;
        km = miles * dif;
        cout << miles << " miles equal " << km << " kilometers" << "\n";
        break;

    case 2:
        cout << "Enter the count of km: ";
        cin >> km;
        miles = km / dif;
        cout << km << " km equal " << miles << " miles" << "\n";
        break;

    default:
        cout << "Unknown command...\n";
        break;
    }

    return 0;
}
