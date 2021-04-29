#pragma once

#include "OpNewFactoryUnit.hpp"

template<
    class AbstractFact, 
    template <class, class> class Creator = OpNewFactoryUnit, 
    class TList = typename AbstractFact::ProductList> 
class ConcreteFactory : public GenLinearHierarchy<typename TL::Reverse<TList>::Result, Creator, AbstractFact> {
public:
    typedef typename AbstractFact::ProductList ProductList;
    typedef TList ConcreteProductList;
};
