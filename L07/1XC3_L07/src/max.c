/*******************************************************************************
*
* Purpose: Prints the maximum number of any number of int command-line 
* arguments that are provided.  So if this program is run with:
*   ./max 5 10 20 25 15
* then we can expect it to print 25.
*
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "library.h"

int main(int argc, char *argv[])
{
  int array[argc-1];

  if (argc < 2)
  {
    printf("Incorrect number of arguments provided.\n");
    return 0;
  }

  for (int i = 1; i < argc; i++)
  {
    array[i-1] = atoi(argv[i]);
  }

  int max_value = max(array, argc-1);

  printf("%d\n", max_value);

  return 0;
}
