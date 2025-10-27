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

