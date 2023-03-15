#include "cector.h"

int main()
{
    int i;
    Cector vec;
    Cector_init(&vec);

    Cector_pushback(&vec, "Test");

    printf("%s\n", Cector_at(&vec, 0));

    Cector_delete(&vec);

    return 0;
}