#include <iostream>
using namespace std;


/**
    Function that creates a dynamic array of integers.
    Every element of the array is set to its index.

    @param[in] n the size of the array
    @return address of the newly created dynamic array of
            length n, or if n <= 0 returns nullptr
*/
int* createDArray(int n){

    ///If the value of n is not correct return nullptr
    if(n<=0) return nullptr;

    int* arr = new int[n]; ///Create new dynamic array of integers with length n

    ///Set every element of the array to its index value
    for(int i = 0; i < n; i++){
        arr[i] = i;
    }

    ///Return the address of the begging of the new dynamic array
    return arr;
}


int main(){

    /**
        Good practice is to set every new pointer to nullptr!
        Just like in the scenarios with other type of data
        if not initialized as nullptr its value will be whatever is
        in that cell in the memory at that time
    */
    int n, *arr = nullptr;

    cout<<"How large you want your array to be: ";
    cin>>n;

    arr = createDArray(n);

    cout<<"Here is your array:";
    for(int i = 0; i < n; i++){
        cout<<" "<<arr[i];
    }

    cout<<endl;

}
