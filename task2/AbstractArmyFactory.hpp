#pragma once

#include "AbstractFactory/AbstractFactory.hpp"

#include "Warriors/Infantry.hpp"
#include "Warriors/Cavalry.hpp"

typedef AbstractFactory<TypeList<Infantry, Cavalry> > AbstractArmyFactory;
