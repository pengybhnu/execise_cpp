#include "catch2/catch_test_macros.hpp"
#include "catch2/benchmark/catch_benchmark.hpp"
#include "folly/FBString.h"
#include <string>
#include <cstdint>

TEST_CASE("fbstringt","[folly]"){

    folly::fbstring fb{"station"};

    REQUIRE(fb.toStdString()==std::string("station"));
}

