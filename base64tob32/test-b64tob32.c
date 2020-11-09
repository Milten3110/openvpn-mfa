/*Compile: gcc -o test test.c */
/*Autor: */
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

static const char * base32_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ234567=";

int main(int argc, char** argv) {
  uint16_t n=0,val=0;
  int c;
  while (!(feof(stdin))) {
    c=fgetc(stdin);
    if (c>=0) {
      /* save the byte */
      c<<=n;
      val|=c;
      n+=8;

      /* encode one symbol */
      do {
	fputc(base32_chars[val&0x1f], stdout);
	n-=5; val>>=5;
      } while (n >= 5);
      
    } else break;
  }
  if (n>0) {
    fputc(base32_chars[val&0x1f], stdout);
    fputc('=', stdout);
  }
  fputc('\n',stdout);
  
  return EXIT_SUCCESS;
}