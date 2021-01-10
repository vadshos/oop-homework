#include "var.h"

const Var Var::operator+(Var& obj)
{
    if (obj.num)
    {
        if (num != NULL)
        {
            return num + obj.num;
        }
        else if (real != NULL)
        {
            return real + (double)obj.num;
        }

        else  
        {
            String t;
            t = std::to_string(obj.num);
            String tmp;
            tmp=  str+t;
            return tmp;
        }
    }
    else if(obj.real) 
    {
        if (num != NULL)
        {
            return real + (double)obj.num;
        }
        else if (real != NULL)
        {
            return real + obj.real;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            String tmp;
            tmp = str + t;
            return tmp;
        }
    }
    else 
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            String tmp;
            tmp = obj.str + t;
            return tmp;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            String tmp;
            tmp = obj.str + t;
            return tmp;
        }

        else
        {
            String tmp = str + obj.str;
            return tmp;
        }
    }
}

const Var Var::to_string()
{
    if (num)
    {
        str = std::to_string(num);
        num = NULL;
    }
    else if (real)
    {
        str = std::to_string(real);
        real = NULL;
    }
    return *this;
}

const Var Var::to_integer()
{
    if (real)
    {
        num = (int)real;
        real = NULL;
    }
    else if (str != "")
    {
        num = std::stoi(str.getStr());
        str = "";
    }
    return *this;
}

const Var Var::to_double()
{
    if (num)
    {
        real = (int)real;
        num = NULL;
    }
    else if (str != "")
    {
        real = std::stoi(str.getStr());
        str = "";
    }
    return *this;
}

const Var Var::operator+=(Var& obj)
{
    if (obj.num)
    {
        if (num != NULL)
        {
            num += obj.num;
            return *this;
        }
        else if (real != NULL)
        {
            real += (double)obj.num;
            return *this;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            str = str + t;
            return *this;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            real += (double)obj.num;
            return *this;
        }
        else if (real != NULL)
        {
            real += obj.real;
            return *this;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            str = str + t;
            return *this;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            String tmp;
            num = NULL;
            str = obj.str + t;
            return *this;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            String tmp;
            real = NULL;
            str = obj.str + t;
            return *this;
        }

        else
        {
            str + obj.str;
            return *this;
        }
    }
}

const Var Var::operator-(const Var& obj)
{
    if (obj.num)
    {
        if (num != NULL)
        {
            return num - obj.num;
        }
        else if (real != NULL)
        {
            return real - (double)obj.num;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            String tmp;
            tmp.concat(t);
            return tmp;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            return real - (double)obj.num;
        }
        else if (real != NULL)
        {
            return real - obj.real;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            t.concat(str);
            return t;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            t.concat(str);
            return t;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            t.concat(str);
            return t;
        }

        else
        {
            String tmp ;
            tmp = str;
            tmp.concat(obj.str);
            return tmp;
        }
    }
}

const Var Var::operator-=(Var& obj)
{
    if (obj.num)
    {
        if (num != NULL)
        {
            num -= obj.num;
            return *this;
        }
        else if (real != NULL)
        {
            real - (double)obj.num;
            return *this;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            str = str + t;
            return *this;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            real - (double)obj.num;
            return *this;
        }
        else if (real != NULL)
        {
            real - obj.real;
            return *this;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            str.concat(t);
            return *this;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            str.concat(t);
            return *this;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            str.concat(t);
            return *this;
        }

        else
        {
            str.concat(obj.str);
            return *this;
        }
    }
}

const Var Var::operator*(Var& obj)
{
    if (obj.num)
    {
        if (num != NULL)
        {
            return num * obj.num;
        }
        else if (real != NULL)
        {
            return real * (double)obj.num;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            String tmp;
            tmp = str * t;
            return tmp;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            return real * (double)obj.num;
        }
        else if (real != NULL)
        {
            return real * obj.real;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            String tmp;
            tmp = str * t;
            return tmp;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            String tmp;
            tmp = obj.str * t;
            return tmp;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            String tmp;
            tmp = obj.str * t;
            return tmp;
        }

        else
        {
            String tmp;
            tmp = str* obj.str;
            return tmp;
        }
    }
}

const Var Var::operator*=(Var& obj)
{
    if (obj.num)
    {
        if (num != NULL)
        {
            num *= obj.num;
            return *this;
        }
        else if (real != NULL)
        {
            real *= (double)obj.num;
            return *this;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            str = str * t;
            return *this;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            real *= (double)obj.num;
            return *this;
        }
        else if (real != NULL)
        {
            real *= obj.real;
            return *this;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            str = str * t;
            return *this;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            String tmp;
            num = NULL;
            str = obj.str * t;
            return *this;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            String tmp;
            real = NULL;
            str = obj.str * t;
            return *this;
        }

        else
        {
            str * obj.str;
            return *this;
        }
    }
}

const Var Var::operator/(Var& obj)
{
    if (obj.num)
    {
        if (num != NULL)
        {
            return num / obj.num;
        }
        else if (real != NULL)
        {
            return real / (double)obj.num;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            String tmp;
            tmp = str / t;
            return tmp;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            return real / (double)obj.num;
        }
        else if (real != NULL)
        {
            return real / obj.real;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            String tmp;
            tmp = str / t;
            return tmp;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            String tmp;
            tmp = obj.str / t;
            return tmp;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            String tmp;
            tmp = obj.str / t;
            return tmp;
        }

        else
        {
            String tmp = str / obj.str;
            return tmp;
        }
    }
}

const Var Var::operator/=(Var& obj)
{
    if (obj.num)
    {
        if (num != NULL)
        {
            num *= obj.num;
            return *this;
        }
        else if (real != NULL)
        {
            real *= (double)obj.num;
            return *this;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            str = str * t;
            return *this;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            real *= (double)obj.num;
            return *this;
        }
        else if (real != NULL)
        {
            real *= obj.real;
            return *this;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            str = str * t;
            return *this;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            String tmp;
            num = NULL;
            str = obj.str * t;
            return *this;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            String tmp;
            real = NULL;
            str = obj.str + t;
            return *this;
        }

        else
        {
            str * obj.str;
            return *this;
        }
    }
}

const bool Var::operator<(Var& obj)const 
{
    if (obj.num)
    {
        if (num != NULL)
        {
            return num < obj.num;
        }
        else if (real != NULL)
        {
            return real < (double)obj.num;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            return str < t;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            return real < (double)obj.num;
        }
        else if (real != NULL)
        {
            return real < obj.real;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            return str < t;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            return obj.str  < t;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            return obj.str < t;
        }

        else
        {
            return str < obj.str;
        }
    }
}

const bool Var::operator>(Var& obj) const 
{
    if (obj.num)
    {
        if (num != NULL)
        {
            return num > obj.num;
        }
        else if (real != NULL)
        {
            return real > (double)obj.num;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            return str > t;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            return real > (double)obj.num;
        }
        else if (real != NULL)
        {
            return real > obj.real;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            return str > t;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            return obj.str > t;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            return obj.str > t;
        }

        else
        {
            return str > obj.str;
        }
    }
}

const Var Var::operator>=(Var& obj) const 
{
    if (obj.num)
    {
        if (num != NULL)
        {
            return num >= obj.num;
        }
        else if (real != NULL)
        {
            return real >= (double)obj.num;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            return str >= t;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            return real >= (double)obj.num;
        }
        else if (real != NULL)
        {
            return real >= obj.real;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            return str >= t;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            return obj.str >= t;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            return obj.str >= t;
        }

        else
        {
            return str >= obj.str;
        }
    }
}

const Var Var::operator<=(Var& obj)  const
{
    if (obj.num)
    {
        if (num != NULL)
        {
            return num <= obj.num;
        }
        else if (real != NULL)
        {
            return real <= (double)obj.num;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            return str <= t;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            return real <= (double)obj.num;
        }
        else if (real != NULL)
        {
            return real <= obj.real;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            return str <= t;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            return obj.str <= t;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            return obj.str <= t;
        }

        else
        {
            return str <= obj.str;
        }
    }
}

const Var Var::operator==(Var& obj) const
{
    if (obj.num)
    {
        if (num != NULL)
        {
            return num == obj.num;
        }
        else if (real != NULL)
        {
            return real == (double)obj.num;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            return str == t;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            return real == (double)obj.num;
        }
        else if (real != NULL)
        {
            return real == obj.real;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            return str == t;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            return obj.str == t;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            return obj.str == t;
        }

        else
        {
            return str == obj.str;
        }
    }
}

const Var Var::operator!=(Var& obj) const
{
    if (obj.num)
    {
        if (num != NULL)
        {
            return num != obj.num;
        }
        else if (real != NULL)
        {
            return real != (double)obj.num;
        }

        else
        {
            String t;
            t = std::to_string(obj.num);
            return str != t;
        }
    }
    else if (obj.real)
    {
        if (num != NULL)
        {
            return real != (double)obj.num;
        }
        else if (real != NULL)
        {
            return real != obj.real;
        }

        else
        {
            String t;
            t = std::to_string(obj.real);
            return str != t;
        }
    }
    else
    {
        if (num != NULL)
        {
            String t;
            t = std::to_string(num);
            return obj.str != t;
        }
        else if (real != NULL)
        {
            String t;
            t = std::to_string(real);
            return obj.str != t;
        }

        else
        {
            return str != obj.str;
        }
    }
}

std::ostream& operator<<( std::ostream& os, const Var& obj)
{
    if (obj.num) {
        os << obj.num;
    }else if(obj.real) {
        os << obj.real;
    }
    else {
        os << obj.str;
    }
    return os;
}

