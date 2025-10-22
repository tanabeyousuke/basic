#include "include.h"

int main(void)
{
  int line_num = 0;
  code_line* program = malloc(sizeof(line_num) * line_num);

  char line[512];
  bool l_or_c = true;
  
  while(l_or_c == true)
    {
      get_input(line);
      add_code_line(program, &line_num, line);
      l_or_c = code_or_line(line);
    }

  for(int i = 0; i < line_num; i++)
    {
      printf("%s/n", program[i].line);
    }
  

  free(program);
  return 0;
}
