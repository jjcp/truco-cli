#ifndef TRC_JUGADOR_HPP_FZ8KTA4G
#define TRC_JUGADOR_HPP_FZ8KTA4G

#include "equipo_id.hpp"


namespace trc {

class Jugador {
public:

    Jugador(const trc::EquipoId equipo)
        : m_equipo{equipo}
    { }

    auto equipo() const
    {
        return m_equipo;
    }

private:
    const trc::EquipoId m_equipo;
};

} /* trc */

#endif
