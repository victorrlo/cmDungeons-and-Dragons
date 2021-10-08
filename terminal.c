//Desenvolvimento de um Terminal em C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>


void moveDir();
void cdirs();
void reads();
void writes();
void copy();
int checkIfFileExists();
void clear();
void help();
void exits();
void exitSpecial();

void green();
void greenBold();
void red();
void redBold();
void yellow();
void yellowBold();
void blueBold();
void whiteBold();
void purpleBold();
void purple();

void executarFork();

//funções que funcionavam no windows(tive que trocar por causa do fork para o ubuntu)
void dt();
void append();
void edit();
void renames();
void removes();



int main(){

    clear();

    char a[100];

    purpleBold();
    printf("Projeto Terminal\nVictor Leta\n\n");
    printf("Bem-vindo ao Projeto Terminal de Victor Leta\n");
    printf("Escreva \"help\" para mais informacoes.\n\n");

    while(1){

        green();

        cdirs();
        fflush(stdin);
        scanf("%s", a);

        if(strcmp(a, "read") == 0){
            reads();
        }
        else if(strcmp(a, "fork") == 0){
            executarFork();
        }
        else if(strcmp(a, "cd") == 0){
            moveDir();
        }
        else if(strcmp(a, "write") == 0){
            greenBold();
            writes();
        }
        else if(strcmp(a, "clr") == 0){
            clear();
        }
        else if(strcmp(a, "help") == 0){
            help();
        }
        else if(strcmp(a, "cd") == 0){
            moveDir();
        }
        else if(strcmp(a, "copy") == 0){
            copy();
        }
        else if(strcmp(a, "exit") == 0){
            exits();
        }
        else{
            redBold();
            printf("\nColoque apenas as opcoes citadas no \"help\"!\n");
        }

    }
}

void executarFork(){

    purple();
    char a[100];
    int b = 777;

    pid_t pid, wpid;
    int status;

    printf("Valor de b atual:%d", b);

    pid = fork();

    if(pid == 0){
        blueBold();
        printf("\nOi! Eu sou o filho executando!!\n");
        b+= 89;
        printf("\nValor de b do filho:%d\n", b);
        exitSpecial();
    }
    else if(pid < 0){
        redBold();
        printf("\nERRO! O pai e esteril!!!\n");
    }
    else{
        do{
            wpid = waitpid(pid, &status, WUNTRACED);
        }while(!WIFEXITED(status) && !WIFSIGNALED(status));

        yellowBold();
        printf("\nOlá! Eu sou o pai executando!\n");
        b -= 192;
        printf("\nValor de b do pai:%d\n", b);
    }
}

void purple(){
    printf("\033[0;35m");
}

void purpleBold(){
    printf("\033[1;35m");
}

void whiteBold(){
    printf("\033[1;37m");
}

void blueBold(){
    printf("\033[1;34m");
}

void green(){
    printf("\033[0;32m");
}

void greenBold(){
    printf("\033[1;32m");
}

void red(){
    printf("\033[0;31m");
}

void redBold(){
    printf("\033[1;31m");
}

void yellow(){
    printf("\033[0;33m");
}

void yellowBold(){
    printf("\033[1;33m");
}

void cdirs(){
    int sizeDir = 1024;
    char currentDir[sizeDir];

    getcwd(currentDir, sizeof(currentDir));
    printf("%s>>> ", currentDir);
    
}

void moveDir(){

    char a[100];
    printf("\nDigite o diretorio desejado:");
    scanf("%s", a);

    if(chdir(a) != 0){
        redBold();
        printf("\nErro! Diretorio nao encontrado!\n");
    }
    else{
        chdir(a);
    }

}

void reads(){

    whiteBold();

    char a[100];

    printf("Use .txt ou outra extensao para realizar leitura.\nEx: hello.txt\n\n");

    FILE *p;

    printf("Coloque o nome do arquivo a ser lido: ");
    scanf("%s", a);

    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    
    char c;

    p = fopen(a, "r");

    if(p == NULL){
        redBold();
        printf("\nErro! Arquivo inexistente!\n");
       
        printf("\n");
        whiteBold();
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); 
        //como colocar um timer aqui?
        
        
    }
    else{

        c = fgetc(p); //gets the next character

        //printf("\n");

        while(c != EOF){
            printf("%c", c);
            c = fgetc(p);
        }
   
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

        fclose(p);

        printf("\n\nArquivo lido com sucesso!\n");

    }

}

int checkIfFileExists(const char *fname){
    
    FILE *p;

    if(access(fname, F_OK) == 0){
        return 1;
    }
    else{
        return 0;
    }

    
}

void writes(){

    char a[100];
    int check;

    printf("Use .txt ou qualquer outra extensao para leitura.\nEx: hello.txt\n\n");

    FILE *p;

    printf("Coloque o nome do arquivo a ser escrito: ");
    scanf("%s", a);

    if(checkIfFileExists(a) == 1){
        
        printf("\nArquivo ja existe! Deseja sobrescrever?(Todo o conteudo existente anteriormente sera apagado!!!)\nEscreva 1 para SIM:\n");
        scanf("%d", &check);

        if(check == 1){
                p = fopen(a, "w");

                fflush(stdin);

                printf("Digite ~ para sair do modo de escrita!\n");
                printf("Comeco da escrita: \n");

                char ch = ' '; 

                while(ch != '~'){
                    ch = getchar();

                    if(ch != '~'){
                        fputc(ch , p);
                    }
                }
                fclose(p);

                printf("\nEscrita realizada com sucesso!\n");
        }
        else{
            printf("\nModo de Escrita finalizado!");
        }

    }
    else if(checkIfFileExists(a) == 0){
        p = fopen(a, "w");

        fflush(stdin);

        printf("Digite ~ para sair do modo de escrita!\n");
        printf("Comeco da escrita: \n");

        char ch = ' '; 

        while(ch != '~'){
            ch = getchar();

            if(ch != '~'){
                fputc(ch , p);
            }
        }
        fclose(p);

        printf("\nEscrita realizada com sucesso!");
    }
    
}

void clear() {
  printf("\033[H\033[J");
}

void copy(){

    blueBold();

    char a[100], b[100];
    int c;
    FILE *p, *q;

    printf("Use .txt ou qualquer outra extensao para copiar.\nEx: hello.txt\n\n");
    printf("Digite o nome de um arquivo existente: ");
    scanf("%s", a);

    if(checkIfFileExists(a) == 0){
        redBold();
        printf("\nErro! Arquivo inexistente!\n");
       
        printf("\n");
    }
    else if(checkIfFileExists(a) == 1){
        printf("\nDigite o nome do novo arquivo de copia: ");
        scanf("%s", b);

        p = fopen(a, "r");
        q = fopen(b, "a");

        c = fgetc(p);

        while(c != EOF){
            fputc(c, q);
            c = fgetc(p);
        }

        fclose(p);
        fclose(q);

        printf("Copia realizada com sucesso!\n");
    }
}




void help(){

    yellowBold();
    printf("\n");
    printf("fork     >>> Demonstra graficamente o comportamento de um fork manipulando uma unica variavel\n");
    printf("cd     >>> Encaminhar a outro diretorio\n");
    printf("write  >>> Escrever/Criar arquivo\n");
    printf("read   >>> Ler do arquivo\n");
    //printf("append >>> Adicionar(append) no arquivo\n");
    //printf("remove >>> Remover um arquivo\n");
    //printf("rename >>> Renomear arquivo\n");
    printf("clr    >>> Limpa a tela\n");
    //printf("dt     >>> Mostra data e hora\n");
    //printf("stscr  >>> Mostra a tela inicial\n");
    //printf("edit   >>> Edita um arquivo\n");
    //printf("cdir   >>> Visualiza o diretorio e seus arquivos\n");
    //printf("copy   >>> Copia um arquivo para um novo arquivo ou adiciona a arquivo existente\n");
   /* printf("cknow  >>> Visualiza quantas vezes um caractere foi repetido no arquivo\n");
    printf("lknow  >>> Visualiza quantas linhas existem no arquivo\n");
    printf("gcd    >>> Acha o maior divisor comum de numeros\n");
    printf("lcm    >>> Acha o menor múltiplo comum de numeros\n");
    printf("tconv  >>> Converte temperatura\n"); */

    printf("exit   >>> Sai do programa\n");
    printf("\n");
    green();
}

void exits(){
    greenBold();
    printf("Projeto Terminal finalizado com sucesso!\n");
    exit(1);
}

void exitSpecial(){
    purpleBold();
    printf("Processo do Filho terminado!\n");
    exit(1);
}