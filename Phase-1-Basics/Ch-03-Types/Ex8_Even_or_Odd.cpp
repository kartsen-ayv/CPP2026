#include <iostream>
using std::cout, std::cin;

bool isEven(int value)
{
    return !(value & 1);
}

int main()
{
    int num{0};
    cout << "Enter the value : ";

    while (cin >> num)
    {
        if (isEven(num))
            cout << "The value " << num << " is an even number\n";
        else
            cout << "The value " << num << " is an odd number\n";

        cout << "\nEnter the value : ";
    }

    return 0;
}
