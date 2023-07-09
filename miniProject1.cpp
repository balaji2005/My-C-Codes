#include <bits/stdc++.h>

using ProcessId = int;
using namespace std;

struct Process {
	Process* previousProcess;
	Process* nextProcess;
	ProcessId id;
};

Process* recentProcess;
// Process* headProcess;
// headProcess.previousProcess = NULL; 

class Scheduler {
public:
  /*
        adds process with id = pid to the end of the linked list
  */
	Process *add_process(ProcessId pid) {
		// code to add_process goes here
		Process process;
		process.id = pid;
		process.previousProcess = recentProcess;
		process.nextProcess = NULL;
		cout << recentProcess->id << endl;
		cout << recentProcess->previousProcess<<endl;
		cout << recentProcess->nextProcess<<endl;
		if (recentProcess == NULL) {
			// headProcess.id = pid;
			// headProcess.nextProcess = 
			// cout << "Head Process: " <<headProcess->id<<endl;
		} else {
			recentProcess->nextProcess = &process;
		}
		recentProcess = &process;
		cout << recentProcess->id << endl;
		cout << recentProcess->previousProcess<<endl;
		cout << recentProcess->nextProcess<<endl;
		return recentProcess;
	}
    
  /*
        deletes process with id == pid
  */
    void delete_process(ProcessId pid) {
		// code to delete_process goes here
		// Process* tempP = new Process(*recentProcess);
		Process* tempP;
		Process temp;
		temp.id = NULL;
		temp.previousProcess = NULL;
		temp.nextProcess = NULL;
		tempP = &temp;
		tempP->id = recentProcess->id;
		tempP->previousProcess = recentProcess->previousProcess;
		tempP->nextProcess = recentProcess->nextProcess;
		while (tempP->id != pid) {
			// *tempP = new Process(tempP->previousProcess);
			tempP->id = (tempP->previousProcess)->id;
			tempP->previousProcess = (tempP->previousProcess)->previousProcess;
			tempP->nextProcess = (tempP->previousProcess)->nextProcess;
		}
		(tempP->previousProcess)->nextProcess = tempP->nextProcess;
		(tempP->nextProcess)->previousProcess = tempP->previousProcess;
  }

  /*
        add a process with id == childId after process with id == parentId
  */
  	Process *fork(ProcessId process, ProcessId newId) {
    	// code to fork process goes here
		// Process* tempP = new Process(recentProcess);
		Process* tempP;
		Process temp;
		temp.id = NULL;
		temp.previousProcess = NULL;
		temp.nextProcess = NULL;
		tempP = &temp;
		tempP->id = recentProcess->id;
		tempP->previousProcess = recentProcess->previousProcess;
		tempP->nextProcess = recentProcess->nextProcess;
		while (tempP->id != process) {
			// *tempP = new Process(*(tempP->previousProcess));
			tempP->id = (tempP->previousProcess)->id;
			tempP->previousProcess = (tempP->previousProcess)->previousProcess;
			tempP->nextProcess = (tempP->previousProcess)->nextProcess;
		}
		Process newP;
		newP.id = newId;
		newP.nextProcess = tempP->nextProcess;
		newP.previousProcess = tempP;
		Process* newptr = &newP;
		(tempP->nextProcess)->previousProcess = newptr;
		tempP->nextProcess = newptr;
		return newptr;
	}

	void print_schedule() {
		// code to print_schedule goes here
		// Process* tempP = new Process(*headProcess);
		cout << "Printing" << endl;
		// cout << "Head Process Id: "<<headProcess->id<<endl;
		Process* tempP;
		Process temp;
		temp.id = NULL;
		temp.previousProcess = NULL;
		temp.nextProcess = NULL;
		tempP = &temp;
		tempP->id = recentProcess->id;
		tempP->previousProcess = recentProcess->previousProcess;
		tempP->nextProcess = recentProcess->nextProcess;
		cout << recentProcess->id<<endl;
		cout << recentProcess->previousProcess<<endl;
		cout << recentProcess->nextProcess<<endl;
		vector<int> printv = {};
		while (tempP -> previousProcess != NULL) {
			printv.push_back(tempP->id);
			cout << tempP -> id << endl;
			// *tempP = new Process(*(tempP -> nextProcess);
			tempP = tempP->nextProcess;
		}
		printv.push_back(tempP->id);
		reverse(printv.begin(), printv.end());
		// cout << tempP -> id << endl;
		for (int ele : printv) {
			cout << ele << endl;
		}
  }
};

enum Operations {
	ADD_PROCESS,
	DELETE_PROCESS,
	FORK,
	PRINT_SCHEDULE,
};

int main() {
	Scheduler s;
	int n;
	cin >> n;

	while (n--) {
		int operationInput;
		cin >> operationInput;

		Operations opId = static_cast<Operations>(operationInput);

		if (opId == ADD_PROCESS) {
			ProcessId newPid;
			cin >> newPid;
			s.add_process(newPid);
		} else if (opId == DELETE_PROCESS) {
			ProcessId toBeDeletedPid;
			cin >> toBeDeletedPid;
			s.delete_process(toBeDeletedPid);
		} else if (opId == FORK) {
			ProcessId pidToBeForked;
			ProcessId newPid;
			cin >> pidToBeForked;
			cin >> newPid;
			s.fork(pidToBeForked, newPid);
		} else if (opId == PRINT_SCHEDULE) {
			s.print_schedule();
		}
	}
}