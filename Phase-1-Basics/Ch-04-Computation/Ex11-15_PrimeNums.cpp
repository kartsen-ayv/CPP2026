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

vector<int> EratosthenesSieve(int n)
{
    if (n < 2)
        return vector<int>();

    // vector<char> faster than vector<bool>
    vector<char> sieve(n + 1, 't');
    sieve[0] = 'f';
    sieve[1] = 'f';

    // We find and remove all composite (non-prime) numbers
    for (int p = 2; (long long)p * p <= n; p++)
        if (sieve[p] == 't')
            for (long long j = (long long)p * p; j <= n; j += p)
                sieve[j] = 'f';

    vector<int> primes;
    for (size_t i = 2; i < sieve.size(); i++)
    {
        if (sieve[i] == 't')
            primes.push_back((int)i);
    }

    return primes;
}

vector<int> FirstPrimes(unsigned int n)
{
    if (n < 1)
        return {};

    vector<int> primes = {2};
    for (int p = 3; (unsigned int)primes.size() < n; p += 2)
    {
        bool is_prime = true;
        for (int j = 3; (long long)j * j <= p; j += 2)
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
    constexpr unsigned int N = 100000000;

    int duration = howLong(
                       [&]
                       {
                           EratosthenesSieve(N);
                       })
                       .count();

    cout << "The time: " << duration << " ms\n";

    return 0;
}
