#include <iostream>
using namespace std;

class IntArray{
public:
    int n, *ptr;

private:

    ///Because we override our default constructor
    ///it is for the best to create it back
    IntArray();

    ///Our constructor from the task
    IntArray(int n);

    ///Destructor to clear the memory
    ~IntArray();

    ///The class functions that are to be made from the task
    ///Because the don't change any data we set them to const
    ///so if we try to change anything with them it won't compile
    ///Just a failsafe in the case we do something we don't want
    int size()const;
    int get(int k)const;

    void put(int k, int value);
};

IntArray::IntArray(){

    ///By default we set the size to be 10 and
    ///create new dynamic array of the same size
    n = 10;
    ptr = new int[n];
}

IntArray::IntArray(int n){
    ptr = new int[n];
    this->n = n;
}

IntArray::~IntArray(){
    delete[] ptr;
}

int IntArray::size()const{
    return n;
}
int IntArray::get(int k)const{
    if(k<0||k>=n){
        cout<<"Out of bounds!";
        return -1;
    }

    return ptr[k];
}

void IntArray::put(int k, int value){
    if(k<0||k>=n){
        cout<<"Out of bounds!";
        return;
    }

    ptr[k] = value;
}

int main(){
}
