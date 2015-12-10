#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void binarySearch();
char** readDictionary(char fileName[]);
void testPrint(char** words);
void freeGrid(char** gridArray, int rows);
void generalLoop(int numCases);
void printFound();

#define DICTIONARY_FILE "dictionary.txt"

const int minSIZE = 4;
const int maxSIZE = 19;

int dictionarySize;

const int DXsize = 8;
const int DX[] = {-1,-1,-1,0,0,1,1,1};
const int DY[] = {-1,0,1,-1,1,-1,0,1};





int main(){

    int cases;


    char** dictionary = readDictionary(DICTIONARY_FILE);

    //printf("DICTIONARY SIZE: %d\n", dictionarySize);
    //testPrint(dictionary);
    //printf("Test Done\n");

    scanf("%d", &cases);
    //printf("%d\n", cases);

    generalLoop(cases);




    return 0;

}

char ** readDictionary(char fileName[]){

    int i;
    FILE* dict = fopen(fileName, "r");

    fscanf(dict,"%d",&dictionarySize);

    char** words = malloc(sizeof(char*)*dictionarySize);

    for(i=0;i<dictionarySize;i++){
        words[i] = malloc(sizeof(char)*maxSIZE+1);
        fscanf(dict,"%s",words[i]);
    }

    fclose(dict);

    return words;

}

void testPrint(char** words){

    int i;

    for(i=0;i<dictionarySize;i++){
        printf("Word %d: %s\n", i, words[i]);
    }

}

void generalLoop(int numCases){

    int i,j;
    int caseX;
    int caseY;


    for(i=0;i<numCases;i++){
        scanf("%d %d", &caseX, &caseY);
       // printf("Case# %d: %d %d\n", i, caseX, caseY);
        char** gridArray = malloc(sizeof(char*)*caseX);
        for(j=0;j<caseX;j++){
            gridArray[j] = malloc(sizeof(char)*(caseY+1));
            scanf("%s", gridArray[j]);
            //printf("%s\n", gridArray[j]);
        }

        //void printFound();
        freeGrid(gridArray, caseX);

    }

}

void freeGrid(char** gridArray, int rows){

    int i;

    for(i=0;i<rows;i++){
        free(gridArray[i]);
        //printf("free %d\n", rows);
    }
    free(gridArray);

}