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

    //adds "test" to the end of the array
    v.pushback(&v, "test");
    
    //prints the data at index 0 of the array
    printf("%s\n", v.at(&v, 0));

    //removes the item at index 0 of the array
    v.remove(&v, 0);

    //deletes the array and frees the memory
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
