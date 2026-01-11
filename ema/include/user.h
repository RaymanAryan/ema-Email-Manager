#pragma once
#ifndef USER_H

int user_counter(char **names);

void add_user(char name[],char ***names,char email[],char ***emails,size_t* size) ;

void rn_user(char*** names,char*** emails,int i) ;

void all_users(char** names, char** emails);

void update_user(char ***names,char ***emails,int i) ;


#endif