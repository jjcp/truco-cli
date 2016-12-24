#ifndef TRC_PALO_HPP_9CIH58DB
#define TRC_PALO_HPP_9CIH58DB


namespace trc {

enum class Palo
{
    Oro,
    Copa,
    Espada,
    Basto
};


inline auto to_cstr(const trc::Palo palo)
    -> const char*
{
    switch(palo)
    {
    case Palo::Oro: return "Oro";
    case Palo::Copa: return "Copa";
    case Palo::Espada: return "Espada";
    case Palo::Basto: return "Basto";
    }
}

} /* trc */

#endif
