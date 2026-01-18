#include <stdio.h>
#include <stdlib.h>

//voglio ritornare i campi che compongono la prima riga del dataset
//il parser riceve il buffer, che è ciò che il documento contiene
//non proprio! la funzione usata restituisce solo la prima riga!
//per adesso quindi parsiamo solo la prima riga, che sarebbe la lista delle nostre features
//per testare facciamo che il parser ritorna solo la prima stringa
void parser(char *data, size_t sizeData, char divider)
{
    printf("printing the data in function: %s\n", data);

    
    char features[20][20];
    size_t sizeSingleEntry = sizeof(features[0])/sizeof(features[0][0]);
    size_t numbersOfEntry = sizeof(features)/sizeof(features[0]);

    //riempio la il char di caratteri di terminazione
    for(int i = 0; i<numbersOfEntry; i++)
    {
        for(int c=0;c<sizeSingleEntry;c++)
        {
            features[i][c] = '\0';
        }
    }


    //costruisco un while per riavviare il while interno ogni volta che trova un divider
    //mi serve un terzo contatore per la stringa del dataset!
    printf("%s\n", data);
    int entry = 0;
    int i = 0;
    
    while(entry<numbersOfEntry)
    {

        int posEntry=0;
        //scansiono il testo fino a raggiunere il divider
        while(posEntry<sizeSingleEntry)
        {
            if(data[i]!=divider && i<sizeData)
            {
                features[entry][posEntry] = data[i];
                printf("%c\n", data[i]);
                posEntry ++; 
            }
            else
            {
                printf("%c\n", data[i]);
                features[entry][posEntry]= '\0';
                posEntry = sizeSingleEntry;  //forziamo al condzione di stop while
                entry++;  //passiamo alla entry successiva
                
                
            }
            i++;
            
            
        }
        
        
    }

    for(int i=0; i < numbersOfEntry; i++ )
    {
        printf("%s\n", features[i]);
    }
    

    //il ciclo cicla tutta la prima riga
        //comincia a inserire tutte le lettere in un vettore
        //quando incontra una virgola cessa di inserire roba
            //come? come fermo il ciclo? non devo fermare il ciclo
            //devo dirgli di copiare il vettore temporaneo nella cella del vettore di vettori
        //salva il vettore come cella di un vettore di vettori
    // for(int i = 0; data[i] != '\0'; i++)
    // {
        
    //     if(data[i]!=divider)
    //     {
    //         printf("sto scrivendo il termine: %c\n",data[i]);
    //         features[c][i]=data[i];
    //     }
    //     else
    //     {
    //         c=c+1;
    //     }
    // }
    

}

int csvOpener(char path[])
{
    printf("%s\n", "<-------------------------------->");
    char buffer[10000];
    FILE *dataset = fopen("Dataset.csv","r");
    if(dataset == NULL)
    {
        printf("error could not open file!\n");
        return -1;
    }

    printf("I was able to open the file!\n");

    //creo buffer e leggo la prima riga del dataset
    fgets(buffer, sizeof(buffer), dataset);
    //printf("%s\n", buffer);

    printf("%s\n", "opening the parse");


    //ottengo la prima riga del dataset
    char features[50];
    char divider = ',';
    size_t sizeData = sizeof(buffer)/sizeof(buffer[0]);
    parser(buffer,sizeData, divider);

    printf("%s\n", "<-------------------------------->");
    return 1;
}

int main(void)
{
    char path[] = "Dataset.csv";
    int risDocument= csvOpener(path);

    return 0;
}

