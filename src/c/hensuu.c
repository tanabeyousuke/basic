#include "include.h"

hensuu* search_hensuu(hensuu *vars, int current_size, const char* name)
{
  hensuu* a_hensuu = NULL;
  for(int i = 0; i < current_size; i++)
    {
      if(strcmp(vars[i].name, name) == 0)
	{
	  a_hensuu = &vars[i];
	  break;
	}
    }
  return a_hensuu;
}

int new_hensuu(hensuu** vars, int *current_size, const char* new_name)
{
  hensuu *searched = search_hensuu(*vars, *current_size, new_name);
  if(searched != NULL)
    {
      printf("定義済みです\n");
      return 1;
    }
 
  hensuu* new_vars = realloc(*vars, (*current_size + 1) * sizeof(hensuu));
  *vars = new_vars;
  
  hensuu* new_hensuu = &(*vars)[*current_size];
  char buffer[20]; 
  size_t s = strlen(new_name);
  if(s < 20)
    {
      strncpy(buffer, new_name, s);
      buffer[s] = '\0';
    }
  else
    {
      strncpy(buffer, new_name, 19);
      buffer[19] = '\0';
    }
  strcpy(new_hensuu->name, buffer);

  new_hensuu->data_s = NULL;
  return 0;
}

int mov(hensuu* vars, int current_size,  const char* name, const char* formula)
{
  hensuu *a_hensuu = search_hensuu(vars, current_size, name);
  if(a_hensuu == NULL)
    {
      printf("未定義です\n");
      return 1;
    }
  
  *a_hensuu = formula_eval(formula);
  return 0;
}

int write(hensuu *vars, int current_size, const char *name, const char* str)
{
  hensuu *a_hensuu = search_hensuu(vars, current_size, name);
  if(a_hensuu == NULL)
    {
      printf("未定義です\n");
      return 1;
    }
  
  if(a_hensuu->data_s != NULL)
    {
      free(a_hensuu->data_s);
    }

  size_t length = strlen(str);
  a_hensuu->data_s = malloc(length);
  strncpy(a_hensuu->data_s, str, length);
  a_hensuu->type = TYPE_STRING;
  
  return 0;
}  
