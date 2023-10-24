
#include <complex>
#include <iostream>

#include <boost/mpl/list.hpp>

#include <boost/typeof/std/complex.hpp>

#include <boost/units/pow.hpp>
#include <boost/units/quantity.hpp>
#include <boost/units/io.hpp>

// #include "test_system.hpp"

int main(void)
{
    using namespace boost::units;
    using namespace boost::units::test;

    {
    //[quantity_snippet_1
    quantity<length> L = 2.0*meters;                     // quantity of length
    quantity<energy> E = kilograms*pow<2>(L/seconds);    // quantity of energy
    //]
    
    std::cout << "L                                 = " << L << std::endl
              << "L+L                               = " << L+L << std::endl
              << "L-L                               = " << L-L << std::endl
              << "L*L                               = " << L*L << std::endl
              << "L/L                               = " << L/L << std::endl
              << "L*meter                           = " << L*meter << std::endl
              << "kilograms*(L/seconds)*(L/seconds) = "
              << kilograms*(L/seconds)*(L/seconds) << std::endl
              << "kilograms*(L/seconds)^2           = "
              << kilograms*pow<2>(L/seconds) << std::endl
              << "L^3                               = "
              << pow<3>(L) << std::endl
              << "L^(3/2)                           = "
              << pow<static_rational<3,2> >(L) << std::endl
              << "2vL                               = "
              << root<2>(L) << std::endl
              << "(3/2)vL                           = "
              << root<static_rational<3,2> >(L) << std::endl
              << std::endl;
    }
    
    {
    //[quantity_snippet_2
    quantity<length,std::complex<double> > L(std::complex<double>(3.0,4.0)*meters);
    quantity<energy,std::complex<double> > E(kilograms*pow<2>(L/seconds));
    //]
    
    std::cout << "L                                 = " << L << std::endl
              << "L+L                               = " << L+L << std::endl
              << "L-L                               = " << L-L << std::endl
              << "L*L                               = " << L*L << std::endl
              << "L/L                               = " << L/L << std::endl
              << "L*meter                           = " << L*meter << std::endl
              << "kilograms*(L/seconds)*(L/seconds) = "
              << kilograms*(L/seconds)*(L/seconds) << std::endl
              << "kilograms*(L/seconds)^2           = "
              << kilograms*pow<2>(L/seconds) << std::endl
              << "L^3                               = "
              << pow<3>(L) << std::endl
              << "L^(3/2)                           = "
              << pow<static_rational<3,2> >(L) << std::endl
              << "2vL                               = "
              << root<2>(L) << std::endl
              << "(3/2)vL                           = "
              << root<static_rational<3,2> >(L) << std::endl
              << std::endl;
    }

    return 0;
}
