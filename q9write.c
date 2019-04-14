/*
 * Programmer : Josh Booth      Date : Apr 18 , 2019
 * Instructor : Professor Hou   Class : ENGR 120 - 03
 *
 * Takes IP addresses from stdin and writes to binary file
 */

#include <stdio.h> /* Includes printf, scanf */
#include <string.h> /* Includes strcmp */

#define MAX_NAME_LEN 10 /* Max nickname length */
#define MAX_ADDR 100 /* Max number of addresses to read */
/* Sentinal nickname to stop reading file */
#define NICKNAME_SENTINEL "end"
/* Output file holding structure */
#define OUTPUT_FILE "ip.bin"


/* Structure for holding a computer IP address */
typedef struct{
  int xx;
  int yy;
  int zz;
  int mm;
  char nickname[MAX_NAME_LEN];
} address_t;

/* Reads in computer address */
int scan_address(address_t *computer);
/* Writes structure to binary file */
void write_address(FILE *outp, address_t *computer);


int
main(void)
{
  int num_of_computers = 0; /* Number of computers read in */
  FILE *outp; /* Output files to write computer addresses to */
  address_t computers[MAX_ADDR]; /* Holds IP addresses */

  /* Opens output files for writing */
  outp = fopen(OUTPUT_FILE, "w");

  /* Reads computers while sentinel value hasn't been reached */
  while(scan_address(&computers[num_of_computers]))
  {
    num_of_computers++;
  }

  /* Writes each computer in list of IP addresses to binary file */
  for(int i = 0; i < num_of_computers; i++)
  {
    write_address(outp, &computers[i]);
  } 

  fclose(outp); /* Closes output file */

  return 0;
}

/* Reads in computer address */
int
scan_address(address_t *computer)
{
 /* Reads in computer information */
 printf("Enter IP address and name: ");
 scanf("%d.%d.%d.%d %s", &computer->xx, &computer->yy,
                         &computer->zz, &computer->mm, computer->nickname);

 /* Checks if sentinel values were reached */
 if(computer->xx == 0 && computer->yy == 0 && computer->zz == 0 &&
     !strcmp(computer->nickname, NICKNAME_SENTINEL))
 {
   return 0; /* Returns 0 if sentinel values were read */
 }
 else /* Returns 1 if read successfully */
 {
   return 1;
 }
}

/* Writes structure to binary file */
void
write_address(FILE *outp, address_t *computer)
{
  fwrite(computer, sizeof(address_t), 1, outp);
}
