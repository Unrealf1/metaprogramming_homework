#include <iostream>
#include "Typelist/Tests.hpp"
#include "ArmyFactories.hpp"

int main() {
    auto sf = SavageArmyFactory();
    auto si = sf.Create<Infantry>();
    auto sc = sf.Create<Cavalry>();
    
    auto kf = KindArmyFactory();
    auto ki = kf.Create<Infantry>();
    auto kc = kf.Create<Cavalry>();

    auto true_si = new SavageInfantry();
    auto true_sc = new SavageCavalry();

    auto true_ki = new KindInfantry();
    auto true_kc = new KindCavalry();

    auto base_i = new Infantry();
    auto base_c = new Cavalry();

    bool savage_test = (
        si->greeting() == true_si->greeting() && 
        sc->greeting() == true_sc->greeting() && 
        si->greeting() != base_i->greeting() && 
        sc->greeting() != base_c->greeting()
    );

    bool kind_test = (
        ki->greeting() == true_ki->greeting() && 
        kc->greeting() == true_kc->greeting() &&
        ki->greeting() != base_i->greeting() &&
        kc->greeting() != base_c->greeting()
    );

    std::cout << "Kind infantry greeting:\n" << ki->greeting() << '\n';

    std::cout << "Savage test: ";
    if (!savage_test) {
        std::cout << "failed\n";
    } else {
        std::cout << "passed\n";
    }


    std::cout << "Kind test: ";
    if (!kind_test) {
        std::cout << "failed\n";
    } else {
        std::cout << "passed\n";
    }

    std::cout << "done." << std::endl;
}
