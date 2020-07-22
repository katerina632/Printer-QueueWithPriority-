#pragma once
#include<iostream>


using namespace std;
template <typename T>
class QueueWithPriority
{

	T* data;

	int* priorities;

	int maxSize;

	int size;

public:
	/*QueueWithPriority() : data(nullptr), size(0), priorities(nullptr), maxSize(0)
	{

	}*/

	QueueWithPriority(int maxSize) {

		this->maxSize = maxSize;
		data = new T[maxSize];
		priorities = new int[maxSize];
		size = 0;
	}

	~QueueWithPriority() {
		delete[] data;
		delete[] priorities;
	}

	QueueWithPriority(const QueueWithPriority& other)
	{

		data = new T[other.GetCount()];
		priorities = new int[other.GetCount()];

		size = other.GetCount();

		for (int i = 0; i < size; i++)
			data[i] = other.data[i];

		for (int i = 0; i < size; i++)
			priorities[i] = other.priorities[i];
	}

	QueueWithPriority operator=(const QueueWithPriority& other)
	{
		if (this == &other)
			return *this;

		if (size > 0)
		{
			delete[] data;
			delete[] priorities;
			size = 0;
		}

		data = new T[other.GetCount()];
		priorities = new int[other.GetCount()];


		size = other.GetCount();

		for (int i = 0; i < size; i++)
		{
			data[i] = other.data[i];
			priorities[i] = other.priorities[i];
		}
		return *this;
	}


	void AddWithPriority(T elem, int priority) {

		T* data2;
		int* priorities2;

		data2 = (T*)new T[size + 1];
		priorities2 = (int*)new int[size + 1];


		int pos;

		if (size == 0)
			pos = 0;
		else
		{
			pos = 0;
			while (pos < size)
			{
				if (priorities[pos] < priority)
					break;
				pos++;
			}
		}


		for (int i = 0; i < pos; i++)
		{
			data2[i] = data[i];
			priorities2[i] = priorities[i];
		}


		data2[pos] = elem;
		priorities2[pos] = priority;


		for (int i = pos + 1; i < size + 1; i++)
		{
			data2[i] = data[i - 1];
			priorities2[i] = priorities[i - 1];
		}

		if (size > 0)
		{
			delete[] data;
			delete[] priorities;
		}

		data = data2;
		priorities = priorities2;

		size++;
	}

	T ExtractElem() {

		/*if (size == 0)
			return 0;*/

		T* data2;
		int* priorities2;


		data2 = new T[size - 1]; 
		priorities2 = new int[size - 1];

		
		T item;
		item = data[0];

		
		for (int i = 0; i < size - 1; i++)
		{
			data2[i] = data[i + 1];
			priorities2[i] = priorities[i + 1];
		}

		
		if (size > 0)
		{
			delete[] data;
			delete[] priorities;
		}
		
		size--;
		
		data = data2;
		priorities = priorities2;
		
		return item;
	}

	T Peek() const {
		if (!IsEmpty())
		{

			int prIndex = 0;
			int prValue = priorities[0];


			for (int i = 1; i < size; ++i)
			{
				if (priorities[i] < prValue)
				{
					prValue = priorities[i];
					prIndex = i;
				}
			}

			return data[prIndex];
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
		cout << "\n-----------------------------------\n";
		
		for (int i = 0; i < size; i++) {
			//cout<<"\tPriority: " << priorities[i] << endl;
			cout << data[i] << endl;
		}
		cout << "\n-----------------------------------\n";
	}
};

