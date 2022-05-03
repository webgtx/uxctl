#include "define.c"

int is_flag_valid(const char *val, const char *key, const char *key_short) {
  return !strcmp(key, val) || !strcmp(key_short, val) ? 1 : 0;
}

void help() {
  char str_dat[ASIZE];
  rd_file("assets/help.dat", str_dat);
  printf("%s\n", str_dat);
}

int unit(char *title) {
  if (!title) return 1;
  wrt_file("[ Unit ]\n", title);
  puts("Unit was created !\n");
}

int status(const char *service) {
  if (!service) return 1;
  puts(service);
}
