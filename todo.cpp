#include <iostream>
#include "todo.h"
using namespace std;

int count;
struct task{
	int counter;
	string description;
	int time[2];
	int date[3];
};

//this function add a task..
void todo::addTask(){
	//read counter
	ifstream counter("counter",ios::in);
	counter>>count;
	counter.close();
	
	//write counter
	count++;
	ofstream counter1("counter",ios::out);
	counter1<<count;
	counter1.close();
	
	//Get the structure
	task shape;
	cin.ignore();
	getline(cin,shape.description);
	cout<<"Time input layout \"Hour Minute\"\n";
	cin>>shape.time[0]>>shape.time[1];
	cout<<"Date input layout \"Day Month Year\"\n";
	cin>>shape.date[0]>>shape.date[1]>>shape.date[3];
	
	//Write the task
	ofstream taskFile("data",ios::out | ios::app | ios::binary);
	taskFile<<endl;
	taskFile.write((char *) &shape, sizeof(struct task));
	taskFile.close();
}

//This function delete a task...
void todo::deleteTask(){
	
}

//Thid function refresh the state..
void todo::refresh(){
	cout<<"Ha ha nothing to do\n";
}

//This function show all task...
void todo::showTask(){
	
}
