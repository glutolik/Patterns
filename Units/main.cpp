#include <iostream>
#include "Units.h"
#include "Oficer.h"

Officer* Officer::officer;

int main()
{
    Barrack barrack;

    SwordsmanBuilder swordsman_builder;
    barrack.set_unit_builder (&swordsman_builder);
    barrack.train_unit();
    std::shared_ptr<Infantry> unit = barrack.create_unit();
    unit->show_stats();

    std::cout << std::endl;
    Officer::create_officer()->show_stats();
    return 0;
}
