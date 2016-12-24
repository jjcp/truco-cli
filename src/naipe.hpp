#ifndef TRC_NAIPE_HPP_ZFWWL8PN
#define TRC_NAIPE_HPP_ZFWWL8PN

#include <cassert>
#include <ostream>

#include "palo.hpp"


namespace trc {

class Naipe {
public:

    Naipe() = default;

    Naipe(int valor, trc::Palo palo)
    {
        assert((valor >= 1 and valor <= 7) or (valor >= 10 and valor <= 12));
        assert(palo != trc::Palo::Nada);

        m_valor = valor;
        m_palo = palo;
    }

    auto valor() const
    {
        return m_valor;
    }

    auto palo() const
    {
        return m_palo;
    }

private:
    trc::Palo m_palo = trc::Palo::Nada;
    int       m_valor = 0;
};


inline std::ostream& operator<<(std::ostream& os, const trc::Naipe& naipe)
{
    os << "(" << naipe.valor() << ", " << trc::to_cstr(naipe.palo()) << ")";
    return os;
}

} /* trc */

#endif
