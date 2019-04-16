/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);
    
    PhysicalNumber Gram(30, Unit::G);
    PhysicalNumber Cm(30, Unit::CM);
    PhysicalNumber KM(30, Unit::KM);
    PhysicalNumber MET(200, Unit::M);


    testcase
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")

    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)
    

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

    // YOUR TESTS - INSERT AS MANY AS YOU WANT

      .setname("Should not work")
      .CHECK_THROWS(Gram+Cm)
      .CHECK_THROWS(Cm+Gram)
      .CHECK_THROWS(Gram+=Cm)
      .CHECK_THROWS(Cm+=Gram)
      .CHECK_THROWS(Cm-=Gram)
      .CHECK_THROWS(Gram-=Cm)
      .CHECK_THROWS(Cm-Gram)
      .CHECK_THROWS(Gram-Cm)
      .CHECK_THROWS(Cm < Gram)
      .CHECK_THROWS(Gram > KM)
      .CHECK_THROWS(Gram >= KM)
      .CHECK_THROWS(Cm <= Gram)
      .CHECK_THROWS(KM <= Gram)
      .CHECK_THROWS(a <= b)
      .CHECK_THROWS(b <= c)
      .CHECK_THROWS(b += Gram)
      .CHECK_THROWS(a -= d)
      .CHECK_THROWS(c += MET)
      .CHECK_THROWS(c -= MET)
      .CHECK_THROWS(MET -= c)
      .CHECK_THROWS(MET += c)
      .CHECK_THROWS(Gram < KM)
      .CHECK_OK(istringstream("200[g") >> Gram)
      .CHECK_OK(istringstream("0.2[]") >> a)
      .CHECK_OK(istringstream("200g]") >> Gram)
      .CHECK_OK(istringstream("0.2[kgg]") >> a)
      .CHECK_OK(istringstream("122.2kg") >> a)
      .CHECK_OK(istringstream("1332.2[to n]") >> a)
      .CHECK_OK(istringstream("[ton]1332.2") >> a)


      .setname("Should work")
      .CHECK_OUTPUT(++Gram, "31[g]")
      .CHECK_OUTPUT(--Gram, "30[g]")
      .CHECK_OUTPUT(--Cm, "29[cm]")
      .CHECK_OUTPUT(++Cm, "30[cm]")
      .CHECK_OUTPUT((Gram+=Gram), "60[g]")
      .CHECK_OUTPUT((Cm+=Cm), "60[cm]")
      .CHECK_OUTPUT((-Gram),"-60[g]")
      .CHECK_OUTPUT(+Gram,"60[g]")
      .CHECK_OUTPUT(Gram-Gram,"0[g]")
      .CHECK_OUTPUT((KM+=MET) , "30.2[km]")
      .CHECK_OUTPUT((Cm-=Cm),"0[cm]")
      .CHECK_OUTPUT(Cm,"0[cm]")
      .CHECK_OUTPUT((Cm+=MET),"20000[cm]")
      .CHECK_OUTPUT((MET+=Cm) , "400[m]")
      .CHECK_OUTPUT((++MET) , "401[m]")
      .CHECK_OUTPUT((--MET) , "400[m]")
      .CHECK_OUTPUT((-MET) , "-400[m]")
      .CHECK_OUTPUT((+MET) , "400[m]")
      .CHECK_OUTPUT(Gram++, "60[g]")
      .CHECK_OUTPUT(Gram, "61[g]")
      .CHECK_OUTPUT(Gram--, "61[g]")
      .CHECK_OUTPUT(Gram, "60[g]")



      .CHECK_EQUAL(Cm < KM, true)
      .CHECK_EQUAL(Cm > KM, false)
      .CHECK_EQUAL(Cm != KM, true)
      .CHECK_EQUAL(Cm == KM, false)
      .CHECK_EQUAL(Cm == Cm, true)
      .CHECK_EQUAL(MET > Cm, true)
      .CHECK_EQUAL(MET != Cm, true)
      .CHECK_EQUAL(MET > Cm, true)
      .CHECK_EQUAL(MET >= Cm, true)
      .CHECK_OK(istringstream("200[m]") >> MET)
      .CHECK_OUTPUT(MET, "200[m]")
      .CHECK_EQUAL(MET == Cm, true)
      .CHECK_OK(istringstream("2000[g]") >> Gram)
      .CHECK_OK(istringstream("2[kg]") >> a)
      .CHECK_OUTPUT(a, "2[kg]")
      .CHECK_EQUAL(Gram == a, true)
      .CHECK_EQUAL(Gram != a, false)
      .CHECK_OUTPUT((--Gram) , "1999[g]")
      .CHECK_EQUAL(Gram != a, true)
      .CHECK_EQUAL(Gram == a, false)
      .CHECK_OK(istringstream("200[g]") >> Gram)
      .CHECK_OK(istringstream("0.2[kg]") >> a)
      .CHECK_OUTPUT(Gram , "200[g]")
      .CHECK_OUTPUT(a , "0.2[kg]")
      .CHECK_EQUAL(Gram != a, false)
      .CHECK_EQUAL(Gram == a, true)

      .CHECK_OK(istringstream("30[min]") >> b)
      .CHECK_OK(istringstream("0.5[hour]") >> c)
      .CHECK_OUTPUT(b , "30[min]")
      .CHECK_OUTPUT(c , "0.5[hour]")

      .CHECK_OK(istringstream("1[ton]") >> b)
      .CHECK_OK(istringstream("1000[kg]") >> c)
      .CHECK_OUTPUT(b , "1[ton]")
      .CHECK_OUTPUT(c , "1000[kg]")

      .CHECK_EQUAL(b != c, false)
      .CHECK_EQUAL(b == c, true)

      .CHECK_OK(istringstream("0.5[km]") >> b)
      .CHECK_OK(istringstream("500[m]") >> c)
      .CHECK_OUTPUT(b , "0.5[km]")
      .CHECK_OUTPUT(c , "500[m]")

      .CHECK_EQUAL(b != c, false)
      .CHECK_EQUAL(b == c, true)
      .CHECK_OUTPUT((b+b+c), "1.5[km]")
      .CHECK_OUTPUT((c+b+b), "1500[m]")
      .CHECK_OUTPUT((c+b-b), "500[m]")
      .CHECK_OUTPUT((b-c-c+b), "0[km]")
      .CHECK_EQUAL((b+c > b), true)
      .CHECK_EQUAL((b-c < b), true)
      .CHECK_OUTPUT((b+=c+=b), "1.5[km]")
      .CHECK_OUTPUT(b, "1.5[km]")
      .CHECK_OUTPUT(c, "1000[m]")


      .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }

    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}








// /**
//  * Examples of automatic tests for the exercise on physical numbers.
//  *
//  * @author Erel Segal-Halevi
//  * @since 2019-02
//  */

// #include <iostream>
// #include <sstream>
// using std::cout, std::endl, std::istringstream;
// #include "PhysicalNumber.h"
// using ariel::PhysicalNumber, ariel::Unit;
// #include "badkan.hpp"

// int main()
// {
//   badkan::TestCase testcase;
//   int grade = 0;
//   int signal = setjmp(badkan::longjmp_buffer);
//   if (signal == 0)
//   {

//     // BASIC TESTS - DO NOT CHANGE
//     PhysicalNumber a(2, Unit::KM);
//     PhysicalNumber b(300, Unit::M);
//     PhysicalNumber c(2, Unit::HOUR);
//     PhysicalNumber d(30, Unit::MIN);

//    // my physislNumber 
//     PhysicalNumber l1(4, Unit::KM);
//     PhysicalNumber l2(4000, Unit::M);
//     PhysicalNumber l3(4, Unit::CM);
//     PhysicalNumber t1(60, Unit::SEC);
//     PhysicalNumber t2(6, Unit::MIN);
//     PhysicalNumber t3(3, Unit::HOUR);
//     PhysicalNumber t4(1, Unit::MIN);
//     PhysicalNumber w1(8, Unit::G);
//     PhysicalNumber w2(7, Unit::KG);
//     PhysicalNumber w3(5, Unit::TON);

//     PhysicalNumber zero1(0, Unit::M);
//     PhysicalNumber zero2(0, Unit::KM);

//     PhysicalNumber minus(-2, Unit::M);

//     testcase
//         .setname("Basic output")
//         .CHECK_OUTPUT(a, "2[km]")
//         .CHECK_OUTPUT(b, "300[m]")

//         .setname("Compatible dimensions")
//         .CHECK_OUTPUT(b + a, "2300[m]")
//         .CHECK_OUTPUT((a += b), "2.3[km]")
//         .CHECK_OUTPUT(a, "2.3[km]")
//         .CHECK_OUTPUT(a + a, "4.6[km]")
//         .CHECK_OUTPUT(b - b, "0[m]")
//         .CHECK_OUTPUT(c, "2[hour]")
//         .CHECK_OUTPUT(d, "30[min]")
//         .CHECK_OUTPUT(d + c, "150[min]")

//         .setname("Incompatible dimensions")
//         .CHECK_THROWS(a + c)
//         .CHECK_THROWS(a + d)
//         .CHECK_THROWS(b + c)
//         .CHECK_THROWS(b + d)

//         .setname("Basic input")
//         .CHECK_OK(istringstream("700[kg]") >> a)
//         .CHECK_OUTPUT(a,"700[kg]")
//         .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

//         // YOUR TESTS - INSERT AS MANY AS YOU WANT

//         //+ operator tests
//         .CHECK_OUTPUT(l1 + l2, "8[km]") //m to km
//         .CHECK_OUTPUT(l1 + l1, "8[km]")
//         .CHECK_OUTPUT(l2 + l1, "8000[m]")     //km to m
//         .CHECK_OUTPUT(l1 + l3, "4.00004[km]") //cm to km
//         .CHECK_OUTPUT(l3 + l1, "400004[cm]")  //km to cm
//         .CHECK_OUTPUT(l2 + l3, "4000.04[m]") //cm to m
//         .CHECK_OUTPUT(l3 + l2, "400004[cm]")  //m to cm
//         .CHECK_OUTPUT(t1 + t2, "420[sec]")    // min to sec
//         .CHECK_OUTPUT(t2 + t1, "7[min]")      //sec to min
//         .CHECK_OUTPUT(t1 + t3, "10860[sec]")  // hour to sec
//         .CHECK_OUTPUT(t3 + t1, "3.01667[hour]") // sec to hour
//         .CHECK_OUTPUT(t2 + t3, "186[min]")    // hour to min
//         .CHECK_OUTPUT(t3 + t2, "3.1[hour]")  // min to hour
//         .CHECK_THROWS(t1 + l2)
//         .CHECK_THROWS(w1 + l2)
//         .CHECK_OUTPUT(zero1+ zero2, "0[m]")
//         .CHECK_OUTPUT(zero2+ zero1, "0[km]")

//         // //- operator tests
//         .CHECK_OUTPUT(l1 - l2, "0[km]")      //m to km
//         .CHECK_OUTPUT(l2 - l1, "0[m]")       //km to m
//         .CHECK_OUTPUT(l2 - l3, "3999.96[m]") //cm to m
//         .CHECK_OUTPUT(l1 - l3, "3.99996[km]")    //cm to km
//         .CHECK_THROWS(t1 - l2)//different types 
//         .CHECK_THROWS(w1 - l2)//different types 

//         // //-() operator
//         .CHECK_OUTPUT(-l1, "-4[km]")//chang + to -
//         .CHECK_OUTPUT(-t1, "-60[sec]")//chang + to -
//         .CHECK_OUTPUT(-w1, "-8[g]")//chang + to -
//         .CHECK_OUTPUT(-minus, "2[m]")//chang -- to +

//         // //+() operator
//         .CHECK_OUTPUT(+w2, "7[kg]")//no chang
//         .CHECK_OUTPUT(+t2, "6[min]")//no chang
//         .CHECK_OUTPUT(+l2, "4000[m]")//no chang
//         .CHECK_OUTPUT(+minus, "2[m]")//chang - to +

//         //< operator
//         .CHECK_EQUAL(t1 < t2, true)
//         .CHECK_EQUAL(t3 < t2, false)
//         .CHECK_THROWS(t1 < w3)//different types

//         // //> operator
//         .CHECK_EQUAL(t1 > t2, false)
//         .CHECK_EQUAL(t3 > t2, true)
//         .CHECK_THROWS(t1 > w3)//different types

//         // //>= operator
//         .CHECK_EQUAL(t1 >= t2, false)
//         .CHECK_EQUAL(t3 >= t2, true)
//         .CHECK_EQUAL(t4 >= t1, true)
//         .CHECK_THROWS(t1 >= w3)//different types

//         // //<= operator
//         .CHECK_EQUAL(t1 <= t2, true)
//         .CHECK_EQUAL(t3 <= t2, false)
//         .CHECK_EQUAL(t4 <= t1, true)
//         .CHECK_THROWS(t1 <= w3)//different types

//         // //== operator
//         .CHECK_EQUAL(t1 == t2, false)
//         .CHECK_EQUAL(t3 == t2, false)
//         .CHECK_EQUAL(t4 == t1, true)
//         .CHECK_THROWS(t1 == w3)//different types

//         // //!= operator
//         .CHECK_EQUAL(t1 != t2, true)
//         .CHECK_EQUAL(t3 != t2, true)
//         .CHECK_EQUAL(t4 != t1, false)
//         .CHECK_THROWS(t1 != w3)//different types

//         // //++ operator
//         .CHECK_OUTPUT(t1++, "60[sec]")// 59++=60
//         .CHECK_OUTPUT(l1++, "4[km]")
//         .CHECK_OUTPUT(w1++, "8[g]")

//         // //-- operatot
//         .CHECK_OUTPUT(t1--, "61[sec]")//61--=60
//         .CHECK_OUTPUT(l1--, "5[km]")
//         .CHECK_OUTPUT(w1--, "9[g]")

//         // //operator +=
//         .CHECK_OUTPUT((w2 += w1), "7.008[kg]") // g to kg
//         .CHECK_OUTPUT(w2, "7.008[kg]")
//         .CHECK_OUTPUT((w1 += w2), "7016[g]") //kg to g
//         .CHECK_OUTPUT(w1, "7016[g]")
//         // .CHECK_OUTPUT((w2 += w3), "5007.008[kg]") //ton to kg
//         // .CHECK_OUTPUT(w2, "5007.008[kg]")
//         .CHECK_THROWS(w1 += l2)//different types
//         .CHECK_THROWS(t1 += w2)
//         .CHECK_THROWS(l1 += w3)
//         .CHECK_THROWS(w2 += t2)

//         // //-= operator
//         .CHECK_OUTPUT((t2 -= t1), "5[min]") //sec to min
//         .CHECK_OUTPUT(t2, "5[min]")
//         .CHECK_OUTPUT((t3 -= t1), "2.98333[hour]") //sec to hour
//         .CHECK_OUTPUT(t3, "2.98333[hour]")
//         .CHECK_OUTPUT((t3 -= t2), "2.9[hour]") //min to hour
//         .CHECK_OUTPUT(t3, "2.9[hour]")
//         .CHECK_THROWS((w2 -= t3))

//         // //>> operator 
//         .CHECK_OK(istringstream("800[kg]") >> l1)
//         .CHECK_OUTPUT(l1, "800[kg]")


        
//         .setname("...")

//         .print(cout, /*show_grade=*/false);
//     grade = testcase.grade();
//   }
//   else
//   {
//     testcase.print_signal(signal);
//     grade = 0;
//   }
//   cout << "*** Grade: " << grade << " ***" << endl;
//   return grade;
// }