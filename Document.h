#pragma once
#include<iostream>
#include<string>
using namespace std;


struct Time {
	int hours, minutes, seconds;

	Time() : hours(0), minutes(0), seconds(0) {}
	
	Time(int h, int m, int s) : hours(h), minutes(m), seconds(s)
	{
		CorrectValues();
	}

	void CorrectValues();
};

class Document
{
private:
	string name;
	int size;
	int priority;

	friend ostream& operator<<(ostream& os, const Document& dt);

public:
	Document() : name("No name"), size(0),priority(0) {}
	Document(string name, int size,int prior) : name(name), size(size),priority(prior) {}

	void Show() const;

	const string GetName() const;

	const int GetSize() const;

	const int GetPriority() const;
};

