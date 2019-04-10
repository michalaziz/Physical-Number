#include <iostream>
#include "PhysicalNumber.h"
using namespace std;
namespace ariel
{
string type[9]={"cm","m","km","sec","min","hour","g","kg","ton"};
//deafult ctor
PhysicalNumber::PhysicalNumber(){};
//ctor
PhysicalNumber::PhysicalNumber(double n, int un)
{
    num = n;
    u = un;
}


PhysicalNumber PhysicalNumber::convert(PhysicalNumber &n2)
{
    switch (u)
    {
    case 0: //cm
    {
        if (n2.u == 1) //m to cm
        {
            n2.num *= 100;
            return n2;
        }
        if (n2.u == 2) //km to cm
        {
            n2.num *= 100000;
            return n2;
        }
        return *this;
    }
    case 1: //m
    {
        if (n2.u == 0) //cm to m
        {
            n2.num *= 0.01;
            return n2;
        }
        if (n2.u == 2) //km to m
        {
            n2.num *= 1000;
            return n2;
        }
        return *this;
    }
    case 2: //km
    {
        if (n2.u == 0) //cm to km
        {
            n2.num *= 0.00001;
            return n2;
        }
        if (n2.u == 1) //m to km
        {
            n2.num *= 0.001;
            return n2;
        }
        return *this;
    }
    case 3: //sec
    {
        if (n2.u == 4) //min to sec
        {
            n2.num *= 60;
            return n2;
        }
        if (n2.u == 5) //hour to sec
        {
            n2.num *= 3600;
            return n2;
        }
        return *this;
    }
    case 4: //min
    {
        if (n2.u == 3) //sec to min
        {
            n2.num /= 60;
            return n2;
        }
        if (n2.u == 5) //hour to min
        {
            n2.num *= 60;
            return n2;
        }
        return *this;
    }
    case 5: //hour
    {
        if (n2.u == 3) //sec to hour
        {
            n2.num /= 3600;
            return n2;
        }
        if (n2.u == 5) //min to hour
        {
            n2.num /= 60;
            return n2;
        }
        return *this;
    }
    case 6: //g
    {
        if (n2.u == 7) //kg to g
        {
            n2.num *= 1000;
            return n2;
        }
        if (n2.u == 8) //ton to g
        {
            n2.num *= 1000000;
            return n2;
        }
        return *this;
    }

    case 7: //kg
    {
        if (n2.u == 6) //g to kg
        {
            n2.num *= 0.001;
            return n2;
        }
        if (n2.u == 8) //ton to kg
        {
            n2.num *= 1000;
            return n2;
        }
        return *this;
    }

    case 8: //ton
    {
        if (n2.u == 6) //g to ton
        {
            n2.num *= 0.000001;
            return n2;
        }
        if (n2.u == 7) //kg to ton
        {
            n2.num *= 0.001;
            return n2;
        }
        return *this;
    }

    default:
        break; //ERROR
    }          // namespace ariel
}
//+

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    convert(temp);
    temp.num = num + temp.num;
    return temp;
}

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    convert(temp);
    num=num+temp.num;
    return *this;
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    convert(temp);
    temp.num = num - temp.num;
    return temp;  
}

PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    convert(temp);
    num=num-temp.num;
    return *this;
    
}

PhysicalNumber &PhysicalNumber::operator-()
{
    num=-num;
    return *this;
    
}

PhysicalNumber &PhysicalNumber::operator+()
{
    num =+num; 
    return *this;
   
}

const bool PhysicalNumber::operator<(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    convert(temp);
    if (num < temp.num)
        return true;
    return false;
}

const bool PhysicalNumber::operator>(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    convert(temp);
    if (num > temp.num)
        return true;
    return false;
}

const bool PhysicalNumber::operator>=(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    convert(temp);
    if (num >= temp.num)
        return true;
    return false;
}

const bool PhysicalNumber::operator<=(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    convert(temp);
    if (num <= temp.num)
        return true;
    return false;
}

const bool PhysicalNumber::operator==(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    convert(temp);
    if (num== temp.num)
        return true;
    return false;
}

const bool PhysicalNumber::operator!=(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    convert(temp);
    if (num != temp.num)
        return true;
    return false;
}

PhysicalNumber &PhysicalNumber::operator++(int temp)
{
    num= num +1;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator--(int temp)
{
    num =num-1;
    return *this;
}

ostream &operator<<(ostream &out, const PhysicalNumber &p)
{
    return out << p.num <<"["<<type[p.u]<<"]"<<endl;
}
istream &operator>>(istream &in, PhysicalNumber &x)
{
    return in;
}

} // namespace ariel
