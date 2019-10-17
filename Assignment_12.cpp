#include<iostream>
using namespace std;

template<typename T>

void SelectionSort(T arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i; j < n; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        T temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr1[5] = {5, 3, 4, 1, 2};
    char arr2[5] = "gkaq";

    SelectionSort(arr1, 5);
    SelectionSort(arr2, 5);

    for(int i = 0; i < 5; i++)
        cout<<arr1[i]<<" ";

    cout<<endl;
    for(int i = 0; i < 5; i++)
    cout<<arr2[i]<<" ";

    return 0;
}
