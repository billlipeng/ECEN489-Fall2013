
#ifndef COMPAT_MISMATCH_HH
#define COMPAT_MISMATCH_HH

// For std::pair
#include <utility>

/// \file mismatch.hh
///
/// Implementation of a C++14 compatible four-iterator mismatch.  The <C++14
/// version of mismatch has undefined behavior if the second sequence is shorter
/// than the first.

namespace cpp14_compat
{

template<class InputIt1, class InputIt2>
std::pair<InputIt1, InputIt2> mismatch(
    InputIt1 first1, InputIt1 last1,
    InputIt2 first2, InputIt2 last2
)
{
    while((*first1) == (*first2) && first1 != last1 && first2 != last2)
    {
        ++first1;
        ++first2;
    }
    
    return std::make_pair(first1, first2);
}

}

#endif
