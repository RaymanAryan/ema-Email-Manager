#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stddef.h>
#include "emails.h"

void add_name(const char name[], char ***names)
{
    size_t i;

    for (i = 0; (*names)[i] != NULL; i++) ;   // find NULL slot

    (*names)[i] = malloc((strlen(name) + 1)*sizeof(char));
    
    strcpy((*names)[i], name);
    (*names)[i + 1] = NULL;
}
