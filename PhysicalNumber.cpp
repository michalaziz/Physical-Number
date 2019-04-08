#include <iostream>
#include "PhysicalNumber.h"
using namespace std;
namespace ariel
{
    //deafult ctor
   PhysicalNumber::PhysicalNumber(){};
//ctor
   PhysicalNumber::PhysicalNumber(double n,int un)
   {
       num=n;
       u=un;
   }
//dtor
   PhysicalNumber::~PhysicalNumber()
   {
   }
//+
PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber& ph)
{
    return *this;
}

PhysicalNumber& PhysicalNumber::operator+=(const PhysicalNumber& ph)
{
    return *this;
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber& ph)
{
    return *this;
}

PhysicalNumber& PhysicalNumber::operator-=(const PhysicalNumber& ph)
{
    return *this;
}

PhysicalNumber& PhysicalNumber::operator-()
{
    return *this;
}

PhysicalNumber& PhysicalNumber::operator+()
{
    return *this;
}

const bool PhysicalNumber::operator<(const PhysicalNumber& ph)
{
    return 0;
}

const bool PhysicalNumber::operator>(const PhysicalNumber& ph)
{
    return 0;
}

const bool PhysicalNumber::operator>=(const PhysicalNumber& ph)
{
    return 0;
}

const bool PhysicalNumber::operator<=(const PhysicalNumber& ph)
{
    return 0;
}

const bool PhysicalNumber::operator==(const PhysicalNumber& ph)
{
    return 0;
}

const bool PhysicalNumber::operator!=(const PhysicalNumber& ph)
{
    return 0;
}

PhysicalNumber& PhysicalNumber::operator++(int temp)
{
    return *this;
}

PhysicalNumber& PhysicalNumber::operator--(int temp)
{
    return *this;
}

ostream& operator<<(ostream &out,const PhysicalNumber& x)
{
    out<<x.num<<endl;
    return out;
}
istream& operator>>(istream &in, PhysicalNumber &x)
{
    in>>x.num;
    return in;
}

}

