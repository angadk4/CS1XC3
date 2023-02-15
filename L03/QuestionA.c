#include <stdio.h>

int main() {
    for (int i = 1; i < 168 / 2 + 1; ++i) {
        if (168 % i == 0) {
            int j = 168 / i;
            if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0) {
                int m = (i + j) / 2;
                int n = (i - j) / 2;
                int x = n * n - 100;
                printf("%d + 100 = %d * %d\n", x, n, n);
                printf("%d + 268 = %d * %d\n", x, m, m);
            }
        }
    }
    return 0;

}
