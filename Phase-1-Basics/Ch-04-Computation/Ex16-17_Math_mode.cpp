#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using std::cout,
    std::string,
    std::vector,
    std::random_device,
    std::default_random_engine,
    std::uniform_int_distribution,
    std::ostream,
    std::operator<<;

// in range [begin, end]
int randInt(int begin = 0, int end = 1)
{
    static random_device r;
    static default_random_engine el(r());
    uniform_int_distribution<int> rangeN(begin, end);
    return rangeN(el);
}

template <class T>
ostream &operator<<(ostream &s, const vector<T> &vec)
{
    for (T val : vec)
    {
        s << val << " ";
    }
    s << "\n";
    return s;
}

template <typename T>
T sorted_vector_mode(const vector<T> &vec)
{
    if (vec.empty())
        return T{};

    size_t i_mode = 0; // индекс моды
    int max_count = 1, cur_count = 1;

    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] == vec[i + 1])
        {
            ++cur_count;
        }
        else
        {
            if (cur_count > max_count)
            {
                max_count = cur_count;
                i_mode = i;
            }
            cur_count = 1;
        }
    }
    if (cur_count > max_count)
    {
        max_count = cur_count;
        i_mode = vec.size() - 1;
    }

    return vec[i_mode];
}

int main()
{
    constexpr int N = 100;

    vector<int> nums(N, 0);
    for (int &val : nums)
    {
        val = randInt(1, N);
    }
    sort(nums.begin(), nums.end());

    cout << nums << "Mode: " << sorted_vector_mode(nums) << "\n";

    vector<string> words = {"resink",
                            "transversomedial",
                            "transversomedial",
                            "pharyngopathy",
                            "postmineral",
                            "postmineral",
                            "postmineral",
                            "myelosyphilis",
                            "silverer",
                            "evincement",
                            "evincement",
                            "phrygium",
                            "punnigram",
                            "imminution",
                            "imminution",
                            "imminution",
                            "imminution"};
    sort(words.begin(), words.end());

    cout << words << "Mode: " << sorted_vector_mode(words) << "\n";

    return 0;
}
