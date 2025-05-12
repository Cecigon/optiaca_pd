#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para obtener el máximo entre dos valores
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Versión con programación dinámica (tabulación)
int mochilaDP(int horas[], int beneficios[], int n, int tiempoDisponible) {
    int dp[n + 1][tiempoDisponible + 1];

    for (int i = 0; i <= n; i++) {
        for (int t = 0; t <= tiempoDisponible; t++) {
            if (i == 0 || t == 0)
                dp[i][t] = 0;
            else if (horas[i - 1] <= t)
                dp[i][t] = max(beneficios[i - 1] + dp[i - 1][t - horas[i - 1]], dp[i - 1][t]);
            else
                dp[i][t] = dp[i - 1][t];
        }
    }

    return dp[n][tiempoDisponible];
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

    int resultado = mochilaDP(horas, beneficios, n, tiempoDisponible);
    printf("\nEl beneficio máximo posible es: %d\n", resultado);

    return 0;
}