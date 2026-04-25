#include <iostream>
using namespace std;

class Animal
{
public:
	void Speak() { cout << "Sound!\n"; }
	~Animal() { cout << "Animal destructor called.\n"; }
};

class Dog : public Animal
{
public:
	void Speak() { cout << "Woof!\n"; }
	~Dog() { cout << "Dog destructor called.\n"; }
};

class Duck : public Animal
{
public:
	void Speak() { cout << "Quack!\n"; }
	~Duck() { cout << "Duck destructor called.\n"; }
};

class Cat : public Animal
{
public:
	void Speak() { cout << "Meow!\n"; }
	~Cat() { cout << "Cat destructor called.\n"; }
};

void processAnimal(Animal* animal)
{
	animal->Speak();
}

int main()
{
	Animal* animals[3] = { new Dog(), new Duck(), new Cat() };

	for (int i = 0; i < 3; i++)
		processAnimal(animals[i]);

	return 0;
}
