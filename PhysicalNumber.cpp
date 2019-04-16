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

//made the trans between the different types 
PhysicalNumber PhysicalNumber::convert(PhysicalNumber &n2)
{
    if (u == n2.u)//no need to convert its the same type
    {
        return n2;
    }
    switch (u)//go to the enum of the number that we want to cinvert to 
    {
    case 0: //cm
    {
        if (n2.u == 1) //m to cm
        {
            n2.num *= 100;//to conert meters to cm we need to mult in 100
            return n2;
        }
        if (n2.u == 2) //km to cm
        {
            n2.num *= 100000;//to conert km to cm we need to mult in 100000
            return n2;
        }
        throw "error";//tryig to convert between different types
    }
    case 1: //m
    {
        if (n2.u == 0) //cm to m
        {
            n2.num *= 0.01;//to conert cm  to m we need to mult in 0.01
            return n2;
        }
        if (n2.u == 2) //km to m
        {
            n2.num *= 1000;//to conert cm  to km we need to mult in 1000
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
    return n2;//
}

//+

PhysicalNumber PhysicalNumber::operator+(const PhysicalNumber &n2)
{
    //this+n2
    PhysicalNumber temp;//we dont want chang the original
    temp.num = n2.num;//put the original in temporary variable
    temp.u = n2.u;
    this->convert(temp);//we convert n2 to n1 
    temp.num = num + temp.num;//do this + n2 
    temp.u = u;//its the same  type now
    return temp;//we changed the temporary varibal so we also return it 
}

PhysicalNumber &PhysicalNumber::operator+=(const PhysicalNumber &n2)
{
    //this+=n2
    PhysicalNumber temp;//we dont want chang the original
    temp.num = n2.num;//put the original in temporary variable
    temp.u = n2.u;
    this->convert(temp);//convert n2 to this's type
    num = num + temp.num;//it += so we chang the the original varibal 
    return *this;//return the original 
}

PhysicalNumber PhysicalNumber::operator-(const PhysicalNumber &n2)
{
    //this - n2
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
    //this-=n2
    PhysicalNumber temp;
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);
    num = num - temp.num;
    return *this;
}

PhysicalNumber PhysicalNumber::operator-()
{
    //-(this)
    PhysicalNumber temp;//we dont chang the original varibal 
    temp.num = -(num);//-()
    temp.u = u;
    return temp;
}

PhysicalNumber PhysicalNumber::operator+()
{
    //+(this)
    PhysicalNumber temp;
    temp.num = num;
    if (num < 0)//if the number is negetiv we need to chang it to positiv 
        temp.num = 0 - temp.num;//0-(-num)=+num 
    return temp;
}

PhysicalNumber &PhysicalNumber::operator=(const PhysicalNumber &n2)
{
    //this = n2 
    num = n2.num;
    u = n2.u;
    return *this;
}

const bool PhysicalNumber::operator<(const PhysicalNumber &n2)
{
    //this <? n2 
    PhysicalNumber temp;//we dont chang the original varibal 
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);//convert n2 to this's type 
    if (num < temp.num)//after converting we can simply ask 
        return true;
    return false;
}

const bool PhysicalNumber::operator>(const PhysicalNumber &n2)
{
    //this>?n2
    PhysicalNumber temp;//we dont chang the original varibal 
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);//convert n2 to this's type 
    if (num > temp.num)//after converting we can simply ask 
        return true;
    return false;
}

const bool PhysicalNumber::operator>=(const PhysicalNumber &n2)
{
    //this>=?n2 
    PhysicalNumber temp;//we dont chang the original varibal 
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);//convert n2 to this's type
    if (num >= temp.num)//after converting we can simply ask
        return true;
    return false;
}

const bool PhysicalNumber::operator<=(const PhysicalNumber &n2)
{
    //this<=?n2 
    PhysicalNumber temp;//we dont chang the original varibal 
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);//convert n2 to this's type
    if (num <= temp.num)//after converting we can simply ask
        return true;
    return false;
}

const bool PhysicalNumber::operator==(const PhysicalNumber &n2)
{
    //this==?n2 
    PhysicalNumber temp;//we dont chang the original varibal 
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);//convert n2 to this's type
    if (num == temp.num)//after converting we can simply ask
        return true;
    return false;
}

const bool PhysicalNumber::operator!=(const PhysicalNumber &n2)
{
    //this!=?n2 
    PhysicalNumber temp;//we dont chang the original varibal 
    temp.num = n2.num;
    temp.u = n2.u;
    this->convert(temp);//convert n2 to this's type
    if (num != temp.num)//after converting we can simply ask
        return true;
    return false;
}

PhysicalNumber &PhysicalNumber::operator++() //prefix
{
    //++num 
    num = num + 1;//first do ++
    return *this;//than return 
}

PhysicalNumber &PhysicalNumber::operator--() //prefix
{
    //--num 
    num = num - 1;//first do --
    return *this;//than return
}

PhysicalNumber PhysicalNumber::operator++(int notused) //postfix
{
    //num++
    PhysicalNumber temp(num, u);//put the original number in temporary varibal 
    num++;//do ++ to the original 
    return temp;//return the temp without the ++
}

PhysicalNumber PhysicalNumber::operator--(int notused) //postfix
{
    PhysicalNumber temp(num, u);//put the original number in temporary varibal
    num--;//do -- to the original 
    return temp;//return the temp without the --
}

ostream &operator<<(ostream &out, const PhysicalNumber &p)//output
{
    return out << p.num << "[" << type[p.u] << "]";//num[type]
}
istream &operator>>(istream &in, PhysicalNumber &p)//input 
{

    string s, number, typeCut;
    in >> s;//get all to string 
    number = s.substr(0, s.find('['));//cut the number only
    typeCut = s.substr(s.find('[')+1, s.length() - s.find("[") - 2);//cut the type only 

    string type[9] = {"cm", "m", "km", "sec", "min", "hour", "g", "kg", "ton"};
    int count = 0,index;
    for (size_t i = 0; i < 9; i++)//search the type in the type list that in the array
    {
        if (type[i] == typeCut)//if we found the type we search for 
        {
            count++;//kind of flag that check that we found some type 
            index=i;//save the place of the type in the array
        }  
    }
  
        
    int count2 = 0;
    for (size_t i = 0; i < number.length(); i++)
    {
        if (isdigit(number.at(i)) || (number.at(i) == '.'))//check that the number part is really number
        {
            count2++;//count the number of digits
        }
    }
    if (count2 != number.length()||count == 0||s.find("[")==string::npos||s.find("]")==string::npos)
    {//if the input is incorrect 
        cout<<typeCut<<" "<<number<<endl;
        return in;
    }
    else//the input is correct 
    {
        p.u = (Unit)index;//convert the place in the array to the enum type
        p.num = stod(number);//convert the number part in to double 
    }
    return in;
}

} // namespace ariel
