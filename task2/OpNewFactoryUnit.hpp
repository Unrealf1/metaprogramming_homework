#pragma once


// Base is required by GenLinearHierarchy
template <class ConcreteProduct, class Base>
class OpNewFactoryUnit : public Base {
    typedef typename Base::ProductList BaseProductList;
protected:
    typedef typename BaseProductList::Tail ProductList;
public:
    typedef typename BaseProductList::Head AbstractProduct;
    
    ConcreteProduct* DoCreate(Type2Type<AbstractProduct>) {
        return new ConcreteProduct;
    }
};