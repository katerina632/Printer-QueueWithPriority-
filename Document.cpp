#include "Document.h"

ostream& operator<<(ostream& os, const Document& dt)
{
	
	cout << "Name of document: " << dt.name << endl;
	cout << "Size of document: " << dt.size << endl;
	cout << "Priority of document: " << dt.priority << endl;
	cout << endl;
	return os;
	
}

void Time::CorrectValues()
{
	if (seconds >= 60) {
		minutes = minutes + seconds / 60;
		while (seconds >= 60) {
			seconds = seconds - 60;
		}
	}
	if (minutes >= 60) {
		hours = hours + minutes / 60;
		while (minutes >= 60) {
			minutes = minutes - 60;
		}
	}
}

void Document::Show() const
{
	cout << "Name of document: " << name << endl;
	cout << "Size of document: " << size << endl;
	cout << "Çriority of document: " << priority << endl;
}

const string Document::GetName() const
{
	return name;
}

const int Document::GetSize() const
{
	return size;
}

const int Document::GetPriority() const
{
	return priority;
}
