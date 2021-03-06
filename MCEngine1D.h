#pragma once


#include <cmath>
#include <ctime>
#include <tuple>
#include <stdexcept>

namespace SiriusFM
{
    template <typename Diffusion1D, 
              typename AProvider, 
              typename BProvider,
              typename AssetClassA,
              typename AssetClassB>

    class MCEngine1D
    {
    private:
        long const          m_MaxL;
        long const          m_MaxP;
        double *            m_paths;  
        long                m_L;     // m_L <= m_MaxL
        long                m_P;     // m_P <= m_MaxP

    public:
        MCEngine1D (long a_MaxL, long a_MaxP) :
            m_MaxL  (a_MaxL),
            m_MaxP  (a_MaxP),
            m_paths (new double [m_MaxL * m_MaxP]), 
            m_L     (0),
            m_P     (0)
        {
            if (m_MaxL <= 0 || m_MaxP <= 0)
            {
                throw std::invalid_argument("Negative sizes");
            }

            for (long p = 0; p < m_MaxP; ++p)
            {
                for (long l = 0; l < m_MaxL; ++l)
                {
                    m_paths[p * m_MaxL + l] = 0;
                }
            }
        }


        std::tuple <long, long, double const *> Get_paths () const
        {
            return (m_L <= 0 || m_P <= 0) ? std::make_tuple(0, 0, nullptr)
                                          : std::make_tuple(m_L, m_P, m_paths);
        }


        template <bool IsRN>
        inline void Simulate 
            (time_t              a_t0,     // Pricing Time 
             time_t              a_T,      // Expir. Time
             int                 a_tau_min, 
             long                a_P,      // Paths number
             Diffusion1D const * a_diff,
             AProvider   const * a_rateA,
             BProvider   const * a_rateB,
             AssetClassA         a_A,
             AssetClassB         a_B);


        MCEngine1D (const MCEngine1D &) = delete;

        MCEngine1D & operator = (const MCEngine1D &) = delete;
        
        ~ MCEngine1D ()
        {
            delete [] m_paths;
        }
    };
}
