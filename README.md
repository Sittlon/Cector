# Cector

Cector is a really simple and lighweight vector style dynamic array implementation in C.

```c
#include "cector.h"
```

## Usage

```c
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
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
