#include "include.h"

hensuu* let(char* name, int num, hensuu* last)
{
  hensuu* new;
  new = malloc(sizeof(hensuu));
  
  new->name = name;
  new->num = num;
  new->behind = last;

  return new;
}

hensuu* search(char* name, hensuu* last)
{
  hensuu* now = last;
  int notfound == 0;
  
  while(strcmp(now->name) != 0)
    {
      if(now->behind != NULL)
	now = now->behind;
      else
	return NULL;
    }
  return now;
}

void set(hensuu* target, int num)
{
  target->num = num;
}

int read(hensuu* target)
{
  return target->num;
}
