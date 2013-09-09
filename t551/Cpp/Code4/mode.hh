
#ifndef MODE_HH
#define MODE_HH

#include <algorithm>
#include <iterator>
#include <tuple>
#include <unordered_map>

template<class InputIterator>
auto mode_frequency_map(
    InputIterator first,
    InputIterator last
)
    -> typename std::iterator_traits<InputIterator>::value_type
{
    typedef
        typename std::iterator_traits<InputIterator>::value_type
        value_type;
    
    typedef std::unordered_map<value_type, std::size_t> frequency_table_t;
    typedef typename frequency_table_t::value_type table_value_type;
    frequency_table_t frequency_table;
    
    for(; first != last; ++first)
    {
        frequency_table[(*first)] += 1;
    }

    auto max_pair_iterator = std::max_element(
        begin(frequency_table),
        end(frequency_table),
        [](
            const table_value_type &left,
            const table_value_type &right
        ) -> bool {
            return (std::get<1>(left) < std::get<1>(right));
        }
    );
    
    return std::get<0>(*max_pair_iterator);
}

#endif
