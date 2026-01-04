#include <stdio.h>

float f2c(float fahr);

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = upper;
    while (fahr >= lower) {
        celsius = f2c(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr - step;
    }
    return 0;
}

/* f2c: converts fahrenheit temperatures to celsius */
float f2c(float fahr) {
    return (5.0/9.0) * (fahr - 32.0);
}
