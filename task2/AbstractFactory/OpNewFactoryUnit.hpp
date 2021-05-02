#pragma once

#include "../Utility.hpp"

// Base is required by GenLinearHierarchy
template <class ConcreteProduct, class Base>
class OpNewFactoryUnit : public Base {
    typedef typename Base::ProductList BaseProductList;
protected:
    typedef typename BaseProductList::tail ProductList;
public:
    typedef typename BaseProductList::head AbstractProduct;
    
    ConcreteProduct* DoCreate(Type2Type<AbstractProduct>) {
        return new ConcreteProduct;
    }
};