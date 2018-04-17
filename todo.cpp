#include <iostream>
#include "todo.h"
using namespace std;

struct task{
	int counter;
	string description;
	int time[2];
	int date[3];
};

//this function add a task..
void todo::addTask(){
	task shape;
	cin.ignore();
	getline(cin,shape.description);
	cout<<"Time input layout \"Hour Minute\"\n";
	cin>>shape.time[0]>>shape.time[1];
	cout<<"Date input layout \"Day Month Year\"\n";
	cin>>shape.date[0]>>shape.date[1]>>shape.date[3];
	ofstream taskFile("data",ios::out | ios::app);
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
