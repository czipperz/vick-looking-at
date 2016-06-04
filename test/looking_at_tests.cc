#include "catch.hpp"
#include "../lib.hh"

using namespace vick;
using namespace vick::looking_at;

TEST_CASE("looking_at basic tests") {
    contents c({"hello", "world", ""});

    REQUIRE(is_at(c, 0, 0, "hello"));
    REQUIRE_FALSE(is_at(c, 0, 0, "world"));

    REQUIRE(is_at(c, 1, 0, "world"));
    REQUIRE_FALSE(is_at(c, 1, 0, "hello"));

    REQUIRE(is_at(c, 0, 2, "llo"));
    REQUIRE_FALSE(is_at(c, 0, 2, "hi"));
}

TEST_CASE("looking_at newline query tests") {
    contents c({"hello", "world", ""});

    REQUIRE(is_at(c, 0, 0, "hello\nworld"));
    REQUIRE_FALSE(is_at(c, 0, 0, "world\nhello"));

    REQUIRE(is_at(c, 0, 2, "llo\nwor"));
    REQUIRE_FALSE(is_at(c, 0, 2, "llo\nh"));
}
