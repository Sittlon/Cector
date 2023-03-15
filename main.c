#include "cector.h"

int main()
{
    int i;
    Cector vec;
    Cector_init(&vec);

    //first pushback test
    Cector_pushback(&vec, "Test");
    printf("%s\n", Cector_at(&vec, 0));

    //erase test
    Cector_erase(&vec, 0);
    Cector_pushback(&vec, "nach löschen");
    printf("%s\n", Cector_at(&vec, 0));


    //size test
    char str[10];
    for(int i = 0; i < 1000000; ++i)
    {
        sprintf(str, "d", i);
        Cector_pushback(&vec, str);
    }
    printf("%d\n", Cector_size(&vec));

    Cector_delete(&vec);

    return 0;
}