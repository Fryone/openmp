// ConsoleApplication2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <omp.h>
#include <time.h>

#define RANDOM_MAX 1000

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double sum;
	int N;
	int i;
	int j1;
	int j2;
	int m;
	cin >> N;
	double *A;
	double *B;
	double *C;
	omp_set_num_threads(8);
	sum = 0;
	A = new double [N*N];
	B = new double [N*N];
	C = new double [N*N];
	srand((unsigned) time(NULL));
	for (i = 0; i < N*N; i++) 
	{
		//cin >> A[i] ;
		A[i] = (int)rand()/RANDOM_MAX;
		//if (A[i]>=150) A[i]=1; else A[i]=0;  
		//if ((i+1)%N == 0) {cout << A[i]<<"\n";} else {cout << A[i]<<" ";}
		//cout << A[i] <<" ";
	}
	cout <<"\n-------------------\n";

	for (i = 0; i < N*N; i++)
	{
		cout << A[i] << " ";
		if ((i + 1) % N == 0) { cout << "\n"; }
	}

	for (i = 0; i < N*N; i++) 
	{
		//cin >> B[i] ;
		B[i] = (int)rand()/RANDOM_MAX;
		//if (B[i]>=150) B[i]=1; else B[i]=0;  
		//if ((i+1)%N == 0) {cout << B[i]<<"\n";} else {cout << B[i]<<" ";}
		//cout << B[i] <<" ";

	}

	for (i = 0; i < N*N; i++)
	{
		cout << B[i] << " ";
		if ((i + 1) % N == 0) { cout << "\n"; }
	}

	cout <<"\n-------------------\n";
	#pragma omp parallel
	{
		#pragma omp for schedule(static, N)
		for (i = 0; i < N*N; i++) 
		{
			for (m = 0; m < N; m++) 
			{
				j1 = i % N;
				j2 = i / N;
				sum += A[j2 * N + m] * B[m * N + j1];
			}
			C[i] = sum;
			sum = 0;
		}	
	}

	for (i = 0; i < N*N; i++)
	{
		cout << C[i] << " ";
		if ((i+1) % N == 0) {cout << "\n";}
	} 
	cout <<"\n ";
	system("pause");
	return 0;
}


