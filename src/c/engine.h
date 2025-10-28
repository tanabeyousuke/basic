typedef struct {
  char line_buffer[512];

  code_line *program;
  int last_line;

  bool exit_flag;
} engine_meta;
  
/* void line_execute(engine_meta meta); */
void run(engine_meta meta);
void prompt_loop(engine_meta meta);
