#include "Triangle.h"

std::ostream& operator<<(std::ostream& os, const Triangle& obj)
{
    
    os << "First side triangle : " << std::get<0>(obj.tuple) << std::endl;
    os << "Second side triangle : " << std::get<1>(obj.tuple) << std::endl;
    os << "Third side triangle : " << std::get<2>(obj.tuple) << std::endl;
    os << "Area : " << obj.area()<<std::endl;
    os << "Length : " << obj.length() << std::endl;
    os << std::endl;
    return os;
}
