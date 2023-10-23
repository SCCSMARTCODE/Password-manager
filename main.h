#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define UNUSED(x) (void)(x)
#define MIN_NAME_LENGTH 8
#define MAX_NAME_LENGTH 15
#define MIN_PASSWORD_LENGTH 6
#define MAX_PASSWORD_LENGTH 10

int sign_log_in();
int password_manager();
int get_details();
void check_malloc_failure(char *ptr);
void write_in_file(char *name, char *password, char *email);
int pass_input(char *input);
int check_user_input(char *input, int block);
int check_input_availability(char *file_name, char *name, char *password, char *gmail);
int saved_account(char *file_name, char *name, char *password);

#endif