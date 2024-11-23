// Task 11: std::unique_ptr and Polymorphism (Inheritance)
// In this task, you'll work with std::unique_ptr in the context of polymorphism and inheritance.

// Instructions:
// Create a base class (e.g., Animal) with a virtual function speak().
// Create at least two derived classes (e.g., Dog and Cat), each overriding the speak() function.
// Use a std::vector<std::unique_ptr<Animal>> to store objects of type Dog and Cat polymorphically.
// Iterate over the vector and call the speak() function on each object, demonstrating polymorphic behavior.
// Ensure that the memory is automatically cleaned up when the std::unique_ptr goes out of scope.

#include <iostream>
#include <vector>

using namespace std;

class Animal{
    public:
    virtual void speak(){
        cout << "Animal speaking" << endl;
    }
};

class Dog : public Animal{
    public:
    void speak() override {
        cout << "Dog speaking" << endl;
    }
};

class Cat : public Animal{
    public:
    void speak() override {
        cout << "cat speaking" << endl;
    }
};

int main(){
    vector<unique_ptr<Animal>> vec_to_unique_animal;
    Animal a;
    Dog d;
    Cat c;

    vec_to_unique_animal.push_back(make_unique<Animal>(a));
    vec_to_unique_animal.push_back(make_unique<Animal>(d));
    vec_to_unique_animal.push_back(make_unique<Animal>(c));

    for(const auto& val : vec_to_unique_animal){
        val->speak();
    }


    return 0;
}