#include "define.h"
#include "lib/dxtlib.c"


struct unit {
  char description[ASIZE];
  char type[50];
  char exec_start[ASIZE];
  char work_dir[ASIZE];
  char restart[10];
};

int is_flag_valid(const char *val, const char *key, const char *key_short) {
  return !strcmp(key, val) || !strcmp(key_short, val) ? 1 : 0;
}

void help() {
  char str_dat[ASIZE];
  rd_file(str_dat, "assets/help.dat");
  printf("%s\n", str_dat);
}

int unit(char *title) {

  struct unit new_unit;
  char unit_data[1000];
  if (!title) return 1;

  printf("Description: ");
  lnrd(new_unit.description);
  printf("Type: ");
  lnrd(new_unit.type);
  printf("ExecStart: ");
  lnrd(new_unit.exec_start);
  printf("WorkingDirectory: ");
  lnrd(new_unit.work_dir);
  printf("Restart Always? (y/N): ");
  lnrd(new_unit.restart);
  puts("Unit was created !");
  sprintf(
      unit_data,
      "[ Unit ]\nDescription=%s\n[Service]\nType=%s\nExecStart=%s\nWorkingDirectory=%s\n%s[Install]\nWantedBy=default.target\n",
      new_unit.description, new_unit.type, new_unit.exec_start, new_unit.work_dir, strcmp(new_unit.restart, "y") ? "" : "Restart=always\n");
  wrt_file(unit_data, title);
  return 0;
}

int status(const char *service) {
  if (!service) return 1;
  puts(service);
  return 0;
}
