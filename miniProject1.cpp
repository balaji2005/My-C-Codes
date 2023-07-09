#include <bits/stdc++.h>

using ProcessId = int;
using namespace std;

struct Process {
	Process* previousProcess;
	Process* nextProcess;
	ProcessId id;
};

Process* recentptr;

class Scheduler {
public:
  	/*
        adds process with id = pid to the end of the linked list
  	*/
	Process *add_process(ProcessId pid) {
		// code to add_process goes here
		Process* process = new Process;
		process->id = pid;
		process->previousProcess = recentptr;
		process->nextProcess = nullptr;
		if (recentptr != nullptr) {
			recentptr -> nextProcess = process;
		}
		recentptr = process;
		return recentptr;
	}
    
  	/*
        deletes process with id == pid
  	*/
    void delete_process(ProcessId pid) {
		// code to delete_process goes here
		Process* tempP = new Process;
		tempP = recentptr;
		while (tempP->id != pid) {
			tempP = tempP -> previousProcess;
		}
		if (tempP -> previousProcess) {
			tempP -> previousProcess -> nextProcess = tempP -> nextProcess;
		}
		if (tempP -> nextProcess) {
			tempP -> nextProcess -> previousProcess = tempP -> previousProcess;
		} else {
			recentptr = tempP -> previousProcess;
		}
  	}

  /*
        add a process with id == childId after process with id == parentId
  */
  	Process *fork(ProcessId process, ProcessId newId) {
    	// code to fork process goes here
		Process* tempP = new Process;
		tempP = recentptr;
		while (tempP -> id != process) {
			tempP = tempP -> previousProcess;
		}
		Process* newptr = new Process;
		newptr -> id = newId;
		newptr -> previousProcess = tempP;
		if (tempP -> nextProcess) {
			newptr -> nextProcess = tempP -> nextProcess;
			tempP -> nextProcess -> previousProcess = newptr;
		} else {
			newptr -> nextProcess = nullptr;
			recentptr = newptr;
		}
		tempP -> nextProcess = newptr;
		return newptr;
	}

	void print_schedule() {
		// code to print_schedule goes here
		Process* tempP = recentptr;
		vector<int> printv;
		while (tempP != NULL) {
			printv.push_back(tempP->id);
			tempP = tempP -> previousProcess;
		}
		reverse(printv.begin(), printv.end());
		for (int ele : printv) {
			cout << ele << ' ';
		}
		cout << '\n';
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