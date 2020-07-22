#include<iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include"QueueWithPriority.h"
#include "Document.h"
#include "Queue.h"




using namespace std;


int main() {	

	QueueWithPriority<Document> printer(5);
	
	Document d1("First", 25, rand() % 5);
	Document d2("Second", 55, rand() % 5);
	Document d3("Third", 15, rand() % 5);

	printer.AddWithPriority(d1, d1.GetPriority());
	printer.AddWithPriority(d2, d2.GetPriority());
	printer.AddWithPriority(d3, d3.GetPriority());

	printer.Show();
	

	Queue<string> printStatistics(3);

	string statistics;
	
	Document d5;	
	
	Time timeNow(15, 30, 40);
	cout << "\tTime now: " << timeNow.hours << ":" << timeNow.minutes
		<< ":" << timeNow.seconds << endl << endl;

	cout << "==Print documents==" << endl << endl;

	for (int i = 0; i < 3; i++) {
		statistics = "";
		d5 = printer.ExtractElem();
		statistics += d5.GetName() + " (";
		statistics += to_string(d5.GetSize()) + ") ";
		statistics += to_string(timeNow.hours) + ":" + to_string(timeNow.minutes+i*2) + ":" + to_string(timeNow.seconds+i);
		printStatistics.Enqueue(statistics);				
	}
	printStatistics.Show();


	system("pause");
	return 0;
}