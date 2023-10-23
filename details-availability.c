#include "main.h"

int check_input_availability(char *file_name, char *name, char *password, char *gmail)
{
  FILE *file;
  char *line = NULL, *token, **tokenize;
  size_t len = 0;
  ssize_t read;
  int i;
  token = (char *)malloc(sizeof(char) * 200);
  tokenize = (char **)malloc(sizeof(char *) * 200);


  file = fopen(file_name, "r");
  if (file == NULL)
  {
    return(EXIT_SUCCESS);
  }
  while((read = getline(&line, &len, file)) != -1)
    {
      i = 0;
      token = strtok(line, " \t\n()");
      if(token[0] == '#' && token[1] == '#')
      {
        continue;
      }
      while(token != NULL)
        {
          tokenize[i] = token;
          token = strtok(NULL, " \t\n()");
          i++;
        }
      tokenize[i] = NULL;
      
      if (strcmp(tokenize[0], name) == 0)
      {
        printf("User name not available\n");
        free(line);
        free(token);
        free(tokenize);
        fclose(file);
        password_manager();
        return (-1);
      }
      if (strcmp(tokenize[1], password) == 0)
      {
        printf("Password not available\n");
        free(line);
        free(token);
        free(tokenize);
        fclose(file);
        password_manager();
        return (-1);

      }
      if (strcmp(tokenize[2], gmail) == 0)
      {
        printf("You already have an account with us kindly login to your account\n");
        free(line);
        free(token);
        free(tokenize);
        fclose(file);
        password_manager();
        return (-1);
      }
      
    }
  free(line);
  free(token);
  free(tokenize);
  fclose(file);
  return(EXIT_SUCCESS);
}




int password_manager()
{
  if (get_details() == -1)
  {
    return(1);
  }
  return(1);
}






void write_in_file(char *name, char *password, char *email)
{
  FILE *filepointer;

  filepointer = fopen("user_backup.txt", "r");
  if (filepointer == NULL)
  {
    filepointer = fopen("user_backup.txt", "w");
    if (filepointer == NULL)
    {
      printf("Error opening file...\n");
    }
    fprintf(filepointer, "####\t\t\t\tThis is the official password data base\n");

  }
  fclose(filepointer);

  /*real opening*/
  filepointer = fopen("user_backup.txt", "a");
  if (filepointer == NULL)
  {
    printf("Error opening file...\n");
  }
  fprintf(filepointer, "((( %s )))\t((( %s )))\t((( %s@gmail.com )))\n", name, password, email);

  free(name);
  free(password);
  free(email);
  fclose(filepointer);
}