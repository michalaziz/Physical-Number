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
        .CHECK_OUTPUT(l1+l2, "8[km]")
        .CHECK_OUTPUT(l1+l2, "8000[m]")
        .CHECK_OUTPUT(l1+l2, "800000[cm]")
        .CHECK_OUTPUT(l1+l3, "4.00004[km]")
        .CHECK_OUTPUT(l1+l3, "4000.04[m]")
        .CHECK_OUTPUT(l1+l3, "400004[cm]")
        .CHECK_OUTPUT(l2+l3, "4.00004[km]")
        .CHECK_OUTPUT(l2+l3, "4000.04[m]")
        .CHECK_OUTPUT(l2+l3, "400004[cm]")
        .CHECK_OUTPUT(t1+ t2, "420[sec]")
        .CHECK_OUTPUT(t1+ t2, "7[min]")
        .CHECK_OUTPUT(t1+ t2, "150[hour]")



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