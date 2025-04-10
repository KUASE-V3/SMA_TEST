#include <stdio.h>
#include "add.hpp"
#include "sub.hpp"

int main() {
    int a = 5, b = 7;
    printf("Sum: %d\n", add(a, b));
    printf("Sub: %d\n", sub(a, b));
    return 0;
}