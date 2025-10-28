#include "include.h"

void get_token(const char* line, int* start, int* end)
{
  *start = *end;
  while(line[*start] == ' ')
    {
      *start = *start + 1;
    }

  *end = *start + 1;
  while(line[*end] != ' ')
    {
      if(line[*end] == '\0') break;
      *end = *end + 1;
    }
}


void bubble_sort (int *array, int n)
{
  for(int i = 0; i < n - 1; i++)
    {
      for(int ro = 0; ro < n - 1 ; ro++)
	{
	  if(array[ro] > array[ro + 1])
	    {
	      int ha = array[ro];
	      array[ro] = array[ro + 1];
	      array[ro + 1] = ha;
	    }
	}
    }
}
