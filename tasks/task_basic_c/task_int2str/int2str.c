#include <assert.h>
#include <stdio.h>
#include "int2str.h"

char* int2str(int number) {

    int i = 0;
    int nega = 0;
    int temp = number;
    static char buf[16];

    if (number == 0){
        buf[i] = '0';;
        return &buf[i];
    }

    if (number < 0) {
        nega = 1;
        number = -number;
    }

    while (temp > 0) {i++;}

    while (number > 0 && i >= 0){
        buf[i] = '0' + number % 10;
        number /= 10;
        i--;
    }

    if (nega) buf[i--] = '-';

    return &buf;
}
