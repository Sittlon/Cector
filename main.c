#include "cector.h"

int main()
{
    Cector(v);

    v.pushback(&v, "test");

    printf("%s\n", v.at(&v, 0));

    v.remove(&v, 0);

    v.delete(&v);

    return 0;
}