#include "include.h"

int main(void)
{
  engine_meta meta;
  prompt_loop(meta);
}  

/* int main(void) */
/* { */
/*   hensuu h = formula_eval("1 2 + 3.0 *"); */
/*   if(h.type == TYPE_INT) */
/*     { */
/*       printf("%d\n", h.data_i); */
/*     } */
/*   else */
/*     { */
/*       printf("%f\n", h.data_f); */
/*     } */
    
/*   return 0; */
/* } */

/* int main(void) */
/* { */
/*   code_line* program = malloc(0); */
/*   int line_num = 0; */

/*   char line[512]; */

/*   while(1) */
/*     { */
/*       get_input(line); */
  
/*       bool l_or_c = code_or_line(line); */
/*       if(l_or_c == true) */
/* 	{ */
/* 	  int linenum = code_line_num(line); */
/* 	  add_code_line(&program, &line_num, line); */
/* 	} */
/*       else */
/* 	{ */
/* 	  break; */
/* 	} */
/*     } */

/*   for(int i = 0; i < line_num; i++) */
/*     { */
/*       printf("num = %d command = %s \n", program[i].num, program[i].line); */
/*     } */
  
/*   free(program); */

/*   return 0; */
/* } */
