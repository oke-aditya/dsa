// Like function templates, class templates are useful when a class defines something that is independent of data type

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Array
{
    // Data members
    private:
        int *ptr;
        int size;
    
    public:
        // Constructor
        Array(T arr[], int s);
        
        // Member function.
        void print();

};

// Defining the constructor.
template <typename T>
Array<T> :: Array(T arr[], int s)
{
    this->ptr = new T[s];
    this->size = s;

    for(int i=0; i<this->size; i++)
    {
        this->ptr[i] = arr[i];
    }

}

template <typename T>
void Array<T> :: print()
{
    for(int i=0; i<this->size; i++)
    {
        cout<<*(this->ptr + i)<<" ";
    }
    cout<<endl;
}


int main(int argc, char const *argv[])
{
    int arr[5] = {1, 2, 3, 4, 5};
    Array <int> cus_arr(arr, 5);

    cus_arr.print();

    return 0;
}

