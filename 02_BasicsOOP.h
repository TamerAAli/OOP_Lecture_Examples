#pragma once
#include <iostream>
#include <string>

using namespace std;


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
		class Circle
		{
		private:
			double radius = 1;
		public:
			void setRadius(double r) { radius = r; }
			double getRadius() const { return radius; }
			double getArea() const { return radius * radius * 3.14; }
		};

		void someFunction(const Circle& c)
		{
			//c.
		}

		int main()
		{
			Circle c;
			const Circle _c;

			c.setRadius(9);
			cout << c.getArea();

			//_c.setRadius(9);

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

	namespace LimitedIntExample
	{
		class LimitedInt
		{
		private:
			const int MIN;
			const int MAX;
			int value;
		public:
			LimitedInt(int min, int max, int val) : MIN(min), MAX(max), value(val)
			{
				if (value < MIN || value > MAX)
					value = MIN;
			}
			LimitedInt(int min, int max) : LimitedInt(min, max, min)
			{
			}
			LimitedInt(int val) : LimitedInt(INT_MIN, INT_MAX, val)
			{
			}
			LimitedInt() : LimitedInt(INT_MIN, INT_MAX, 0)
			{
			}
			int getValue() const
			{
				return value;
			}
			void setValue(int val)
			{
				if (val < MIN)
					value = MIN;
				else if (val > MAX)
					value = MAX;
				else
					value = val;
			}
			operator int() const
			{
				return value;
			}

			void operator= (int val)
			{
				setValue(val);
			}
		};

		int main()
		{
			LimitedInt a, b, c;
			a = 1;
			b = 90;
			c = a + b;

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
			return 0;

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