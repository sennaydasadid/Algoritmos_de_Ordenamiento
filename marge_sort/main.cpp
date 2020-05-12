#include<iostream>
using namespace std;

void convinar(int arr[], int l, int m, int r) {
   int i, j, k, nl, nr;
   // tamaño de las sub-matrices izquierda y derecha
   nl = m-l+1; nr = r-m;
   int larr[nl], rarr[nr];
   //llenar sub-matrices izquierda y derecha
   for(i = 0; i<nl; i++)
      larr[i] = arr[l+i];
   for(j = 0; j<nr; j++)
      rarr[j] = arr[m+1+j];
   i = 0; j = 0; k = l;
   //unir matrices temporales a matrices reales
   while(i < nl && j<nr) {
      if(larr[i] <= rarr[j]) {
         arr[k] = larr[i];
         i++;
      }else{
         arr[k] = rarr[j];
         j++;
      }
      k++;
   }
   while(i<nl) {       //elemento extra en la matriz izquierda
      arr[k] = larr[i];
      i++; k++;
   }
   while(j<nr) {     // elemento adicional en la matriz derecha
      arr[k] = rarr[j];
      j++; k++;
   }
}
void mergeSort(int arr[], int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Ordenar primero y segundo arrays
      mergeSort(arr, l, m);
      mergeSort(arr, m+1, r);
      convinar(arr, l, m, r);
   }
}
int main() {
   int n;
   cout << "Numero de elementos: ";
   cin >> n;
   int arr[n];     //crea una matriz con un número dado de elementos
   cout << "Elementos:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
   mergeSort(arr, 0, n-1);     //(n-1) para el ultimo indice
    cout<<endl;

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
