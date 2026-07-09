#include <iostream>
using std::cout, std::cin, std::string;

int main()
{
    string str{};
    cout << "Enter the word : ";
    while (cin >> str)
    {
        if (str == "zero")
        {
            cout << 0 << "\n";
        }
        else if (str == "one")
        {
            cout << 1 << "\n";
        }
        else if (str == "two")
        {
            cout << 2 << "\n";
        }
        else if (str == "three")
        {
            cout << 3 << "\n";
        }
        else if (str == "four")
        {
            cout << 4 << "\n";
        }
        else
        {
            cout << "I don't know such a number...\n";
        }

        cout << "Enter the word: ";
    }

    return 0;
}
