package main

import (
	"fmt"
	"math/rand"
	"time"
)

// Função para gerar uma matriz aleatória
func generateRandomMatrix(n int) [][]float64 {
	rand.Seed(time.Now().UnixNano()) // Inicializa a semente do gerador de números aleatórios
	matrix := make([][]float64, n)
	for i := range matrix {
		matrix[i] = make([]float64, n+1)
		for j := range matrix[i] {
			matrix[i][j] = float64(rand.Intn(100)) / 10.0 // Números aleatórios entre 0.0 e 9.9
		}
	}
	return matrix
}

func gaussianElimination(n int, matrix [][]float64) {
	// Eliminação para frente
	for i := 0; i < n; i++ {
		// Pivoteamento parcial (encontrar o maior pivô)
		maxRow := i
		for k := i + 1; k < n; k++ {
			if matrix[k][i] > matrix[maxRow][i] {
				maxRow = k
			}
		}

		// Trocar linhas se necessário
		matrix[i], matrix[maxRow] = matrix[maxRow], matrix[i]

		// Tornar o pivô igual a 1
		for k := i + 1; k < n+1; k++ {
			matrix[i][k] /= matrix[i][i]
		}
		matrix[i][i] = 1

		// Eliminar os elementos abaixo do pivô
		for j := i + 1; j < n; j++ {
			factor := matrix[j][i]
			for k := i; k < n+1; k++ {
				matrix[j][k] -= factor * matrix[i][k]
			}
		}
	}

	// Substituição regressiva
	solution := make([]float64, n)
	for i := n - 1; i >= 0; i-- {
		solution[i] = matrix[i][n]
		for j := i + 1; j < n; j++ {
			solution[i] -= matrix[i][j] * solution[j]
		}
	}

	// Exibir a solução (opcional para matrizes grandes)
	if n <= 10 { // Só exibe a solução para matrizes pequenas
		fmt.Println("Solucao:")
		for i := 0; i < n; i++ {
			fmt.Printf("x%d = %f\n", i+1, solution[i])
		}
	}
}

func main() {
	sizes := []int{50, 500, 1000} // Tamanhos das matrizes a serem testadas

	for _, n := range sizes {
		// Gerar matriz aleatória
		matrix := generateRandomMatrix(n)

		// Iniciar a medição do tempo
		start := time.Now()

		// Executar a eliminação gaussiana
		gaussianElimination(n, matrix)

		// Finalizar a medição do tempo
		elapsed := time.Since(start)

		// Exibir o tempo de execução
		fmt.Printf("Tempo de execucao para matriz %dx%d: %s\n", n, n, elapsed)
	}
}
