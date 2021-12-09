#pragma once
constexpr auto mSize = 50;

#include <iostream>

template <typename T>
class TStack {
private:
	T *_stack;									
	int _size;								
	int _last_index;							
public:
	TStack();
	TStack(int size);			
	TStack(const TStack<T> &stack);
	~TStack();
  [[nodiscard]] int getSize() const {return _size;}
	int getLastIndex() const {return _last_index;}
	TStack<T>& operator=(const TStack<T>& stack);

	bool isFull();
	bool nFull(T* &stack);					
	bool isEmpty();							
	void push(const T &value);	
	double put ();							
	double peek ();							
	
	template <typename T>
	friend std::ostream& operator<<(std::ostream &out, const TStack<T> &v);
};
	
template <typename T>
std::ostream& operator<<(std::ostream &out, const TStack<T> &v)
{
	for (int i = v._last_index; i >= 0; i--)
	{
		out << v._stack[i] << endl;
	}
	return out;
}

template <typename T>
TStack<T>::TStack()
{
  _stack = new T[mSize];
	_size=mSize;
	for (int i = 0; i < _size; i++)
	{
		_stack[i] = 0;
	}
  _last_index = -1;							
}

template <typename T>
TStack<T>::TStack(int size)
{
	if (size < 0)
	{
		throw ("negative length");
	}

	_size = size;
  _stack = new T[_size];						
	for (int i = 0; i < _size; i++)
	{
		_stack[i]=0;
	}
  _last_index = -1;							
}

template <typename T>
TStack<T>::~TStack()						
{
    delete [] _stack; 
}

template <typename T>                       
TStack<T>::TStack(const TStack<T> & stack)
{
	_size = stack.getSize();
  _stack = new T[_size];
  _last_index = stack.getLastIndex();

  for(int i=0;i<_last_index;i++)
  {
      _stack[i] = stack._stack[i];
  }
}

template <typename T>						
void TStack<T>::push(const T &value)
{
	if(this->isFull())
	{
		throw "Full";
	}
	else
	{
		_last_index++;
		_stack[_last_index] = value;
	}
} 

template <typename T>
bool TStack<T>::nFull(T* &stack)
{
  if (_last_index < _size) 
  {
	  return true;
  }
	return false;
}

template <typename T>
bool TStack<T>::isFull() {
	if (_last_index == _size - 1)
	{
		return true;
	}
	return false;
}

template <typename T>
bool TStack<T>::isEmpty()
{
	if (_last_index == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
double TStack<T>::put()
{
	if (this->isFull())
	{
		throw "Full";
	}
	else
	{
	  double top = _stack[_last_index];
	  _last_index--;
	  return top;
	}
}

template <typename T>
double TStack<T>::peek()
{
	if (this->isEmpty())
	{
		throw ("Empty");
	}
	return _stack[_last_index];
}

template <typename T>
TStack<T>& TStack<T>::operator=(const TStack<T>& s)
{
	if (_stack == s._stack) 
	{
		return *this;
	}
	_size = s._size;
	_last_index = s._last_index;
	delete[]_stack;
	_stack = new T[_size];
	for (int i = 0; i < _size; i++) 
	{
		_stack[i] = s._stack[i];
	}
	return *this;
}

