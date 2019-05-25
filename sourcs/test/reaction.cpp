#include <cmath>

#define CATCH_CONFIG_MAIN
#include "../../third/catch2/catch.hpp"
double reaction(int _sec, int result)
{
	double a;
		if (!result){
			a = sqrt(-1);
		}
		else{
			a = (double)_sec/result;
		}
	return a;
}
TEST_CASE("TEST_REACTION", "[int]") {
  REQUIRE(reaction(10,2) == Approx(5.0).epsilon(0.01));
  REQUIRE(reaction(10,3) == Approx(3.33).epsilon(0.01));
  REQUIRE(reaction(10,0) != reaction(10,0));
}