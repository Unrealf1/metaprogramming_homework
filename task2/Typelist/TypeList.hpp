#pragma once

class NullType {};

template<typename T=NullType, typename... rest>
struct TypeList {
    using head = T;
    using tail = TypeList<rest...>;
};

template<typename T>
struct TypeList<T> {
    using head = T;
    using tail = NullType;
};

using EmptyList = TypeList<>;
