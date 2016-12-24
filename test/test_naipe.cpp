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

    SECTION("Naipe(valor, palo)")
    {
        // -------------------
        // Del 1 al 7
        // -------------------

        for(int i=1; i <= 7; ++i)
        {
            Naipe naipe{i, Palo::Oro};

            REQUIRE(naipe.valor() == i);
            REQUIRE(naipe.palo() == Palo::Oro);
        }

        for(int i=1; i <= 7; ++i)
        {
            Naipe naipe{i, Palo::Copa};

            REQUIRE(naipe.valor() == i);
            REQUIRE(naipe.palo() == Palo::Copa);
        }

        for(int i=1; i <= 7; ++i)
        {
            Naipe naipe{i, Palo::Espada};

            REQUIRE(naipe.valor() == i);
            REQUIRE(naipe.palo() == Palo::Espada);
        }

        for(int i=1; i <= 7; ++i)
        {
            Naipe naipe{i, Palo::Basto};

            REQUIRE(naipe.valor() == i);
            REQUIRE(naipe.palo() == Palo::Basto);
        }

        // -------------------
        // Del 10 al 12
        // -------------------

        for(int i=10; i <= 12; ++i)
        {
            Naipe naipe{i, Palo::Oro};

            REQUIRE(naipe.valor() == i);
            REQUIRE(naipe.palo() == Palo::Oro);
        }

        for(int i=10; i <= 12; ++i)
        {
            Naipe naipe{i, Palo::Copa};

            REQUIRE(naipe.valor() == i);
            REQUIRE(naipe.palo() == Palo::Copa);
        }

        for(int i=10; i <= 12; ++i)
        {
            Naipe naipe{i, Palo::Espada};

            REQUIRE(naipe.valor() == i);
            REQUIRE(naipe.palo() == Palo::Espada);
        }

        for(int i=10; i <= 12; ++i)
        {
            Naipe naipe{i, Palo::Basto};

            REQUIRE(naipe.valor() == i);
            REQUIRE(naipe.palo() == Palo::Basto);
        }
    }
}
