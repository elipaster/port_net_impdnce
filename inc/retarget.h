
#ifndef _RETARGET_H_
#define _RETARGET_H_  __FILE__

struct __FILE { int handle; /* Add whatever you need here */ };

int fgetc(FILE *f);
int putchar(int c);
int fputc(int c, FILE *f);
int _read (int fd, char * ptr, int len);
int _write (int fd, char * ptr, int len);

#endif //_RETARGET_H_