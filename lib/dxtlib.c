// Author: webgtx @ 2022
// Github: https://github.com/webgtx/dxtlib
// Version: Development Testing 2.19

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void matrix();
void readstr();
void lnrd();
void wrt_exmpl();
void wrt_file();
void fs_exmpl();
void rd_file();
void sleep();
void foreach();
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

// Only INT, don't trying use arrays with char
void foreach(int *arr, int len, void (*callback) (int item, int idx)) {
  unsigned idx = 0;
  for (idx; idx < len; idx++) 
    callback(arr[idx], idx);
}

// This function is broken, stopwatcher always late on 1 seconds for iteration.
void sleep(int timeout) { // FIXME
  int idx = 0;
  printf("sleep was started...\n");
  int time_bp = time(NULL) + timeout;
  while (time_bp >= time(NULL)) {
    printf("%is timeout: %i\n", idx, time(NULL));
    idx++;
  }
}

// this function for test, dont use it
void readstr(char * string) {
  scanf("%s", string);
  printf("STR: %s\nADRS: %p\n", string, string);
}

void matrix() {
  char mtx[2][3] = {{"mat"}, {"rix"}};
  mtx[1][1] = '1';
  for (int i = 0; i < 2; i++) {
    printf("%i)idx: [%c] [%c] [%c]\n", i, mtx[i][0], mtx[i][1], mtx[i][2]);
  }
  printf("\tsizeof arr = %i bytes\n", sizeof(mtx));
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

