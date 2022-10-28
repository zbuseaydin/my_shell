#include <iostream>
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
	strcat(username, cool);
	
	while (command != "exit"){
		cout << username;
		cin >> command;

		if(history.size()>=15){
			it = history.begin();
			history.erase(it);
		}

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
//			system("ls");

		}else if(command == "mycomputername"){
			pid_t pid = fork();
			if(pid < 0){
				cerr << "Error while forking!";
			}else if(pid == 0){
				execl("/bin/whoami", "whoami", NULL);
				exit(0);
			}else{
				wait(NULL);
			}
	//		system("whoami");

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

		}else if(command == "hellotext"){  ////// must do something else
			char* defaultEditor = getenv("EDITOR");
			if(defaultEditor == NULL)
				system("nano");
			else
				system(defaultEditor);

		}else if(command == "dididothat"){
//			for(it = history.begin(); it != history.end(); it++)
//				cout << *it;

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
			if(arg.find(">") < arg.length()){
				string commandStr = "cat " + arg;
				system(commandStr.c_str());
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
		history.push_back(command);

	}
	return 0;
}
