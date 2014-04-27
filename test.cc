#define USE_MPREAL 1
#include "mpcxx.hh"
#include "mpreal.h"

#include <iostream>

using namespace std;

int main ()
{
    mpcplx z0;
    mpcplx z1 (z0);
    mpcplx z  (10);
    mpcplx zi (2);
    mpcplx zf (3.0f);
    mpcplx zd (4.0);

    mpcplx zii (3,4);
    mpcplx zff (1.0f, 2.0f);
    mpcplx zdd (1.0, 2.0);

    z0 = z1;

    mpfr::mpreal real = z1.real();
    mpfr::mpreal imag = z1.imag();

    z += zi;
    z += zf;
    z -= zf;
    z *= zd;
    z /= zii;

    cout << z.real() << " + " << z.imag() << " i" << endl;
    cout << z << endl;
    return 0;
}

