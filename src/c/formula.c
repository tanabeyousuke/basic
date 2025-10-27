#include "include.h"

hensuu formula_eval(const char* formula)
{
  hensuu stack[10];
  int shead = 0;
  char buffer[10];
  int start, end, formula_end;
  end = 0;
  printf("%s\n", formula);
  for(int i = 0;;i++)
    {
      if(formula[i] == '\0')
	{
	  formula_end = i;
	  break;
	}
    }
    
  while(1)
    {
      get_token(formula, &start, &end);
      
      if(end - start < 10)
	{
	  strncpy(buffer, &formula[start], end - start);
	  buffer[end - start] = '\0';
	}
      else
	{
	  strncpy(buffer, &formula[start], 9);
	  buffer[9] = '\0';
	}

      if(strcmp(buffer, "+") == 0)
	{
	  if(stack[shead - 1].type == TYPE_INT &&
	     stack[shead - 2].type == TYPE_INT)
	    {
	      stack[shead - 2].data_i = stack[shead - 2].data_i + stack[shead - 1].data_i;
	    }
	  else if(stack[shead - 1].type == TYPE_FLOAT &&
		  stack[shead - 2].type == TYPE_FLOAT)
	    {
	      stack[shead - 2].data_f = stack[shead - 2].data_f + stack[shead - 1].data_f;
	    }
	  else if(stack[shead - 2].type == TYPE_FLOAT)
	    {
	      stack[shead - 2].data_f = stack[shead - 2].data_f + (float)stack[shead - 1].data_i;
	    }
	  else if(stack[shead - 2].type == TYPE_INT)
	    {
	      stack[shead - 2].data_f = (float)stack[shead - 2].data_i + stack[shead - 1].data_f;
	      stack[shead - 2].type = TYPE_FLOAT;
	    }
	  shead = shead - 1;
	}
      else if(strcmp(buffer, "-") == 0)
	{
	  if(stack[shead - 1].type == TYPE_INT &&
	     stack[shead - 2].type == TYPE_INT)
	    {
	      stack[shead - 2].data_i = stack[shead - 2].data_i - stack[shead - 1].data_i;
	    }
	  else if(stack[shead - 1].type == TYPE_FLOAT &&
		  stack[shead - 2].type == TYPE_FLOAT)
	    {
	      stack[shead - 2].data_f = stack[shead - 2].data_f - stack[shead - 1].data_f;
	    }
	  else if(stack[shead - 2].type == TYPE_FLOAT)
	    {
	      stack[shead - 2].data_f = stack[shead - 2].data_f - (float)stack[shead - 1].data_i;
	    }
	  else if(stack[shead - 2].type == TYPE_INT)
	    {
	      stack[shead - 2].data_f = (float)stack[shead - 2].data_i - stack[shead - 1].data_f;
	      stack[shead - 2].type = TYPE_FLOAT;
	    }
	  shead = shead - 1;
	}
      else if(strcmp(buffer, "*") == 0)
	{
	  if(stack[shead - 1].type == TYPE_INT &&
	     stack[shead - 2].type == TYPE_INT)
	    {
	      stack[shead - 2].data_i = stack[shead - 2].data_i * stack[shead - 1].data_i;
	    }
	  else if(stack[shead - 1].type == TYPE_FLOAT &&
		  stack[shead - 2].type == TYPE_FLOAT)
	    {
	      stack[shead - 2].data_f = stack[shead - 2].data_f * stack[shead - 1].data_f;
	    }
	  else if(stack[shead - 2].type == TYPE_FLOAT)
	    {
	      stack[shead - 2].data_f = stack[shead - 2].data_f * (float)stack[shead - 1].data_i;
	    }
	  else if(stack[shead - 2].type == TYPE_INT)
	    {
	      stack[shead - 2].data_f = (float)stack[shead - 2].data_i * stack[shead - 1].data_f;
	      stack[shead - 2].type = TYPE_FLOAT;
	    }
	  shead = shead - 1;
	}
      else if(strcmp(buffer, "/") == 0)
	{
	  if(stack[shead - 1].type == TYPE_INT &&
	     stack[shead - 2].type == TYPE_INT)
	    {
	      stack[shead - 2].data_i = stack[shead - 2].data_i / stack[shead - 1].data_i;
	    }
	  else if(stack[shead - 1].type == TYPE_FLOAT &&
		  stack[shead - 2].type == TYPE_FLOAT)
	    {
	      stack[shead - 2].data_f = stack[shead - 2].data_f / stack[shead - 1].data_f;
	    }
	  else if(stack[shead - 2].type == TYPE_FLOAT)
	    {
	      stack[shead - 2].data_f = stack[shead - 2].data_f / (float)stack[shead - 1].data_i;
	    }
	  else if(stack[shead - 2].type == TYPE_INT)
	    {
	      stack[shead - 2].data_f = (float)stack[shead - 2].data_i / stack[shead - 1].data_f;
	      stack[shead - 2].type = TYPE_FLOAT;
	    }
	  shead = shead - 1;
	}
      else
	{
	  if(strchr(buffer, '.') == NULL)
	    {
	      sscanf(buffer, "%d", &stack[shead].data_i);
	      stack[shead].type = TYPE_INT;
	    }
	  else
	    {
	      sscanf(buffer, "%f", &stack[shead].data_f);
	      stack[shead].type = TYPE_FLOAT;
	    }
	  shead = shead + 1;
	}

      if(formula[end] == '\0')
	break;
    }

  return stack[shead - 1];
}
