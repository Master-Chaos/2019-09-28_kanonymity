#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXFILESIZE 50

typedef struct management // Struct für Management
{
    unsigned int elementcount; //Elementcounter (max Elemente)
    struct row* first; //wie next
} mangement_struct;

typedef struct row
{
    struct row *next;
    int qi1;
    char qi2[MAXFILESIZE];
    char qi3[MAXFILESIZE];
    char sensitive1[MAXFILESIZE];
    char sensitive2[MAXFILESIZE];
    char sensitive3[MAXFILESIZE];
} row_element;

/*
3; // number of QIs
3; // number of sensitive attributes
QI 1; QI 2; QI 3; Sensitive 1; Sensitive 2;
Sensitive 3;
int; string; date; string; string; string;
1701; Wesley; 2349-07-29; diplomatic mission
to Pentarus V ; afraid of lightning storms and
        Bulgallian rats; kidnapped by the Aldeans;*/


int init_management_struct(mangement_struct* row) { //init row
    if( !row ) {			// gleich wie: if( pq == NULL ) Abbruch bei Fehler bei Übergabe von pq
        return -1;
    }

    row->first =  NULL; // Bei auf Null setzen
    row->elementcount = 0;

    return 0;
}

int addNewRow(mangement_struct *managmentrow, int qi1, char *qi2, char *qi3, char *sensitive1, char *sensitive2,
              char *sensitive3)
{
    if( qi1 == NULL ) { // gleich wie: if( pq == NULL ) Abbruch bei Fehler bei Übergabe von pq
        return -1;
    }

    struct row *nextrow = NULL;
    //printf("in add\n");

    if( managmentrow == NULL ) { // gleich wie: if( pq == NULL ) Abbruch bei Fehler bei Übergabe von pq
        return -1;
    }

    nextrow = malloc( sizeof( row_element ) ); //Speicherbereich für new_element reservieren
    if( nextrow == NULL ) { //Abbruch bei Fehler bei Übergabe von pq
        return -1;
    }

    nextrow->qi1 = qi1;
    if( (strncpy((nextrow->qi2), qi2, (MAXFILESIZE -1))) == NULL)
    {
        fprintf(stderr, "ERROR 4: NULLPOINTER strncpy in add\n");
        return -1;
    }

    if( (strncpy((nextrow->qi3), qi3, (MAXFILESIZE -1))) == NULL)
    {
        fprintf(stderr, "ERROR 4: NULLPOINTER strncpy in add\n");
        return -1;
    }

    if( (strncpy((nextrow->sensitive1), sensitive1, (MAXFILESIZE -1))) == NULL)
    {
        fprintf(stderr, "ERROR 4: NULLPOINTER strncpy in add\n");
        return -1;
    }

    if( (strncpy((nextrow->sensitive2), sensitive2, (MAXFILESIZE -1))) == NULL)
    {
        fprintf(stderr, "ERROR 4: NULLPOINTER strncpy in add\n");
        return -1;
    }

    if( (strncpy((nextrow->sensitive3), sensitive3, (MAXFILESIZE -1))) == NULL)
    {
        fprintf(stderr, "ERROR 4: NULLPOINTER strncpy in add\n");
        return -1;
    }

    nextrow->next = managmentrow->first;
    managmentrow->first = nextrow;

    managmentrow->elementcount++; // Elementcounter im pg (Management) um eins erhöhen, da ein element hinzugefügt wird

    return 1;
}

void makeKanonymity(const mangement_struct *row, int k)
{
    int i;
    row_element* current = row->first; // Aktuelles Element speichern

    printf("make k = %d:\n", k);
    for(i = 0; i < row->elementcount; i++) { //

     /*   if(current->qi1 = INTAGER)
        {*/
            switch(current->qi1) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                    current->qi1 = 10;
                    break;
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                    current->qi1 = 20;
                    break;
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                case 26:
                case 27:
                case 28:
                case 29:
                case 30:
                    current->qi1 = 30;
                    break;
                case 31:
                case 32:
                case 33:
                case 34:
                case 35:
                case 36:
                case 37:
                case 38:
                case 39:
                case 40:
                    current->qi1 = 40;
                    break;
                default: current->qi1 = 0; break;
            }
       /* }*/


        current = current->next; // Und nächstes Element als aktuelles Element
    }

}

void printRow(const mangement_struct *row, int number)
{
    int i;
    int existrow = 0;
    row_element* current = row->first; // Aktuelles Element speichern

    printf("printRow with Number %d:\n", number);
    for(i = 0; i < row->elementcount; i++) { //

        if(i == number)
        {
            printf("ELEMENT [%d]: %d, %s, %s, %s, %s, %s \n", i, current->qi1, current->qi2, current->qi3, current->sensitive1, current->sensitive2, current->sensitive3);
            existrow = 1;
        }
        current = current->next; // Und nächstes Element als aktuelles Element
    }

    if (existrow <= 0)
    {
        printf("Sorry no Row\n");
    }
}

void printAllRows(const mangement_struct *row)
{
    int i;
    printf("printAllRows\n");
    row_element* current = row->first; // Aktuelles Element speichern

    for(i = 0; i < row->elementcount; i++) { // Knoten mit minimalsten Wert finden

        printf("ELEMENT [%d]: %d, %s, %s, %s, %s, %s \n", i, current->qi1, current->qi2, current->qi3, current->sensitive1, current->sensitive2, current->sensitive3);
        current = current->next; // Und nächstes Element als aktuelles Element
    }
}

int main(int argc, char **argv)
{
    mangement_struct managmentrow;
    init_management_struct(&managmentrow);

    if(argc == NULL)
    {
        fprintf(stderr, "ERROR 2: NULLPOINTER name in argc\n");
        return -1;
    }


    char *ptr;
    long convertk =  strtol(argv[2], &ptr, 10); //CONVERT TYPE FROM ARGV FROM STRING TO LONG
    int k = convertk; //CONVERT TYPE LONG TO INT
    printf("argc = %d + %d\n", argc, k);

    printf("argv[0] = %s\n", argv[0]); //Programpath
    printf("argv[1] = %s\n", argv[1]); //Befehl
    printf("argv[2] = %s\n", argv[2]); //K
    printf("argv[3] = %s\n", argv[3]); //inputfile
    printf("argv[4] = %s\n", argv[4]); //outputfile
    printf("argv[5] = %s\n", argv[5]); //debugfile
    printf("Befehl: %s\n", argv[1]); //outputfile
    printf("PATH NAME2: %s\n", argv[3]); //outputfile*/


    if((argc == 6) && (strcmp(argv[1], "–anonymize") == 0)) /* –anonymize 5 inputFile.csv outputFile.csv [debugfile.txt] */
    {
        printf("if 1\n");
        char buffer[1024] ;
        char delimiter[] = ",,;";

        FILE *fstream = fopen( argv[3],"r");

        if(fstream == NULL)   {
            printf("\n file opening failed ");
            return -1 ;
        }


        fgets(buffer, sizeof(buffer), fstream);
        printf("BUFFER: %s\n", buffer);


        char *store[MAXFILESIZE] = {NULL};
        char *token = 0;
        while (fgets(buffer, sizeof(buffer), fstream))
        {
            int i = 0;
            token = strtok(buffer, ",");
            while (token)
            {
                store[i] = token;
                //printf("Abschnitt gefunden[%d]:%s\n", i,  store[i]);
                token = strtok(NULL, ",");
                i++;
            }
            addNewRow(&managmentrow, atoi(store[4]), store[1], store[2], store[3], store[5], store[6]);
        }
        /*
             add_int(&managmentrow, 1, "ma", "dienstag", "april", "hans", "mayr");
             add_int(&managmentrow, 2, "ma", "montag", "juni", "betty", "arik");
             add_int(&managmentrow, 3, "ma", "montag", "juni", "betty", "arik");
             add_int(&managmentrow, 4, "ma", "montag", "juni", "betty", "arik");
             addNewRow(&managmentrow, 5, "ma", "montag", "juni", "betty", "arik");

              *
              * Abschnitt gefunden[0]:100001225
     Abschnitt gefunden[1]:Connor
     Abschnitt gefunden[2]:McLean
     Abschnitt gefunden[3]:Male
     Abschnitt gefunden[4]:34
     Abschnitt gefunden[5]:England
     Abschnitt gefunden[6]:White Collar
     Abschnitt gefunden[7]:15.Jul.15
     Abschnitt gefunden[8]:919.1

              */
        printRow(&managmentrow, 0);
        printRow(&managmentrow, 4013);
        makeKanonymity(&managmentrow, k);
        printRow(&managmentrow, 0);
        printRow(&managmentrow, 4013);
        //printAllRows(&managmentrow);

    }
    else
    {
        if((argc == 3) && (strcmp(argv[1], "–findk") == 0)) /* –findk inputFile.csv */
        {

            printf("test im if\n");

            return k;
        }
        else
        {
            printf("ERROR 1: Fehler bei den Argumenten\n");
            exit(1);
        }
    }





    return 0 ;
}

