#include "mpcxx.hh"

int main ()
{
    mpcplx z0;
    mpcplx z1 (z0);
    mpcplx zi (3);
    mpcplx zf (1.0f);
    mpcplx zd (1.0);

    mpcplx zii (3,4);
    mpcplx zff (1.0f, 2.0f);
    mpcplx zdd (1.0, 2.0);

    return 0;
}

