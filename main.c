/*Задача 1.	Вставить число 100 после второго положительного элемента
 * линейного массива, сдвинув оставшиеся элементы к концу. Учесть
 * изменение размера массива. Массив, в котором нет двух
 * положительных элементов, признается некорректным.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");
    int i, n; /*вспомогательная переменная, размер массива*/
    int prev, cur;
    int second_positive_index;
    int positive_count = 0;
    int *p; /*указатель на массив*/
    printf("Введите размер массива:\n"); /*ввод массива*/
    scanf("%d", &n);
    p = (int *) malloc((n + 1) * sizeof(int)); /*выделение памяти*/
    printf("Исходный массив \n");
    for (i = 0; i < n; i++) /*ввод*/
    {
        printf("a[%d] = ", i);
        scanf("%d", &p[i]);
    }
    for (i = 0; i < n; i++) /*проверка есть ли 2 положительных*/
    {
        if (p[i] > 0)
            positive_count++;
        if (positive_count == 2) {
            second_positive_index = i;
            break;
        }
    }
    if (positive_count == 2) {
        printf("В массиве есть минимум 2 полжительных числа"); /*выводим
сообщение, что все ок*/
        prev = p[second_positive_index];
        for (i = second_positive_index + 1; i < n + 1; i++) {
            cur = p[i];
            p[i] = prev;
            prev = cur;
        }
        p[second_positive_index + 1] = 100;
        printf("Новый массив:\n");
        for (i = 0; i < n + 1; i++)
            printf("%5d", p[i]);
    } else
        printf("В массиве нет 2 положительных чисел"); /*если к меньше двух, то
выводим сообщение*/
    free(p);
    return 0;
}

