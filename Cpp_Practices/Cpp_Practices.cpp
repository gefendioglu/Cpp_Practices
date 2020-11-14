#include <iostream>

template <class T>
class Stack
{
public:
	Stack() : head(nullptr) {};
	~Stack();
	void push(T data);
	T pop();

protected:
	class Element {
	public:
		Element(Element* n, T d) : next(n), data(d) {}
		Element* getNext() const { return next; }
		T value() const { return data; }

	private:
		Element* next;
		T data;
	};

	Element* head;
};



int main()
{

}




