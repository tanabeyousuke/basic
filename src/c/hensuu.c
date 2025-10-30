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
  strncpy(new_hensuu->name, new_name, 19);
  new_hensuu->name[19] = '\0';

  return 0;
}

int mov(hensuu* vars, int current_size,  const char* name, int type, void* data)
{
  hensuu *a_hensuu = search_hensuu(vars, current_size, name);
  if(a_hensuu == NULL)
    {
      printf("未定義です\n");
      return 1;
    }
  
  a_hensuu->type = type;
  
  if(a_hensuu->type == TYPE_INT)
    {
      a_hensuu->data_i = *(int*)data;
    }
  else if(a_hensuu->type == TYPE_FLOAT)
    {
      a_hensuu->data_f = *(float*)data;
    }
  return 0;
}
