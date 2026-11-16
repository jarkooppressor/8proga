#include "myarrfunc.h"
#include <stdio.h>

void fill_array(int *arrptr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("Элемент [%zu]: ", i);
        while (scanf("%d", arrptr + i) != 1) {
            if (feof(stdin)) return;
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Ошибка ввода. Повторите [%zu]: ", i);
        }
    }
}

void print_array_info(const int *arrptr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("[%zu] = %d (адрес: %p)\n", i, *(arrptr + i), (void *)(arrptr + i));
    }
}

int find_last_negative(const int *arrptr, size_t n, int *result) {
    for (size_t i = n; i > 0; i--) {
        if (*(arrptr + i - 1) < 0) {
            *result = *(arrptr + i - 1);
            return 0;
        }
    }
    return -1;
}

long long sum_in_value_range(const int *arrptr, size_t n, int k, int m) {
    if (k > m) {
        int t = k;
        k = m;
        m = t;
    }
    long long sum = 0;
    for (size_t i = 0; i < n; i++) {
        int val = *(arrptr + i);
        if (val >= k && val <= m) {
            sum += val;
        }
    }
    return sum;
}

size_t count_above_average(const int *arrptr, size_t n) {
    if (n == 0) return 0;
    double sum = 0;
    for (size_t i = 0; i < n; i++) {
        sum += *(arrptr + i);
    }
    size_t count = 0;
    for (size_t i = 0; i < n; i++) {
        if (*(arrptr + i) > sum / n) {
            count++;
        }
    }
    return count;
}
//16вар