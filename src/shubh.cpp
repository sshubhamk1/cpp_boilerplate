#include "shubh.h"
#include <string>
#include <iostream>

Shubham::Shubham():m_name("empty"), m_mob(12345)
{
}

Shubham::Shubham(std::string name, int mob):m_name(name), m_mob(mob)
{

}

std::string Shubham::get_name()
{
    return m_name;
}
void Shubham::set_name(std::string name)
{
    this->m_name = name;
}
int Shubham::get_mob()
{
    return this->m_mob;
}
void Shubham::set_mob(int mob)
{
    this->m_mob = mob;
}
void Shubham::display_info()
{
    std::cout << "INFO" << std::endl;
    std::cout << "name: " << this->m_name << std::endl;
    std::cout << "mob: " << this->m_mob << std::endl;

}