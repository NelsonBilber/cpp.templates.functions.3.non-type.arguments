#include <iostream>

using namespace std;

//primary template
template <typename T>
T Max(T x, T y)
{
    cout << typeid(T).name() << endl;
    
    return x > y ? x: y;
}

//Explicit Instantiation
template char Max (char c, char y);


//Explicit Specialization
//templates args should be empty
template<> const char* Max<const char*>(const char* x, const char*y)
{
    cout << "Explicit specialization" << endl;
    return strcmp(x,y) > 0 ? x : y;
}

template<int size>
void Print()
{
    char buffer[size]; //size is constant so we can use to specify the size of an array
    cout << size << endl;
}

template<typename T>
T Sum(T* parr, int size)
{
    T sum{};
    for(int i = 0; i < size; ++i)
    {
        sum += parr[i];
    }
    return sum;
}

template<typename T, int size> //use a non-type template argument, compute in compile time
T Sum2(T (&parr)[size]) //reference of an array
{
    T sum{};
    for(int i = 0; i < size; ++i)
    {
        sum += parr[i];
    }
    return sum;
}


int main() {

    //Non templates arguments should be const expressions
    //int i = 3;
    //Print<sizeof(i)>();
    
    Print<3>();
    
    int arr[]{1, 2, 3, 4};
    
    int(&ref)[4] = arr; // reference of array has to have same size of an array
    
    int sum = Sum(ref, 4);
    
    cout << sum << endl;
       
	return 0;
}
