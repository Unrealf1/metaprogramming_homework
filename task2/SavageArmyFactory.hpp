#pragma once

#include "typelist/TypeList.hpp"
#include "ConcreteFactory.hpp"
#include "SavageInfantry.hpp"
#include "AbstractArmyFactory.hpp"
#include "OpNewFactoryUnit.hpp"

typedef ConcreteFactory<AbstractArmyFactory, OpNewFactoryUnit, TypeList<SavageInfantry>> SavageArmyFactory;