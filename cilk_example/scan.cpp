#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
#include "get_time.h"
#include "scan.h"
using namespace std;

int main(int argc, char** argv) {
	int n = atoi(argv[1]);
	int* A = new int[n];
	int* B = new int[n];
	int* e1 = new int[n];
	int* e2 = new int[n];
	cilk_for (int i = 0; i < n; i++) A[i] = i;
	
	timer t; t.start();
	scan(A, B, e1, e2, n);
	t.stop(); cout << "time: " << t.get_total() << endl;
	
	return 0;
}