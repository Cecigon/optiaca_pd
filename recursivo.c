// Basado en la implementación recursiva de BaseMax [5]
// Adaptado para seleccionar materias según horas disponibles y beneficio académico
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función recursiva sin programación dinámica
int mochilaRecursiva(int horas[], int beneficios[], int n, int tiempoDisponible) {
    if (n == 0 || tiempoDisponible == 0)
        return 0;

    if (horas[n - 1] > tiempoDisponible)
        return mochilaRecursiva(horas, beneficios, n - 1, tiempoDisponible);

    // Elegir entre estudiar o no estudiar la materia n-ésima
    return max(
        beneficios[n - 1] + mochilaRecursiva(horas, beneficios, n - 1, tiempoDisponible - horas[n - 1]),
        mochilaRecursiva(horas, beneficios, n - 1, tiempoDisponible)
    );
}

int main() {
    int horas[] = {3, 2, 4, 1};         // Tiempo requerido por materia
    int beneficios[] = {8, 4, 5, 3};    // Utilidad académica estimada
    int n = sizeof(horas) / sizeof(horas[0]);
    int tiempoDisponible = 5;

    int resultado = mochilaRecursiva(horas, beneficios, n, tiempoDisponible);
    printf("Beneficio máximo (sin PD): %d\n", resultado);
    return 0;
}