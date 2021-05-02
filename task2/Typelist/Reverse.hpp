#pragma once

#include "Utility.hpp"

//-----------------------------------------------------------------

template<class TypeList>
struct Reverse;

template<>
struct Reverse<EmptyList> {
    using Result = EmptyList;
};

template<class Head, class... Tail>
struct Reverse<TypeList<Head, Tail...>> {
private:
    using temp = typename Reverse<TypeList<Tail...>>::Result;
public:
    using Result = typename Append<temp, TypeList<Head>>::Result;
};
