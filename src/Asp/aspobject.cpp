#include "Asp/aspobject.h"
#include <iostream>



template<>
void Asp2<int>::print(void)
{
    std::cout << "It's an int id: " << m_id << std::endl;
}


