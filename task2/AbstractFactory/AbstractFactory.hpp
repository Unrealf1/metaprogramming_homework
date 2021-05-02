#pragma once

#include "AbstractFactoryUnit.hpp"

template<class TList, template <class> class Unit = AbstractFactoryUnit>
class AbstractFactory : public GenScatterHierarchy<TList, Unit> {
public:
    typedef TList ProductList;
    
    template <class T> T* Create(){
        Unit <T>& unit = *this;
        return unit.DoCreate(Type2Type<T>());
    }
};
