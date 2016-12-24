#include "catch.hpp"
#include "naipe.hpp"

using trc::Naipe;
using trc::Palo;


TEST_CASE("Naipe")
{
    SECTION("Naipe nulo")
    {
        Naipe naipe;

        REQUIRE(naipe.valor() == 0);
        REQUIRE(naipe.palo() == Palo::Nada);
    }

    Naipe naipe{1, Palo::Oro};

    REQUIRE(naipe.valor() == 1);
    REQUIRE(naipe.palo() == Palo::Oro);
}
