#include "include.h"

int command_or_program(char* line)
{
  int headposition = 0;
  
  while(isspace(line[headposition])) headposition++;

  if(isdigit(line[headposition]))
    return 0;
  else if(isalpha(line[headposition]))
    return 1;
  else return 2;
}  

int whats_command(char* line, int cmd_or_prg)
{
  int headposition = 0;
  
  if(cmd_or_prg == 0)
      while(isdigit(line[headposition])) headposition++;

  if(strncmp(&line[headposition], "let", 3))
    {//変数を代入する      
    }
  else if(strncmp(&line[headposition], "print", 5))
    {//表示する
    }
  else if(strncmp(&line[headposition], "exec", 4))
    {//プログラムを実行
    }
  else if(strncmp(&line[headposition], "clear", 5))
    {//プログラムを消去
    }
  else if(strncmp(&line[headposition], "show", 4))
    {//プログラムを表示
    }  
}

int solve_formula(char* formula)
{
  int stack[10];
  int rsp = 0;
  
  int headerposition = 0;
  while(formula[headposition] != '\0')
    {
      char[12] buffer = "";
      char* bufferhead = &buffer;
      
      while(!isspace(formula[headposition]))
	{
	  bufferhead = formula[headposition];
	  bufferhead++;
	}

      if(buffer[0] == '+')
	{
	  rsp--;
	  stack[rsp - 1] = stack[rsp] + stack[rsp - 1];
	}
      else if(buffer[0] == '-')
	{
	  rsp--;
	  stack[rsp - 1] = stack[rsp] - stack[rsp - 1];
	}
      else if(buffer[0] == '*')
	{
	  rsp--;
	  stack[rsp - 1] = stack[rsp] * stack[rsp - 1];
	}
      else if(buffer[0] == '/')
	{
	  rsp--;
	  stack[rsp - 1] = stack[rsp] / stack[rsp - 1];
	}
      else if(strncmp(&buffer, "**", 2))
	{
	  rsp--;
	  stack[rsp - 1] = stack[rsp] ** stack[rsp - 1];
	}
      else
	{
	  stack[rsp] = atoi(&buffer);
	  rsp++;
	}
    }
  
  rsp--;
  return stack[rsp];
}
