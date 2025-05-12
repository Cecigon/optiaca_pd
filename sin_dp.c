#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para obtener el máximo entre dos valores
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Versión recursiva del problema de la mochila
int mochilaRecursiva(int horas[], int beneficios[], int n, int tiempoDisponible) {
    if (n == 0 || tiempoDisponible == 0)
        return 0;

    if (horas[n - 1] > tiempoDisponible)
        return mochilaRecursiva(horas, beneficios, n - 1, tiempoDisponible);

    return max(
        beneficios[n - 1] + mochilaRecursiva(horas, beneficios, n - 1, tiempoDisponible - horas[n - 1]),
        mochilaRecursiva(horas, beneficios, n - 1, tiempoDisponible)
    );
}

int main() {
    int n, tiempoDisponible;
    printf("¿Cuántas materias tienes? ");
    scanf("%d", &n);

    char materias[n][30];
    int horas[n];
    int beneficios[n];

    for (int i = 0; i < n; i++) {
        printf("Nombre de la materia %d: ", i + 1);
        scanf(" %s", materias[i]);
        printf("Horas necesarias para %s: ", materias[i]);
        scanf("%d", &horas[i]);
        printf("Beneficio académico de %s (1-10): ", materias[i]);
        scanf("%d", &beneficios[i]);
    }

    printf("¿Cuántas horas en total tienes disponibles para estudiar? ");
    scanf("%d", &tiempoDisponible);

    int resultado = mochilaRecursiva(horas, beneficios, n, tiempoDisponible);
    printf("\nEl beneficio máximo posible es: %d\n", resultado);

    return 0;
}