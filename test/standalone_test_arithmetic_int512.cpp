///////////////////////////////////////////////////////////////
//  Copyright 2012 - 2021 John Maddock. 
//  Copyright 2021 Matt Borland. Distributed under the Boost
//  Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt

#include "standalone_test_arithmetic.hpp"

#define BOOST_MP_STANDALONE

#include <boost/multiprecision/cpp_int.hpp>

template <unsigned MinBits, unsigned MaxBits, boost::multiprecision::cpp_integer_type SignType, class Allocator, boost::multiprecision::expression_template_option ExpressionTemplates>
struct is_twos_complement_integer<boost::multiprecision::number<boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, boost::multiprecision::checked, Allocator>, ExpressionTemplates> > : public std::integral_constant<bool, false>
{};

template <>
struct related_type<boost::multiprecision::cpp_int>
{
   using type = boost::multiprecision::int256_t;
};
template <unsigned MinBits, unsigned MaxBits, boost::multiprecision::cpp_integer_type SignType, boost::multiprecision::cpp_int_check_type Checked, class Allocator, boost::multiprecision::expression_template_option ET>
struct related_type<boost::multiprecision::number<boost::multiprecision::cpp_int_backend<MinBits, MaxBits, SignType, Checked, Allocator>, ET> >
{
   using type = boost::multiprecision::number<boost::multiprecision::cpp_int_backend<MinBits / 2, MaxBits / 2, SignType, Checked, Allocator>, ET>;
};

int main()
{
   test<boost::multiprecision::int512_t>();
   return boost::report_errors();
}