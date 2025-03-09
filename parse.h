typedef struct {
  char* command;
  int linenum;
} a_line;

int command_or_program(char* line); //コマンドかプログラムの行かを判定する
int whats_command(char* line, int cmd_or_prg);//コマンドの種類を判定する
int solve_formula(char* formula);
