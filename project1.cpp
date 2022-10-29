//#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>
#include <list>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
using namespace std;

int main(int argc, char *argv[]){
	string command;
	string arg;
	list <string> history;
	list <string> :: iterator it;
	char* username = getenv("USERNAME");
	char cool[] = " >>> ";
	char* user;
	strcat(user, username);
	strcat(user, cool);
	
	while (command != "exit"){
		cout << user;
		cin >> command;

		// must store the last executed 15 commands
		if(history.size()>=15){
			it = history.begin();
			history.erase(it);
		}

		// execute "ls" for "listdir" command
		if(command == "listdir"){
			pid_t pid = fork();
			if(pid < 0){
				cerr << "Error while forking!";
			}else if(pid == 0){
				execl("/bin/ls", "ls", NULL);
				exit(0);
			}else{
				wait(NULL);
			}

		// execute "whoami" for "mycomputername" command
		}else if(command == "mycomputername"){
			cout << username;
			cout << "\n";

		// execute "hostname -i" for "whatsmyip" command
		}else if(command == "whatsmyip"){
			pid_t pid = fork();
			if(pid < 0){
				cerr << "Error while forking!";
			}else if(pid == 0){
				execl("/bin/hostname", "hostname", "-i", NULL);
				exit(0);
			}else{
				wait(NULL);
			}

		// "hellotext" command opens gedit
		}else if(command == "hellotext"){ 
			pid_t pid = fork();
			if(pid < 0){
				cerr << "Error while forking!";
			}else if(pid == 0){
				execl("/bin/gedit", "gedit", NULL);
				exit(0);
			}else{
				wait(NULL);
			}

		// if the command is in history list, print "Yes", else "No"
		}else if(command == "dididothat"){
			getline(cin, arg);
			command += arg;
			int last = arg.find_last_of("\"");
			string checkCommand = arg.substr(2, last-2);
			bool found = false;
			for(it = history.begin(); it != history.end(); it++){
				if(*it == checkCommand){
					cout << "Yes\n";
					found = true;
					break;
				}
			}
			if(found == false)
				cout << "No\n";

		}else if(command == "printfile"){
			getline(cin, arg);
			command += arg; 

			// call system with "cat fileName1 > fileName2"
			if(arg.find(">") < arg.length()){
				string commandStr = "cat " + arg;
				system(commandStr.c_str());

			// print out the file line by line, with enter is pressed
			}else{
				string line;
				ifstream readFile(arg.substr(1, arg.length()).c_str());
				do{
					getline(readFile, line);
					cout << line;
					getline(cin, arg);
				}
				while(arg.length()==0 && readFile.peek()!=EOF);
			}
		}else{
			continue;
		}

		// store the executed command
		history.push_back(command);

	}
	return 0;
}
