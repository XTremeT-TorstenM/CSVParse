#include <stdio.h>
#include <string.h>

typedef struct {
    char ort[30];
    char zusatz[30];
    char plz[7];
    char vorwahl[9];
    char bundesland[20];
} ORT;

int main () {
    FILE *f;
    char dataset[100];
    char eingabe[30];
    char bndlnd[20];

    char *original;
    char *token;

    ORT meineOrte[20000] = {0};
    int orteindex = 0;
    int spindex = 0;

    if (( f = fopen("plz_de.csv", "r")) != NULL) {

        while (fgets(dataset, 99, f) != NULL) {

            spindex = 0;
            original = strdup(dataset);
            while ( (token = strsep(&original, ";")) != NULL ) {

                switch (spindex) {
                    case 0: { 
                        strcpy(meineOrte[orteindex].ort, token); 
                        spindex++;
                        break;
                    }
                    case 1: { 
                        strcpy(meineOrte[orteindex].zusatz, token); 
                        spindex++;
                        break;
                    }
                    case 2: { 
                        strcpy(meineOrte[orteindex].plz, token); 
                        spindex++;
                        break;
                    }
                    case 3: { 
                        strcpy(meineOrte[orteindex].vorwahl, token); 
                        spindex++;
                        break;
                    }
                    case 4: { 
                        strcpy(meineOrte[orteindex].bundesland, token); 
                        spindex++;
                        break;
                    }
                }
            }
            orteindex++;
        }
    }
    else 
        printf("FOPEN ERROR\n");

    printf("Bitte Bundesland eingeben: \n");
    scanf("%s", bndlnd);

    for (int i = 0; i < 20000; i++) {
        if ( strcmp(meineOrte[i].bundesland, bndlnd) == 0 )
            printf("\n%s - %s - %s - %s - %s\n", meineOrte[i].ort, meineOrte[i].zusatz, meineOrte[i].plz, meineOrte[i].vorwahl, meineOrte[i].bundesland);
    }

    printf("%s - %ld  ::: %s - %ld\n", meineOrte[13650].bundesland, strlen( meineOrte[13650].bundesland ), bndlnd, strlen(bndlnd));

    fclose(f);
    return 0;
}
