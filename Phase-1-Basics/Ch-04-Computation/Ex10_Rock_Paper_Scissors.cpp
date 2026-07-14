#include <iostream>
#include <random>
#include <cstdlib>
#include <limits>
#include <chrono>
#include <thread>

using std::cout,
    std::cerr,
    std::cin,
    std::flush,
    std::string,
    std::random_device,
    std::default_random_engine,
    std::uniform_int_distribution,
    std::numeric_limits,
    std::streamsize,
    std::this_thread::sleep_for,
    std::chrono::milliseconds;

// in range [begin, end]
int randInt(int begin = 1, int end = 3)
{
    static random_device r;
    static default_random_engine el(r());
    uniform_int_distribution<int> rangeN(begin, end);
    return rangeN(el);
}

void show_menu()
{
    cout << "[1] Rock\n"
         << "[2] Paper\n"
         << "[3] Scissors\n"
         << "[0] Exit\n"
         << "Choose an option: ";
}

void clear_screen()
{
    std::cout << "\033[2J\033[1;1H";
}

bool validate(int ans)
{
    return ans == 0 || ans == 1 || ans == 2 || ans == 3;
}

int get_answer()
{
    int ans{-1};
    cin >> ans;

    while (!validate(ans) || cin.fail())
    {
        cin.clear();                                         // Сбрасываем флаг ошибки
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем буфер ввода
        cerr << "Invalid input... try again: ";
        cin >> ans;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // игнорируй всё вплоть до символа новой строки
    return ans;
}

void say_goodbuy()
{

    for (int i{0}; i < 2; ++i)
    {
        cout << "\rGood bye" << flush;
        sleep_for(milliseconds(300));

        for (int j{0}; j < 3; ++j)
        {
            cout << "." << flush;
            sleep_for(milliseconds(300));
        }

        // Очищаем строку пробелами перед следующим циклом
        cout << "\rGood bye   " << flush;
    }
}

int main()
{
    const string choice[] = {"Rock", "Paper", "Scissors"};
    show_menu();
    int player_choice{get_answer()};

    while (player_choice != 0)
    {
        int computer_choice{randInt()};

        cout << "Computer choice is " << choice[computer_choice - 1] << "\n";

        int result{(player_choice - computer_choice + 3) % 3};

        switch (result)
        {
        case 0:
            cout << "Draw!\n";
            break;
        case 1:
            cout << "Win!\n";
            break;
        case 2:
            cout << "Lose!\n";
            break;
        default:
            break;
        }

        cout << "Press ENTER to play again...\n";

        cin.get();
        clear_screen();

        show_menu();
        player_choice = get_answer();
    }

    say_goodbuy();

    return 0;
}
