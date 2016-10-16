#include <iostream>
#include "Singletone.h"

bool Singleton::specimen = false;
Singleton* Singleton::sin;
int main()
{

    std::cout << Singleton::GetSin()->data << std::endl;
    //Singleton s1;
    //s.SetSpecimen(10);
//    std::cout << s.GetSpecimen() << std::endl;
//    std::cout << s1.GetSpecimen() << std::endl;
    //s.SetSpecimen(10);
    //int i = s.GetSpecimen();
    //std::cout << i << std::endl;
    return 0;
}
