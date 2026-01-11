#include <stdio.h>
#include "contactor.h"
#include "user.h"
#include <stdlib.h>

void open_email(const char *email) {
    char link[256];

    snprintf(link, sizeof(link), "mailto:%s", email);

#ifdef _WIN32
    char cmd[300];
    snprintf(cmd, sizeof(cmd), "start %s", link);
    system(cmd);
#elif __APPLE__
    char cmd[300];
    snprintf(cmd, sizeof(cmd), "open %s", link);
    system(cmd);
#else
    char cmd[307];
    snprintf(cmd, sizeof(cmd), "xdg-open %s", link);
    system(cmd);
#endif
}

void contactor(char** names, char** emails) {
    char choice;
    printf("(A) to see all users , (C) to contact , (B) to go back : ");
    scanf(" %c", &choice);
    printf("\n");
    if(choice == 'A') {
      all_users(names,emails);
      contactor(names,emails);
    } else if(choice == 'B') {
      return;
      
    } else if(choice == 'C') {
      printf("Enter the id of the required user : ");
      int id;
      scanf(" %d", &id);
      
      open_email(emails[id-1]);
      
      return;
        } else
        { contactor(names,emails); }
}
  
    