#include <stdio.h>      // Biblioteca padrão para funções de entrada e saída, como printf e scanf
#include <stdlib.h>     // Biblioteca padrão para funções de utilidade geral, como malloc, rand, e srand
#include <string.h>     // Biblioteca para manipulação de strings, como strlen e strcpy
#include <ctype.h>      // Biblioteca para manipulação de caracteres, como toupper
#include <time.h>       // Biblioteca para manipulação de tempo, como time

#define MAX_LINHAS 181         // Define o número máximo de linhas para o arquivo de palavras
#define MAX_TAM_PALAVRA 47     // Define o tamanho máximo de uma palavra

// Variáveis globais utilizadas no jogo
int numero_de_letras, placar_partida = 0, index_aleatorio, numero_de_erros = 0, controle_tabuleiro = 1;
char palavra[47], letra, palavra_ficticia[47];  // Arrays para armazenar a palavra, uma letra, e a palavra fictícia (escondida)


// Função para inicializar a palavra fictícia com underscores (_)
void limpar_palavra_ficticia(int numeroltrs){
    for(int i = 0; i < numeroltrs; i++){
        palavra_ficticia[i] = '_';  // Substitui cada letra por um underscore
    }
    palavra_ficticia[numeroltrs] = '\0';  // Adiciona o terminador de string
}

// Função para mostrar o estado atual do tabuleiro com base no número de erros
void mostrar_tabuleiro(int num){
    switch (numero_de_erros)
    {
    case 0: printf("\n_______\n|     |\n|\n|\n|\n|\n|\n|\n|  ");       
        break;
    case 1: printf("\n_______\n|     |\n|     O\n|\n|\n|\n|\n|\n|  ");
        break;
    case 2: printf("\n_______\n|     |\n|     O\n|     |\n|\n|\n|\n|  ");
        break;
    case 3: printf("\n_______\n|     |\n|     O\n|     |\\ \n|\n|\n|\n|  ");
        break;
    case 4: printf("\n_______\n|     |\n|     O\n|    /|\\ \n|\n|\n|\n|  ");
        break;
    case 5: printf("\n_______\n|     |\n|     O\n|    /|\\ \n|     |\n|\n|\n|  ");
        break;
    case 6: printf("\n_______\n|     |\n|     O\n|    /|\\ \n|     |\n|    /\n|\n|  ");
        break;
    case 7: printf("\n_______\n|     |\n|     O\n|    /|\\ \n|     |\n|    / \\ \n|\n|  ");
        break;
    default:
        break;
    }
    // Exibe a palavra fictícia (com letras acertadas e underscores)
    for(int i = 0; i < num; i++){
        printf("%c ", palavra_ficticia[i]);
    }
    printf("\n");
}

// Função para solicitar ao usuário que digite uma letra
void digite_letra() {
    printf("\nDigite uma letra: ");
    scanf(" %c", &letra);  // O espaço antes de %c ignora espaços em branco
}

// Função para converter a palavra para maiúsculas
void deixar_maiuscula(char *pal) {
    for(int numero = 0; numero < strlen(pal); numero++){
        pal[numero] = toupper(pal[numero]);  // Converte cada caractere da palavra para maiúscula
    }
}

// Função para procurar a letra digitada na palavra
void procurar(){
    int a = numero_de_letras;
    for(int i = 0; i < numero_de_letras; i++){
        if(palavra[i] == letra){  // Se a letra estiver na palavra
            if (palavra_ficticia[i]=='_'){  // Se a letra ainda não foi adivinhada
                palavra_ficticia[i] = letra;  // Atualiza a palavra fictícia com a letra correta
                placar_partida++;  // Incrementa o placar
                controle_tabuleiro = 1;
                a++;
            } else {
                printf("Letra já inserida anteriormente, tente novamente\n");
                letra = '@';  // Letra já usada
                controle_tabuleiro = 0;
                a++;
            }
        } else if (a<=1){  // Se a letra não estiver na palavra
            printf("Não possui essa letra, tente novamente\n");
            numero_de_erros++;  // Incrementa o número de erros
            controle_tabuleiro = 1;
        } else {
            a--;
        }
    }
}

// Função para gerar uma palavra aleatória a partir de um arquivo de texto
void gerar_palavra () {
    FILE *file;
    char palavras[MAX_LINHAS][MAX_TAM_PALAVRA];  // Array para armazenar as palavras do arquivo
    int num_palavras = 0, i = 0;
     
    // Abrir o arquivo para leitura
    file = fopen("palavras.txt", "r");
    if (file == NULL) {
        perror("Não foi possível abrir o arquivo");
        return;
    }

    // Ler as palavras do arquivo e armazená-las no array
    while (fgets(palavras[num_palavras], MAX_TAM_PALAVRA, file) != NULL) {
        // Remover o caractere de nova linha no final de cada palavra
        palavras[num_palavras][strcspn(palavras[num_palavras], "\n")] = '\0';
        num_palavras++;
        if (num_palavras >= MAX_LINHAS) {
            printf("Número máximo de palavras excedido, numero de palavras lidos: %d\n", num_palavras);
            break;
        }
    }

    fclose(file);

    if (num_palavras == 0) {
        printf("Nenhuma palavra foi carregada.\n");
        return;
    }

    // Inicializar o gerador de números aleatórios
    srand(time(NULL));
    index_aleatorio = rand() % num_palavras;

    // Copiar a palavra aleatória selecionada para a variável 'palavra'
    strcpy(palavra, palavras[index_aleatorio]);
}

// Função principal
int main() {
    int controle_jogo = 0;  // Variável para controlar a continuidade do jogo
    for(controle_jogo = 0; controle_jogo < 1;){
        numero_de_erros = 0;
        gerar_palavra();  // Gera uma nova palavra para o jogo
    
        numero_de_letras = strlen(palavra);
        printf("Numero de letras: %d", numero_de_letras);

        limpar_palavra_ficticia(numero_de_letras);  // Inicializa a palavra fictícia com underscores
        
        mostrar_tabuleiro(numero_de_letras);  // Exibe o tabuleiro inicial

        // Loop principal do jogo, continua até que a palavra seja adivinhada ou que o jogador cometa 7 erros
        for(placar_partida = 0; placar_partida < numero_de_letras && numero_de_erros < 7;){
            digite_letra();  // Solicita uma letra ao jogador
            deixar_maiuscula(&letra);  // Converte a letra para maiúscula
            deixar_maiuscula(palavra);  // Converte a palavra para maiúscula (caso ainda não tenha sido)
            procurar();  // Verifica se a letra está na palavra
            if (controle_tabuleiro == 1){
                mostrar_tabuleiro(numero_de_letras);  // Atualiza o tabuleiro se necessário
            }

            // Exibe o status do jogo
            printf("Numero de letras descobertas: %d\nNumero de erros: %d\n", placar_partida, numero_de_erros);
        }

        // Verifica se o jogador ganhou ou perdeu
        if (numero_de_erros < 7){
            printf("\nParabéns você acertou a palavra!!!\n");
        } else {
            printf("\n💀Você foi enforcado(a)💀 , a palavra era '%s'\n", palavra);
        }

        // Pergunta ao jogador se ele quer continuar jogando
        printf("\nDigite 0 para continuar jogando ou 1 para parar:");
        scanf("%d", &controle_jogo);
    }

    return 0;
}
