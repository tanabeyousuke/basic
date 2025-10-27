#include "include.h"

int new_hensuu(hensuu** vars, int *current_size, const char* new_name)
{
  hensuu* new_vars = realloc(*vars, (*current_size + 1) * sizeof(hensuu));
  *vars = new_vars;
  
  hensuu* new_hensuu = &(*vars)[*current_size];
  strncpy(new_hensuu->name, new_name, 19);
  new_hensuu->name[19] = '\0';

  return 0;
}

int mov(hensuu** vars, int *current_size,  const char* name, int type, void* data)
{
  for(int i = 0; i < *current_size; i++)
    {
      hensuu* a_hensuu = &(*vars)[i];
      if(a_hensuu->name == name)
	{
	  if(type = TYPE_INT)
	    {
	    }
	  else if(type = TYPE_FLOAT)
	    {
	    }
	  else if(type = TYPE_STRING)
	    {
	    }
	  else
	    {
	    }
	}
    }
}
