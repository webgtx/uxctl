#include <stdio.h>
#include "lib/dxtlib.c"
#include "flags.c"
#include "define.c"

int main(int argc, char * argv[]) {

  void exec_flag(const char *value) { 
    if (is_flag_valid(value, "--help", "-h"))
      help();
    if (is_flag_valid(value, "--unit", "-u"))
      unit(argv[2]);
    if (is_flag_valid(value, "--status", "-s"))
      status(argv[2]);
  }

  SLINE("UXCTL");
  if (!argv[1]) {
    help();
    return 0;
  }
  exec_flag(argv[1]);
//  char flags {}  
  return 0;
}
