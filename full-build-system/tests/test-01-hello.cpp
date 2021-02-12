#include <catch2/catch.hpp>

#include "hello.hpp"

TEST_CASE("01: I get five.", "[hello]") {
  REQUIRE(gimmeFive() == 5);
}
