/*
 * Programmer : Josh Booth      Date : Apr 18 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Reads in IP addresses from binary file and prints them
 */

#include <stdio.h> /* Includes printf, scanf */

#define MAX_NAME_LEN 10 /* Max nickname length */
/* Input file holding structure */
#define INPUT_FILE "ip.bin"

/* Structure for holding a computer IP address */
typedef struct{
  int xx;
  int yy;
  int zz;
  int mm;
  char nickname[MAX_NAME_LEN];
} address_t;

/* Prints IP address */
void print_address(address_t computer);

int
main(void)
{
  FILE *inp; /* Input file to read computer addresses from */
  address_t computer; /* Holds read in IP address */

  /* Opens output files for reading */
  inp = fopen(INPUT_FILE, "r");

  /* Reads IP address from file and then prints it */
  while(fread(&computer, sizeof(address_t), 1, inp))
  {
    print_address(computer);
  }

  fclose(inp); /* Closes input file */

  return 0;
}


/* Prints computer address */
void print_address(address_t computer)
{
  printf("%d.%d.%d.%d %s\n", computer.xx, computer.yy, computer.zz, computer.mm,
                             computer.nickname);
}
