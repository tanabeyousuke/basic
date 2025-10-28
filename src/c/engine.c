#include "include.h"

void run(engine_meta meta)
{
  int *num_array;
  num_array = malloc(sizeof(int) * meta.last_line);

  for(int i = 0; i < meta.last_line; i++)
    {
      num_array[i] = meta.program[i].num;
    }

  bubble_sort(num_array, meta.last_line);

  for(int i = 0; i < meta.last_line; i++)
    {
      printf("%d\n", num_array[i]);
    }

  free(num_array);
}

void prompt_loop(engine_meta meta)
{
  meta.program = malloc(0);
  meta.last_line = 0;
  meta.exit_flag = false

  while(meta.exit_flag == false)
    {
      get_input(meta.line_buffer);
  
      bool l_or_c = code_or_line(meta.line_buffer);
      if(l_or_c == true)
	{
	  int linenum = code_line_num(meta.line_buffer);
	  add_code_line(&meta.program, &meta.last_line, meta.line_buffer);
	}
      else
	{
	  run(meta);
	}
    }

  for(int i = 0; i < meta.last_line; i++)
    {
      printf("num = %d command = %s \n", meta.program[i].num, meta.program[i].line);
    }
  
  free(meta.program);

}
