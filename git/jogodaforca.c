#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


#define MAX_LINHAS 181
#define MAX_TAM_PALAVRA 47

int numero_de_letras, placar_partida=0, index_aleatorio, numero_de_erros=0, controle_tabuleiro=1;
char palavra[47], letra, palavra_ficticia[47];

void limpar_palavra_ficticia(int numeroltrs){
    for(int i = 0; i < numeroltrs; i++){
        palavra_ficticia[i] = '_';
    }
    palavra_ficticia[numeroltrs] = '\0';  // Adiciona o terminador de string
}

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
    
    default:
        break;
    }
    for(int i = 0; i < num; i++){
        printf("%c ", palavra_ficticia[i]);
    }
    printf("\n");
}

void digite_letra() {
    printf("\nDigite uma letra: ");
    scanf(" %c", &letra);  // Note o espaço antes de %c para ignorar espaços em branco
}

void deixar_maiuscula(char *pal) {
    for(int numero = 0; numero < strlen(pal); numero++){
        pal[numero] = toupper(pal[numero]);
    }
}

void procurar(){
    int a = numero_de_letras;
    for(int i = 0; i < numero_de_letras; i++){
        if(palavra[i] == letra){
            if (palavra_ficticia[i]=='_'){
            palavra_ficticia[i] = letra;
            placar_partida++;
            controle_tabuleiro=1;
            a++;
            } else {
                printf("Letra já inserida anteriormente, tente novamente\n");
                letra = '@';
                controle_tabuleiro=0;
                a++;
            }
        } else if (a<=1){printf("Não possui essa letra, tente novamente\n");
                        numero_de_erros++;
                        controle_tabuleiro=1;}
        else{a--;}
    }
}

void gerar_palavra () {
    FILE *file;
    char palavras[MAX_LINHAS][MAX_TAM_PALAVRA];
    int num_palavras = 0, i=0;
     
    // Abrir o arquivo para leitura
    file = fopen("palavras.txt", "r");
    if (file == NULL) {
        perror("Não foi possível abrir o arquivo");
        return;
    }

    // Ler as palavras do arquivo
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

        
    // Exibir a palavra aleatória
    //printf("Palavra aleatória: %s\n", palavras[index_aleatorio]);
    strcpy(palavra, palavras[index_aleatorio]);
}

int main() {
    int controle_jogo=0;
    for(controle_jogo=0;controle_jogo<1;){
        numero_de_erros=0;
        gerar_palavra();
    
        numero_de_letras = strlen(palavra);
        printf("Numero de letras: %d", numero_de_letras);

        limpar_palavra_ficticia(numero_de_letras);
        
        mostrar_tabuleiro(numero_de_letras);

        for(placar_partida=0;placar_partida<numero_de_letras && numero_de_erros<7;){
            digite_letra();
            deixar_maiuscula(&letra);
            deixar_maiuscula(palavra);
            procurar();
            if (controle_tabuleiro==1){
                mostrar_tabuleiro(numero_de_letras);}

            printf("Numero de letras descobertas: %d\nNumero de erros: %d\n", placar_partida, numero_de_erros);
        }
        if (numero_de_erros<7){
            printf("\nParabéns você acertou a palavra!!!\n");} else {printf("\n💀Você foi enforcado(a)💀 , a palavra era '%s'\n", palavra);}

        printf("\nDigite 0 para continuar jogando ou 1 para parar:");
        scanf("%d",&controle_jogo);
    }

    return 0;
}
