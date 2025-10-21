#include "include.h"

int main(void)
{
  code_line* program = malloc(0);
  int line_num = -1;

  char line[512];
  get_input(line);
  printf("%s\n", line);

  int linenum = code_or_line(line);

  if(linenum != -1)
    {
      printf("code, %d \n", linenum);
    }
  else
    {
      printf("line\n");
    }
  
  return 0;
}
