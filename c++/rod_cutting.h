#ifndef ALGORITHM_DP_RODCUTTING
#define ALGORITHM_DP_RODCUTTING

#include <algorithm>
#include <vector>

namespace algorithm::dp
{
    // template T is either int or double
    // template U is either std::vector or std::array

    // recursive solution
    // inefficient way to deal with optimal substructure and overlapping subproblems
    template <typename T, typename U>
    T recursive_cut_rod(const U list, const int n)
    {
        if (n == 0)
            return 0;

        T q = -1;
        for (auto i = 1; i <= n; i++)
        {
            q = std::max(q, list[i - 1] + recursive_cut_rod<T, U>(list, n - i));
        }
        return q;
    }

    template <typename T, typename U>
    T memorised_cut_rod_aux(const U list, const int n, std::vector<T> &table)
    {
        if (table[n] >= 0)
            return table[n];
        T q;
        if (n == 0)
            q = 0;
        else
        {
            q = -1;
            for (auto i = 1; i <= n; i++)
            {
                q = std::max(q, list[i - 1] + memorised_cut_rod_aux<T, U>(list, n - i, table));
            }
        }

        table[n] = q;
        return q;
    }

    // top down DP approach
    template <typename T, typename U>
    T memorised_cut_rod(const U list, const int n)
    {
        std::vector<T> table(n + 1, -1);
        return memorised_cut_rod_aux<T, U>(list, n, table);
    }

    // bottom-up DP approach
    // time complexity is the same as top-down. however, implementation is simpler
    template <typename T, typename U>
    T bottom_up_cut_rod(const U list, int n)
    {
        std::vector<int> table(n + 1, 0);
        for (auto i = 1; i <= n; i++)
        {
            T q = -1;
            for (auto j = 1; j <= i; j++)
            {
                q = std::max(q, list[j - 1] + table[i - j]);
            }
            table[i] = q;
        }
        return table[n];
    }
}

#endif // !ALGORITHM_DP_RODCUTTING
