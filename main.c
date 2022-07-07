#include "define.h"
#include "flags.c"

int main(int argc, char * argv[]) {

  void exec_flag(const char *value) { 
    if (is_flag_valid(value, "--help", "-h") || argc <= 3) 
      help(argv[2] == "--local" ? "./assets/help.dat" : "/usr/local/etc/uxctl/assets/help.dat");
    if (is_flag_valid(value, "--unit", "-u"))
      if (argv[2]) 
        unit(argv[2]);
      else
        puts("You must write title for file");
    if (is_flag_valid(value, "--status", "-s"))
      status(argv[2]);
  }

  SLINE("UXCTL");
  if (!argv[1]) {
    puts("See --help ?--local (optional)");
    return 0;
  }
  exec_flag(argv[1]);
  return 0;
}
