// Basado en GeeksforGeeks [3] y adaptado del código de BaseMax [4]
// Aplicado al contexto de estudiantes que deben planear su estudio eficientemente
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Solución con programación dinámica (bottom-up)
int mochilaDP(int horas[], int beneficios[], int n, int tiempoDisponible) {
    int dp[n + 1][tiempoDisponible + 1];

    for (int i = 0; i <= n; i++) {
        for (int t = 0; t <= tiempoDisponible; t++) {
            if (i == 0 || t == 0)
                dp[i][t] = 0;
            else if (horas[i - 1] <= t)
                dp[i][t] = max(
                    beneficios[i - 1] + dp[i - 1][t - horas[i - 1]],
                    dp[i - 1][t]
                );
            else
                dp[i][t] = dp[i - 1][t];
        }
    }

    return dp[n][tiempoDisponible];
}

int main() {
    int horas[] = {3, 2, 4, 1};         // Horas necesarias para cada materia
    int beneficios[] = {8, 4, 5, 3};    // Beneficios académicos estimados
    int n = sizeof(horas) / sizeof(horas[0]);
    int tiempoDisponible = 5;

    int resultado = mochilaDP(horas, beneficios, n, tiempoDisponible);
    printf("Beneficio máximo (con PD): %d\n", resultado);
    return 0;
}