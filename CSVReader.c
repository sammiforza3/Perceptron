#include <stdio.h>
#include <stdlib.h>

//voglio ritornare i campi che compongono la prima riga del dataset
char *parser()
{
    static char buff[256];

    return buf;
}

int csvOpener(char path[])
{
    printf("%s\n", "<-------------------------------->");
    char buffer[1000];
    FILE *dataset = fopen("Dataset.csv","r");
    if(dataset == NULL)
    {
        printf("error could not open file!\n");
        return -1;
    }

    printf("I was able to open the file!\n");

    //creo buffer e leggo la prima riga del dataset
    fgets(buffer, sizeof(buffer), dataset);
    printf("%s\n", buffer);

    printf("%s\n", "<-------------------------------->");
    return 1;
}

int main(void)
{
    char path[] = "Dataset.csv";
    int risDocument= csvOpener(path);

    return 0;
}

