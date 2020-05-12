#include <iostream>
using namespace std;

void countSort(int arr[], int tam) {
/*
 El tamaño del recuento debe ser al menos (max + 1) pero
 no podemos asignar declararlo como int count (max + 1) en C ++ como
 no es compatible con la asignación de memoria dinámica.
  Entonces, su tamaño se proporciona estáticamente
*/
  int output[10];
  int count[10];
  int max = arr[0];

  // Encuentra el elemento más grande de la matriz
  for (int i = 1; i < tam; i++) {
    if (arr[i] > max)
      max = arr[i];
  }

  // Inicializa la matriz de conteo con todos los ceros.
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

// Almacenar el recuento de cada elemento
  for (int i = 0; i < tam; i++) {
    count[arr[i]]++;
  }
//Almacenar el recuento acumulativo de cada matriz
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

// Encuentra el índice de cada elemento de la matriz original en la matriz de conteo, y coloca los elementos en la matriz de salida
  for (int i = tam - 1; i >= 0; i--) {
    output[count[arr[i]] - 1] = arr[i];
    count[arr[i]]--;
  }

  // Copie los elementos ordenados en la matriz original
  for (int i = 0; i < tam; i++) {
    arr[i] = output[i];
  }
}


int main() {
  int arr[] = {4, 2, 2, 8, 3, 3, 1};

  countSort(arr, 7);

  for(int i=0;i<7;i++)
    cout<<arr[i]<<" ";
  return 0;

}
