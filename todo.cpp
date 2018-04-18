#include <iostream>
#include "todo.h"
using namespace std;

int count;
struct task{
	int countTask;
	string description;
	unsigned long int time[2];
   	unsigned long int date[3];
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
	shape.countTask=count;
	cout<<"Write task Description:\n"; 
	cin.ignore();
	getline(cin,shape.description);
	cout<<"Time input layout \"Hour Minute\"\n";
	cin>>shape.time[0]>>shape.time[1];
	cout<<"Date input layout \"Day Month Year\"\n";
	cin>>shape.date[0]>>shape.date[1]>>shape.date[2];
	
	//Write the task
	ofstream taskFile("data",ios::out | ios::app);
	taskFile<<shape.countTask<<endl;
	taskFile<<shape.time[0]<<" "<<shape.time[1]<<endl;
	taskFile<<shape.date[0]<<" "<<shape.date[1]<<" "<<shape.date[2]<<endl;
	taskFile<<shape.description<<endl;;
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
	char temp;
	task shape;
	
	//Reading How many task have..
	ifstream counter("counter");
	counter>>count;
	counter.close();
	
	//
	ifstream taskFile("data"); 
	for(int i=1;i<=count;i++){
		taskFile>>shape.countTask;
		taskFile>>shape.time[0]>>shape.time[1];
		taskFile>>shape.date[0]>>shape.date[1]>>shape.date[2];
		taskFile.ignore();
		getline(taskFile,shape.description);
	
		cout<<shape.countTask<<". "<<shape.time[0]<<": "<<shape.time[1]<<", "<<shape.date[0]<<"-"<<shape.date[1]<<"-"<<shape.date[2]<<endl;
		cout<<"Description:"<<endl;
		cout<<shape.description<<endl;
		cout<<endl;
	}
	taskFile.close();
}
