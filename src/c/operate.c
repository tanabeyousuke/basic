#include "include.h"

int goto_operate(engine_meta *meta, const char* param)
{
  char buffer[10];
  int start, end;
  end = 0;
  get_token(param, &start, &end);

  if(end - start < 10)
    {
    }
  else
    {
      strncpy(buffer, &param[start], 9);
      buffer[9] = '\0';
    }
  
  int goto_num;
  sscanf(buffer, "%d", &goto_num);

  bool flag = false;
  for(int i = 0; i < meta->last_line; i++)
    {
      if(meta->num_array[i] == goto_num)
	{
	  flag = true;
	  break;
	}
    }

  if(flag == true)
    {
      return goto_num;
    }
  else
    {
      printf("不正な行番号です。\n");
      return -1;
    }
}  

void print_operate(engine_meta *meta, const char* param)
{
  hensuu output;
  output.type = TYPE_STRING;
  output.data_s = malloc(sizeof(char) * 512);
  
  char buffer1[BUFFER_SIZE];

  int start, end;
  end = 0;
  get_token_cs(param, &start, &end);
  
  strncpy(buffer1, &param[start], end - start);
  buffer1[end - start] = '\0';

  if(buffer1[0] == '"' && buffer1[(end - 1) - start] == '"')
    {
      strncpy(output.data_s, &buffer1[start + 1], (end - 1) - start);
      output.data_s[(end - 2) - start] = '\0';
    }

  use_escape(output.data_s);
  printf("%s", output.data_s);
  free(output.data_s);
}

int if_operate(engine_meta *meta, const char* param)
{
  char buffer[BUFFER_SIZE];
  int start, end;
  hensuu kekka;
  end = 0;
  get_token_cs(param, &start, &end);
  strncpy(buffer, &param[start], end - start);
  buffer[end - start] = '\0';
  kekka = formula_eval(buffer);

  char i[10], ro[10], ha[10];

  get_token_cs(param, &start, &end);
  strncpy(i, &param[start], end - start);
  buffer[end - start] = '\0';

  get_token_cs(param, &start, &end);
  strncpy(ro, &param[start], end - start);
  buffer[end - start] = '\0';

  get_token_cs(param, &start, &end);
  strncpy(ha, &param[start], end - start);
  buffer[end - start] = '\0';
  
  if(kekka.type == TYPE_INT)
    {
      if(kekka.data_i < 0)
	{
	  return goto_operate(meta, i);
	}
      else if(kekka.data_i == 0)
	{
	  return goto_operate(meta, ro);
	}
      else if(kekka.data_i > 0)
	{
	  return goto_operate(meta, ha);
	}
    }
  else
    {
      if(kekka.data_f < 0)
	{
	  return goto_operate(meta, i);
	}
      if(kekka.data_f == 0)
	{
	  return goto_operate(meta, ro);
	}
      if(kekka.data_f > 0)
	{
	  return goto_operate(meta, ha);
	}
    }
}
      
void let_operate(engine_meta *meta, const char* param)
{
  char buffer[BUFFER_SIZE];
  int start, end;
  end = 0;
  get_token(param, &start, &end);
  strncpy(buffer, &param[start], end - start);
  buffer[end - start] = '\0';

  int result = new_hensuu(&meta->vars, &meta->current_size, buffer);
  if(result == 1)
    {
      meta->code_error_flag = true;
    }
}

