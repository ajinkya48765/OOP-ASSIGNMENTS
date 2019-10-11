/*
    ==========================================================
      ASSIGNMENT 5 : Array Operations & Operator Overloading
    ==========================================================

    Code by: SAHIL HADKE
    Roll No: 17
    Batch: S1
    Question: Implement a class CppArray which is identical to a one-dimensional C++ array (i.e., the index
              set is a set of consecutive integers starting at 0) except for the following :
              1. It performs range checking.
              2. It allows one to be assigned to another array through the use of the assignment
              operator (e.g. cp1= cp2)
              3. It supports a function that returns the size of the array.
              4. It allows the reading or printing of array through the use of cout and cin.
*/

#include<iostream>
using namespace std;

class CppArray
{
    int i,j,n;
public:
    int arr[100];
    void getData();
    void printData();
    void getRange();
    void SortArray();

    // = Operator Overloading
    CppArray operator=(CppArray &obj)
    {
	CppArray _obj;
	_obj.arr[100] = this->arr[100];
	return _obj;
    }
};

void CppArray::SortArray()
{
    for(i = n-1; i>=0; i--)
    {
        for(j = 0; j <= i; j++)
        {
	          if(arr[j] > arr[j+1])
            {
                //Swapping.
	              int temp = 0;
	    	        temp = arr[j];
		            arr[j] = arr[j+1];
		            arr[j+1] = temp;
	          }
        }
    }
    printData(); //After sorting array it prints the sorted array using this function.
}

//For User Input.
void CppArray::getData()
{
    cout<<"Enter the size of array: ";
    cin>>n;

    for(i = 0; i < n; i++)
    {
	cout<<"Enter element "<<i+1<<": ";
   	cin>>arr[i];
    }
}

//Prints the array
void CppArray::printData()
{
    cout<<"The sorted array is: {";
    for(i = 0; i < n; i++)
    {
   	    cout<<arr[i]<<" ";
    }
    cout<<"}\n";
}

//Range of array is maximum number in array - minimum number in array.
void CppArray::getRange()
{
    cout<<"\nThe maximum number is: "<<arr[n-1]<<"\nThe minimum number is :"<<arr[0];
    cout<<"\nThe range is: "<<arr[n-1] - arr[0]<<endl;
}

int main()
{
    CppArray cp1;
    cp1.getData();
    cp1.SortArray();
    cp1.getRange();

    //Copying the array of cp1 to array of cp2 by operator overloading.

    CppArray cp2 = cp1;

    //Printing the array of cp2.
    cout<<"\nFollowing is the array of cp2\n";
    cp2.printData();

    return 0;
}
