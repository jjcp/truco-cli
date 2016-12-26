#ifndef TRC_TRUCO_HPP_VIHEIFRJ
#define TRC_TRUCO_HPP_VIHEIFRJ

#include <cassert>

#include "equipo_id.hpp"


namespace trc {

class Truco {
public:

    bool truco(const trc::EquipoId equipo_id)
    {
        return x_truco(equipo_id, 2);
    }

    bool retruco(const trc::EquipoId equipo_id)
    {
        return x_truco(equipo_id, 3);
    }

    bool vale_cuatro(const trc::EquipoId equipo_id)
    {
        return x_truco(equipo_id, 4);
    }

    bool quiero(const trc::EquipoId equipo_id)
    {
        if (m_reto > 0 and equipo_id != m_retador)
        {
            m_tantos = m_reto;
            m_reto = 0;
            return true;
        }
        return false;
    }

    bool no_quiero(const trc::EquipoId equipo_id)
    {
        if (m_reto > 0 and equipo_id != m_retador)
        {
            m_reto = 0;
            return true;
        }
        return false;
    }

    auto tantos() const
    {
        return m_tantos;
    }

    auto reto() const
    {
        return m_reto;
    }

    auto retador() const
    {
        return m_retador;
    }

private:
    trc::EquipoId m_retador = trc::EquipoId::Nada;
    int           m_tantos = 1; /// Cantidad de tantos aceptados.
    int           m_reto = 0;   /// Cantidad de tantos por aceptar.

    bool x_truco(const trc::EquipoId equipo_id, int tantos)
    {
        assert(equipo_id != trc::EquipoId::Nada);
        assert(tantos > 0 and tantos <= 4);

        quiero(equipo_id);

        if (tantos-1 == m_tantos and equipo_id != m_retador)
        {
            m_retador = equipo_id;
            m_reto = tantos;
            return true;
        }
        return false;
    }
};

} /* trc */

#endif
