### Sequence Diagram

![Sequence Diagram](Png/01_Virtual_keyword.png)

---

### C++ Code Example: Virtual vs Non-Virtual Behavior

```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void print() {
        cout << "Base::print (non-virtual)" << endl;
    }

    virtual void vprint() {
        cout << "Base::vprint (virtual)" << endl;
    }
};

class Derived : public Base {
public:
    void print() {
        cout << "Derived::print (non-virtual override)" << endl;
    }

    void vprint() override {
        cout << "Derived::vprint (virtual override)" << endl;
    }
};

int main() {
    Base* ptr = new Derived();

    ptr->print();   // Calls Base::print (STATIC dispatch)
    ptr->vprint();  // Calls Derived::vprint (DYNAMIC dispatch via vtable)

    delete ptr;
    return 0;
}
```

---

### PlantUML Sequence Diagram Code (matching above)

```plantuml
@startuml
title How `virtual` Enables Dynamic Dispatch in C++

actor "C++ Developer" as Developer
participant "C++ Compiler" as Compiler
participant "Base Class" as Base
participant "Derived Class" as Derived
participant "Base Pointer (Base* ptr)" as BasePtr
participant "Derived Instance" as DerivedObj
participant "Virtual Pointer (vptr)" as Vptr
participant "Virtual Table (vtable)" as VTable
participant "Derived::vprint()" as DerivedPrint

== Compilation Phase ==
Developer -> Compiler: Define Base with virtual vprint()
Compiler -> Base: Add vtable & vptr
Compiler -> Base: Mark vprint() as virtual

Developer -> Compiler: Define Derived overrides vprint()
Compiler -> Derived: Replace vprint() entry in vtable

== Runtime Phase ==
Developer -> BasePtr: ptr->vprint()
activate BasePtr

BasePtr -> DerivedObj: Access actual object
BasePtr -> Vptr: Read vptr from DerivedObj
activate Vptr

Vptr -> VTable: Get address for vprint()
activate VTable

VTable -> DerivedPrint: Resolve override method
deactivate VTable

Vptr -> DerivedPrint: Call Derived::vprint()
deactivate Vptr
deactivate BasePtr

DerivedPrint -> Developer: Output: "Derived::vprint()"
@enduml

```

---


### Summary

| Feature         | `print()`                     | `vprint()`                      |
|----------------|-------------------------------|---------------------------------|
| Static/Dynamic | Static (compile-time)         | Dynamic (runtime via vtable)    |
| Behavior       | Calls `Base::print`            | Calls `Derived::vprint`         |
| Requires `virtual` | ❌ No                          | ✅ Yes                           |

