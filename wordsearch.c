#include <stdio.h>
#include <stdlib.h>

void binarySearch();
char** readDictionary(char fileName[]);
void testPrint(char** words);

#define DICTIONARY_FILE "dictionary.txt"

const int minSIZE = 4;
const int maxSIZE = 19;

int dictionarySize;





int main(){


    char** dictionary = readDictionary(DICTIONARY_FILE);

    printf("DICTIONARY SIZE: %d\n", dictionarySize);
    //testPrint(dictionary);



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