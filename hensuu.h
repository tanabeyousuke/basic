typedef struct {
  char* name;
  int num;
  hensuu* behind;
} hensuu;

hensuu* let(char* name, int num, hensuu* last);
hensuu* search(char* name, hensuu* last);
void set(hensuu* target, int num);
int read(hensuu* target);
