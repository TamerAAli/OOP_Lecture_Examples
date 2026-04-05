#pragma once
#include <iostream>
#include <string>

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

	namespace sumSeries
	{
		int sumSeries(int i1, int i2)
		{
			int sum = 0;
			for (int i = i1; i <= i2; i++)
				sum += i;
			return sum;
		}

		int sumSeries2(int i1, int i2)
		{
			int N = i2 - i1 + 1;
			return N * (i1 + i2) / 2;
		}

		int main()
		{
			cout << "Sum from 1 to 10 is " << sumSeries(1, 10) << endl;
			cout << "Sum from 20 to 37 is " << sumSeries(20, 37) << endl;
			cout << "Sum from 35 to 49 is " << sumSeries(35, 49) << endl;
			cout << "Sum from 1 to 100 is " << sumSeries(1, 100) << endl;
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

		double max(double values[], int arrayLength)
		{
			double max = values[0];
			for (int i = 1; i < arrayLength; i++)
				if (values[i] > max)
					max = values[i];

			return max;
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

	namespace refExample
	{
		int main()
		{
			int count = 1;
			int& r = count;

			r++;

			count = 10;

			cout << r;
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