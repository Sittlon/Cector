#include "cector.h"

int main()
{
    int i;
    LVector lumia_history;
    LVector_init(&lumia_history);

    LVector_pushback(&lumia_history, "Test");

    LVector_delete(&lumia_history);

    return 0;
}