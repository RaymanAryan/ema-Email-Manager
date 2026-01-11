#include <stdio.h>
#include "memory.h"
#include "contactor.h"
#include "manager.h"
#include "user.h"
#include <unistd.h>
#include <limits.h>

void app(char*** names , char *** emails,size_t * size) {
    printf("\nTo Contact someone \"C\" and for Manager \"M\" ,to exit the program \"E\" : ");
    
   char choice ;
    
   scanf(" %1c", &choice);
   switch(choice) {
       case 'C' :
       printf("\nWelcome! We do not connect people, we connect hearts.");
       all_users(*names, *emails);
       contactor(*names,*emails);
       app(names,emails,size);
      break;
       case 'M' :
       printf("\nSimplified but powerful way to manage your contacts.");
       all_users(*names, *emails);
       manager(names,emails,size);
       printf("\n");
       app(names,emails,size);
       break;
       case 'E' :
                printf("\nSee you again.");
                printf("\n");
                break;
       default: app(names,emails,size);
       break;
 }
 return;
}
   
int main() {
	printf("Welcome to your Contact Management CLI!\n");
	printf("\n");
	

  char cwd[54];
  getcwd(cwd, sizeof(cwd));
  printf("CWD = %s\n", cwd);
	
	size_t size = 16 * 2 * sizeof(char *);
  char**names;
  char**emails;
	init(&names,&size,names_file);
  init(&emails,&size,emails_file);
	//app
	
	
	app(&names, &emails,&size);
	return 0;
}


   