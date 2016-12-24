#ifndef TRC_CRUPIER_HPP_AYCOHIQL
#define TRC_CRUPIER_HPP_AYCOHIQL

#include <cassert>

#include <algorithm>
#include <array>
#include <random>


namespace trc {

class Crupier {
public:

    Crupier()
        : m_prng{m_rng()}
    {
        m_baraja.reserve(40);
        mezclar();
    }

    void mezclar()
    {
        inicializar_baraja();
        std::shuffle(m_baraja.begin(), m_baraja.end(), m_prng);
    }

    auto siguiente_naipe() -> trc::Naipe
    {
        assert(m_baraja.size() > 0);

        auto r = m_baraja.back();
        m_baraja.pop_back();
        return r;
    }

private:
    std::random_device      m_rng;  /// random number generator.
    std::mt19937            m_prng; /// pseudorandom number generator.
    std::vector<trc::Naipe> m_baraja;

    void inicializar_baraja()
    {
        if (m_baraja.size() != 40)
        {
            m_baraja.clear();

            for(int i=1; i <= 7; ++i)
            {
                m_baraja.emplace_back(i, trc::Palo::Oro);
                m_baraja.emplace_back(i, trc::Palo::Copa);
                m_baraja.emplace_back(i, trc::Palo::Espada);
                m_baraja.emplace_back(i, trc::Palo::Basto);
            }

            for(int i=10; i <= 12; ++i)
            {
                m_baraja.emplace_back(i, trc::Palo::Oro);
                m_baraja.emplace_back(i, trc::Palo::Copa);
                m_baraja.emplace_back(i, trc::Palo::Espada);
                m_baraja.emplace_back(i, trc::Palo::Basto);
            }
        }
    }
};

} /* trc */

#endif
