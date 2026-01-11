#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include "memory.h"
#include "user.h"

char names_file[] ="saves/names.txt";
char emails_file[] = "saves/emails.txt";

void init(char ***array, size_t* size, char file_name[]) {
  
  *array = malloc(*size);
  (*array)[0] = NULL;
  
  
  printf("Loading\n");
  FILE *file = fopen(file_name,"r");
  if(file == NULL) {
    printf("%s couldn't be found.\n",file_name);
    return;
  } int row;
    for(row=0; ;row++) {
        if(*size <= row+1) {
          *array = realloc(*array, *size + (16 *sizeof(char*)));
          *size +=16 *sizeof(char*);
        }
        char result[256];
        if (fgets(result, 256, file) == NULL) {
            (*array)[row] = NULL;
            fclose(file);
            printf("Loading Completed.\n");
            return;   // EOF reached
          }   
        (*array)[row] = malloc(sizeof(char *));
        strcpy((*array)[row],result);
    }
}

#include <stdio.h>
#include <string.h>

void save(char **array, const char *file_name) {
    FILE *file = fopen(file_name, "a+");

    if (file == NULL) {
        printf("\n%s couldn't be opened.\n", file_name);
        return;
    }

    printf("Saving.....\n");

    for (size_t i = 0; array[i] != NULL; i++) {
        if (strcmp(array[i], "***") != 0) {
            fprintf(file, "%s\n", array[i]);
        }
    }

    fclose(file);
    printf("Saving Completed.\n");
}