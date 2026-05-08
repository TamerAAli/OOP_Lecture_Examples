#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Extending Your Code: Templates, Casting, and Exception Handling
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

	namespace ClassTemplate
	{
		template <typename T> class Grade
		{
		private:
			T score;
		public:
			Grade();
			void setScore(const T&);
			T getScore() const;
		};

		template <typename T>
		Grade<T>::Grade()
		{
			this->score = 0;
		}

		template <typename T2>
		void Grade<T2>::setScore(const T2& score)
		{
			this->score = score;
		}

		template <typename T>
		T Grade<T>::getScore() const
		{
			return this->score;
		}
	}

	namespace Casting
	{
		class GeomObject
		{
		public:
			GeomObject() {}
			virtual double getArea() const { return 0; }
			virtual double getPerimeter() const { return 0; }
		};
		class Circle : public GeomObject
		{
		public:
			Circle(double r) {}
			double getRadius() const { return 0; }
			double getDiameter() const { return 0; }
		};
		class Rectangle : public GeomObject
		{
		public:
			Rectangle(double x, double y) {}
			double getWidth() const { return 0; }
			double getHeight() const { return 0; }
		};

		void displayGeomObject(const GeomObject* g)
		{
			if (g == nullptr) return;

			const Circle* ptrC = dynamic_cast<const Circle*>(g);
			const Rectangle* ptrR = dynamic_cast<const Rectangle*>(g);

			if (ptrC != nullptr)
			{
				cout << "The radius is " << ptrC->getRadius() << endl;
				cout << "The diameter is " << ptrC->getDiameter() << endl;
			}
			if (ptrR != nullptr)
			{
				cout << "The width is " << ptrR->getWidth() << endl;
				cout << "The height is " << ptrR->getHeight() << endl;
			}

			cout << "The area is " << g->getArea() << endl;
			cout << "The perimeter is " << g->getPerimeter() << endl;
		}

		int main()
		{
			vector<GeomObject*> geomObjectVector = {
				new Rectangle(3,4),
				new Rectangle(6,8),
				new Circle(5),
				new Circle(9)
			};

			for (GeomObject* geomObject : geomObjectVector) {
				displayGeomObject(geomObject);
				cout << string(20, '-') << endl;
			}

			return 0;
		}
	}

	namespace TryCatch0
	{
		int* readDataFile(const string& filelName, int size)
		{
			ifstream file(filelName);
			int* data = new int[size];
			//
			//if (!file)
			//{
			//	throw string("File not found: " + filelName);
			//}

			for (int i = 0; i < size; i++)
				file >> data[i];

			return data;
		}
		double calcAvg(const string& fileName, int N)
		{
			int* data = readDataFile(fileName, N);
			double sum = 0.0;
			for (int i = 0; i < N; i++)
				sum += data[i];
			return sum / N;
		}
		int main()
		{
			//
			//try
			//{
			int size = 10;
			double average = calcAvg("counts.txt", size);
			cout << "Average: " << average << endl;
			//}
			//
			//catch (const string& errorMessage)
			//{
			//	cout << "Error: " << errorMessage << endl;
			//}
			return 0;
		}

	}
	namespace TryCatch1
	{
		int F1(), F2(), F3();

		int main()
		{
			try
			{
				cout << F1() << endl;
			}
			catch (int e)
			{
				cout << "Exception1: " << e << endl;
			}
			catch (string e)
			{
				cout << "Exception2: " << e << endl;
			}

			return 0;
		}
		int F1()
		{
			F2();
			return 1;
		}

		int F2()
		{
			F3();
			return 2;
		}

		int F3()
		{
			throw string("Error in F3()");
			return 3;
		}
	}
	namespace TryCatch2
	{
		int F1(), F2(), F3();
		int main()
		{
			try
			{
				cout << F1() << endl;
			}
			catch (int e)
			{
				cout << "Exception: " << e << endl;
			}
			catch (string e)
			{
				cout << "Exception: " << e << endl;
			}
			catch (...)
			{
				cout << "Unknown exception" << endl;
			}

			return 0;
		}
		int F1()
		{
			try
			{
				F2();
			}
			catch (string e)
			{
				cout << "Exception: " << e << endl;
				throw string("Error in F1()");
			}
			return 1;
		}
		int F2()
		{
			try
			{
				F3();
			}
			catch (string e)
			{
				cout << "Exception: " << e << endl;
				throw;
			}
			return 2;
		}

		int F3()
		{
			throw string("Error in F3()");
			return 3;
		}
	}
	namespace TryCatch3
	{
		// Simulates a system check
		bool fetchBankStatus()
		{
			return false; // Change to false to trigger the 'E' exception
		}

		string getStudentName(int id)
		{
			if (id < 201300000) throw string("Invalid Student ID"); // Compact one-liner
			return "Adam";
		}

		double calculateTotal(double payment)
		{
			if (payment > 5000.0) throw 5000.0f;
			return payment + 15.50;
		}

		long generateReceipt(bool serverUp)
		{
			if (!serverUp) throw 'E';
			return 987654321L;
		}

		int main()
		{
			int id = 202900123;
			double payment = 4500.0;

			try
			{
				// 1. Fetch Name
				string name = getStudentName(id);
				cout << "Welcome, " << name << "!" << endl;

				// 2. Process Calculation
				double finalAmount = calculateTotal(payment);
				cout << "Total with fees: EGP " << finalAmount << endl;

				// 3. Finalize Transaction with fetched status
				long receipt = generateReceipt(fetchBankStatus());
				cout << "SUCCESS! Confirmation: #" << receipt << endl;
			}
			catch (string msg) { cout << "DATA ERROR: " << msg << endl; }
			catch (float limit) { cout << "FINANCE ERROR: Limit is EGP " << limit << endl; }
			catch (char code) { cout << "SERVER ERROR: Code " << code << endl; }
			catch (...) { cout << "An unexpected error occurred." << endl; }

			return 0;
		}
	}
	namespace TryCatch4
	{
		// --- Deepest Level: Returns a value OR throws ---
		string databaseLookup(int bookId)
		{
			if (bookId == 0)
			{
				throw string("Database Connection Failed!");
			}
			if (bookId < 0)
			{
				throw bookId;
			}

			if (bookId == 101) return "C++ Programming 101";
			if (bookId == 102) return "Data Structures & Algorithms";

			return "Unknown Book";
		}

		// --- Middle Level: Logic and "Rethrowing" ---
		void processLoan(int bookId, bool isMember)
		{
			try
			{
				string title = databaseLookup(bookId);

				if (!isMember)
				{
					throw 40.0f; // Guest fine
				}

				cout << "SUCCESS: You have borrowed '" << title << "'" << endl;
			}
			catch (int errId)
			{
				// Local fix for an invalid ID
				cout << "[Library Level] Handling error: ID " << errId << " is invalid. Re-directing to help desk." << endl;
			}
		}

		// --- Top Level: Dynamic User Input ---
		int main()
		{
			int userBookId;
			bool userIsMember;

			cout << "--- Digital Library Portal ---" << endl;
			cout << "Enter Book ID (Try 101, 0, or -1): ";
			cin >> userBookId;

			cout << "Are you a member? (1 for Yes, 0 for No): ";
			cin >> userIsMember;

			try
			{
				processLoan(userBookId, userIsMember);
			}
			catch (string sysError)
			{
				cout << "[Main Level] CRITICAL SYSTEM ALERT: " << sysError << endl;
			}
			catch (float fine)
			{
				cout << "[Main Level] PAYMENT REQUIRED: Please pay $" << fine << " to borrow as guest." << endl;
			}
			catch (...)
			{
				cout << "[Main Level] An unexpected error occurred." << endl;
			}

			cout << "--- Session Ended ---" << endl;
			return 0;
		}
	}
}