#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "user.h"
#include "emails.h"
#include "names.h"

int user_counter(char **array) {
  size_t user_count=0;
  int i;
  for(i=0;array[i]!=NULL;i++) {
    user_count++;
  }
  return user_count;
}

void add_user(char name[],char ***names,char email[],char ***emails,size_t* size) {
  if(user_counter(*emails) <= *size) {
    *size += 16;
    *names = realloc(*names,*size);
    *emails = realloc(*emails,*size);
  }
  
  add_name(name, names);
  
  add_email(email, emails);
}

void rn_array(char ***arrays,int i) {
  if((*arrays)[i] != 0) {
    free((*arrays)[i]);
    (*arrays)[i] = malloc(4 * sizeof(char));
    strcpy((*arrays)[i], "***");
  }
}

void rn_user(char*** names,char*** emails,int i) {
  rn_array(names,i-1);
  rn_array(emails,i-1);
}

void all_users(char **names, char **emails)
{
    size_t i;

    printf("\n_________________________________\n");
    for (i = 0; names[i] != NULL && emails[i] != NULL; i++) {
        printf("| %zu | %s | %s |\n", i + 1, names[i], emails[i]);
    }
    printf("_________________________________\n");
}

void update_array(const char array[],const int i, char***arrays) {
  
  if((*arrays)[i] != 0) {
    free((*arrays)[i]);
    (*arrays)[i] = malloc(sizeof(char) *(strlen(array)+1) );
    strcpy((*arrays)[i], array);
  }
}

void update_user(char ***names,char ***emails,int i) {
  char choice[256];
  printf("Enter new Name or for old name (O) : ");
  
  //name
  scanf(" %255s", choice);
  if (strcmp(choice, "O") != 0) {
    update_array(choice,i-1,names);
  }
  printf("\nEnter new Email or for old Email (O)");
  //email
  scanf(" %255s", choice);
  if(strcmp(choice, "O") != 0) {
    update_array(choice,i-1,emails);
  }
}