#pragma once

#include "AbstractFactory.hpp"

#include "Infantry.hpp"

typedef AbstractFactory<TypeList<Infantry> > AbstractArmyFactory;
