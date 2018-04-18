#include <iostream>
#include "todo.h"
using namespace std;

//main blocks declaration ..
bool fexists(const char *filename);

/*Main Driver Blocks*/
int main(int argc, char** argv) {
	int serial;
	todo myTask;
	
	if(fexists("data")==0){
		ofstream file("data");
		file.close();
		ofstream file1("counter");
		file1<<"0";
		file1.close();
	}
	
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
			myTask.showTask();
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

//check is there description file exists...
bool fexists(const char *filename) {
  ifstream ifile(filename);
  return (bool)ifile;
}
