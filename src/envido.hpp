#ifndef TRC_ENVIDO_HPP_ZJ3KAU2F
#define TRC_ENVIDO_HPP_ZJ3KAU2F

#include <cassert>

#include "equipo_id.hpp"


namespace trc {

class Envido {
public:

    bool envido(const trc::EquipoId equipo_id)
    {
        return x_tantos_envido(equipo_id, 2);
    }

    bool real_envido(const trc::EquipoId equipo_id)
    {
        return x_tantos_envido(equipo_id, 3);
    }

    bool falta_envido(const trc::EquipoId)
    {
        return false;
    }

    bool x_tantos_envido(const trc::EquipoId equipo_id, int tantos)
    {
        assert(tantos > 0);
        assert(equipo_id != trc::EquipoId::Nada);

        if (equipo_id != m_retador)
        {
            m_retador = equipo_id;
            m_tantos += m_reto;
            m_reto = tantos;
            return true;
        }
        return false;
    }

    bool quiero(const trc::EquipoId equipo_id)
    {
        assert(equipo_id != trc::EquipoId::Nada);

        if (m_reto > 0 and equipo_id != m_retador)
        {
            m_tantos += m_reto;
            m_reto = 0;
            return true;
        }
        return false;
    }

    bool no_quiero(const trc::EquipoId equipo_id)
    {
        assert(equipo_id != trc::EquipoId::Nada);

        if (m_reto > 0 and equipo_id != m_retador)
        {
            m_reto = 0;
            m_tantos = m_tantos <= 0 ? 1 : m_tantos;

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

private:
    trc::EquipoId m_retador;
    int           m_tantos = 0; /// Cantidad de tantos aceptados.
    int           m_reto = 0;   /// Cantidad de tantos por aceptar.
};

} /* trc */

#endif