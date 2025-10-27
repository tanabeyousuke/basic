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
  bool b = false;
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
	  return true;
	}
    }

  return false;
}
  
int code_line_num(const char* line)
{
  int num;
  int token_start, token_end;
  token_end = 0;
  get_token(line, &token_start, &token_end);
  
  sscanf(&line[token_start], "%d", &num);
  return num;
}

void add_code_line(code_line** program_ptr, int* current_size, const char* line)
{
  int line_num;
  char  buffer[BUFFER_SIZE];
  sscanf(line, "%d %[^\n]", &line_num, &buffer);

  for(int i = 0; i < line_num; i++)
    {
      code_line* a_line = &(*program_ptr)[i];
      if(a_line->num == line_num)
	{
	  a_line->num = line_num;
	  strncpy(a_line->line, buffer, BUFFER_SIZE - 1);
	  return;
	}
    }
  
  code_line* new_program = realloc(*program_ptr, (*current_size + 1) * sizeof(code_line));
  
  
  *program_ptr = new_program;
  
  code_line* new_line = &(*program_ptr)[*current_size];
  
  size_t buffer_size = sizeof(new_line->line);

  
  strncpy(new_line->line, buffer, BUFFER_SIZE - 1);
  new_line->line[BUFFER_SIZE - 1] = '\0';
  new_line->num = line_num;

  *current_size = *current_size + 1;
  
  return;
}

