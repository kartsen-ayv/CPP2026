#include <iostream>
#include <cstdio>
#include <print> // run only with "-lstdc++exp" key
using std::cout, std::endl, std::println;

int main()
{
    cout << "Hello world!" << endl; // default output
    printf("Hi World!\n");          // c-style output
    println("Hi there!");           // C++23 format output

    return 0;
}
