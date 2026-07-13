#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using std::cout,
    std::operator<<,
    std::ostream,
    std::vector,
    std::random_device,
    std::default_random_engine,
    std::uniform_int_distribution;

template <class T>
ostream &operator<<(ostream &s, const vector<T> &v)
{
    for (auto &val : v)
        s << val << " ";
    s << "\n";
    return s;
}

bool is_odd(int x)
{
    return x & 1;
}

// in range [begin, end]
int randInt(int begin = 0, int end = 1)
{
    random_device r;
    default_random_engine el(r());
    uniform_int_distribution<int> rangeN(begin, end);
    return rangeN(el);
}

double median_sort(vector<int> &vec)
{
    if (vec.empty())
        return -1;
    else
    {
        sort(vec.begin(), vec.end());

        if (is_odd(vec.size()))
        {
            return vec.at(vec.size() / 2);
        }
        else
        {
            return (vec.at(vec.size() / 2 - 1) + vec.at(vec.size() / 2)) * 0.5;
        }
    }
}

int main()
{
    const int k{randInt(1, 100)};
    const int N{2 * k + 1};

    vector<int> arr(N, 0);
    for (int &val : arr)
        val = randInt(0, 100);

    // cout << arr;
    cout << "Mid is " << median_sort(arr);

    return 0;
}
