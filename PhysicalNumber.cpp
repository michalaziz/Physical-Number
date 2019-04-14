#include <iostream>
#include <cstring>
#include "PhysicalNumber.h"
using namespace std;
namespace ariel
{
string type[9] = {"cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton"};
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
    if (u == n2.u)
    {
        return n2;
    }
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
        throw "error";
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
        throw "error";
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
        throw "error";
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
        throw "error";
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
        throw "error";
    }
    case 5: //hour
    {
        if (n2.u == 3) //sec to hour
        {
            n2.num /= 3600;
            return n2;
        }
        if (n2.u == 4) //min to hour
        {
            n2.num /= 60;
            return n2;
        }
        throw "error";
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
        throw "error";
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
        throw "error";
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
        throw "error";
    }
    }
    return n2;
}

//+

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    temp.num = num + temp.num;
    temp.u = u;
    return temp;
}

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    num = num + temp.num;
    return *this;
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    temp.num = num - temp.num;
    temp.u = u;
    return temp;
}

PhysicalNumber &PhysicalNumber::operator-=(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    num = num - temp.num;
    return *this;
}

PhysicalNumber PhysicalNumber::operator-()
{
    PhysicalNumber temp;
    temp.num = -(num);
    temp.u = u;
    return temp;
}

PhysicalNumber PhysicalNumber::operator+()
{
    PhysicalNumber temp;
    temp.num = num;
    if (num < 0)
        temp.num = 0 - temp.num;
    temp.u = u;
    return temp;
}

PhysicalNumber &PhysicalNumber::operator=(const PhysicalNumber &n2)
{
    num = n2.num;
    u = n2.u;
    return *this;
}

const bool PhysicalNumber::operator<(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    if (num < temp.num)
        return true;
    return false;
}

const bool PhysicalNumber::operator>(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    if (num > temp.num)
        return true;
    return false;
}

const bool PhysicalNumber::operator>=(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    if (num >= temp.num)
        return true;
    return false;
}

const bool PhysicalNumber::operator<=(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    if (num <= temp.num)
        return true;
    return false;
}

const bool PhysicalNumber::operator==(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    if (num == temp.num)
        return true;
    return false;
}

const bool PhysicalNumber::operator!=(const PhysicalNumber &n2)
{
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    if (num != temp.num)
        return true;
    return false;
}

PhysicalNumber &PhysicalNumber::operator++() //prefix
{
    num = num + 1;
    return *this;
}

PhysicalNumber &PhysicalNumber::operator--() //prefix
{
    num = num - 1;
    return *this;
}

PhysicalNumber PhysicalNumber::operator++(int notused) //postfix
{
    PhysicalNumber temp(num, u);
    num++;
    return temp;
}

PhysicalNumber PhysicalNumber::operator--(int notused) //postfix
{
    PhysicalNumber temp(num, u);
    num--;
    return temp;
}

ostream &operator<<(ostream &out, const PhysicalNumber &p)
{
    return out << p.num << "[" << type[p.u] << "]";
}
istream &operator>>(istream &in, PhysicalNumber &p)
{

    string s, number, typeCut;
    in >> s;
    number = s.substr(0, s.find('['));
    typeCut = s.substr(s.find('[')+1, s.length() - s.find("[") - 2);

    string type[9] = {"cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton"};
    int count = 0,index;
    for (size_t i = 0; i < 9; i++)
    {
        if (type[i] == typeCut)
        {
            count++;
            index=i;
        }  
    }
  
        
    int count2 = 0;
    for (size_t i = 0; i < number.length(); i++)
    {
        if (isdigit(number.at(i)) || (number.at(i) == '.'))
        {
            count2++;
        }
    }
    if (count2 != number.length()||count == 0||s.find("[")==string::npos||s.find("]")==string::npos)
    {
        cout<<typeCut<<" "<<number<<endl;
        return in;
    }
    else
    {
         p.u = (Unit)index;
        p.num = stod(number);
    }
    return in;
}

} // namespace ariel
