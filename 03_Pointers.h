#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Pointers and Dynamic Memory Management
namespace Unit03
{
	namespace UsingPointers
	{
		int main()
		{
			int    a = 3;
			char   s = 'z';
			double d = 1.03;

			int* pa = &a;
			char* ps = &s;
			double* pd = &d;

			cout << sizeof(pa) << " " << sizeof(*pa) << " " << sizeof(&pa) << endl;
			cout << sizeof(ps) << " " << sizeof(*ps) << " " << sizeof(&ps) << endl;
			cout << sizeof(pd) << " " << sizeof(*pd) << " " << sizeof(&pd) << endl;

			return 0;
		}
	}

	namespace ZombieExample
	{
		class Zombie
		{
		private:
			static int ID;
			int myID;
		public:
			Zombie() { myID = ++ID; }
			int getID() const { return myID; }
		};
		int Zombie::ID = 0;

		class GameLevel
		{
		private:
			int currentLevel = 1;
		public:
			Zombie* spawnZombies()
			{
				Zombie z[100];
				for (int i = 0; i < 100; i++)
				{
					cout << z[i].getID() << " ";
				}
				return z;
			}
		};

		int main()
		{
			GameLevel level;
			Zombie* z = level.spawnZombies();
			for (int i = 0; i < 100; i++)
			{
				cout << z[i].getID() << " ";
			}

			return 0;
		}
	}

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
				: room1(n1), room2(n2)
			{
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

			AudioBuffer(const AudioBuffer& other) //: AudioBuffer(other.CAPACITY)
				: CAPACITY(other.CAPACITY), size(other.size)
			{
				if (other.CAPACITY <= 0) return;
				samples = new float[other.CAPACITY];
				for (int i = 0; i < CAPACITY; ++i) samples[i] = other.samples[i];
			}

			//AudioBuffer& operator=(const AudioBuffer& other)
			//{
			//	CAPACITY = other.CAPACITY, size = other.size;
			//	if (other.CAPACITY <= 0) return *this;
			//
			//	if (samples) delete[] samples;
			//	samples = new float[other.CAPACITY];
			//	for (int i = 0; i < CAPACITY; ++i) samples[i] = other.samples[i];
			//
			//	return *this;
			//}
			AudioBuffer& operator=(const AudioBuffer& other) = delete;

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

	namespace NoExceptionHandling
	{

		class BankAccount
		{
		private:
			int accountID;
			double balance = 0;

		public:
			BankAccount(int id)
			{
				this->accountID = id;
			}

			int getAccountID() const { return accountID; }
			double getBalance() const { return balance; }

			void deposit(double amount)
			{
				if (amount <= 0) return;
				balance += amount;
			}

			void withdraw(double amount)
			{
				if (amount <= 0) return;
				if (amount > balance) return;
				balance -= amount;
			}
		};

		double findAccountBalance(BankAccount* account, int searchID)
		{
			if (account == nullptr) return -1.0;
			if (searchID <= 0 || searchID > 10000) return -1.0;

			if (account->getAccountID() == searchID)
				return account->getBalance();

			return -1.0;
		}

		BankAccount* prepareTestData()
		{
			BankAccount* myAccount = new BankAccount(123);
			myAccount->deposit(5000.0);
			myAccount->withdraw(2000.0);

			return myAccount;
		}

		int main()
		{
			BankAccount* myAccount = prepareTestData();

			int id;
			cout << "Enter account ID to find balance: ";
			cin >> id;

			double balance;

			balance = findAccountBalance(myAccount, id);

			if (balance == -1.0)
				cout << "Failed to find valid balance.\n";
			else
				cout << "Account Balance: $" << balance << endl;

			return 0;
		}
	}

	namespace WithExceptionHandling
	{

		class BankAccount
		{
		private:
			int accountID;
			double balance = 0;

		public:
			BankAccount(int id)
			{
				this->accountID = id;
			}

			int getAccountID() const { return accountID; }
			double getBalance() const { return balance; }

			void deposit(double amount)
			{
				if (amount <= 0) return;
				balance += amount;
			}

			void withdraw(double amount)
			{
				if (amount <= 0) return;
				if (amount > balance) return;
				balance -= amount;
			}
		};

		double findAccountBalance(BankAccount* account, int searchID)
		{
			if (account == nullptr) throw string("database connection error");
			if (searchID <= 0 || searchID > 10000) throw string("searchID is invalid");

			if (account->getAccountID() == searchID)
				return account->getBalance();

			throw string("ID not found");
		}

		BankAccount* prepareTestData()
		{
			BankAccount* myAccount = new BankAccount(123);
			myAccount->deposit(5000.0);
			myAccount->withdraw(2000.0);

			return myAccount;
		}

		int main()
		{
			BankAccount* myAccount = prepareTestData();

			int id;
			cout << "Enter account ID to find balance: ";
			cin >> id;

			double balance;

			try
			{
				balance = findAccountBalance(myAccount, id);
				cout << "Account Balance: $" << balance << endl;
			}
			catch (string e)
			{
				cout << "Error: " << e;
			}

			return 0;
		}
	}
}