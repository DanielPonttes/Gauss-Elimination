#include <stdio.h>
#include <time.h> // Para usar a função clock()
#include <stdlib.h> // Para usar rand(), srand() e malloc()

// Função para gerar uma matriz aleatória
void generateRandomMatrix(int n, double **matrix) {
    srand(time(NULL)); // Inicializa a semente do gerador de números aleatórios
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n + 1; j++) {
            matrix[i][j] = (double)(rand() % 100) / 10.0; // Números aleatórios entre 0.0 e 9.9
        }
    }
}

void gaussianElimination(int n, double **matrix) {
    // Eliminação para frente
    for (int i = 0; i < n; i++) {
        // Pivoteamento parcial (encontrar o maior pivô)
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (matrix[k][i] > matrix[maxRow][i]) {
                maxRow = k;
            }
        }

        // Trocar linhas se necessário
        for (int k = i; k < n + 1; k++) {
            double temp = matrix[i][k];
            matrix[i][k] = matrix[maxRow][k];
            matrix[maxRow][k] = temp;
        }

        // Tornar o pivô igual a 1
        for (int k = i + 1; k < n + 1; k++) {
            matrix[i][k] /= matrix[i][i];
        }
        matrix[i][i] = 1;

        // Eliminar os elementos abaixo do pivô
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i];
            for (int k = i; k < n + 1; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    // Substituição regressiva
    double *solution = (double *)malloc(n * sizeof(double));
    for (int i = n - 1; i >= 0; i--) {
        solution[i] = matrix[i][n];
        for (int j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
    }

    // Exibir a solução (opcional para matrizes grandes)
    if (n <= 10) { // Só exibe a solução para matrizes pequenas
        printf("Solucao:\n");
        for (int i = 0; i < n; i++) {
            printf("x%d = %lf\n", i + 1, solution[i]);
        }
    }

    free(solution); // Liberar memória alocada para a solução
}

int main() {
    int sizes[] = {50, 500, 1000}; // Tamanhos das matrizes a serem testadas
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    for (int s = 0; s < num_sizes; s++) {
        int n = sizes[s];

        // Alocar memória para a matriz
        double **matrix = (double **)malloc(n * sizeof(double *));
        for (int i = 0; i < n; i++) {
            matrix[i] = (double *)malloc((n + 1) * sizeof(double));
        }

        // Gerar matriz aleatória
        generateRandomMatrix(n, matrix);

        // Iniciar a medição do tempo
        clock_t start = clock();

        // Executar a eliminação gaussiana
        gaussianElimination(n, matrix);

        // Finalizar a medição do tempo
        clock_t end = clock();

        // Calcular o tempo decorrido em segundos
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        // Exibir o tempo de execução
        printf("Tempo de execucao para matriz %dx%d: %f segundos\n", n, n, time_spent);

        // Liberar memória alocada para a matriz
        for (int i = 0; i < n; i++) {
            free(matrix[i]);
        }
        free(matrix);
    }

    return 0;
}
