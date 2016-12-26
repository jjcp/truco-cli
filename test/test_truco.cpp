#include "catch.hpp"

#include "truco.hpp"


using trc::Truco;
using trc::EquipoId;


TEST_CASE("Truco")
{
    SECTION("truco, quiero")
    {
        Truco truco;

        REQUIRE(truco.tantos() == 1);
        REQUIRE(truco.reto() == 0);
        REQUIRE(truco.retador() == EquipoId::Nada);

        REQUIRE(truco.truco(EquipoId::E1) == true);

        REQUIRE(truco.tantos() == 1);
        REQUIRE(truco.reto() == 2);
        REQUIRE(truco.retador() == EquipoId::E1);

        REQUIRE(truco.quiero(EquipoId::E2) == true);

        REQUIRE(truco.tantos() == 2);
        REQUIRE(truco.reto() == 0);
        REQUIRE(truco.retador() == EquipoId::E1);
    }

    SECTION("truco, retruco, quiero")
    {
        Truco truco;

        REQUIRE(truco.tantos() == 1);
        REQUIRE(truco.reto() == 0);
        REQUIRE(truco.retador() == EquipoId::Nada);

        REQUIRE(truco.truco(EquipoId::E1) == true);

        REQUIRE(truco.tantos() == 1);
        REQUIRE(truco.reto() == 2);
        REQUIRE(truco.retador() == EquipoId::E1);

        REQUIRE(truco.retruco(EquipoId::E2) == true);

        REQUIRE(truco.tantos() == 2);
        REQUIRE(truco.reto() == 3);
        REQUIRE(truco.retador() == EquipoId::E2);

        REQUIRE(truco.quiero(EquipoId::E1) == true);

        REQUIRE(truco.tantos() == 3);
        REQUIRE(truco.reto() == 0);
        REQUIRE(truco.retador() == EquipoId::E2);
    }

    SECTION("truco, retruco, vale-cuatro, quiero")
    {
        Truco truco;

        REQUIRE(truco.tantos() == 1);
        REQUIRE(truco.reto() == 0);
        REQUIRE(truco.retador() == EquipoId::Nada);

        REQUIRE(truco.truco(EquipoId::E1) == true);

        REQUIRE(truco.tantos() == 1);
        REQUIRE(truco.reto() == 2);
        REQUIRE(truco.retador() == EquipoId::E1);

        REQUIRE(truco.retruco(EquipoId::E2) == true);

        REQUIRE(truco.tantos() == 2);
        REQUIRE(truco.reto() == 3);
        REQUIRE(truco.retador() == EquipoId::E2);

        REQUIRE(truco.vale_cuatro(EquipoId::E1) == true);

        REQUIRE(truco.tantos() == 3);
        REQUIRE(truco.reto() == 4);
        REQUIRE(truco.retador() == EquipoId::E1);

        REQUIRE(truco.quiero(EquipoId::E2) == true);

        REQUIRE(truco.tantos() == 4);
        REQUIRE(truco.reto() == 0);
        REQUIRE(truco.retador() == EquipoId::E1);
    }
}
