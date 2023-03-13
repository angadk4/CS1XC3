/*******************************************************************************
*
* Purpose: Library function definitions
*
* Author: Kevin Browne
*
*******************************************************************************/

int square_area(int side) { return side * side; }

int multiply(int m, int n) { return m * n; }

int max(int array[], int total)
{
  int max = array[0];
  for (int i = 1; i < total; i++)
  {
    if (array[i] > max) max = array[i];
  }
  return max;
}

