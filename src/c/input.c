#include "include.h"

void get_input(char* line_buffer)
{
  char buffer[512];
  int len;
  
  if(fgets(buffer, sizeof(char)*512, stdin) != NULL)
    {
      len = strlen(buffer);
      if(len > 0 && buffer[len - 1] == '\n')
	{
	  buffer[len - 1] = '\0';
	}
      strncpy(line_buffer, buffer, len);
    }
}

bool code_or_line(const char* line)
{
  int num = -1;
  int token_start, token_end;
  token_end = 0;
  get_token(line, &token_start, &token_end);

  for(int i = token_start; i < token_end; i++)
    {
      if(line[i] == '\0')
	{
	  break;
	}

      if(isdigit((unsigned char)line[i]))
	{
	  sscanf(&line[0], "%d", &num);
	}
    }

  return num;
}


  
void add_code_line(code_line* program, int* old_size, const char* line)
{
  program = realloc(program, (*old_size + 1) * sizeof(code_line));
  
  /* program[*old_size].num = line_num; */
  
  int len = strlen(line);
  strncpy(program[*old_size].line, line, len);
  *old_size = *old_size + 1;
}
