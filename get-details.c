#include "main.h"

void check_malloc_failure(char *ptr)
{
  if (ptr == NULL)
  {
    printf("Malloc failed. Exiting...\n");
    exit(-1);
  }
}


int get_details()
{
  int non, not, no, ch, nod;
  char *user_name = NULL, *password = NULL, *email = NULL, *username1 = NULL;
  user_name = (char *)malloc(16);
  check_malloc_failure(user_name);
  username1 = (char *)malloc(16);
  check_malloc_failure(username1);
  password = (char *)malloc(11);
  check_malloc_failure(password);
  email = (char *)malloc(25);
  check_malloc_failure(email);

  printf("Signing up to access this site is mandatory.\n----------\n");

  printf("Input your user name: ");
  non = scanf("%s", user_name);
  ch = check_user_input(user_name, 0);
  username1 = user_name;
  while (ch == -1 || strlen(user_name) == 0)
    {
      printf("Invalid user name. Input your user name: ");
      nod = scanf("%s", user_name);
      ch = check_user_input(user_name, 0);
    }

  printf("\nInput your preferred password: ");
  not = scanf("%s", password);
  while (check_user_input(password, 1) == -1)
    {
      printf("Invalid password. Input your preferred password: ");
      not = scanf("%s", password);
    }

  printf("\nInput your email address: ");
  no = scanf("%s", email);
  while (check_user_input(email, 2) == -1)
    {
      printf("Invalid email address. Input your email address: ");
      no = scanf("%s", email);
    }
 
  if (check_input_availability("user_backup.txt", username1, password, email) != -1)
  {
    write_in_file(user_name, password, email);
  }
  else{
    return(-1);
  }

  UNUSED(non);
  UNUSED(not);
  UNUSED(no);
  UNUSED(nod);
  
return(EXIT_SUCCESS);
}





int check_user_input(char *input, int block)
{
  int in;

  if (block == 0)
  {
    if (strlen(input) < MIN_NAME_LENGTH)
    {
      printf("User name must be at least %d characters long.\n", MIN_NAME_LENGTH);
      return (-1);
    }
    else if (strlen(input) > MAX_NAME_LENGTH)
    {
      printf("User name must be at most %d characters long.\n", MAX_NAME_LENGTH);
      return (-1);
    }
    in = pass_input(input);
    if (in == -1)
    {
      printf("User name must only contain letters and numbers.\n");
      return (-1);
    }
    return(EXIT_SUCCESS);
  }

  else if (block == 1)
  {
    if (strlen(input) < MIN_PASSWORD_LENGTH)
    {
      printf("Password must be at least %d characters long.\n", MIN_PASSWORD_LENGTH);
      return(-1);
    }
    else if (strlen(input) > MAX_PASSWORD_LENGTH)
    {
      printf("Password must be at most %d characters long.\n", MAX_PASSWORD_LENGTH);
      return(-1);
    }
    if (pass_input(input) == -1)
    {
      printf("Password must only contain letters and numbers.\n");
      return(-1);
    }
    return(1);
  }

  else if (block == 2)
  {
    char *_input = input;
    char *end_gmail = "@gmail.com";
    int gmail_len = strlen(input);
    int _len = strlen(end_gmail);
    int check = (gmail_len - _len);
    int i = 0;
    
    while (check < gmail_len)
      {
        if (input[check] != end_gmail[i] || input[check] == '\0')
        {
         printf("Email address must end with @gmail.com.\n");
         return(-1);
        }
        i++;
        check++;
      }
      input[gmail_len - _len] = '\0';
      if (pass_input(_input) == -1)
      {
        printf("Email address must only contain letters, numbers and extension [@gmail] e.g --[emanple234@gmail.com]--\n");
        return(-1);
      }
    return(1);
  }

  return (EXIT_SUCCESS);
}

int pass_input(char *input) {
  int i = 0;
  int j = strlen(input);

  for (i = 0; i < j; i++) {
    char current = input[i];

    if ((current >= '0' && current <= '9') ||
        (current >= 'A' && current <= 'Z') ||
        (current >= 'a' && current <= 'z')) {
      continue;
    } else {
      return -1;
    }
  }

  return 1;
}
