#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Used by qsort().  
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

// Prints an array, assuming 0 termination
void printArray (int *toPrint) {
	printf("\n[") ;
	for (int i = 0; toPrint[i] != 0; i++) {
		if (toPrint[i+1] == 0) {
			printf("%d]", toPrint[i]);
		} else {
			printf("%d, ", toPrint[i]);
		}
	}
	int prod = 1;
	for (int i = 0; toPrint[i] != 0; i++) {
		prod *= toPrint[i];
	}
	
	printf(" = %d", prod);
}

// Prints a 2D array, assuming zero termination
void printArray2D (int toPrint[100][50]) {
	if (toPrint[0][0] == 0) {
		printf("\n[]");
	} else {
		printf("\n[ ") ;
	}
	for (int i = 0; toPrint[i][0] != 0; i++) {
		printf("[") ;
		for (int j = 0; toPrint[i][j] != 0; j++) {
			if (toPrint[i][j+1] == 0) {
				printf("%d]", toPrint[i][j]);
			} else {
				printf("%d, ", toPrint[i][j]);
			}
		}	
		int prod = 1;
		for (int j = 0; toPrint[i][j] != 0; j++) {
			prod *= toPrint[i][j];
		}
	
		printf(" = %d", prod);
		if (toPrint[i+1][0] == 0) {
			printf("\n]");
		} else {
			printf("\n, ");
		}
	} 
}

// Computes the prime factors of N using a recursion.
// Stores factors in "factors" array.
void primeFactors_rec (int N, int* factors, int size) {
	int i = 2;
	while (N % i != 0) {
		i += 1; 
	}
	factors[size] = i;
	factors[size+1] = 0;
	if (N != i) {
		primeFactors_rec( (N / i), factors, size + 1);
	}
} // end of primeFactors

// Computes all factor groups for the prime factors given.
// Stores factor groups in "all"
void allFactors_rec (int primes[50], int all[100][50]) {
	int temp[50];
	// For each pair of factors in primes
	for (int i = 0; primes[i] != 0; i++) {
		for (int j = i + 1; primes[j] != 0; j++ ) {
			// populate temp with the original factors
			memcpy(temp, primes, 50*sizeof(int));
			// delete the element at j
			for (int k = j; primes[k] != 0; k ++) {
				temp[k] = temp[k+1];
			}
			// delete the element at i, leaving space to overwrite
			if (i != 0) { 
				for (int k = i; k > 0; k --) {
					temp[k] = temp[k-1];
				}
			}
			// overwrite index 0 with the product of the factor pair
			temp[0] = primes[i] * primes[j];
			int items = 0;
			// count the number of remaing factors
			while (temp[items] != 0) {
				items ++;
			}
			
			// sort the factors
			qsort(temp, items, sizeof(int), cmpfunc);

			// Check whether the new set of factors is already in all.
			bool check1 = false;
			for (int a = 0; all[a][0] != 0 ; a ++ ) {
				bool check2 = true;
				for (int b = 0; temp[b] != 0; b ++ ) {
					check2 = check2 && (temp[b] == all[a][b]);
				}
				check1 = check1 || check2;
			}
			
			if (!check1) { 
				// if not... 
				int q = 0;
				while (all[q][0] != 0) {
					q ++;
				}
				// copy it in! 
				memcpy(all[q], temp, 50*sizeof(int));
				all[q+1][0] = 0;
	
				
				int z = 0;
				while (temp[z] != 0) {
					z ++;
				}
				
				// and recursively run again, with the new factor grouping as the starting point.
				if (z > 2) {
					allFactors_rec(temp, all);
				}
			} 
		}
	} 
} // end of allFactors


void factor_rec(int d) {
	int primefactors_rec[50];
	primeFactors_rec(d, primefactors_rec, 0);
	int factors_rec[100][50];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 50; j++) {
			factors_rec[i][j] = 0;
		}
	}

   	memcpy(factors_rec[0], primefactors_rec, 10*sizeof(int));
	allFactors_rec(primefactors_rec, factors_rec);
	printf("The prime factors of %d are ", d);
	for (int i = 0; primefactors_rec[i] != 0; i++) {
		printf("%d, ", primefactors_rec[i]);
	}
	printf("\n\nAll groups of factors are:");
	printArray2D(factors_rec);
	
	printf("\n\n");
}

void primeFactors_itr (int N, int* factors) {
	int pos = 0;
	while (N > 1) {
		int i = 2;
		while (N % i != 0) {
			i += 1; 
		}
		factors[pos] = i;
		factors[pos + 1] = 0;
		pos += 1;
		N /= i;
	}
}

void allFactors_itr(int primes[50], int all[100][50]) {
	// loop over all elements in "all" (initially 1)
	//   - all will grow dynamically as we add factor groups to it.
	for (int a = 0; all[a][0] != 0; a++) {

		// If the number of factors in this row is less than 2, skip it!
		int z_out;
		for (int z = 0; all[a][z] != 0; z++) {
			z_out = z;
		}
		if (z_out < 2) {
			continue;
		}
		
		// for every pair of elements in the current row...
		for (int i = 0; all[a][i] != 0; i ++) {
			for (int j = i+1; all[a][j] != 0; j ++) {
				// set up a temporary buffer to hold our new array of factors.
				int remainingList[50];
				remainingList[0] = 0;
				int end = 0;
				// loop through the current row and append everything that isn't at index i or j
				for (int k = 0; all[a][k] != 0; k++) {
					if ((k != i) && (k != j)) {
						remainingList[end] = all[a][k];
						remainingList[end+1] = 0;
						end ++;
					}
				}
				// append i * j 
				remainingList[end] = all[a][i] * all[a][j];
				remainingList[end+1] = 0;
				end ++;
				// Sort! That! Array!
				qsort(remainingList, end, sizeof(int), cmpfunc);
				
				// Check if the array is already in "all"
				bool check1 = false;
				for (int b = 0; all[b][0] != 0 ; b ++ ) {
					bool check2 = true;
					for (int c = 0; remainingList[c] != 0; c ++ ) {
						check2 = check2 && (remainingList[c] == all[b][c]);
					}
					check1 = check1 || check2;
				}
				
				if (!check1) {
					// if not... 
					int q = 0;
					while (all[q][0] != 0) {
						q ++;
					}
					// copy it in! 
					memcpy(all[q], remainingList, 50*sizeof(int));
					all[q+1][0] = 0;
				}
			}
		}
	}
}

void factor_itr(int d) {
	
	int primefactors_itr[50];
	primeFactors_itr(d, primefactors_itr);
	int allfactors_itr[100][50];
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 50; j++) {
			allfactors_itr[i][j] = 0;
		}
	}

    memcpy(allfactors_itr[0], primefactors_itr, 10*sizeof(int));
    allfactors_itr[1][0] = 0;
	allFactors_itr(primefactors_itr, allfactors_itr);

	printf("The prime factors of %d are ", d);
	for (int i = 0; primefactors_itr[i] != 0; i++) {
		printf("%d, ", primefactors_itr[i]);
	}
	printf("\n\nAll groups of factors are:");
	printArray2D(allfactors_itr);
	
	printf("\n\n");
}

int main(int argc, char *argv[]){
	if (argc < 3){
		return 0;
	}
	int d = atoi(argv[2]);

	switch (atoi(argv[1])){
		case 0:
			printf("Running Recursive Factors \n");
			factor_rec(d);
			return (0);
		case 1:
			printf("Running Iterative Factors \n");
			factor_itr(d);
			return (0);
		default:
			return (0);
	}
}