#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include "emails.h"


void add_email(const char email[], char ***emails)
{
    size_t i;

    for (i = 0; (*emails)[i] != NULL; i++) ;   // find NULL slot

    (*emails)[i] = malloc((strlen(email) + 1)*sizeof(char));
    
    strcpy((*emails)[i], email);
    (*emails)[i + 1] = NULL;
}
