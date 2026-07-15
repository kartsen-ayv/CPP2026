#include <iostream>
#include <vector>
#include <chrono>
#include <functional>

using std::cout,
    std::vector,
    std::ostream,
    std::operator<<,
    std::chrono::steady_clock,
    std::chrono::milliseconds,
    std::chrono::duration_cast,
    std::function;

ostream &operator<<(ostream &s, const vector<int> &v)
{
    for (int val : v)
    {
        s << val << " ";
    }
    s << "\n";
    return s;
}

// a simple search function for prime numbers from 1 to N with some optimizations
vector<int> Primes(int n)
{
    if (n < 2)
        return {};

    vector<int> primes{2};
    // We only check for odd numbers, because every even number is divisible by 2
    for (int p{3}; p <= n; p += 2)
    {
        bool is_prime{true};
        /*
            Мы ищем делители для p, хотя бы один делитель всегда <= √p,
            т.о. ставим ограничение в j * j <= p
            Мы ограничили p только нечетными числами - внешний цикл это гарантирует.
            Нечётное число никогда не делится на чётное число. Значит, проверять j = 4, 6, 8... — заранее потрачённое время.
        */
        for (int j{3}; (long long)j * j <= p; j += 2)
        {
            if (p % j == 0)
            {
                is_prime = false;
                break;
            }
        }
        if (is_prime)
            primes.push_back(p);
    }
    return primes;
}

milliseconds howLong(function<void()> what)
{
    auto begin = steady_clock::now();
    what();
    auto end = steady_clock::now();
    return duration_cast<milliseconds>(end - begin);
}

int main()
{
    constexpr unsigned int N = 100;

    int duration = howLong(
                       [&]
                       {
                           cout << Primes(N);
                       })
                       .count();

    cout << "The time: " << duration << " ms\n";

    return 0;
}
