#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Inheritance and polymorphism
namespace Unit04
{
	namespace InheritanceChain
	{
		class BaseClass
		{
		public:
			BaseClass() { cout << "BaseClass constructor.\n"; }
			~BaseClass() { cout << "BaseClass destructor.\n"; }
		};

		class DerivedClass : public BaseClass
		{
		public:
			DerivedClass() { cout << "DerivedClass constructor.\n"; }
			~DerivedClass() { cout << "DerivedClass destructor.\n"; }
		};

		int main()
		{
			cout << "We will now define a DerivedClass object.\n";
			DerivedClass object;
			cout << "The program is now going to end.\n";
			return 0;
		}
	}

	namespace BaseMemberAcess
	{
		class Base
		{
		private:
			int bsPvDta;
			void bsPvMthd() {}

		protected:
			int bsPtDta;
			void bsPtMthd() {}

		public:
			int bsPbDta;
			void bsPbMthd() {}
		};

		class Derived : protected Base
		{
		public: void drvPbMthd() { this->bsPtDta = 5; }
		};

		class DerivedDerived : protected Derived
		{
		public: void drvDrvPbMthd() { this->bsPtDta = 5; }
		};

		int	main()
		{
			Base bs; bs.bsPbDta = 10;

			Derived drv; drv.drvPbMthd();

			DerivedDerived drvDrv; drvDrv.drvDrvPbMthd();

			return 0;
		}


	}

	namespace GenericPrograming
	{
		class GeomObject
		{
		private: string color;
		public:
			GeomObject() : color("red")
			{
			}
			GeomObject(string c) : color(c)
			{
			}
			string getColor() const
			{
				return color;
			}
			string getString() const
			{
				return "Geometric Object";
			}
		};

		class Circle : public GeomObject
		{
		private: double radius;
		public:
			Circle()
			{
				radius = 1;
			}
			Circle(double r)
			{
				radius = r;
			}
			//Circle(double r, string c)
			//	: GeomObject(c), radius(r)
			//{
			//}
			string getString() const
			{
				return "Circle";
			}
		};

		class Rectangle : public GeomObject
		{
		private: double length, width;
		public:
			Rectangle(double l = 1, double w = 1, string c = "red")
				: GeomObject(c), length(l), width(w)
			{
			}
			string getString() const
			{
				return "Rectangle";
			}
		};

		void diaplayGeomData(const GeomObject& shape)
		{
			cout << "Shape: " << shape.getString() << endl;
			cout << "Color: " << shape.getColor() << endl;
		}

		int main()
		{
			GeomObject shape("red");
			Circle circle(8);
			Rectangle rectangle(3, 4, "green");

			diaplayGeomData(shape);
			diaplayGeomData(circle);
			diaplayGeomData(rectangle);

			return 0;
		}

	}

	namespace PolymorphismExample
	{
		class Animal
		{
		public:
			virtual void Speak() { cout << "Noise!\n"; }
			~Animal() {}
		};

		class Dog : public Animal
		{
		public: void Speak() { cout << "Woof!\n"; }
		};

		class Duck : public Animal
		{
		public: void Speak() { cout << "Quack!\n"; }
		};

		class Cat : public Animal
		{
		public: void Speak() { cout << "Meow!\n"; }
		};

		Animal* createAnimal()
		{
			int choice;
			cout << "Choose an animal: ";
			cin >> choice;
			switch (choice)
			{
			case 1: return new Dog();
			case 2: return new Duck();
			case 3: return new Cat();
			default: return nullptr;
			}
		}

		void test1()
		{
			int n;
			cout << "Number of animals: ";
			cin >> n;

			vector<Animal*> animals;

			for (int i = 0; i < n; i++)
				animals.push_back(createAnimal());

			for (Animal* animal : animals)
				if (animal) animal->Speak();

			for (Animal* animal : animals)
				delete animal;
			animals.clear();
		}

		void test2()
		{
			Animal* animals[3] = { new Dog(), new Duck(), new Cat() };

			for (int i = 0; i < 3; i++)
				animals[i]->Speak();
		}
	}

	namespace PolymorphismExample2
	{
		class PaymentMethod
		{
		public:
			virtual void pay(double amount) const
			{
				cout << "Paying " << amount << " EGP using a payment method." << endl;
			}
		};

		class Cash : public PaymentMethod
		{
		public:
			void pay(double amount) const override
			{
				cout << "Paying " << amount << " EGP in cash." << endl;
			}
		};

		class CreditCard : public PaymentMethod
		{
		public:
			void pay(double amount) const override
			{
				cout << "Paying " << amount << " EGP with a credit card." << endl;
			}
		};

		class VodafoneCash : public PaymentMethod
		{
		public:
			void pay(double amount) const override
			{
				cout << "Paying " << amount << " EGP through Vodafone Cash app." << endl;
			}
		};

		int main()
		{
			PaymentMethod* method1 = new Cash();
			PaymentMethod* method2 = new CreditCard();
			PaymentMethod* method3 = new VodafoneCash();

			method1->pay(100);
			method2->pay(250.5);
			method3->pay(75);

			delete method1;
			delete method2;
			delete method3;

			return 0;
		}

	}

	namespace AbstractClass
	{
		class PaymentMethod
		{
		public: virtual void pay(double amount) const = 0;
		};

		class Cash : public PaymentMethod
		{
		public:
			void pay(double amount) const override
			{
				cout << "Paying " << amount << " EGP in cash." << endl;
			}
		};

		class CreditCard : public PaymentMethod
		{
		public:
			void pay(double amount) const override
			{
				cout << "Paying " << amount << " EGP with a credit card." << endl;
			}
		};

		class VodafoneCash : public PaymentMethod
		{
		public:
			void pay(double amount) const override
			{
				cout << "Paying " << amount << " EGP through Vodafone Cash app." << endl;
			}
		};

		void processPayment(PaymentMethod* method, double amount)
		{
			method->pay(amount);
		}

		int main()
		{
			PaymentMethod* methods[] = {
				new Cash(),
				new CreditCard(),
				new VodafoneCash() };

			for (int i = 0; i < 3; i++)
				processPayment(methods[i], 100.0);

			for (int i = 0; i < 3; i++)
				delete methods[i];

			//delete[] methods;

			return 0;
		}
	}

	namespace FractionOverloading
	{
		class Fraction
		{
		public:
			Fraction(int num, int denom);
			Fraction(int num);
			Fraction(const Fraction& other);
			Fraction& operator=(const Fraction& other);
			Fraction& operator=(const int& other);
			Fraction operator+(const Fraction& other) const;
			Fraction operator+(const int& other) const;
			friend Fraction operator+(const int& lhs, const Fraction& rhs);
			friend ostream& operator<<(ostream& cout, const Fraction& rhs);

			double convertToDecimal() const { return double(numerator) / denominator; }
			operator double() const { return (double)numerator / denominator; }

		private:
			int numerator = 0;
			int denominator = 1;
		};

		Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {}
		Fraction::Fraction(int num) : Fraction(num, 1) {}
		Fraction::Fraction(const Fraction& other)
		{
			this->numerator = other.numerator;
			this->denominator = other.denominator;
		}

		Fraction& Fraction::operator=(const Fraction& other)
		{
			if (this != &other)
			{
				this->numerator = other.numerator;
				this->denominator = other.denominator;
			}
			return *this;
		}

		Fraction& Fraction::operator=(const int& other)
		{
			numerator = other;
			denominator = 1;
			return *this;
		}

		Fraction Fraction::operator+(const Fraction& other) const
		{
			int newNumerator = numerator * other.denominator + other.numerator * denominator;
			int newDenominator = denominator * other.denominator;
			return Fraction(newNumerator, newDenominator);
		}

		Fraction Fraction::operator+(const int& other) const
		{
			int newNumerator = numerator + other * denominator;
			int newDenominator = denominator;
			return Fraction(newNumerator, newDenominator);
		}

		Fraction operator+(const int& lhs, const Fraction& rhs)
		{
			int newNumerator = lhs * rhs.denominator + rhs.numerator;
			int newDenominator = rhs.denominator;
			return Fraction(newNumerator, newDenominator);
		}

		ostream& operator<<(ostream& cout, const Fraction& rhs)
		{
			cout << rhs.numerator << " / " << rhs.denominator;
			return cout;
		}

		void displayFraction(const Fraction& f)
		{
			cout << f << endl;
		}

		int test()
		{
			Fraction f1(1, 2);
			cout << f1 << endl;

			Fraction f2(2, 3);
			cout << f2 << endl;

			Fraction f3(3, 4);
			cout << f3 << endl;

			f1 = f2 = f3;
			cout << f1 << endl;

			f1 = f2;
			cout << f1 << endl;

			f1 = 1;
			cout << f1 << endl;

			Fraction f4 = f2 + f3;
			cout << f4 << endl;

			Fraction f5 = f2 + 5;
			cout << f5 << endl;

			Fraction f6 = 10 + f2;
			cout << (double)f6 << endl;
			cout << f6 << endl;

			double d = f6;
			cout << d << endl;

			displayFraction(f6);
			displayFraction(2);

			return 0;
		}
	}

	namespace MultipleInheritance
	{
		class Person
		{
		protected: string name;
		public:
			Person(const string& name) : name(name) {}
			virtual ~Person() = default;

			void setName(const string& newName) { name = newName; }
			string getName() const { return name; }
		};

		class Employee
		{
		protected: int id;
		public:
			Employee(int id) : id(id) {}
			virtual ~Employee() = default;

			void setId(int newId) { id = newId; }
			int getId() const { return id; }
		};

		class Manager : public Person, public Employee
		{
		private: string department;
		public:
			Manager(const string& name, int id, const string& dept)
				: Person(name), Employee(id), department(dept) {
			}

			void setDepartment(const string& newDept) { department = newDept; }
			string getDepartment() const { return department; }
		};

		int main()
		{
			return 0;
		}
	}
}

// Extending your code