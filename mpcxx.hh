#ifndef _MPCXX_HH_
#define _MPCXX_HH_

#include <mpc.h>
#include <complex>
#include <iostream>

#ifndef NO_MPREAL
#include "mpreal.h"
#endif

class mpcplx
{
public:

    mpc_t mpc;

public:

    inline static mpc_rnd_t get_default_rnd()    {    return MPC_RNDNN;       }
    inline static mp_prec_t get_default_prec()   {    return mpfr_get_default_prec();                            }

    ~mpcplx();
    mpcplx();

    /// copy constructor ///
    mpcplx (const mpcplx& z);

    /// real value constructor ///
    mpcplx (int         x,		    mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());
    mpcplx (float       x,		    mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());
    mpcplx (double      x,		    mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());
    mpcplx (long double x,		    mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());
    mpcplx (mpf_t       x,		    mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());

    /// real and imaginary parts constructor ///
    mpcplx (int         x, int         y,   mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());
    mpcplx (float       x, float       y,   mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());
    mpcplx (double      x, double      y,   mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());
    mpcplx (long double x, long double y,   mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());
    
    /// complex value constructor ///
    mpcplx (std::complex<float>       z,    mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());
    mpcplx (std::complex<double>      z,    mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());
    mpcplx (std::complex<long double> z,    mp_prec_t prec = mpcplx::get_default_prec(), mpc_rnd_t mode = mpcplx::get_default_rnd());

    /// basic arithmetic with mpcplx ///
    mpcplx& operator += (const mpcplx& z);
    mpcplx& operator -= (const mpcplx& z);
    mpcplx& operator *= (const mpcplx& z);
    mpcplx& operator /= (const mpcplx& z);

    /// real and imag parts ///
#ifndef NO_MPREAL
    mpfr::mpreal real() const;
    mpfr::mpreal imag() const;
#endif

    /// I/O functions ///
    std::string to_string (size_t prec, int base = 10, mpc_rnd_t mode = mpcplx::get_default_rnd()) const;
};

// Destructor ///
inline mpcplx::~mpcplx()
{
    mpc_clear (mpc);
}

// Constructors ////////////////////////////////////////////////////////////////
inline mpcplx::mpcplx()
{
    mpc_init2 (mpc, get_default_prec());
}

inline mpcplx::mpcplx (const mpcplx& z)
{
    mpc_init2 (mpc, get_default_prec());
    mpc_set (mpc, z.mpc, mpcplx::get_default_rnd());
}

inline mpcplx::mpcplx (int x, mp_prec_t prec, mpc_rnd_t mode)
{
    mpc_init2 (mpc, prec);
    mpc_set_si (mpc, static_cast<long int> (x), mode);
}

inline mpcplx::mpcplx (float x, mp_prec_t prec, mpc_rnd_t mode)
{
    mpc_init2 (mpc, prec);
    mpc_set_d (mpc, static_cast<double> (x), mode);
}

inline mpcplx::mpcplx (double x, mp_prec_t prec, mpc_rnd_t mode)
{
    mpc_init2 (mpc, prec);
    mpc_set_d (mpc, x, mode);
}

inline mpcplx::mpcplx (long double x, mp_prec_t prec, mpc_rnd_t mode)
{
    mpc_init2 (mpc, prec);
    mpc_set_ld (mpc, x, mode);
}

inline mpcplx::mpcplx (int x, int y, mp_prec_t prec, mpc_rnd_t mode)
{
    mpc_init2 (mpc, prec);
    mpc_set_si_si (mpc, static_cast<long int>(x), static_cast<long int>(y), mode);
}

inline mpcplx::mpcplx (float x, float y, mp_prec_t prec, mpc_rnd_t mode)
{
    mpc_init2 (mpc, prec);
    mpc_set_d_d (mpc, static_cast<double>(x), static_cast<double>(y), mode);
}

inline mpcplx::mpcplx (double x, double y, mp_prec_t prec, mpc_rnd_t mode)
{
    mpc_init2 (mpc, prec);
    mpc_set_d_d (mpc, x, y, mode);
}

inline mpcplx::mpcplx (long double x, long double y, mp_prec_t prec, mpc_rnd_t mode)
{
    mpc_init2 (mpc, prec);
    mpc_set_ld_ld (mpc, x, y, mode);
}

/// real and imag parts ////////////////////////////////////////////////////////
#ifndef NO_MPREAL

mpfr::mpreal mpcplx::real() const
{
    mpfr::mpreal r;
    mpc_real (r.mp, mpc, (mp_rnd_t)(mpfr_get_default_rounding_mode()));
    return r;
}

mpfr::mpreal mpcplx::imag() const
{
    mpfr::mpreal r;
    mpc_imag (r.mp, mpc, (mp_rnd_t)(mpfr_get_default_rounding_mode()));
    return r;
}

#endif

/// mpcplx arithmetics /////////////////////////////////////////////////////////
mpcplx& mpcplx::operator += (const mpcplx& z)
{
    mpc_add (mpc, mpc, z.mpc, get_default_rnd());
    return *this;
}

mpcplx& mpcplx::operator -= (const mpcplx& z)
{
    mpc_sub (mpc, mpc, z.mpc, get_default_rnd());
    return *this;
}

mpcplx& mpcplx::operator *= (const mpcplx& z)
{
    mpc_mul (mpc, mpc, z.mpc, get_default_rnd());
    return *this;
}

mpcplx& mpcplx::operator /= (const mpcplx& z)
{
    mpc_div (mpc, mpc, z.mpc, get_default_rnd());
    return *this;
}

/// I/O functions //////////////////////////////////////////////////////////////
std::string mpcplx::to_string (size_t prec, int base, mpc_rnd_t mode) const
{
    char* buf = mpc_get_str (base, prec, mpc, mode);
    std::string str (buf);
    mpc_free_str (buf);
    return str;
}

inline std::ostream& operator << (std::ostream& os, const mpcplx& z)
{
    return os << z.to_string (static_cast<size_t> (os.precision()));
}


#endif

