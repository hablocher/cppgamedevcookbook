#include <vector>

using namespace std;

template <class T>
class Stack {
private:
	vector<T> elements;

public:
	void push(T const&);
	void pop();
	T top() const;
	bool empty() const {
		return elements.empty();
	}
};

template <class T>
void Stack<T>::push(T const& elem)
{
	elements.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (elements.empty()) {
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	elements.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if (elements.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return elements.back();
}