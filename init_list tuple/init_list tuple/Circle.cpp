#include "Circle.h"

std::ostream& operator<<(std::ostream& os, const Circle& obj)
{
    os << "Radius : " << obj.radius << std::endl;
    os << "Diameters : " << obj.radius * 2 << std::endl;
    os << "Area : " << obj.area() << std::endl;
    os << "Length :" << obj.length() << std::endl;
    os << std::endl;
    return os;
}
