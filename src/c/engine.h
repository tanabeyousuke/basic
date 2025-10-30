typedef struct {
  char line_buffer[512];

  code_line *program;
  int last_line;
  int *num_array;

  hensuu *vars;
  int current_size;
  
  bool exit_flag;
  bool end_flag;
  bool code_error_flag;
} engine_meta;
  
int line_execute(engine_meta *meta, code_line a_line);
void run(engine_meta *meta);
void prompt_loop(engine_meta *meta);
