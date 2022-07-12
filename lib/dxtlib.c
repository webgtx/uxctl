// Author: webgtx @ 2022
// Github: https://github.com/webgtx/dxtlib
// Version: Development Testing 2.19

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void lnrd();
void wrt_file();
void rd_file();
int sint(const char *str);
int system(const char *shell);


// SINT - StringInteger, sum of all chars converted to int
int sint(const char * str) {
  unsigned len = strlen(str);
  int sint = 0;
  for (unsigned idx = 0; idx < len; idx++)
    sint += str[idx];
  return sint;
}

void lnrd(char * str) {
  int idx = 0;
  while (true) {
    char ch = getchar();
    if (ch == '\n') 
      break;
    str[idx] = ch;
    idx++;
  }
  str[idx++] = '\0';
}

void wrt_file(char * dat, char * filename) { 
  FILE *file = fopen(filename, "w");
    fprintf(file, dat);
  fclose(file);
}

void rd_file(char * dat, char * filename) {
  int c;
  int idx = 0;
  FILE *file;
  file = fopen(filename, "r");
  if (file) {
    while ((c = getc(file)) != EOF) {
      dat[idx] = c;
      idx++;
    }
    fclose(file);
  }
}
