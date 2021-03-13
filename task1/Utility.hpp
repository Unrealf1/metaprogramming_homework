#pragma once

#include "TypeList.hpp"

template<typename TypeList>
struct Length {
    enum { value=Length<typename TypeList::tail>::value + 1 };
};

template<>
struct Length<EmptyList> {
    enum { value= 0 };
};

template<>
struct Length<NullType> {
    enum { value = 0 };
};

//-----------------------------------------------------------------

template<class TList, unsigned int index>
struct TypeAt{
    using Result = typename TypeAt<typename TList::tail, index-1>::Result;
};

template<class TList>
struct TypeAt<TList, 0> {
    using Result = typename TList::head;
};

//-----------------------------------------------------------------

template<class TypeList, class T>
struct IndexOf;

template<class Head, class... Tail, class T>
struct IndexOf<TypeList<Head, Tail...>, T> {
private:
    enum { temp = IndexOf<TypeList<Tail...>, T>::value };
public:
    enum { value = temp != -1 ? temp + 1 : -1 };
};

template<class... Tail, class T>
struct IndexOf<TypeList<T, Tail...>, T> {
    enum { value = 0 };
};

template <class T>
struct IndexOf<EmptyList, T> {
    enum { value = -1 };
};

//-----------------------------------------------------------------

template<class TypeList, class T>
struct Append;

// This is unnecessary
// template<>
// struct Append<NullType, NullType> {
//     using Result = NullType;
// };
//
// template<class T>
// struct Append<NullType, T> {
//     using Result = TypeList<T>;
// };
//
// template<class Head, class... Tail>
// struct Append<NullType, TypeList<Head, Tail...>> {
//     using Result = TypeList<Head, Tail...>;
// };

// special case for null for some reason(was in task)
template<class TypeList>
struct Append<TypeList, NullType> {
    using Result = TypeList;
};


/// ----- Adding not list type -----

// add any _not list_ type to empty list = list of that type
template<class T>
struct Append<EmptyList, T> {
    using Result = TypeList<T>;
};

// add any _not list_ type to a _not_ empty list = list of old types + new type 
template<class... types, class T>
struct Append<TypeList<types...>, T> {
public:
    using Result = TypeList<types..., T>;
};

// ----- Adding list to list -----

// empty + empty = empty
template<>
struct Append<EmptyList, EmptyList>{
    using Result = EmptyList;
};

// notEmpty + empty = old list
template<class Head, class... Tail>
struct Append<TypeList<Head, Tail...>, EmptyList> {
public:
    using Result = TypeList<Head, Tail...>;
};

// empty + notEmpty = new list
template<class Head, class... Tail>
struct Append<EmptyList, TypeList<Head, Tail...>> {
public:
    using Result = TypeList<Head, Tail...>;
};

// not empty + not empty = concatenation
template<class... types1, class... types2>
struct Append<TypeList<types1...>, TypeList<types2...>> {
    using Result = TypeList<types1..., types2...>;
};