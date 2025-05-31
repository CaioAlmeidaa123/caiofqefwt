 #include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char titulo[100];
    char autor[100];
    char editora[100];
    int anoPublicacao;
    int qtdPaginas;
} Livro;

// Função para preencher o vetor
void preencherVetor(Livro vetor[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Livro %d:\n", i + 1);
        printf("Título: ");
        fgets(vetor[i].titulo, 100, stdin);
        vetor[i].titulo[strcspn(vetor[i].titulo, "\n")] = '\0'; // remover \n
        printf("Autor: ");
        fgets(vetor[i].autor, 100, stdin);
        vetor[i].autor[strcspn(vetor[i].autor, "\n")] = '\0';
        printf("Editora: ");
        fgets(vetor[i].editora, 100, stdin);
        vetor[i].editora[strcspn(vetor[i].editora, "\n")] = '\0';
        printf("Ano de Publicação: ");
        scanf("%d", &vetor[i].anoPublicacao);
        printf("Quantidade de Páginas: ");
        scanf("%d", &vetor[i].qtdPaginas);
        getchar(); 
        printf("\n");
    }
}

// Função para imprimir o vetor
void imprimirVetor(Livro vetor[], int n) {
    printf("Lista de Livros:\n");
    for (int i = 0; i < n; i++) {
        printf("Livro %d: %s | %s | %s | %d | %d páginas\n",
            i + 1,
            vetor[i].titulo,
            vetor[i].autor,
            vetor[i].editora,
            vetor[i].anoPublicacao,
            vetor[i].qtdPaginas);
    }
}

// Busca linear por título
int buscarPorTitulo(Livro vetor[], int n, char titulo[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(vetor[i].titulo, titulo) == 0) {
            return i;
        }
    }
    return -1;
}

// Bubble Sort para ordenar por título
void ordenarPorTitulo(Livro vetor[], int n) {
    Livro temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(vetor[j].titulo, vetor[j + 1].titulo) > 0) {
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

// Busca binária por título
int buscaBinariaPorTitulo(Livro vetor[], int n, char titulo[]) {
    int inicio = 0, fim = n - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(vetor[meio].titulo, titulo);
        if (cmp == 0) {
            return meio;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}


// Função principal
int main() {
    Livro livros[MAX];
    int n, opcao, pos;
    char tituloBusca[100];

    printf("Quantos livros deseja cadastrar? ");
    scanf("%d", &n);
    getchar(); 

    preencherVetor(livros, n);

    printf("\n--- Livros cadastrados ---\n");
    imprimirVetor(livros, n);

    printf("\nDigite o título do livro para busca linear: ");
    fgets(tituloBusca, 100, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';
    pos = buscarPorTitulo(livros, n, tituloBusca);
    if (pos != -1) {
        printf("Livro encontrado na posição %d\n", pos);
    } else {
        printf("Livro não encontrado\n");
    }

    printf("\nOrdenando livros por título...\n");
    ordenarPorTitulo(livros, n);
    imprimirVetor(livros, n);

    printf("\nDigite o título do livro para busca binária: ");
    fgets(tituloBusca, 100, stdin);
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';
    pos = buscaBinariaPorTitulo(livros, n, tituloBusca);
    if (pos != -1) {
        printf("Livro encontrado na posição %d\n", pos);
    } else {
        printf("Livro não encontrado\n");
    }

    return 0;
}

