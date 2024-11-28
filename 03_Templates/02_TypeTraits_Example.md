# Constrain a Template Function


Write a template function printIfIntegral that:
- Only works if the template parameter is an integral type (int, char, etc.).
- Does nothing (or fails to compile) for other types.

```cpp
#include <iostream>

using namespace std;

template <typename T>
class checkIntegral{
    public:
    void printIfIntegral(enable_if<T,int>){
        cout << "is an integer" << endl;
    }
    void printIfIntegral(enable_if<T,char>){
        cout << "is an integer" << endl;
    } 
};
```