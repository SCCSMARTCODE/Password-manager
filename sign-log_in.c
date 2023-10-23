#include "main.h"

int sign_log_in()
{
  int ch, sh, jh, choice = 0, check;
  char username[MAX_NAME_LENGTH], password[MAX_PASSWORD_LENGTH];
  
  while (choice != 1 && choice != 2)
    {
      printf("Input 1.to login or 2.to sign_up: ");
      ch = scanf("%d", &choice);
    }
  UNUSED(ch);

  if(choice == 1)
  {
    printf("Input your Username: ");
    sh = scanf(" %s", username);
    printf("Input your password: ");
    jh = scanf(" %s", password);

    if ((check = saved_account("user_backup.txt", username, password)) == 1)
    {
      printf("Login success\n");
      return 1;
    }
    else{
      printf("Login failed\n");
      return 0;
    }
  }
  else{
    if ((check = password_manager()) == 1)
    {
      printf("Sign_up success\n");
      return 1;
    }
    else
    {
      printf("Sign_up failed\n");
      return 0;
    }
  }
  return (EXIT_SUCCESS);
}




int saved_account(char *file_name, char *name, char *password)
{
  FILE *file;
  char *line = NULL, *token, **tokenize;
  size_t len = 0;
  ssize_t read;
  int i, check;
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
         if (strcmp(tokenize[1], password) == 0)
           {
             printf("Welcome %s\n", tokenize[0]);
             check = 1;
             free(line);
             free(token);
             free(tokenize);
             fclose(file);
             return(check);
           }
        else
          {
            printf("Wrong password\n");
            check = 0;
            free(line);
            free(token);
            free(tokenize);
            fclose(file);
            return(check);
          }
      }
      
    }
  
  printf("User not found\n");
  check = -1;
  
  free(line);
  free(token);
  free(tokenize);
  fclose(file);
  return(check);
}