#include "catch.hpp"
#include "naipe.hpp"

using trc::Naipe;
using trc::Palo;


TEST_CASE("Naipe")
{
    Naipe naipe{1, Palo::Oro};

    REQUIRE(naipe.valor() == 1);
    REQUIRE(naipe.palo() == Palo::Oro);
}
