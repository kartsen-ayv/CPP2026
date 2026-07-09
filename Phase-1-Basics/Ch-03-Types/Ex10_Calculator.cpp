#include <iostream>
using std::cout, std::cin, std::string;

int main()
{
    string operation{};
    double val1{0}, val2{0};
    cout << "Enter the operation (+, -, *, /), then the first and the second values: ";
    
    while (cin >> operation >> val1 >> val2)
    {
        if (operation == "+" || operation == "plus")
        {
            cout << val1 << " + " << val2 << " = " << val1 + val2 << "\n";
        }
        else if (operation == "-" || operation == "minus")
        {
            cout << val1 << " - " << val2 << " = " << val1 - val2 << "\n";
        }
        else if (operation == "*" || operation == "mul")
        {
            cout << val1 << " * " << val2 << " = " << val1 * val2 << "\n";
        }
        else if (operation == "/" || operation == "div")
        {
            if (val2 != 0)
                cout << val1 << " / " << val2 << " = " << val1 / val2 << "\n";
            else
                cout << "You can't divide by 0!" << "\n";
        }
        else
        {
            cout << "I dont know such command...\n";
        }

        cout << "Enter the operation (+, -, *, /), then the first and the second values: ";
    }

    return 0;
}
