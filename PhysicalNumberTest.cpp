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

int main()
{
  badkan::TestCase testcase;
  int grade = 0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0)
  {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber d(30, Unit::MIN);

    PhysicalNumber l1(4, Unit::KM);
    PhysicalNumber l2(4000, Unit::M);
    PhysicalNumber l3(4, Unit::CM);
    PhysicalNumber t1(60, Unit::SEC);
    PhysicalNumber t2(6, Unit::MIN);
    PhysicalNumber t3(3, Unit::HOUR);
    PhysicalNumber t4(1, Unit::MIN);
    PhysicalNumber w1(8, Unit::G);
    PhysicalNumber w2(7, Unit::KG);
    PhysicalNumber w3(5, Unit::TON);

    testcase
        .setname("Basic output")
        .CHECK_OUTPUT(a, "2[km]")
        .CHECK_OUTPUT(b, "300[m]")

        .setname("Compatible dimensions")
        .CHECK_OUTPUT(b + a, "2300[m]")
        .CHECK_OUTPUT((a += b), "2.3[km]")
        .CHECK_OUTPUT(a, "2.3[km]")
        .CHECK_OUTPUT(a + a, "4.6[km]")
        .CHECK_OUTPUT(b - b, "0[m]")
        .CHECK_OUTPUT(c, "2[hour]")
        .CHECK_OUTPUT(d, "30[min]")
        .CHECK_OUTPUT(d + c, "150[min]")

        .setname("Incompatible dimensions")
        .CHECK_THROWS(a + c)
        .CHECK_THROWS(a + d)
        .CHECK_THROWS(b + c)
        .CHECK_THROWS(b + d)

        .setname("Basic input")
        .CHECK_OK(istringstream("700[kg]") >> a)
        .CHECK_OUTPUT((a += PhysicalNumber(1, Unit::TON)), "1700[kg]")

        // YOUR TESTS - INSERT AS MANY AS YOU WANT

        //+ operator tests
        .CHECK_OUTPUT(l1 + l2, "8[km]") //m to km
        .CHECK_OUTPUT(l1 + l1, "8[km]")
        .CHECK_OUTPUT(l2 + l1, "8000[m]")     //km to m
        .CHECK_OUTPUT(l1 + l3, "4.00004[km]") //cm to km
        .CHECK_OUTPUT(l3 + l1, "400004[cm]")  //km to cm
        .CHECK_OUTPUT(l2 + l3, "40000.04[m]") //cm to m
        .CHECK_OUTPUT(l3 + l2, "400004[cm]")  //m to cm
        .CHECK_OUTPUT(t1 + t2, "420[sec]")    // min to sec
        .CHECK_OUTPUT(t2 + t1, "7[min]")      //sec to min
        .CHECK_OUTPUT(t1 + t3, "10860[sec]")  // hour to sec
        .CHECK_OUTPUT(t3 + t1, "3.001[hour]") // sec to hour
        .CHECK_OUTPUT(t2 + t3, "186[min]")    // hour to min
        .CHECK_OUTPUT(t3 + t2, "3.06[hour]")  // min to hour
        .CHECK_THROWS(t1 + l2)
        .CHECK_THROWS(w1 + l2)

        //- operator tests
        .CHECK_OUTPUT(l1 - l2, "0[km]")      //m to km
        .CHECK_OUTPUT(l2 - l1, "0[m]")       //km to m
        .CHECK_OUTPUT(l2 - l3, "3999.96[m]") //cm to m
        .CHECK_OUTPUT(l1 - l3, "3.99996")    //cm to km
        .CHECK_THROWS(t1 - l2)
        .CHECK_THROWS(w1 - l2)

        //-() operator
        .CHECK_OUTPUT(-l1, "-4[km]")
        .CHECK_OUTPUT(-t1, "-60[sec]")
        .CHECK_OUTPUT(-w1, "-8[g]")

        //+() operator
        .CHECK_OUTPUT(+w2, "7[kg]")
        .CHECK_OUTPUT(+t2, "6[min]")
        .CHECK_OUTPUT(+l2, "4000[m]")

        //< operator
        .CHECK_EQUAL(t1 < t2, true)
        .CHECK_EQUAL(t3 < t2, false)
        .CHECK_THROWS(t1 < w3)

        //> operator
        .CHECK_EQUAL(t1 > t2, false)
        .CHECK_EQUAL(t3 > t2, true)
        .CHECK_THROWS(t1 > w3)

        //>= operator
        .CHECK_EQUAL(t1 >= t2, false)
        .CHECK_EQUAL(t3 >= t2, true)
        .CHECK_EQUAL(t4 >= t1, true)
        .CHECK_THROWS(t1 >= w3)

        //<= operator
        .CHECK_EQUAL(t1 <= t2, true)
        .CHECK_EQUAL(t3 <= t2, false)
        .CHECK_EQUAL(t4 <= t1, true)
        .CHECK_THROWS(t1 <= w3)

        //== operator
        .CHECK_EQUAL(t1 == t2, false)
        .CHECK_EQUAL(t3 == t2, false)
        .CHECK_EQUAL(t4 == t1, true)
        .CHECK_THROWS(t1 == w3)

        //!= operator
        .CHECK_EQUAL(t1 != t2, true)
        .CHECK_EQUAL(t3 != t2, true)
        .CHECK_EQUAL(t4 != t1, false)
        .CHECK_THROWS(t1 != w3)

        //++ operator
        .CHECK_OUTPUT(t1++, "61[sec]")
        .CHECK_OUTPUT(l1++, "5[km]")
        .CHECK_OUTPUT(w1++, "9[g]")

        //-- operatot
        .CHECK_OUTPUT(t1, "59[sec]")
        .CHECK_OUTPUT(l1, "3[km]")
        .CHECK_OUTPUT(w1, "7[g]")

        //operator +=
        .CHECK_OUTPUT((w2 += w1), "7.08[kg]") // g to kg
        .CHECK_OUTPUT(w2, "7.08[kg]")
        .CHECK_OUTPUT((w1 += w2), "7088[g]") //kg to g
        .CHECK_OUTPUT(w1, "7088[g]")
        .CHECK_OUTPUT((w2 += w3), "5007.08[kg]") //ton to kg
        .CHECK_OUTPUT(w2, "5007.08[kg]")
        .CHECK_THROWS(w1 += l2)
        .CHECK_THROWS(t1 += w2)
        .CHECK_THROWS(l1 += w3)
        .CHECK_THROWS(w2 += t2)

        //-= operator
        .CHECK_OUTPUT((t2 -= t1), "5[min]") //sec to min
        .CHECK_OUTPUT(t2, "2[min]")
        .CHECK_OUTPUT((t3 -= t1), "2.59[hour]") //sec to hour
        .CHECK_OUTPUT(t3, "2.59[hour]")
        .CHECK_OUTPUT((t3 -= t2), "2.54[hour]") //min to hour
        .CHECK_OUTPUT(t3, "2.54[hour]")
        .CHECK_THROWS((w2 -= t3))

        
        .setname("...")

        .print(cout, /*show_grade=*/false);
    grade = testcase.grade();
  }
  else
  {
    testcase.print_signal(signal);
    grade = 0;
  }
  cout << "*** Grade: " << grade << " ***" << endl;
  return grade;
}