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
	int delNum,i;
	cout<<"Enter the number which task you want to delete?";
	cin>>delNum;
	
	//read counter
	ifstream counter("counter");
	counter>>count;
	counter.close();
	
	//file holding structure... 
	task shape[count-1],temp;
	
	ifstream taskFile("data");
	for(int i=0,j=0;i<count;i++){
		if(i+1==delNum){
			taskFile>>temp.countTask;
			taskFile>>temp.time[0]>>temp.time[1];
			taskFile>>temp.date[0]>>temp.date[1]>>temp.date[2];
			taskFile.ignore();
			getline(taskFile,temp.description);
			continue;
		}
		
		//read from the the file to stream
		taskFile>>shape[j].countTask;
		taskFile>>shape[j].time[0]>>shape[j].time[1];
		taskFile>>shape[j].date[0]>>shape[j].date[1]>>shape[j].date[2];
		taskFile.ignore();
		getline(taskFile,shape[j].description);
		j++;
	}
	taskFile.close();
	
	//write the structures...
	ofstream taskFile1("data");
	for(int i=0;i<count-1;i++){
		
		//read from the the file to stream
		taskFile1<<i+1<<endl;
		taskFile1<<shape[i].time[0]<<" "<<shape[i].time[1]<<endl;;
		taskFile1<<shape[i].date[0]<<" "<<shape[i].date[1]<<" "<<shape[i].date[2]<<endl;
		taskFile1<<shape[i].description<<endl;
	}
	taskFile1.close();
		
	count--;
	ofstream counter1("counter",ios::out);
	counter1<<count;
	counter1.close();
	
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
	cout<<"....................................................\nAll Tasks..:\n\n";
	for(int i=1;i<=count;i++){
		
		//read from the the file to stream
		taskFile>>shape.countTask;
		taskFile>>shape.time[0]>>shape.time[1];
		taskFile>>shape.date[0]>>shape.date[1]>>shape.date[2];
		taskFile.ignore();
		getline(taskFile,shape.description);
		
		//print to the std out..
		cout<<shape.countTask<<". "<<shape.time[0]<<": "<<shape.time[1]<<", "<<shape.date[0]<<"-"<<shape.date[1]<<"-"<<shape.date[2]<<endl;
		cout<<"Description:"<<endl;
		cout<<shape.description<<endl;
		cout<<endl;
	}
	cout<<"......................................................\n";
	taskFile.close();
}
