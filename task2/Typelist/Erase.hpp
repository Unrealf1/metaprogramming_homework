#pragma once

#include "Utility.hpp"

//-----------------------------------------------------------------

template<class TypeList, class T>
struct Erase;

template<class T>
struct Erase<EmptyList, T> {
    using Result = NullType;
};

template<class... Tail, class T>
struct Erase<TypeList<T, Tail...>, T> {
    using Result = TypeList<Tail...>;
};

template<class Head, class... Tail, class T>
struct Erase<TypeList<Head, Tail...>, T> {
private:
    using temp = typename Erase<TypeList<Tail...>, T>::Result;
public:
    using Result = typename Append<TypeList<Head>, temp>::Result;
};
