#include <iostream>
#include "todo.h"
using namespace std;

struct task{
	int counter;
	string description;
	int time[2];
	int date[3];
};

/*Main Driver Blocks*/
int main(int argc, char** argv) {
	int serial;
	todo myTask;
	while(1){
		cout<<"\n\n1.Add Task\n";
		cout<<"2.Show Task\n";
		cout<<"3.Refresh\n";
		cout<<"4.Delete Task\n";
		cout<<"5.Quit\n";
		cout<<"Chose a number..? \n";
		cin>>serial;
		cout<<"\n\n";
		
		if(serial==1){
			myTask.addTask();
		}
		else if(serial==2){
			
		}
		else if(serial==3){
				myTask.refresh();
		}
		else if(serial==4){
			
		}
		else{
			break;
		}
	}
	return 0;
}
