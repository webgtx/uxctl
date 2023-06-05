#include "flags.c"
#define SLINE(title) printf("\n---[ %s ]---\n", title)

int main(int argc, char * argv[]) {

  void exec_flag(const char *value) { 
    if (is_flag_valid(value, "--help", "-h")) 
      help(argv[2] == "--local" ? "./assets/help.dat" : "/usr/local/etc/uxctl/assets/help.dat");
    if (is_flag_valid(value, "--unit", "-u"))
      if (argv[2]) 
        unit(argv[2]);
      else
        puts("Please type filename");
    if (is_flag_valid(value, "--status", "-s"))
      status(argv[2]);
    if (is_flag_valid(value, "--install", "-i")) {
      if (argc == 3) 
        install(argv[2], "/etc/systemd/system");
      else
        install(argv[2], argv[3]);
    }
  }

  SLINE("UXCTL");
  if (!argv[1]) {
    puts("See --help ?--local (optional)");
    return 0;
  }
  exec_flag(argv[1]);
  return 0;
}
