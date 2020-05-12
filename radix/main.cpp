
#include <iostream>

using namespace std;

// Obtenga el valor máximo del array.
int getMax(int arr[], int n)
{
	int maxi = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > maxi)
			maxi = arr[i];
	return maxi;
}

// cuenta los ordenamientos arr[].
void countSort(int arr[], int n, int exp)
{
	// Cuenta[i] array contara el numero de valores
	//de array que tengan ese digito"i" en su(exp)th lugar
	int salida[n], i, cuenta[10] = {0};

	//Cuenta el numero de veces que cada digito ocurrio
	//(esp)th lugar en caada entrada
	for (i = 0; i < n; i++)
		cuenta[(arr[i] / exp) % 10]++;

	// Calculo de su recuento acumulativo
	for (i = 1; i < 10; i++)
		cuenta[i] += cuenta[i-1];

	// Inserta valores de acuerdo con el digito
	//arr[i] / exp) % 10 obteniendo en la cuenta[(arr[i] / exp) % 10]
    for (i = n - 1; i >= 0; i--)
	{
		salida[cuenta[(arr[i] / exp) % 10] - 1] = arr[i];
		cuenta[(arr[i] / exp) % 10]--;
	}

	// Asignando el resultado al array del main
	for (i = 0; i < n; i++)
		arr[i] = salida[i];
}

// Ordenar arr[] de tamaño n usando Radix sort
void radixsort(int arr[], int n)
{
	int exp, m;
	m = getMax(arr, n);

	// Lamando a countsort() para el digito en exp
	//lugar en cada entrada
	for (exp = 1; m/exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

int main()
{
	int n, i;
	cout<<"\nNumero de elementos: ";
	cin>>n;

	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Numeros: "<<i+1<<": ";
		cin>>arr[i];
	}

	radixsort(arr, n);

	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	return 0;
}


