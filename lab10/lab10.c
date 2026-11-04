#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
double area_figure(int k);
void print_definition(void);
void draw_figure(int k, char ch);
double compare_figures(double s1, double s2);
int main() {
    setlocale(LC_ALL, "RUS");
    int choice;
    int k, draw_k;
    int k1, k2;
    double s, s1, s2, diff;
    char ch;
    do {
        printf("Меню операций для геометрической фигуры
            :\n");
        printf("1 - Рассчитать площадь фигуры\n");
        printf("2 - Вывести определение фигуры\n");
        printf("3 - Нарисовать фигуру\n");
        printf("4 - Сравнить две фигуры по площади\n");
        printf("0 - Выход\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Введите масштабный коэффициент k (> 0): ");
            scanf("%d", &k);
            if (k <= 0) {
                printf("\nОшибка: размер должен быть больше нуля.\n");
            }
            else {
                s = area_figure(k);
                printf("\nПлощадь фигуры: %.2lf\n", s);
            }
            break;
        case 2:
            print_definition();
            break;
        case 3:
            printf("Введите масштабный коэффициент k (> 0): ");
            scanf("%d", &draw_k);
            if (draw_k <= 0) {
                printf("\nОшибка: размер должен быть больше нуля.\n");
            }
            else {
                printf("Введите символ для рисования: ");
                scanf(" %c", &ch);
                printf("\nРезультат:\n");
                draw_figure(draw_k, ch);
            }
            break;
        case 4:
            printf("Первая фигура\n");
            printf("Введите масштабный коэффициент k1: ");
            scanf("%d", &k1);
            printf("Вторая фигура\n");
            printf("Введите масштабный коэффициент k2: ");
            scanf("%d", &k2);
            if (k1 <= 0 || k2 <= 0) {
                printf("\nОшибка: коэффициенты должны быть больше нуля.\n");
            }
            else {
                s1 = area_figure(k1);
                s2 = area_figure(k2);
                diff = compare_figures(s1, s2);
                printf("\nПлощадь первой: %.2lf, площадь второй: %.2lf\n", s1, s2);
                if (diff > 0) {
                    printf("\nПервая фигура больше второй на %.2lf\n", diff);
                }
                else if (diff < 1e-9 && diff > -1e-9) {
                    printf("\nПлощади фигур равны\n");
                }
                else {
                    printf("\nВторая фигура больше первой на %.2lf\n", -diff);
                }
            }
            break;
        case 0:
            printf("Завершение программы.\n");
            break;
        default:
            printf("Неверный пункт меню, попробуйте снова.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
double area_figure(int k) {
    double total_area = (8.0 * k) * (4.0 * k);
    double cut_area = (2.0 * k) * (1.0 * k);
    return total_area - cut_area;
}
void print_definition(void) {
    printf("\nПредставленная фигура — это многоугольник в виде П-образной арки, \n");
    printf("образованный внешним прямоугольником с вырезанной центральной нижней частью.\n");
}
void draw_figure(int k, char ch) {
    int y, x;
    for (y = 5 * k; y >= 1 * k; y--) {
        for (x = -4 * k; x <= 4 * k; x++) {
            if (y <= 2 * k && x >= -1 * k && x <= 1 * k) {
                printf(" ");
            }
            else {
                printf("%c", ch);
            }
        }
        printf("\n");
    }
}
double compare_figures(double s1, double s2) {
    return s1 - s2;
}
