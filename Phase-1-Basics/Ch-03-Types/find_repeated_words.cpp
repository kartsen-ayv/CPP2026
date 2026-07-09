#include <iostream>
using std::cout, std::cin, std::string;

int main()
{
    int count = 0;
    string cur, pre;

    while (cin >> cur)
    {
        ++count;
        if (cur == pre)
        {
            cout << "The word number " << count << " repeated: " << cur << "\n";
        }

        pre = cur;
    }

    return 0;
}
