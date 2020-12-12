#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// Templates - Function Template for max()
// --------------------------------------------
// --------------------------------------------

//// One function works for all data types. 
//// This would work even for user defined types if operator '>' is overloaded 
//template <typename T>
//T myMax(T x, T y){
//	return (x > y) ? x : y;
//}
//
//int main(){
//
//	// Call myMax for int 
//	std::cout << myMax<int>(3, 7) << "\n"; // 7
//	
//	// call myMax for double 
//	std::cout << myMax<double>(3.0, 7.0) << "\n"; // 7
//
//	// call myMax for char 
//	std::cout << myMax<char>('g', 'e') << "\n"; // g
//
//	return 0;
//}



// Function Template for Bubble Sort
// --------------------------------------------
// --------------------------------------------

///* Function to swap two int elements */
//void swap(int* xp, int* yp) {
//	int temp = *xp;
//	*xp = *yp;
//	*yp = temp;
//}
//
///* A function template to implement bubble sort */
//template <typename T>
//void bubbleSort(T* arr, T length) {
//	for (T i = 0; i < length - 1; i++)
//
//		// Last i elements are already in place 
//		for (T j = 0; j < length - i - 1; j++)
//			if (arr[j] > arr[j + 1])
//				swap(&arr[j], &arr[j + 1]);
//}
//
///* Function to print an array */
//void printArray(int* arr, int length)
//{
//	std::cout << " Sorted array : ";
//	for (int i = 0; i < length; i++)
//		std::cout << arr[i] << " ";
//	std::cout << "\n";
//}
//
//int main() {
//
//	int arr[5] = { 10, 50, 30, 40, 20 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//
//	bubbleSort<int>(arr, 5);
//	printArray(arr, length);
//
//	return 0;
//	//  Sorted array : 10 20 30 40 50
//}



// Class Template for Bubble Sort
// --------------------------------------------
// --------------------------------------------

///* Function to swap two int elements */
//void swap(int* xp, int* yp) {
//	int temp = *xp;
//	*xp = *yp;
//	*yp = temp;
//}
//
//// A class template to implement bubble sort. 
//// We can use this for any data type that supports comparison operator < and swap works for it. 
//template <class T>
//void bubbleSort(T* arr, int length) {
//	for (int i = 0; i < length - 1; i++)
//		for (int j = length - 1; i < j; j--)
//			if (arr[j] < arr[j - 1])
//				swap(&arr[j], &arr[j - 1]);
//}
//
///* Function to print an array */
//void printArray(int* arr, int length)
//{
//	std::cout << " Sorted array : ";
//	for (int i = 0; i < length; i++)
//		std::cout << arr[i] << " ";
//	std::cout << "\n";
//}
//
//int main() {
//
//	int arr[5] = { 10, 50, 30, 40, 20 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//
//	bubbleSort<int>(arr, 5);
//	printArray(arr, length);
//
//	return 0;
//	//  Sorted array : 10 20 30 40 50
//}


// Class Template for Array Class
// --------------------------------------------
// --------------------------------------------

//template <typename T>
//class Array {
//public:
//	Array(T* arr, int size);
//	void print();
//private:
//	T* ptr;
//	int length;
//};
//
//template <typename T>
//Array<T>::Array(T* arr, int length) {
//	ptr = new T[length];
//	this->length = length;
//	for (int i = 0; i < length; i++)
//		ptr[i] = arr[i];
//}
//
//template <typename T>
//void Array<T>::print() {
//	for (int i = 0; i < length; i++)
//		std::cout << " " << *(ptr + i);
//	std::cout << "\n";
//}
//
//int main() {
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	Array<int> a(arr, 5);
//	a.print(); //  1 2 3 4 5
//
//	return 0;
//}


// Class templates with multiple arguments 
// --------------------------------------------
// --------------------------------------------

//template<class T, class U>
//class A {
//public:
//	A() { 
//		std::cout << "Constructor Called : " << typeid(x).name() << " " << typeid(y).name() << "\n"; 
//	}
//private:
//	T x;
//	U y;
//};
//
//int main() {
//	A<char, char> a;
//	A<int, double> b;
//
//	return 0;
//
//	/*
//		Constructor Called : char char
//		Constructor Called : int double
//	*/
//}


// Class templates with multiple arguments 
// --------------------------------------------
// --------------------------------------------

//// Class template with two parameters 
//template<typename T1, typename T2>
//class Test{
//public:
//	Test(T1 x, T2 y)	{
//		a = x;
//		b = y;
//	}
//	void show()	{
//		std::cout << a << " and " << b << "\n";
//	}
//private:
//	T1 a;
//	T2 b;
//};
//
//int main(){
//
//	// instantiation with float and int type 
//	Test <float, int> test1((float)1.23, 123);
//
//	// instantiation with float and char type 
//	Test <int, char> test2(100, 'W');
//
//	test1.show(); // 1.23 and 123
//	test2.show(); // 100 and W
//
//	return 0;
//}



// Class templates specifying default value
// --------------------------------------------
// --------------------------------------------

//template<class T, class U = char>
//class A {
//public:
//	A() {
//		std::cout << "Constructor Called : " << typeid(x).name() << " " << typeid(y).name() << "\n";
//	}
//private:
//	T x;
//	U y;
//};
//
//int main() {
//	A<char> a; // --> A<char, char>
//	A<int> b;  // --> A<int, char>
//
//	return 0;
//
//	/*
//		Constructor Called : char char
//		Constructor Called : int char
//	*/
//}



// Templates with non-type parameters 
// --------------------------------------------
// --------------------------------------------
//
//template <class T, int max>
//int arrMin(T* arr, int length){
//	int m = max;
//	for (int i = 0; i < length; i++)
//		if (arr[i] < m)
//			m = arr[i];
//
//	return m;
//}
//
//int main(){
//
//	int arr1[] = { 10, 20, 15, 12 };
//	int length1 = sizeof(arr1) / sizeof(arr1[0]);
//
//	char arr2[] = { 1, 2, 3 };
//	int length2 = sizeof(arr2) / sizeof(arr2[0]);
//
//	// Second template parameter to arrMin must be a constant 
//	std::cout << arrMin<int, 10000>(arr1, length1) << "\n"; // 10
//	std::cout << arrMin<char, 256>(arr2, length2) << "\n"; // 1
//
//	return 0;
//}



// Template Metaprogramming
// --------------------------------------------
// --------------------------------------------
//
//template<int n> struct funStruct{
//	enum { val = 2 * funStruct<n - 1>::val };
//};
//
//template<> struct funStruct<0>{
//	enum { val = 1 };
//};
//
//int main()
//{
//	std::cout << funStruct<8>::val << "\n"; // 256
//	return 0;
//}



//Function Templates and Static Variables 
// --------------------------------------------
// --------------------------------------------

//template <typename T>
//void fun(const T& x){
//	static int i = 10;
//	std::cout << ++i;
//	return;
//}
//
//int main(){
//
//	fun<int>(1);      // 11 
//	std::cout << "\n";
//	
//	fun<int>(2);      //  12 
//	std::cout << "\n";
//	
//	fun<double>(1.1); //  11 
//	std::cout << "\n";
//
//	return 0;
//}

// Class Templates and Static Variables
// --------------------------------------------
// --------------------------------------------

//template <class T> 
//class Test{
//public:
//	static int count;
//	Test()	{
//		count++;
//	}
//private:
//	T val;
//};
//
//// The static int variable shall be initialized
//template<class T>
//int Test<T>::count = 0;
//
//int main()
//{
//	Test<int> a; // value of count for Test<int> is 1 now 
//	Test<int> b; // value of count for Test<int> is 2 now 
//	Test<double> c; // value of count for Test<double> is 1 now 
//	std::cout << Test<int>::count << "\n";    // prints 2 
//	std::cout << Test<double>::count << "\n"; // prints 1 
//
//	return 0;
//}



// Function Template Specialization
// --------------------------------------------
// --------------------------------------------

//template <class T>
//void fun(T a){
//	std::cout << "The main template fun(): "
//		<< a << "\n";
//}
//
//template<>
//void fun(int a){
//	std::cout << "Specialized Template for int type: "
//		<< a << "\n";
//}
//
//int main()
//{
//	fun<char>('a');
//	fun<int>(10);
//	fun<float>((float)10.14);
//
//	/*
//		The main template fun(): a
//		Specialized Template for int type: 10
//		The main template fun(): 10.14
//	*/
//}



// Class Template Specialization
// --------------------------------------------
// --------------------------------------------

//template <class T>
//class Test{
//public:
//	Test()	{
//		// Initialization of data members 
//		std::cout << "General template object \n";
//	}
//};
//
//template <>
//class Test <int>{
//public:
//	Test()	{
//		// Initialization of data members 
//		std::cout << "Specialized template object\n";
//	}
//};
//
//int main()
//{
//	Test<int> a;
//	Test<char> b;
//	Test<float> c;
//
//	return 0;
//
//	/*
//		Specialized template object
//		General template object
//		General template object
//	*/
//}



// Variadic Function Templates
// --------------------------------------------
// --------------------------------------------

//// Recursive variadic function template 
//void print(){
//	std::cout << "I am empty function and "
//		"I am called at last.\n";
//}
//
//// Variadic function Template 
//template <typename T, typename... Types>
//void print(T var1, Types... var2){
//	std::cout << var1 << "\n";
//	print(var2...);
//}
//
//int main()
//{
//	print(1, 2, 3.14, "Pass any "
//		"number of arguments",
//		"I will print\n");
//
//	return 0;
//
//	/*
//		1
//		2
//		3.14
//		Pass any number of arguments
//		I will print
//
//		I am empty function and I am called at last.
//	*/
//}



