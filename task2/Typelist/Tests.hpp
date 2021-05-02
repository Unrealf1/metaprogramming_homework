#pragma once

#include "TypeList.hpp"
#include "Utility.hpp"
#include "Erase.hpp"
#include "Reverse.hpp"

#include <string>

using OneElem = TypeList<int>;
using TwoElem = TypeList<int, char>;
using ThreeElem = TypeList<int, char, std::string>;

namespace Lenght_tests
{
    static_assert(0 == Length<EmptyList>::value);
    static_assert(1 == Length<OneElem>::value);
    static_assert(2 == Length<TwoElem>::value);
    static_assert(3 == Length<ThreeElem>::value);
}

namespace TypeAt_tests
{
    static_assert(std::is_same<int, TypeAt<OneElem, 0>::Result>::value);

    static_assert(std::is_same<int, TypeAt<TwoElem, 0>::Result>::value);
    static_assert(std::is_same<char, TypeAt<TwoElem, 1>::Result>::value);
    
    static_assert(std::is_same<int, TypeAt<ThreeElem, 0>::Result>::value);
    static_assert(std::is_same<char, TypeAt<ThreeElem, 1>::Result>::value);
    static_assert(std::is_same<std::string, TypeAt<ThreeElem, 2>::Result>::value);
}

namespace IndexOf_tests
{
    static_assert(-1 == IndexOf<EmptyList, int>::value);

    static_assert(0 == IndexOf<OneElem, int>::value);
    static_assert(-1 == IndexOf<OneElem, char>::value);

    static_assert(0 == IndexOf<ThreeElem, int>::value);
    static_assert(1 == IndexOf<ThreeElem, char>::value);
    static_assert(2 == IndexOf<ThreeElem, std::string>::value);
    static_assert(-1 == IndexOf<ThreeElem, float>::value);
}

namespace Append_tests
{
    using should_be_null = Append<NullType, NullType>::Result;
    using new_OneElem = Append<EmptyList, int>::Result;
    using new_TwoElem = Append<OneElem, char>::Result;
    using new_ThreeElem = Append<new_TwoElem, std::string>::Result;
    
    static_assert(std::is_same<Append<EmptyList, EmptyList>::Result, EmptyList>::value);
    static_assert(0 == Length<should_be_null>::value);
    static_assert(std::is_same<OneElem, new_OneElem>::value);
    static_assert(std::is_same<TwoElem, new_TwoElem>::value);
    static_assert(std::is_same<ThreeElem, new_ThreeElem>::value);
}

namespace Reverse_tests
{
    using r_empty = Reverse<EmptyList>::Result;
    using r_one = Reverse<OneElem>::Result;
    using r_two = Reverse<TwoElem>::Result;
    using r_three = Reverse<ThreeElem>::Result;

    static_assert(std::is_same<EmptyList, r_empty>::value);
    static_assert(std::is_same<OneElem, r_one>::value);
    static_assert(std::is_same<r_two, TypeList<char, int>>::value);
    static_assert(std::is_same<r_three, TypeList<std::string, char, int>>::value);
}

namespace TypeAt_tests
{
    static_assert(std::is_same<int, TypeAt<OneElem, 0>::Result>::value);

    static_assert(std::is_same<int, TypeAt<TwoElem, 0>::Result>::value);
    static_assert(std::is_same<char, TypeAt<TwoElem, 1>::Result>::value);
    
    static_assert(std::is_same<int, TypeAt<ThreeElem, 0>::Result>::value);
    static_assert(std::is_same<char, TypeAt<ThreeElem, 1>::Result>::value);
    static_assert(std::is_same<std::string, TypeAt<ThreeElem, 2>::Result>::value);
}
