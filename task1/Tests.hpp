#pragma once

#include "TypeList.hpp"
#include "Utility.hpp"
#include "Erase.hpp"

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

namespace Erase_tests
{
    using new_Empty = Erase<OneElem, int>::Result;
    using new_OneElem = Erase<TwoElem, char>::Result;
    //Erasing from start
    using char_string = Erase<ThreeElem, int>::Result;
    //Erasing from end
    using char_list = Erase<char_string, std::string>::Result;
    //Erasing from middle
    using int_string = Erase<ThreeElem, char>::Result;
    //Check that only the first entry is erased
    using char_int = Erase<TypeList<int, char, int>, int>::Result;
    //Just long list
    using long_list = Erase<TypeList<char, float, bool, std::is_scalar<double>, int, std::pair<int, bool>, int>, int>::Result;
    using long_list_right = TypeList<char, float, bool, std::is_scalar<double>, std::pair<int, bool>, int>;

    static_assert(std::is_same<EmptyList, new_Empty>::value);
    static_assert(std::is_same<OneElem, new_OneElem>::value);
    static_assert(std::is_same<char_string, TypeList<char, std::string>>::value);
    static_assert(std::is_same<char_list, TypeList<char>>::value);
    static_assert(std::is_same<int_string, TypeList<int, std::string>>::value);
    static_assert(std::is_same<long_list, long_list_right>::value);

    // Если список пустой, то результат NullType
    static_assert(std::is_same<NullType, Erase<EmptyList, int>::Result>::value);
}
