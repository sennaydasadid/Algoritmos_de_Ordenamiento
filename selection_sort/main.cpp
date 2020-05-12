#include <iostream>

using namespace std;
void selection_sort(int arr[], int taille)
{
     int actual, mas_pequeno, j, temp;

     for (actual = 0; actual < taille - 1; actual++)
     {
         mas_pequeno = actual;
         for (j = actual ; j < taille; j++)
              if (arr[j] < arr[mas_pequeno])
                  mas_pequeno = j;
          temp = arr[actual];
          arr[actual] = arr[mas_pequeno];
          arr[mas_pequeno] = temp;
     }
}
int main()
{
    int arr[]={4,3,5,2};
    selection_sort(arr,4);
    for(int i=0;i<4;i++)
        cout<<arr[i]<<endl;
    return 0;
}
