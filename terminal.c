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

int* getSegmet(int entry, int size);
int* createSegmet(int entry, int size);

void reads();
void writes();
void writecrazy();
int checkIfFileExists();
void append();
void clear();
void help();
void dt();
void exits();
void startscreen();
void removes();
void renames();
void edit();
void cdir();
void copy();
void cknow();
void lknow();
void ccount();
void gcd();
void lcm();
void tconv();
int execFork();

int main(){

    clear();

    char a[100];

    printf("Projeto Terminal\nVictor Leta\n\n");

    dt();
    printf("Bem-vindo ao Projeto Terminal de Victor Leta\n");
    printf("Escreva \"help\" para mais informacoes.\n\n");

    while(1){

        printf("\n>>> ");
        fflush(stdin);
        scanf("%s", a);

        if(strcmp(a, "read") == 0){
            reads();
        }
        else if(strcmp(a, "writecrazy") == 0){
            writecrazy();
        }
        else if(strcmp(a, "crazy") == 0){
            fork();
        }
        else if(strcmp(a, "write") == 0){
            writes();
        }
        else if(strcmp(a, "append") == 0){
            append();
        }
        else if(strcmp(a, "clr") == 0){
            clear();
        }
        else if(strcmp(a, "help") == 0){
            help();
        }
        else if(strcmp(a, "dt") == 0){
            dt();
        }
        else if(strcmp(a, "stscr") == 0){
            startscreen();
        }
        else if(strcmp(a, "remove") == 0){
            removes();
        }
        else if(strcmp(a, "rename") == 0){
            renames();
        }
        else if(strcmp(a, "edit") == 0){
            edit();
        }
        else if(strcmp(a, "cdir") == 0){
            cdir();
        }
        else if(strcmp(a, "copy") == 0){
            copy();
        }
        else if(strcmp(a, "exit") == 0){
            exits();
        }
        else{
            printf("Coloque apenas as opcoes citadas no \"help\"!");
        }

    }
}

void reads(){
    char a[100];

    printf("Use .txt ou outra extensao para realizar leitura.\nEx: hello.txt\n\n");

    FILE *p;

    printf("Coloque o nome do arquivo a ser lido: ");
    scanf("%s", a);

    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    
    char c;

    p = fopen(a, "r");

    if(p == NULL){
        printf("\nErro! Arquivo inexistente!\n");
       
        printf("\n");

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

                printf("\nEscrita realizada com sucesso!");
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

void writecrazy(){
    char a[100];
    int check;
    int status;

    printf("Use .txt ou qualquer outra extensao para leitura.\nEx: hello.txt\n\n");

    FILE *p;

    pid_t pid, wpid;

    pid = fork();

    if(pid == 0){
        printf("Coloque o nome do arquivo a ser escrito pelo processo filho: ");
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

                    printf("\nEscrita realizada com sucesso pelo processo filho!");
                    exits(); //fecha o processo filho
            }
            else{
                printf("\nModo de Escrita finalizado!");
                exit(1);
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
    else if(pid < 0){
        perror("lsh");
    }
    else{

        do {
        wpid = waitpid(pid, &status, WUNTRACED);
        printf("Coloque o nome do arquivo a ser escrito pelo processo pai: ");
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

                    printf("\nEscrita realizada com sucesso!");
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

            printf("\nEscrita realizada com sucesso pelo processo pai!");
        }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        
    }
    
    
}

void append(){

    char a[100];
    int check;

    printf("Use .txt ou qualquer outra extensao para leitura.\nEx: hello.txt\n\n");

    FILE *p;
    
    printf("Coloque o nome do arquivo para realizar a operaçao de Append: ");
    scanf("%s", a);

    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");

    if(checkIfFileExists(a) == 0){
        printf("\nDeseja criar um novo arquivo?(Digite 1 para SIM)\n");
        scanf("%d", &check);

        if(check == 1){
            p = fopen(a, "a");

            printf("Digite ~ para sair do modo de escrita!\n");
            printf("Comeco da escrita: \n");

            char ch = ' ';

            while(ch != '~'){
                ch = getchar();

                if(ch != '~'){
                    fputc(ch, p);
                }
            }
            printf("\nEscrita realizada com sucesso!");
            fclose(p);
        }
        else{
            printf("\nModo de Escrita finalizado!");
        }

        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"); 
        
        }
        else if(checkIfFileExists(a) == 1){
            p = fopen(a, "a");

            printf("Digite ~ para sair do modo de escrita!\n");
            printf("Comeco da escrita: \n");

            char ch = ' ';

            while(ch != '~'){
                ch = getchar();

                if(ch != '~'){
                    fputc(ch, p);
                }
            }
            printf("\nEscrita realizada com sucesso!");
            fclose(p);  
        }
        else{
           printf("\nModo de Escrita finalizado!");
        }
}

void clear() {
  printf("\033[H\033[J");
}

void dt(){
    time_t tt = time(NULL);
    printf("%s", ctime(&tt));
}

void startscreen(){
    system("cls");
    printf("Projeto Terminal\nVictor Leta\n\n");

    dt();
    printf("Bem-vindo ao Projeto Terminal de Victor Leta\n");
    printf("Escreva \"help\" para mais informacoes.\n\n");
}

void removes(){
    char a[100];
    int m;

    printf("Coloque o nome do arquivo a ser removido: ");
    scanf("%s", a);

    m = remove(a);

    if(checkIfFileExists(a) == 1){
        printf("Arquivo removido com sucesso!");
    }
    else{
        printf("Erro na remocao do arquivo, por favor checar se o arquivo existe no diretorio\n");
    }
}

void renames(){
    char a[100], b[100];
    int m;

    printf("Digite o nome do arquivo que deseja renomear: ");
    scanf("%s", a);

    printf("\nDigite o novo nome: ");
    scanf("%s", b);

    m = rename(a, b);

    if(m == 0){
        printf("Arquivo renomeado com sucesso!\n");
    }
    else{
        printf("Erro ao tentar renomear o arquivo, por favor, cheque a existencia do arquivo no diretorio\n");
    }
}

void edit(){
    char a[100];

    printf("CUIDADO! Feche o editor para usar o Terminal\n");
    printf("Use .txt ou qualquer outra extensao para copiar.\nEx: hello.txt\n\n");
    printf("Digite o nome do arquivo a ser editado: ");
    scanf("%s", a);

    system(a);

    printf("Programa editor aberto com sucesso!\n");
}

void cdir(){
    char a[100];

    printf("Digite o diretorio desejado: ");
    system("dir");
}

void copy(){

    char a[100], b[100];
    int c;
    FILE *p, *q;

    printf("Use .txt ou qualquer outra extensao para copiar.\nEx: hello.txt\n\n");
    printf("Digite o nome de um arquivo existente: ");
    scanf("%s", a);

    if(checkIfFileExists(a) == 0){
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
    printf("\n");
    printf("write  >>> Escrever/Criar arquivo\n");
    printf("read   >>> Ler do arquivo\n");
    printf("append >>> Adicionar(append) no arquivo\n");
    printf("remove >>> Remover um arquivo\n");
    printf("rename >>> Renomear arquivo\n");
    printf("clr    >>> Limpa a tela\n");
    printf("dt     >>> Mostra data e hora\n");
    printf("stscr  >>> Mostra a tela inicial\n");
    printf("edit   >>> Edita um arquivo\n");
    printf("cdir   >>> Visualiza o diretorio e seus arquivos\n");
    printf("copy   >>> Copia um arquivo para um novo arquivo ou adiciona a arquivo existente\n");
    printf("crazy   >>> Criar uma loucura de processos a cada comando, sem ordem, TOME CUIDADO AO USAR!!!\n");
    printf("writecrazy  >>> Abre um novo processo de escrita filho do terminal para escrever 2 arquivos seguidos.\n");
   /* printf("cknow  >>> Visualiza quantas vezes um caractere foi repetido no arquivo\n");
    printf("lknow  >>> Visualiza quantas linhas existem no arquivo\n");
    printf("gcd    >>> Acha o maior divisor comum de numeros\n");
    printf("lcm    >>> Acha o menor múltiplo comum de numeros\n");
    printf("tconv  >>> Converte temperatura\n"); */

    printf("exit   >>> Sai do programa\n");
    printf("\n");
}

void exits(){
    printf("Projeto Terminal finalizado com sucesso!\n");
    exit(1);
}