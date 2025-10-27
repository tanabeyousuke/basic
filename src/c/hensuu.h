typedef struct{
  char name[20];
  int type;

  int data_i;
  float data_f;
  char *data_s;
} hensuu;

int new_hensuu(hensuu** vars, int *current_size, const char* new_name);
int mov(hensuu** vars, int *current_size,  const char* name, int type, void* data);
