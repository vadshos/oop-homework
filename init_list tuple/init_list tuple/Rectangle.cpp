#include "Rectangle.h"

std::ostream& operator<<(std::ostream& os, const Rectangle& obj)
{
    os << "First side rectangle : " << obj.pair.first << std::endl;
    os << "Second side  rectangle : " << obj.pair.second << std::endl;
    os << "Area : " << obj.area() << std::endl;
    os << "Length : " << obj.length() << std::endl;
    os << std::endl;
    return os;
}
