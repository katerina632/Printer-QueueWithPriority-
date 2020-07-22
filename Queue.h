#pragma once
#include<iostream>
#include<string>
using namespace std;


template <class T>
class Queue
{	
	T* data;	
	int maxSize;	
	int size;

public:
	Queue() = default;	
	Queue(int maxSize) {
	
		this->maxSize = maxSize;

		data = new T[maxSize];

		size = 0;
	}
	~Queue() {
		delete[]data;
	}
	
	void Enqueue(T elem) {
		if (!IsFull())
			data[size++] = elem;
	}

	T Dequeue() {
	
		if (!IsEmpty())
		{
			T first = data[0];

			for (int i = 0; i < size - 1; i++)
			{
				data[i] = data[i + 1];
			}

			--size;

			return first;
		}
	}

	bool IsEmpty() const {
		return size == 0;
	}

	bool IsFull() const {
	
		return size == maxSize;
	}
	
	int GetCount() const {
		return size;
	}
	
	void Clear() {
		size = 0;
	}
	
	void Show() const {
	
		for (int i = 0; i < size; i++)
			cout << data[i] << endl;
		cout << endl;	

		
	}
};

