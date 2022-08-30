#include <iostream>

using namespace std;



template <class T> class stack
{
	int top;
	T* arr;
	int size;
public:
	stack();
	void show();
	void push(T x);
	T pop();
	T peek(int pos);
	bool IsEmpty();
	bool IsFull();

};

template <class T> stack<T>::stack()
{
	top = -1;
	/*Dynamically array creation , Header for type identification 
	#include <typeinfo>
	cout << "Enter the array size : " << typeid(T).name() << endl;
	cin >> size;*/

	size = 10;
	arr = new T[size];
}

template <class T> void stack<T>::show()
{
	if (top == -1)
	{
		cout << "stack is empty " << endl;
		return;

	}	
	for (int i = top;i >= 0;i--)
		cout << arr[i]<<" ";
	cout << endl;
}

template <class T> void stack<T>::push(T x)
{
	//check isfull condition fails then do push
	if (IsFull())
	{
		cout << "stack overflow " << endl;
		return;
	}

	arr[++top] = x;
}

template <class T> T stack<T>::pop()
{
	//check for isempty condition fails then do pop
	if (IsEmpty())
	{
		cout << "stack underflow " << endl;
		return NULL;
	}

	return arr[top--];
}

template <class T> T stack<T>::peek(int pos)
{
	//check for valid pos condition satisfies then do peek
	if(pos<1 || top+1-pos<0)
	{
		cout << " Invalid Position given " << endl;
		return NULL;
	}


	return arr[top + 1 - pos];

}

template <class T> bool stack<T>::IsEmpty()
{
	return top == -1;
}

template <class T> bool stack<T>::IsFull()
{
	return top == size - 1;
}



int main()
{
	cout << "stack of integer is creating ...." << endl;
	stack<int> stack_int;
	stack<char> stack_char;
	stack<string> stack_string;

	stack_int.push(10);
	stack_int.push(20);
	stack_int.push(30);
	stack_int.push(40);
	stack_int.push(50);
	stack_int.push(60);
	stack_char.push('a');
	stack_char.push('b');
	stack_char.push('c');
	stack_char.push('d');
	stack_char.push('e');
	stack_string.push("keert");
	stack_string.push("pavi");
	stack_string.push("zoho");
	stack_string.push("freshworks");
	stack_string.push("amma");
	stack_string.push("50lpa");

	stack_int.show();
	stack_char.show();
	stack_string.show();

	cout<<"poped from int stack : " << stack_int.pop() << endl;
	cout <<"poped from int stack :" << stack_int.pop() << endl;
	cout <<"peeked the 4 th pos in int stack :" << stack_int.peek(4) << endl;
	cout<<"poped the char stack : " << stack_char.pop() << endl;
	cout <<"peek the 3rd pos in char stack : " << stack_char.peek(3) << endl;
	cout<<"poped the string stack :" << stack_string.pop() << endl;
	cout <<"peeked the 1st pos in string stack : " << stack_string.peek(1) << endl;

	stack_int.show();
	stack_char.show();
	stack_string.show();
	


}
