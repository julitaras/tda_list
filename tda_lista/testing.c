#include <stdio.h>
#include <stdbool.h>

#define ROJO	   "\x1b[1m\x1b[31m"
#define VERDE   "\x1b[1m\x1b[32m"

void prueba(const char* mensaje, bool ok) {
	if (ok) {
		printf("%s... ", mensaje);
		printf(VERDE);
		printf("OK\n");
	} else {
		printf("%s: ",mensaje);
		printf(ROJO);
	}
}
