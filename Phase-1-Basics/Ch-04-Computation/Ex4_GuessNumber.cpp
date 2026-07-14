#include <iostream>
#include <limits>

using std::cout, std::cin, std::numeric_limits, std::streamsize;

void print_prompt(int mid)
{
    cout << "Is your number [1] over " << mid
         << ", [2] less than " << mid
         << ", or [3] equal to " << mid << "? ";
}

char get_answer()
{
    char ans{};
    do
    {
        cin >> ans;
    } while (ans != '1' && ans != '2' && ans != '3');

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // игнорируй всё вплоть до символа новой строки
    return ans;
}

int guess(int left, int right)
{
    int mid{(left + right) / 2};
    print_prompt(mid);

    switch (get_answer())
    {
    case '1':
        return guess(mid + 1, right);

    case '2':
        return guess(left, mid - 1);

    case '3':
        return mid;

    default:
        return -1;
    }
}

int main()
{
    cout << "---GUESS NUMBER GAME---\n";
    constexpr int N{100};

    cout << "Choose a number between 1 and " << N << ", answer my questions and I'll guess it!\n";

    int res{guess(1, N)};

    cout << "Your number is " << res << "\n";
    cout << "Press Enter for exit...";
    cin.get();

    return 0;
}
