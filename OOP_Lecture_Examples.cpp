#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
using namespace std;

// Basics of Procedural Programing
namespace Unit01
{

	namespace DataTypes
	{
		int main()
		{
			cout << "Size of short: " << sizeof(short) << endl;
			cout << "Size of int: " << sizeof(int) << endl;
			cout << "Size of long: " << sizeof(long) << endl;
			cout << "Size of long long: " << sizeof(long long) << endl;
			cout << "Size of double: " << sizeof(double) << endl;
			cout << "Size of long double: " << sizeof(long double) << endl;
			cout << "Size of float: " << sizeof(float) << endl;
			return 0;
		}
	}

	namespace SecondsToMinutes
	{
		int main()
		{
			int sec = 0;
			cout << "Enter seconds: ";
			cin >> sec;
			cout << "Minutes: " << sec / 60;
			cout << ", Seconds: " << sec % 60;
			return 0;
		}
	}

	namespace IncrementOperator
	{
		int main()
		{
			int a = 2;
			cout << a << "\n";
			a++;
			cout << a << "\n";
			return 0;
		}
	}

	namespace EnumExample
	{
		enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY };
		int main()
		{
			Day day = MONDAY;
			cout << day;
			Day day2 = WEDNESDAY;
			return 0;
		}
	}

	namespace StructExample
	{
		struct Student
		{
			int studentID;
			string name;
			short intake;
			double gpa;
		};

		int main()
		{
			Student stu1;
			getline(cin, stu1.name);
			Student esraa = { 1234, "Esraa" };
			Student kareem = { 1235, "Kareem", 45, 3.5 };
			return 0;
		}
	}

	namespace GradeCalculation
	{
		int main()
		{
			double score = 85;
			if (score >= 95.0) cout << "Grade is A";
			else
			{
				cout << "Grade is not A";
				if (score >= 80.0) cout << "Grade is B";
				else
				{
					cout << "Grade is not B";
					if (score >= 65.0) cout << "Grade is C";
					else
					{
						cout << "Grade is not C";
						cout << "Grade is F";
					}
				}
			}
			return 0;
		}
	}

	namespace BooleanExample
	{
		int main()
		{
			bool isEnrolled = true;
			bool isGraduated = false;

			cout << boolalpha;
			cout << "Enrolled: " << isEnrolled << endl;
			cout << "Graduated: " << isGraduated << endl;

			return 0;
		}
	}

	namespace CarExample
	{
		enum FuelType { ELECTRIC, DIESEL, PETROL, HYBRID };
		struct Car { FuelType type; int year; };

		int main() {
			Car myCar;
			myCar.type = HYBRID;
			myCar.year = 2020;
			cout << myCar.type << " " << myCar.year << endl;
			return 0;
		}
	}

	namespace TOEFLEligibility
	{
		int main()
		{
			double TOEFLScore = 0;
			cout << "Enter TOEFL score: ";
			cin >> TOEFLScore;
			bool hasGoodTOEFLScore = (TOEFLScore >= 79);

			bool passedEnglishPlacementTest;
			cout << "Did you pass the English Placement Test?: ";
			cin >> passedEnglishPlacementTest;

			bool isEligibleForAdmission = hasGoodTOEFLScore || passedEnglishPlacementTest;
			bool needsRemedialEnglish = !isEligibleForAdmission;

			if (isEligibleForAdmission)
				cout << "Admit student";
			else
				cout << "Enroll in a remedial English course";

			return 0;
		}
	}

	namespace LogicalOperators
	{
		int main()
		{
			cout << boolalpha << (1 < 4 > 3) << endl;
			cout << boolalpha << (1 == 2 == 0) << endl;
			return 0;
		}
	}

	namespace TVControl
	{
		const int MAX_TV_CHANNEL = 100;
		bool getTvStatus(const char* tvName)
		{
			return true;
		}
		int getTvCurrentChannel(const char* tvName)
		{
			return 0;
		}
		int main()
		{
			auto tv1 = "tv1";
			bool isTvOpen = getTvStatus(tv1);
			int currentChannel = getTvCurrentChannel(tv1);
			if (isTvOpen)
				if (currentChannel <= MAX_TV_CHANNEL)
					currentChannel++;
			if (isTvOpen && currentChannel <= MAX_TV_CHANNEL)
				currentChannel++;
			return 0;
		}
	}

	namespace FuelEfficiency
	{
		int main() {
			double distance, fuel;

			cout << "Enter distance traveled (km): ";
			cin >> distance;

			cout << "Enter fuel consumed (liters): ";
			cin >> fuel;

			if (fuel == 0 || (distance / fuel > 100))
				cout << "Error: Invalid input. Fuel must be greater than zero and efficiency should be realistic." << endl;
			else
				cout << "Fuel efficiency: " << distance / fuel << " km/L" << endl;

			return 0;
		}
	}

	namespace MaxFunction
	{
		double max(double num1, double num2)
		{
			if (num1 > num2) return num1;
			else return num2;
		}

		double max(double num1, double num2, double num3)
		{
			return max(max(num1, num2), num3);
		}

		int main()
		{
			cout << "The maximum of 3 and 4 is " << max(3, 4) << endl;
			cout << "The maximum of 3.0 and 5.4 is " << max(3.0, 5.4) << endl;
			cout << "The maximum of 3.0, 5.4, and 10.14 is " << max(3.0, 5.4, 10.14) << endl;
			cout << "The maximum of 3.5 and 4 is " << max(3.5, 4) << endl;
			return 0;
		}
	}

	namespace AreaCalculation
	{
		const double M_PI = 3.14159265358979323846;

		double calculateArea(double radius)
		{
			return M_PI * radius * radius;
		}

		double calculateArea(double length, double width)
		{
			return length * width;
		}

		int main()
		{
			cout << "Area of circle (radius 5): " << calculateArea(5.0) << endl;
			cout << "Area of rectangle (4 x 6): " << calculateArea(4.0, 6.0) << endl;
			return 0;
		}
	}

	namespace overloadingIssues
	{
		// Find the maximum of two double values
		double max(double num1, double num2)
		{
			if (num1 > num2)
				return num1;
			else
				return num2;
		}

		// Find the maximum of three double values
		double max(double n1, double n2, double n3)
		{
			double max1 = max(n1, n2);
			double max2 = max(n2, n3);
			return max(max1, max2);
		}

		// Find max of array of double values
		double max(double values[], int size)
		{
			double max = values[0];
			for (int i = 1; i < size; i++)
				if (values[i] > max)
					max = values[i];
			return max;
		}

		int main()
		{
			cout << max(1.0, 2) << endl;
			cout << max(1, 2.0) << endl;
			//cout << maxNumber(1, 2) << endl;
			return 0;
		}
	}

	namespace PassByReference
	{
		void resetValues(int a, int b)
		{
			a = 0;
			b = 0;
		}

		void updateNumbers(const int& m, int& n)
		{
			resetValues(m, n);
		}

		int main()
		{
			int x = 5, y = 5;
			updateNumbers(x, y);
			cout << x << " " << y;
			return 0;
		}
	}

	namespace SequenceDisplay
	{
		void displaySequence(int& from, int& to)
		{
			while (from <= to) cout << from++ << endl;
		}

		int main()
		{
			cout << "Enter two numbers: ";
			int num1, num2;
			cin >> num1 >> num2;
			cout << "The sequence:" << endl;
			displaySequence(num1, num2);
			cout << "That was the sequence from " << num1 << " to " << num2 << endl;
			return 0;
		}
	}

	namespace MaxFunctionOverload
	{
		int max(int& num1, int& num2)
		{
			int result;
			if (num1 > num2)
				result = num1;
			else
				result = num2;
			return result;
		}

		int main()
		{
			int i = 5;
			int j = 2;
			int k = max(i, j);
			return 0;
		}
	}

	namespace StaticVariable
	{
		void t1();
		void t2();

		int main()
		{
			t1();
			t2();
			return 0;
		}
		int y;
		void t1()
		{
			int x = 0;
			cout << "In t1: x is " << ++x << ", y is " << ++y << endl;
		}
		void t2()
		{
			int x = 0;
			cout << "In t2: x is " << ++x << ", y is " << ++y << endl;
		}
	}

	namespace StaticVariableScope
	{
		void t1();
		void t2();

		int main()
		{
			t1();
			t1();
			t2();
			return 0;
		}
		void t1()
		{
			int x = 0;
			static int y;
			y = 0;
			cout << "In t1: x is " << ++x << ", y is " << ++y << endl;
		}
		void t2()
		{
			int x = 0;
			static int y;
			cout << "In t2: x is " << ++x << ", y is " << ++y << endl;
		}
	}

	namespace ArrayPrint
	{
		void printArray(int arr[], int arraySize);

		int main()
		{
			int numbers[2];
			numbers[0] = -5; numbers[1] = 8;
			printArray(numbers, 2);
			return 0;
		}

		void printArray(int arr[], int arraySize)
		{
			cout << arr;
			for (int i = 0; i < arraySize; i++)
				cout << arr[i] << " ";
		}
	}

	namespace ArrayModification
	{
		void p(int arr[], int arraySize)
		{
			for (int i = 0; i < arraySize; i++)
				arr[i]++;
		}
		int main()
		{
			int numbers[] = { 1, 4, 3, 6, 8 };
			p(numbers, 5);
			return 0;
		}
	}

	namespace ArrayReverse
	{
		void reverse(const int inArr[], int outArr[], int size)
		{
			for (int i = 0, j = size - 1; i < size; i++, j--)
				outArr[j] = inArr[i];
		}
		int main()
		{
			int a[5] = { 1, 2, 3, 4, 5 };
			int b[5];
			reverse(a, b, 5);
			return 0;
		}
	}

	namespace PassByValueReference
	{
		void m(int num, int arr[], int size)
		{
			num = 1001;
			arr[0] = 5555;
		}

		int main()
		{
			int x = 1;
			int y[] = { 2,3 };

			m(x, y, 2);

			cout << "x is " << x << endl;
			cout << "y[0] is " << y[0] << endl;
			cout << "y[1] is " << y[1] << endl;

			return 0;
		}
	}

	namespace ScopeExample
	{
		int x; // Global variable

		class Test
		{
		public:
			int x = 10, y = 10; // Data fields

			void print()
			{
				int x = 20; // Local variable
				cout << "Local x is " << x << endl;
				cout << "Member x is " << Test::x << endl;
				cout << "Global x is " << ScopeExample::x << endl;
				cout << "Member y is " << y << endl;
			}
		};

		int main()
		{
			Test test;
			test.print();
			return 0;
		}
	}

	namespace CounterExample
	{
		struct Counter {
			int count;
			const int MAX;
		};

		Counter c = { 0, 10 };  // Global variable

		void increment() { if (c.count < c.MAX) c.count++; }
		void decrement() { if (c.count > 0) c.count--; }
		void reset() { c.count = 0; }
		void dispCount() { cout << "Count: " << c.count << endl; }

		int main() {
			for (int i = 0; i < 3; i++) increment();
			reset();
			for (int i = 0; i < 2; i++) increment();
			dispCount();
			return 0;
		}
	}

}

// Basics of OOP
namespace Unit02
{
	namespace StaleData
	{
		class Circle1
		{
		private:
			double radius = 1;
			double area = 3.14;
		public:
			void setRadius(double r) { radius = r; }
			void calcArea() { area = 3.14 * radius * radius; }
			double getRadius() { return radius; }
			double getArea() { return area; }
		};

		class Circle2
		{
		private:
			double radius = 1;
			double area = 3.14;
		public:
			void setRadius(double r)
			{
				radius = r;
				area = 3.14 * radius * radius;
			}
			double getRadius() { return radius; }
			double getArea() { return area; }
		};

		class Circle3
		{
		private:
			double radius = 1;

		public:
			void setRadius(double r) { radius = r; }
			double getRadius() { return radius; }
			double getArea() { return 3.14 * radius * radius; }
		};

		int main()
		{
			Circle1 c1;
			c1.setRadius(10);
			c1.calcArea();
			cout << "Area: " << c1.getArea() << endl;

			c1.setRadius(5);
			c1.calcArea();
			cout << "Area: " << c1.getArea() << endl;

			return 0;
		}
	}

	namespace AbstractionStringExample
	{
		int main()
		{
			string s1, s2;
			cin >> s1 >> s2;

			if (s1 == s2)
				cout << "The two strings are equal" << endl;
			else
				cout << "The two strings are not equal" << endl;

			return 0;
		}
	}

	namespace AbstractionFileExample
	{
		int main()
		{
			ofstream file("facts.txt");
			file << "CIE 101 is the best course ever!" << endl;
			file.close();

			return 0;
		}
	}

	namespace ConstMemberFunction
	{
		class Circle1
		{
		private:
			double radius = 1;
		public:
			void setRadius(double r) { radius = r; }
			double getRadius() { return radius; }
			double getArea() { return radius * radius * 3.14; }
		};

		class Circle2
		{
		private:
			double radius = 1;
		public:
			void setRadius(double r) { radius = r; }
			double getRadius() const { return radius; }
			double getArea() const { return radius * radius * 3.14; }
		};

		void someFunction(const Circle2& c)
		{
		}

		int main()
		{
			Circle1 c1;
			const Circle1 _c1;
			c1.setRadius(10);
			//_c1.

			Circle2 c2;
			const Circle2 _c2;
			c2.setRadius(10);
			_c2.getArea();
			cout << "Area: " << c2.getArea() << endl;

			return 0;

		}
	}

	namespace TVClass
	{
		class TV
		{
		private:
			int channel = 1, volumeLevel = 1;
			bool on = false;

		public:
			int getChannel() { return channel; }
			bool isOn() { return on; }

			void setChannel(int newChannel)
			{
				if (on && newChannel >= 1 && newChannel <= 120)
					channel = newChannel;
			}
			void TurnOn() { on = true; }
			void TurnOff() { on = false; }
		};
	}

	namespace SimpleGradeClass
	{
		class Grade
		{
		public:
			int static minGrade;
			int grade = 10;
		};

		int Grade::minGrade = 60;

		int main()
		{
			cout << Grade::minGrade;

			Grade g;
			cout << g.grade;

			return 0;
		}
	}

	namespace GradeClass
	{
		class Grade
		{
		private:
			int static minGrade;
			int grade;

		public:
			void setGrade(int v);
			double getGrade() const;
			void static setMinGrade(int v);
			static int getMinGrade();
			bool isPassing() const;
			string getPF() const;
		};

		int Grade::minGrade = 60;

		void Grade::setGrade(int v) { grade = v; }
		double Grade::getGrade() const { return grade; }

		void Grade::setMinGrade(int v) { minGrade = v; }
		int Grade::getMinGrade() { return minGrade; }

		bool Grade::isPassing() const { return grade >= minGrade; }

		string Grade::getPF() const
		{
			//if (isPassing()) return "P";
			//else return "F";
			return (isPassing() ? "P" : "F");
		}

		int main()
		{
			Grade s[10];
			for (int i = 0; i < 10; i++)
				s[i].setGrade(10 * i + 1);

			for (int i = 0; i < 10; i++)
				cout << s[i].getGrade() << ": "
				<< s[i].getPF() << endl;

			cout << string(5, '-') << endl;

			Grade::setMinGrade(20);
			for (int i = 0; i < 10; i++)
				cout << s[i].getGrade() << ": "
				<< s[i].getPF() << endl;

			return 0;
		}
	}

	namespace AppConfigExample
	{
		class AppConfig
		{
		private:
			AppConfig() = delete;
		public:
			static const int versionMajor;
			static const int versionMinor;
			static const string themeColor;
			static const int MAX_USERS;

			static void displayConfig()
			{
				cout << "Application Version: " << versionMajor << "." << versionMinor << endl;
				cout << "Theme Color: " << themeColor << endl;
				cout << "Maximum Number of Users: " << MAX_USERS << endl;
			}
		};

		const int AppConfig::versionMajor = 1;
		const int AppConfig::versionMinor = 0;
		const string AppConfig::themeColor = "DarkBlue";
		const int AppConfig::MAX_USERS = 100;

		int main()
		{
			AppConfig::displayConfig();
			return 0;
		}
	}

	namespace CircleStatic
	{
		class Circle
		{
		public:
			Circle(double = 1);
			~Circle();
			double getArea() const { return radius * radius * 3.14; }
			double getRadius() const { return radius; }
			void setRadius(double r) { radius = r; };
			static int getNumOfObjects();

		private:
			double radius;
			static int numOfObjects;
		};

		int Circle::numOfObjects = 0;

		Circle::Circle(double newRadius)
		{
			radius = newRadius;
			numOfObjects++;
		}

		int Circle::getNumOfObjects() { return numOfObjects; }

		Circle::~Circle() { numOfObjects--; }

		int main()
		{
			cout << "Number of circle objects created: " << Circle::getNumOfObjects() << endl;

			Circle circ1;
			cout << "The radius of the circle is " << circ1.getRadius() << endl;
			cout << "Number of circle objects created: " << Circle::getNumOfObjects() << endl;

			Circle circ2(5.0);
			cout << "The radius of the circle is " << circ2.getRadius() << endl;
			cout << "Number of circle objects created: " << circ2.getNumOfObjects() << endl;
			return 0;
		}
	}

	namespace ConstructorDestructor
	{
		class Demo
		{
		public:
			Demo() { cout << "1. Welcome to the constructor!\n"; }
			~Demo() { cout << "2. The destructor is running.\n"; }
		};

		int main()
		{
			Demo demoObject;
			cout << "A. This is a demo\n";
			cout << "B. for constructor / destructor.\n";
			return 0;
		}
	}

	namespace ConstructorDestructorOrder
	{
		class Demo
		{
		public:
			Demo() { cout << "1. Welcome to the constructor!\n"; }
			~Demo() { cout << "2. The destructor is running.\n"; }
		};

		void SomeGlobalFunction()
		{
			Demo demoObject;
		}

		int main()
		{
			SomeGlobalFunction();
			cout << "A. This is a demo\n";
			cout << "B. for constructor / destructor.\n";
			return 0;
		}
	}

	namespace ObjectArray
	{
		class Inventory
		{
		public:
			Inventory(string newName, double newSize) : name(newName), size(newSize)
			{
				cout << "You are using: Inventory(string, double)" << endl;
			}
			Inventory(string newName) : Inventory(newName, 0.0)
			{
				cout << "You are using: Inventory(string)" << endl;
			}
			Inventory(double newSize) : Inventory("Tool", newSize)
			{
				cout << "You are using: Inventory(double)" << endl;
			}
			Inventory() : Inventory("Tool", 0.0)
			{
				cout << "You are using: Inventory()" << endl;
			}
		private:
			string name;
			double size;
		};

		int main()
		{
			Inventory myInventoryAr1[5];
			Inventory myInventoryAr2[] = { 1,3,5 };
			Inventory myInventoryAr3[] =
			{
			  string("Hammer"),
			  string("Wrench")
			};
			Inventory myInventoryAr4[] =
			{
			  1,
			  Inventory(),
			  Inventory("Hammer",5),
			  string("Wrench")
			};


		}
	}

	namespace BookClass
	{
		class Book
		{
		private:
			string title, author;
			static int bookCount;

		public:
			Book(string t, string a);

			string getTitle() const { return title; }
			string getAuthor() const { return author; }

			void setTitle(const string& t) { title = t; }
			void setAuthor(const string& a) { author = a; }

			void displayDetails() const;

			static int getTotalBookCount() { return bookCount; }
		};

		int Book::bookCount = 0;

		Book::Book(string t, string a)
		{
			title = t;
			author = a;
			bookCount++;
		}
		inline void Book::displayDetails() const
		{
			cout << title << ", " << author << endl;
		}

		int main()
		{
			Book book1("Age of Science", "Ahmed Zewail");
			Book book2("The Book of Healing", "Ibn Sina");

			book1.displayDetails();
			book2.displayDetails();

			cout << "Total books: " << Book::getTotalBookCount() << endl;

			return 0;
		}
	}

	namespace InheritanceExample
	{
		class GeometricObject
		{
		public: string getColor() const { return "red"; };
		};

		class Circle : public GeometricObject
		{
		public: double getRadius() const { return 1; };
		};

		void dispData(const GeometricObject& o)
		{
			cout << o.getColor();
		}

		int main()
		{
			Circle c;
			dispData(c);
			return 0;
		}
	}

	namespace BankAccountExample
	{
		class BankAccount
		{
		private: double balance;

		public:
			BankAccount(double initBal) : balance(initBal) {}

			bool hasSameBalance(const BankAccount& other) const
			{
				return balance == other.balance;
			}
		};

		int main() {
			BankAccount account1(5000.00), account2(3000.00);

			if (account1.hasSameBalance(account2))
				cout << "Same balance." << endl;
			else
				cout << "Different balances." << endl;

			return 0;
		}
	}

	namespace ClassCommunication
	{
		class ClassB;
		class ClassA
		{
		public: int dataA = 1;
		public:
			bool isEqualToDataB(const ClassB& b);
		};

		class ClassB
		{
		public:
			int dataB = 2;
			bool isEqualToDataA(const ClassA& a)
			{
				return dataB == a.dataA;
			}
		};

		bool ClassA::isEqualToDataB(const ClassB& b)
		{
			return dataA == b.dataB;
		}

		int main()
		{
			ClassA objA;
			ClassB objB;
			cout << boolalpha << objB.isEqualToDataA(objA) << endl;
			return 0;
		}
	}

	namespace AssociationExample
	{
		class Instructor
		{
		private: string _name = "Default Name";
		public:
			void setName(string newName) { _name = newName; }
			string getName() const { return _name; }
		};

		class Student
		{
		private: Instructor* _instr = nullptr;
		public:
			void setInstr(Instructor& instr) { _instr = &instr; }
			string getInstrName() const
			{
				if (_instr) return _instr->getName();
				return "N/A";
			}
		};

		int main()
		{
			Instructor instr;
			cout << "Instr name: " << instr.getName() << endl;
			cout << string(24, '-') << endl;

			Student st1; st1.setInstr(instr);
			Student st2; st2.setInstr(instr);
			cout << "St 1 instr: " << st1.getInstrName() << endl;
			cout << "St 2 instr: " << st2.getInstrName() << endl;
			cout << string(24, '-') << endl;

			instr.setName("new name");
			cout << "Instr name: " << instr.getName() << endl;
			cout << string(24, '-') << endl;

			cout << "St 1 instr: " << st1.getInstrName() << endl;
			cout << "St 2 instr: " << st2.getInstrName() << endl;
			return 0;
		}
	}

}

// Pointers and Dynamic Memory Management
namespace Unit03
{

	namespace CirclePassByReference
	{
		class Circle
		{
		public:
			Circle(double r = 1) : radius(r) {}

			double getArea() const;
			double getRadius() const;
			void setRadius(double r);

		private:
			double radius;
		};

		void displayCircle(const Circle& c)
		{
			cout << "Radius: " << c.getRadius() << endl;
			cout << "Area: " << c.getArea() << endl;
		}

		void initializeCircle(Circle& c, double r)
		{
			c.setRadius(r);
		}

		int main()
		{
			Circle c(5);
			initializeCircle(c, 10);
			displayCircle(c);
			return 0;
		}

		double Circle::getArea() const { return radius * radius * 3.14159; }
		double Circle::getRadius() const { return radius; }
		void Circle::setRadius(double r) { radius = r; }
	}

	namespace RectangleConstructor
	{
		class Rectangle
		{
		private:
			double width = 1;
			double length = 2;
		public:
			Rectangle() : length(width), width(20) {}
			double getLength() const;
			double getWidth() const;
		};

		double Rectangle::getLength() const { return length; }
		double Rectangle::getWidth() const { return width; }

		void displayRectangle(const Rectangle& r)
		{
			cout << "Length: " << r.getLength() << endl;
			cout << "Width: " << r.getWidth() << endl;
		}

		int main()
		{
			Rectangle r;
			displayRectangle(r);
			return 0;
		}
	}

	namespace AggregationComposition
	{
		class Book
		{
		private: string title, author;
		public:
			Book(string t = "title", string a = "author") : title(t), author(a) {}
		};

		class TwoBookPackage
		{
		private: Book& book1, & book2;
		public:
			TwoBookPackage(Book& b1, Book& b2) : book1(b1), book2(b2) {}
		};

		void testAggregation()
		{
			Book book1("Age of Science", "Ahmed Zewail");
			Book book2("The Book of Healing", "Ibn Sina");
			TwoBookPackage package(book1, book2);
		}

		class Room
		{
		private: string name;
		public:
			Room(string n = "Room") : name(n) {}
		};

		class TwoRoomApartment
		{
		private:
			Room room1, room2;

		public:
			TwoRoomApartment(string n1, string n2)
			{
				room1 = Room(n1);
				room2 = Room(n2);
			}
		};

		void testComposition()
		{
			TwoRoomApartment apartment("Living Room", "Bedroom");
		}

		int main()
		{
			testAggregation();
			testComposition();
			return 0;
		}
	}

	namespace ArrayReverseExample
	{
		void reverse(int* list, int size)
		{
			int* left = list;
			int* right = list + size - 1;

			for (; left < right; ++left, --right)
			{
				int temp = *left;
				*left = *right;
				*right = temp;
			}
		}

		int main()
		{
			int myArray[5] = { 1, 2, 3, 4, 5 };
			reverse(myArray, 5);

			for (int i = 0; i < 5; i++)
				cout << myArray[i] << " ";

			return 0;
		}
	}

	namespace DynamicArrayExample
	{
		int main()
		{
			char continueInput = 'Y';

			while (continueInput == 'Y')
			{
				cout << "Enter the size of the array: ";
				int size;
				cin >> size;
				int* array = new int[size];

				cout << "Enter " << size << " integers:" << endl;
				int sum = 0;
				for (int i = 0; i < size; ++i)
				{
					cin >> array[i];
					sum += array[i];
				}

				cout << "You entered:" << endl;
				for (int i = 0; i < size; ++i)
					cout << array[i] << " ";
				cout << endl;
				cout << "The sum is: " << sum << endl;

				delete[] array;

				cout << "Do you want to enter another array? (Y/N): ";
				cin >> continueInput;
			}

			return 0;
		}
	}

	namespace AudioBufferExample
	{
		class AudioBuffer
		{
		private:
			float* samples = nullptr;
			int size = 0;
		public:
			const int CAPACITY;
			AudioBuffer(int n = 0) : CAPACITY(n)
			{
				if (n <= 0) return;
				samples = new float[n];
				for (int i = 0; i < n; ++i) samples[i] = 0.0;
			}

			AudioBuffer(const AudioBuffer& other) : CAPACITY(other.CAPACITY), size(other.size)
			{
				if (other.CAPACITY <= 0) return;
				samples = new float[other.CAPACITY];
				for (int i = 0; i < CAPACITY; ++i) samples[i] = other.samples[i];
			}

			~AudioBuffer() { delete[] samples; samples = nullptr; }

			bool addSample(float value)
			{
				if (!samples || size >= CAPACITY) return false;
				samples[size++] = value;
				return true;
			}
		};

		int main()
		{
			int NUM_SAMPLES = 50;
			AudioBuffer buffer(NUM_SAMPLES);

			ifstream file("samples.txt");
			float sample;

			while (file >> sample && buffer.addSample(sample)) {}

			file.close();
			return 0;
		}
	}

}

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
		}

		void test2()
		{
			Animal* animals[3] = { new Dog(), new Duck(), new Cat() };

			for (int i = 0; i < 3; i++)
				animals[i]->Speak();
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
				: Person(name), Employee(id), department(dept) {}

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
namespace Unit05
{
	namespace TemplateExample
	{
		template<typename AnyType>
		AnyType maxElement(AnyType arr[], int size)
		{
			AnyType max = arr[0];
			for (int i = 1; i < size; ++i)
				if (arr[i] > max)
					max = arr[i];
			return max;
		}

		template<typename T>
		T myMax(const T num1, const T num2)
		{
			if (num1 > num2) return num1; else return num2;
		}

		void test1()
		{
			cout << myMax(1, 3) << endl;
			cout << myMax(1.5, 0.3) << endl;
			cout << myMax(5, 2) << endl;
			cout << myMax('A', 'N') << endl;
			cout << myMax(string("NBC"), string("ABC")) << endl;
		}

		void test()
		{
			int intArr[] = { 1, 2, 3, 4, 5 };
			double doubleArr[] = { 1.1, 2.2, 3.3, 4.4 };
			string stringArr[] = { "CIE 101", "ENV 101" };

			cout << maxElement(intArr, 5) << endl;
			cout << maxElement(doubleArr, 4) << endl;
			cout << maxElement(stringArr, 2) << endl;
		}
	}

	namespace SelectionSortTemplate
	{
		template <typename T>
		void selectionSort(T arr[], int size)
		{
			for (int i = 0; i < size - 1; ++i)
			{
				int minIndex = i;
				for (int j = i + 1; j < size; ++j)
					if (arr[j] < arr[minIndex])
						minIndex = j;

				T temp = arr[minIndex];
				arr[minIndex] = arr[i];
				arr[i] = temp;
			}
		}

		template <typename T>
		void printArray(const T list[], int size)
		{
			for (int i = 0; i < size; i++)
				cout << list[i] << " ";
			cout << endl;
		}

		int test2()
		{
			int list1[] = { 3, 5, 1, 0, 2, 8, 7 };
			selectionSort(list1, 7);
			printArray(list1, 7);

			double list2[] = { 3.5, 0.5, 1.4, 0.4, 2.5, 1.8, 4.7 };
			selectionSort(list2, 7);
			printArray(list2, 7);

			string list3[] = { "Alexandria", "Cairo", "Luxor", "Aswan" };
			selectionSort(list3, 4);
			printArray(list3, 4);

			return 0;
		}
	}
}

// Overview of Modern C++ Features
namespace Unit06
{
}

// Test main function
int main()
{
	Unit02::GradeClass::main();
	return 0;
}