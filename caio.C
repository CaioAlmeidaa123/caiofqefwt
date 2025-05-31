#include <stdio.h>

int contarVogais(char frase[]) {
    int i, cont = 0;
    for (i = 0; frase[i] != '\0'; i++) {
        char c = frase[i];
        if (c == 'a' || c == 'A' ||
            c == 'e' || c == 'E' ||
            c == 'i' || c == 'I' ||
            c == 'o' || c == 'O' ||
            c == 'u' || c == 'U') {
            cont++;
        }
    }
    return cont;
}

void capitalizar(char frase[]) {
    int i = 0;

    
    if (frase[i] >= 'a' && frase[i] <= 'z') {
        frase[i] = frase[i] - 32;
    }

    
    for (i = 1; frase[i] != '\0'; i++) {
        if (frase[i - 1] == ' ' && frase[i] >= 'a' && frase[i] <= 'z') {
            frase[i] = frase[i] - 32;
        }
    }
}

int main() {
    char frase[200];

    printf("Digite uma frase: ");
    fgets(frase, 200, stdin); 

    printf("\nFrase digitada: %s", frase);

    int vogais = contarVogais(frase);
    printf("Número de vogais: %d\n", vogais);

    capitalizar(frase);
    printf("Frase com iniciais maiúsculas: %s", frase);

    return 0;
}

