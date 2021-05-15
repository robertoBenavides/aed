// Ordenamiento.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <time.h>
using namespace std;
struct comparador {
	virtual bool comp(int a, int b) = 0;
};
struct desc:public comparador {
	bool comp(int a, int b) {
		return a > b;
	}
};
struct asc :public comparador {
	bool comp(int a, int b) {
		return a < b;
	}
};

void swap(int* a, int* b) {
	int c=*b;
	*b = *a;
	*a = c;

}

void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	comparador *a =new asc;
	int i = 0,j=0,k=l;
	while (i < n1 && j < n2)
	{
		if ((a->comp)(L[i],R[j]))
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}

}

void ord(int arr[], int l, int r) {
	
	if (l < r)
	{
		int m = l + (r - l) / 2;

		ord(arr, l, m);
		ord(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}




void print(int* arr, int tam) {
	for (int* a = arr; a < arr + tam; a++) {
		cout << *a << " ";
	}
}

int main()
{
	srand(time(NULL));
	int tam = 50000;
	int* a = new int[tam];
	int c =1,d=5;
	for (int* b = a; b < a + tam; b++) {
		*b = rand() % 50000;
	}
	unsigned t0 = clock();
	ord(a, 0, tam - 1);
	unsigned t1 = clock();
	double time = (double(t1 - t0) / CLOCKS_PER_SEC);
	cout << time;
   
}
