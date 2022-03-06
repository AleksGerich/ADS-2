// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    double b = value;
    if (n == 0) {
        return 1;
    } else {
        while (n > 1) {
        value = value * b;
        n -= 1;
        }
    }
    return value;
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

double calcItem(double x, uint16_t n) {
    double res = pown(x, n) / fact(n);
    return res;
}

double expn(double x, uint16_t count) {
    double sum = 1;
    for (int i = 1; i <= count; i++) {
        sum += calcItem(x, i);
    }
    return sum;
}

double sinn(double x, uint16_t count) {
    double sum = x;
    for (int i = 2; i <= count; i++) {
        sum += pown(-1, i-1) * calcItem(x, (2 * i - 1));
    }
    return sum;
}

double cosn(double x, uint16_t count) {
    double sum = 1;
    for (int i = 2; i <= count; i++) {
        sum += pown(-1, i-1) * calcItem(x, (2 * i - 2));
    }
    return sum;
}
