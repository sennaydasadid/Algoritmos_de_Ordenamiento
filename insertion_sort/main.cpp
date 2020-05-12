#include <iostream>

using namespace std;

void Insertion_sort(int t[])
{
    int i, j;
    int actual;

    for (i = 1; i < 4; i++) {
        actual = t[i];
        for (j = i; j > 0 && t[j - 1] > actual; j--) {
            t[j] = t[j - 1];
        }
        t[j] = actual;
    }
}

int main()
{
    int arr[]={4,3,5,2};
    Insertion_sort(arr);
    for(int i=0;i<4;i++)
        cout<<arr[i]<<endl;
    return 0;
}
