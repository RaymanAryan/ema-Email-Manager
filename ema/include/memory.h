#pragma once
#ifndef MEMORY_H

extern char names_file[];
extern char emails_file[];
void init(char ***array, size_t* size, char file_name[]);

void save(char **array,const char file_name[]);
#endif