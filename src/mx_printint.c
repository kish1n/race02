#include "../inc/header.h"

void mx_printint(int n) {
    long int count = 0;
    long int tmp = (long int)n;
    if (n == -2147483648)
        write(1, "-2147483648", 11);
    else {
            if (n < 0) {
                mx_printchar('-');
                n *= -1;
            }
            else if (n == 0)
                mx_printchar('0');
            while (tmp != 0) {
                tmp /= 10;
                count++;
            }
            for (long int i = count; i > 0; i--) {
                long int power = 1;
                for (long int k = i; k > 1; k--) {
                    power *= 10;
                }
                long int digit = n / power;
                n %= power;
                mx_printchar(digit + 48);
            }
    }
}

