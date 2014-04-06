#ifndef _MPCXX_HH_
#define _MPCXX_HH_

#include <mpc.h>

class mpcplx
{
public:

    inline static mpc_rnd_t get_default_rnd()    {    return MPC_RNDNN;       }
    inline static mp_prec_t get_default_prec()   {    return mpfr_get_default_prec();                            }

    ~mpcplx();
    mpcplx();

private:

    mpc_t z;
};

/// Destructor ///
inline mpcplx::~mpcplx()
{
    mpc_clear (z);
}

/// Constructors ///
inline mpcplx::mpcplx()
{
    mpc_init2 (z, get_default_prec());
}

#endif

