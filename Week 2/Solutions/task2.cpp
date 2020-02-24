#include <iostream>
using namespace std;

int* createDArray(int n){
    if(n<=0) return nullptr;

    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        arr[i] = i;
    }

    return arr;
}


/**
    Copy the array pointed by ptr1 to the newly
    created dynamic array pointed by ptr2. In case that
    ptr1 is nullptr or n <= 0 nothing happens.

    @param[in] ptr1 a  pointer to integers
                    used to get the needed data
    @param[out] ptr2 a reference pointer in which we
                     will copy the array pointed by ptr1
    @param[in] n length of the array referenced by ptr1

*/
void copyDArr(int* ptr1, int* &ptr2, int n){

    ///If on of the conditions that break the logic are true we
    ///just terminate the function
    if(ptr1 == nullptr || n <= 0){
        return;
    }
    ///if ptr2 is pointing to something free that memory
    if(ptr2 != nullptr){
        delete ptr2;
    }

    ptr2 = createDArray(n);

    for(int i = 0; i < n; i++){
        ptr2[i] = ptr1[i];
    }

    return;
}


int main(){
    int *dynamicArr = nullptr;
    int staticArr[] = {5, 10, 56, 123, 12, 111, 90};

    copyDArr(staticArr, dynamicArr, 7);

    cout<<"Dynamic array after copy:";
    for(int i = 0; i < 7; i++){
         cout<<" "<<dynamicArr[i];
    }

    cout<<endl;

}
