#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "myarrfunc.h"

int read_int(const char *msg, int *val) {
    printf("%s", msg);
    int res = scanf("%d", val), c;
    while ((c = getchar()) != '\n' && c != EOF);
    return (res == EOF || c == EOF) ? -1 : (res == 1);
}

int main(void) {
    int *arr = NULL, filled = 0, cmd, size, k, m, res;
    size_t n = 0;

    while (1) {
        printf("\na) Размер\nb) Заполнить\nc) Вывод\nd) Последний отрицательный\n"
               "e) Сумма в диапазоне k-m\nf) Кол-во выше среднего\ng) Выход\nВыбор: ");
        while ((cmd = getchar()) != EOF && isspace((unsigned char)cmd));
        if (cmd == EOF) break;
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        cmd = tolower((unsigned char)cmd);
        if (cmd == 'g') break;
        if (cmd == 'a') {
            int st = read_int("Размер (>0): ", &size);
            if (st == -1) break;
            if (!st || size <= 0) { printf("Ошибка.\n"); continue; }
            int *tmp = realloc(arr, (size_t)size * sizeof(int));
            if (!tmp) { printf("Нет памяти.\n"); continue; }
            arr = tmp; n = (size_t)size; filled = 0;
        } 
        else if (cmd == 'b') {
            if (!arr) { printf("Сначала пункт a.\n"); continue; }
            fill_array(arr, n);
            if (feof(stdin)) break;
            while ((c = getchar()) != '\n' && c != EOF);
            filled = 1;
        } 
        else if (!filled && cmd >= 'c' && cmd <= 'f') {
            printf("Сначала заполните массив (a, b).\n");
        } 
        else if (cmd == 'c') print_array_info(arr, n);
        else if (cmd == 'd') {
            if (find_last_negative(arr, n, &res) == 0) printf("Результат: %d\n", res);
            else printf("Отрицательных нет.\n");
        } 
        else if (cmd == 'e') {
            int s1 = read_int("k: ", &k);
            if (s1 == -1) break;
            int s2 = read_int("m: ", &m);
            if (s2 == -1) break;
            if (!s1 || !s2) { printf("Ошибка ввода.\n"); continue; }
            printf("Сумма: %lld\n", sum_in_value_range(arr, n, k, m));
        } 
        else if (cmd == 'f') printf("Выше среднего: %zu\n", count_above_average(arr, n));
        else printf("Неверная команда.\n");
    }
    free(arr);
    return 0;
}
//25