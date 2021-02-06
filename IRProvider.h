#pragma once

#include <cstring>
#include <iostream>

namespace SiriusFM
{
    enum class CcyE
    {
        USD = 0,
        EUR = 1,
        GBP = 2,
        CHF = 3,
        RUB = 4,
        JPY = 5,
        CNY = 6,
        N   = 7
    };


    inline char const * CcyE2Str (CcyE a_ccy)
    {
        switch(a_ccy)
        {
            case CcyE::USD : return "USD";
            case CcyE::EUR : return "EUR";
            case CcyE::GBP : return "GBP";
            case CcyE::RUB : return "RUB";
            case CcyE::JPY : return "JPY";
            case CcyE::CNY : return "CNY";
            default        : throw std::invalid_argument("Wrong ccy");
        }
    }

    
    inline CcyE Str2CcyE (char const * a_str)
    {
        if (!strcmp(a_str, "USD"))
        {
            return CcyE::USD;
        }
        else if (!strcmp(a_str, "EUR"))
        {
            return CcyE::EUR;
        }
        else if (!strcmp(a_str, "GBP"))
        {
            return CcyE::GBP;
        }
        else if (!strcmp(a_str, "RUB"))
        {
            return CcyE::RUB;
        }
        else if (!strcmp(a_str, "JPY"))
        {
            return CcyE::JPY;
        }
        else if (!strcmp(a_str, "CNY"))
        {
            return CcyE::CNY;
        }
        else
        {
            throw std::invalid_argument("Wrong ccy");
        }
    }


    enum class IRModeE
    {
        Const    = 0,
        FwdCurve = 1,
        Stoch    = 2
    };


    template <IRModeE IRM>
    class IRProvider;
}
