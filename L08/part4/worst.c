#include <stdio.h>
#include <stdbool.h>

int main() {
    int arr[5];
    bool b = false;
    int x = 0;
    int y = 0;

    arr[5] = 1; // Out of bounds array access
    b++; // Incrementing a Boolean variable

    if (x == 0) { // Matching if and else if conditions
        printf("x is 0\n");
    } else if (x == 0) {
        printf("x is still 0\n");
    }

    int z = x / y; // Zero division

    return 0;
}
