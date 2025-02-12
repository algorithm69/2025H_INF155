#include <stdio.h>
#include <math.h>

double my_log_avec_pow(double x, int n) {
    double somme = 0;
    for (int k = 1; k <= n; k++) {
        somme += pow(-1, k + 1) * pow(x, k) / k;
    }
    return somme;
}

double my_pow(double x, int n) {
    double res = 1;
    for (int i = 0; i < n; i++) {
        res *= x;
    }
    return res;
}

double my_log_v1(double x, int n) {
    double somme = 0;
    for (int k = 1; k <= n; k++) {
        // somme+= my_pow(-1, k+1) * my_pow(x,k)/k;
        somme += -my_pow(-x, k) / k;
    }
    return somme;
}

double my_log_v2(double x, int n) {
    double terme = x;
    double somme = terme;

    for (int k = 2; k <= n; k++) {
        terme *= -1 * x * (k - 1) / k;
        somme += terme;
    }
    return somme;
}

double my_log(double x, int n) {
    double somme = 0;
    double signe = 1, num = x;

    for (int k = 1; k <= n; k++) {
        somme += signe * num / k;
        signe *= -1;
        num *= x;
    }
    return somme;
}


int main(void) {
    double x;
    int n;

    scanf("%lf", &x);
    scanf("%d", &n);

    printf("%.3lf", my_log(x, n));

    return 0;
}
