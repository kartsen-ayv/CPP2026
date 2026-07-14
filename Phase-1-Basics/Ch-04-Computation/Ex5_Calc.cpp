#include <iostream>
using std::cout, std::cin;

int main()
{
    double a{0}, b{0};
    char op{};

    cout << "Enter the simplest expression (+, -, *, /): ";

    while (cin >> a >> op >> b)
    {
        switch (op)
        {
        case '+':
            cout << a << " + " << b << " = " << a + b;
            break;

        case '-':
            cout << a << " - " << b << " = " << a - b;
            break;

        case '*':
            cout << a << " * " << b << " = " << a * b;
            break;

        case '/':
            if (b < 0.0001)
                cout << "You can't divide by 0!\n";
            else
                cout << a << " / " << b << " = " << a / b;
            break;

        default:
            cout << "I dont know such operation...\n";
            break;
        }

        cout << "\nEnter the simplest expression (+, -, *, /): ";
    }

    return 0;
}
