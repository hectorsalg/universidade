#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h> /* necessario para imprimir a struct timespec de st_ctim */
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char **argv) {

    struct stat fileStat;
    if(stat(argv[1],&fileStat) < 0){
        printf("Erro ao ler informacoes do arquivo. Erro nº %d: %s\n",errno, strerror(errno));
        return 1;
    } else {
        if(argv[2]){
            FILE* output = fopen(argv[2], "w+"); // Abre ou cria o arquivo de saida

            int tam_mb =  fileStat.st_size / 1000000; // Transforma o tamanho do arquivo de bytes para Megabytes
        
            /*  converte st_atime, st_mtime para time_t para melhor visualizacao   */
            char mtime[80], atime[80];
            struct tm tm_at, tm_mt; // struct para conveter o stat.atime em horas, minuto e segundos
            time_t at, mt;
            at = fileStat.st_atime; /*st_atime is type time_t */
            mt = fileStat.st_mtime; /*st_mtime is type time_t */
            localtime_r(&at, &tm_at); /* convert to struct tm */
            localtime_r(&mt, &tm_mt); /* convert to struct tm */
            strftime(atime, sizeof atime, "%a, %d %b %Y %T", &tm_at);
            strftime(mtime, sizeof mtime, "%a, %d %b %Y %T", &tm_mt);

            fprintf(output, "Informacoes - %s\n", argv[1]);
            fprintf(output, "-------------------------\n");
            fprintf(output, "Tamanho do arquivo - %dMb\n", tam_mb);
            fprintf(output, "Numero de links - %ld\n", fileStat.st_nlink);
            fprintf(output, "ID do proprietario do arquivo - %d\n", fileStat.st_uid);
            fprintf(output, "O ID numérico do grupo (gid) para o arquivo - %d\n", fileStat.st_gid);
            fprintf(output, "Ultimo acesso - %s\n", atime);
            fprintf(output, "Ultima modificacao - %s\n\n", mtime);
        }else {
            printf("Erro ao criar arquivo de saida!\n");
            return 1;
        }
    }

    

    return 0;
}