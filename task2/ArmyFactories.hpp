#pragma once

#include "Typelist/TypeList.hpp"
#include "AbstractFactory/ConcreteFactory.hpp"
#include "Warriors/SavageInfantry.hpp"
#include "Warriors/SavageCavalry.hpp"
#include "Warriors/KindInfantry.hpp"
#include "Warriors/KindCavalry.hpp"
#include "AbstractArmyFactory.hpp"
#include "AbstractFactory/OpNewFactoryUnit.hpp"

typedef ConcreteFactory<AbstractArmyFactory, OpNewFactoryUnit, TypeList<SavageInfantry, SavageCavalry>> SavageArmyFactory;

typedef ConcreteFactory<AbstractArmyFactory, OpNewFactoryUnit, TypeList<KindInfantry, KindCavalry>> KindArmyFactory;
