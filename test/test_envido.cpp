#include "catch.hpp"

#include "envido.hpp"


using trc::Envido;
using trc::EquipoId;


TEST_CASE("Envido")
{
    SECTION("caso simple [envido, quiero]")
    {
        Envido envido;

        REQUIRE(envido.retador() == trc::EquipoId::Nada);
        REQUIRE(envido.tantos() == 0);
        REQUIRE(envido.reto() == 0);

        REQUIRE(envido.envido(EquipoId::E1) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E1);
        REQUIRE(envido.tantos() == 0);
        REQUIRE(envido.reto() == 2);

        REQUIRE(envido.quiero(EquipoId::E2) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E1);
        REQUIRE(envido.tantos() == 2);
        REQUIRE(envido.reto() == 0);
    }

    SECTION("caso simple [envido, no-quiero]")
    {
        Envido envido;

        REQUIRE(envido.envido(EquipoId::E2) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E2);
        REQUIRE(envido.tantos() == 0);
        REQUIRE(envido.reto() == 2);

        REQUIRE(envido.no_quiero(EquipoId::E1) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E2);
        REQUIRE(envido.tantos() == 1);
        REQUIRE(envido.reto() == 0);
    }

    SECTION("caso simple [real-envido, quiero]")
    {
        Envido envido;

        REQUIRE(envido.real_envido(EquipoId::E1) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E1);
        REQUIRE(envido.tantos() == 0);
        REQUIRE(envido.reto() == 3);

        REQUIRE(envido.quiero(EquipoId::E2) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E1);
        REQUIRE(envido.tantos() == 3);
        REQUIRE(envido.reto() == 0);
    }

    SECTION("caso simple [real-envido, no-quiero]")
    {
        Envido envido;

        REQUIRE(envido.real_envido(EquipoId::E2) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E2);
        REQUIRE(envido.tantos() == 0);
        REQUIRE(envido.reto() == 3);

        REQUIRE(envido.no_quiero(EquipoId::E1) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E2);
        REQUIRE(envido.tantos() == 1);
        REQUIRE(envido.reto() == 0);
    }

    SECTION("revire [envido, envido, quiero]")
    {
        Envido envido;

        REQUIRE(envido.envido(EquipoId::E1) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E1);
        REQUIRE(envido.tantos() == 0);
        REQUIRE(envido.reto() == 2);

        REQUIRE(envido.envido(EquipoId::E2) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E2);
        REQUIRE(envido.tantos() == 2);
        REQUIRE(envido.reto() == 2);

        REQUIRE(envido.quiero(EquipoId::E1) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E2);
        REQUIRE(envido.tantos() == 4);
        REQUIRE(envido.reto() == 0);
    }

    SECTION("revire [envido, envido, no-quiero]")
    {
        Envido envido;

        REQUIRE(envido.envido(EquipoId::E2) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E2);
        REQUIRE(envido.tantos() == 0);
        REQUIRE(envido.reto() == 2);

        REQUIRE(envido.envido(EquipoId::E1) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E1);
        REQUIRE(envido.tantos() == 2);
        REQUIRE(envido.reto() == 2);

        REQUIRE(envido.no_quiero(EquipoId::E2) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E1);
        REQUIRE(envido.tantos() == 2);
        REQUIRE(envido.reto() == 0);
    }

    SECTION("revire [envido, real-envido, quiero]")
    {
        Envido envido;

        REQUIRE(envido.envido(EquipoId::E1) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E1);
        REQUIRE(envido.tantos() == 0);
        REQUIRE(envido.reto() == 2);

        REQUIRE(envido.real_envido(EquipoId::E2) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E2);
        REQUIRE(envido.tantos() == 2);
        REQUIRE(envido.reto() == 3);

        REQUIRE(envido.quiero(EquipoId::E1) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E2);
        REQUIRE(envido.tantos() == 5);
        REQUIRE(envido.reto() == 0);
    }

    SECTION("revire [envido, real-envido, no-quiero]")
    {
        Envido envido;

        REQUIRE(envido.envido(EquipoId::E2) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E2);
        REQUIRE(envido.tantos() == 0);
        REQUIRE(envido.reto() == 2);

        REQUIRE(envido.real_envido(EquipoId::E1) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E1);
        REQUIRE(envido.tantos() == 2);
        REQUIRE(envido.reto() == 3);

        REQUIRE(envido.no_quiero(EquipoId::E2) == true);

        REQUIRE(envido.retador() == trc::EquipoId::E1);
        REQUIRE(envido.tantos() == 2);
        REQUIRE(envido.reto() == 0);
    }

    SECTION("trc::Envido::estado()")
    {
        Envido envido;

        REQUIRE(envido.estado() == Envido::Estado::Nada);

        envido.real_envido(EquipoId::E1);
        REQUIRE(envido.estado() == Envido::Estado::EnProceso);

        envido.envido(EquipoId::E2);
        REQUIRE(envido.estado() == Envido::Estado::EnProceso);

        envido.quiero(EquipoId::E1);
        REQUIRE(envido.estado() == Envido::Estado::Querido);

        envido = Envido{};

        envido.envido(EquipoId::E1);
        REQUIRE(envido.estado() == Envido::Estado::EnProceso);

        envido.no_quiero(EquipoId::E2);
        REQUIRE(envido.estado() == Envido::Estado::NoQuerido);
    }
}
