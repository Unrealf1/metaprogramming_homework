#pragma once

#include "typelist/TypeList.hpp"

template<typename T>
class Type2Type {
public:
    using OriginalType = T;
};

struct EmptyType {};

template <class TList, template <class> class Unit>
class GenScatterHierarchy;
// GenScatterHierarchy specialization: TypeList to Unit
template <class T1, class T2, template <class> class Unit>
class GenScatterHierarchy<TypeList<T1, T2>, Unit> : public GenScatterHierarchy<T1, Unit> , public GenScatterHierarchy<T2, Unit> {
public:
    typedef TypeList<T1, T2> TList;
    typedef GenScatterHierarchy<T1, Unit> LeftBase;
    typedef GenScatterHierarchy<T2, Unit> RightBase;
};
// Pass an atomic type (non-TypeList) to Unit
template <class AtomicType, template <class> class Unit>
class GenScatterHierarchy : public Unit<AtomicType>
{
    typedef Unit<AtomicType> LeftBase;
};
// Do nothing for NullType
template <template <class> class Unit>
class GenScatterHierarchy<NullType, Unit>
{

};

template<class TList, template <class AtomicType, class Base> class Unit, class Root = EmptyType>
class GenLinearHierarchy;
template<class T1,class T2,template <class, class> class Unit,class Root>
class GenLinearHierarchy<TypeList<T1, T2>, Unit, Root> : public Unit< T1, GenLinearHierarchy<T2, Unit, Root> > {};


template<class T,template <class, class> class Unit,class Root>
class GenLinearHierarchy<TypeList<T>, Unit, Root> : public Unit<T, Root>{};
