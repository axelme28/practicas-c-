#include <stdio.h>

int main(void) {
	/* Declaramos un array de enteros. */
	int vector[4] = { 30, 20, 4, 10 };

	/* Declaramos otras variables que
	 * nos serviran para iterar. */
	int i, j, k, aux;

	/* Ordenamos el array de enteros. */
	for (k = 0; k <= 2; k++) {
		i = k;
		aux = vector[k];
		for (j = k + 1; j <= 3; j++) {
			if (vector[j] < aux) {
				i = j;
				aux = vector[i];
			}
		}
		vector[i] = vector[k];
		vector[k] = aux;
	}

	/* Imprimimos el array de enteros. */
	for (i = 0; i <= 3; i++) {
		printf("%d ", vector[i]);
	}
}

