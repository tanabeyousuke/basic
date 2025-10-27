typedef struct
{
  int num;
  char line[512];
} code_line;

void get_input(char* line_buffer);
bool code_or_line(const char* line);
int code_line_num(const char* line);
void add_code_line(code_line** program_ptr, int* current_size, const char* line);
