#include "include.h"

int line_execute(engine_meta *meta, code_line a_line)
{
  char operate_buffer[10];
  
  int start, end;
  end = 0;
  get_token(a_line.line, &start, &end);

  if(end - start < 10)
    {
      strncpy(operate_buffer, &a_line.line[start], end - start);
      operate_buffer[end - start] = '\0';
    }
  else
    {
      printf("命令の文字数が多すぎる気がします。@%d行目\n", a_line.num);
      meta->code_error_flag = true;
      return -1;
    }

  if(strcmp(operate_buffer, "goto") == 0)
    {
      get_token(a_line.line, &start, &end);
      int goto_num = goto_operate(meta, &a_line.line[start]);
      return goto_num;
    }
  else if(strcmp(operate_buffer, "print") == 0)
    {
      get_token(a_line.line, &start, &end);
      print_operate(meta, &a_line.line[start]);
      return 0;
    }
  else
    {
      printf("不明な命令です。@%d行目\n", a_line.num);
      meta->code_error_flag = true;
      return -1;
    }

  return 0;
}
    

void run(engine_meta *meta)
{
  meta->num_array = malloc(sizeof(int) * meta->last_line);

  for(int i = 0; i < meta->last_line; i++)
    {
      meta->num_array[i] = meta->program[i].num;
    }

  bubble_sort(meta->num_array, meta->last_line);

  
  for(int i = 0; i < meta->last_line; i++)
    {
      code_line a_line;
      for(int ro = 0; ro < meta->last_line; ro++)
	{
	  if(meta->program[ro].num == meta->num_array[i])
	    {
	      a_line = meta->program[ro];
	    }

	}

      int next_line = line_execute(meta, a_line);

      if(meta->code_error_flag == true)
	{
	  printf("エラー コードに誤りがあるそうです。上にエラーの内容が出てるはずなので、修正してください。\n");
	  break;
	}

      if(next_line > 0)
	{
	  for(int ro = 0; ro < meta->last_line; ro++)
	    {
	      if(meta->num_array[ro] == next_line)
		{
		  i = ro - 1;
		  break;
		}
	    }
	}
    }
  
  free(meta->num_array);
}

void prompt_loop(engine_meta *meta)
{
  meta->program = malloc(0);
  meta->last_line = 0;
  meta->exit_flag = false;
  meta->end_flag = false;

  while(meta->exit_flag == false)
    {
      get_input(meta->line_buffer);
  
      bool l_or_c = code_or_line(meta->line_buffer);
      if(l_or_c == true)
	{
	  int linenum = code_line_num(meta->line_buffer);
	  add_code_line(&meta->program, &meta->last_line, meta->line_buffer);
	}
      else
	{
	  meta->code_error_flag = false;
	  run(meta);
	}
    }

  for(int i = 0; i < meta->last_line; i++)
    {
      printf("num = %d command = %s \n", meta->program[i].num, meta->program[i].line);
    }
  
  free(meta->program);

}
