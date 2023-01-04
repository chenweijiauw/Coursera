//=============================================================================
//! \brief      The program should take C arrays in the "My Submission" tab and convert them to vectors.
//!             The conversion should take stdio.h definitions and functions and replace them with iostream I/O.
//!             Use C++ style comments and replace macros and #define constants with inline functions and const declarations if appropriate.
//!
//! \date       Dec 2022
//!
//! \author     Weijia Chen
//=============================================================================

#include <iostream>
#include <vector>

const int N = 40; // change defines of constants to const

inline void sum(int &res, std::vector<int> &v) // inline any short function
{
    for (int i = 0; i < v.size(); ++i)
    {
        res += v[i];
    }
}

int main()
{
    int i;
    int res = 0;
    std::vector<int> data(N); // change array to vector<>
    for (i = 0; i < N; ++i)
    {
        data[i] = i;
    }
    sum(res, data);
    std::cout << "sum is " << res << std::endl; // change to C++ io
    return 0;
}