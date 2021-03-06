/**
 * @defgroup   RETARGET retarget
 *
 * @brief      Retargets printf to uart.
 *
 * @author     Awahab
 * @date       2020
 */
#include "stdio.h"
#include "retarget.h"

FILE __stdout;
FILE __stdin;

int fgetc(FILE *f) {
  return (pADI_UART0->COMRX);
}

int fputc(int c, FILE *f)
{
  pADI_UART0->COMTX = c;
  while((pADI_UART0->COMLSR&0x20) == 0);// tx fifo empty
  return c;
}

int _read(int fd, char *ptr, int len)
{
  char c;
  int  i;

  for (i = 0; i < len; i++)
  {
    c = fgetc(stdin);
    if (c == 0x0D) break;
    *ptr++ = c;
    fputc(c, stdout);
  }
  return (len - i);
}

int _write(int fd, char *ptr, int len)
{
  int i;

  for (i = 0; i < len; i++) fputc(*ptr++, stdout);
  return (i);
}
