#include <iostream>
using std::cout, std::cin, std::string;

void print(int a, int b, int c)
{
    cout << a << " " << b << " " << c << "\n";
}

void print(string a, string b, string c)
{
    cout << a << "\n"
         << b << "\n"
         << c << "\n";
}

int main(int argc, char const *argv[])
{
    int a{0}, b{0}, c{0};
    cout << "Enter three numbers : ";

    // string a{}, b{}, c{};
    // cout << "Enter three words : ";

    cin >> a >> b >> c;

    cout << "In ascending order : ";
    if (a < b)
    {
        if (b < c)
            print(a, b, c);
        else if (a < c)
            print(a, c, b);
        else
            print(c, a, b);
    }
    else
    {
        if (a < c)
            print(b, a, c);
        else if (b < c)
            print(b, c, a);
        else
            print(c, b, a);
    }

    return 0;
}
