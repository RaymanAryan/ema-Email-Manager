#include <stdio.h>
#include <stdlib.h>
#include "user.h"
#include "manager.h"
#include "memory.h"

//manager cli
void manager(char*** names , char *** emails,size_t* size) {
    printf("Type (A) to show all,(C) to create ,(U) to update ,(D) to delete contacts,(S) to save and (B) to back : ");
    char choice;
    scanf(" %1c", &choice);
    
    switch(choice) {
      case 'A':all_users(*names,*emails);
                break;
      case 'C': {
      char name[20];
      char email[256];
      printf("\nEnter the name of the subjec: ");
      scanf(" %s",name);
      printf("\nEnter the email of the subject : ");
      scanf(" %s",email);
              add_user(name,names,email,emails,size);
              printf("\n");
              break;
      }
      case 'U':printf("\nEnter the index of the subject. Or cancel(0) : ");
            int index;
            scanf(" %d",&index);
          if(index ==0 || user_counter(*names) >= index) { break;}
            update_user(names,emails,abs(index));
            printf("\n");
            break;
            
      case 'D':printf("\nEnter the index of the subject. Or cancel(0) : ");
        int i;
        scanf(" %d",&i);
      if(i != 0){ rn_user(names,emails,abs(i));}
      printf("\n");
              break;
      case 'S':
              save(*names,names_file);
              save(*emails,emails_file);
              printf("\n");
              break;
      case 'B': return;
      default: printf("\n");
      break;
      }
  manager(names,emails,size);
}
    