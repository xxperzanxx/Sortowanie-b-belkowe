#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROZMIAR 100

void sortujBabelkowo(int tablica[], int n, bool rosnaco) {
    int i, j, temp;
    bool zamieniono;

    for (i = 0; i < n - 1; i++) {
        zamieniono = false;
        for (j = 0; j < n - i - 1; j++) {
            if ((rosnaco && tablica[j] > tablica[j + 1]) || (!rosnaco && tablica[j] < tablica[j + 1])) {
                // Zamiana miejscami
                temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
                zamieniono = true;
            }
        }
        if (!zamieniono)
            break;
    }
}

void wyswietlTablice(int tablica[], int rozmiar) {
    for (int i = 0; i < rozmiar; i++)
        printf("%d ", tablica[i]);
    printf("\n");
}

int main() {
    int tablica[MAX_ROZMIAR];
    int n;
    char kierunekSortowania;
    bool rosnaco;

    printf("Podaj liczbe elementow w tablicy (max %d): ", MAX_ROZMIAR);
    scanf("%d", &n);

    if (n <= 0 || n > MAX_ROZMIAR) {
        printf("Niepoprawna liczba elementow. Program zakonczony.\n");
        return 1;
    }

    printf("Podaj %d elementow tablicy:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &tablica[i]);
    }

    printf("Czy chcesz sortowac rosnaco czy malejaco? (r/m): ");
    scanf(" %c", &kierunekSortowania);

    if (kierunekSortowania == 'r' || kierunekSortowania == 'R') {
        rosnaco = true;
    } else if (kierunekSortowania == 'm' || kierunekSortowania == 'M') {
        rosnaco = false;
    } else {
        printf("Niepoprawny wybor. Sortowanie rosn¹ce.\n");
        rosnaco = true;
    }

    printf("Nieposortowana tablica:\n");
    wyswietlTablice(tablica, n);

    sortujBabelkowo(tablica, n, rosnaco);

    printf("Posortowana tablica:\n");
    wyswietlTablice(tablica, n);

    return 0;
}
