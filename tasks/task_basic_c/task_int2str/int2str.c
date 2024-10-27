#include "int2str.h"
#include <stdlib.h>
//работает на божьей силе
char* int2str(const int number) {
  int negative = 0, size = 0;
  long long ext_number = number;
  long long temp_number = number;

  if (ext_number < 0) {
    ext_number = -ext_number;
    temp_number = -temp_number;
    negative = 1;
    size++;
  }

  while (temp_number > 0) {
    size++;
    temp_number /= 10;
  }

  char* buf = malloc(size+1);
  buf[size] = '\0';

  if (ext_number == 0) {return "0";}
  if (negative) {buf[0] = '-';}

  for (int i = size - 1; i >= negative; i--) {
    buf[i] = (ext_number % 10) + '0';
    ext_number /= 10;
  }

  return buf;

}
