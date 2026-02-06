#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    int i = 3;  

    unsigned long base = (unsigned long)&arr[0];

    unsigned long formulaAddress = base + (i * sizeof(int));
    unsigned long actualAddress  = (unsigned long)&arr[i];

    printf("Base Address        = %lu\n", base);
    printf("Formula Address     = %lu\n", formulaAddress);
    printf("Actual Address      = %lu\n", actualAddress);

    return 0;
}
