#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>
#include <list>
using namespace std;

int main(int argc, char *argv[]){
	string command;
	string arg;
	list <string> history;
	list <string> :: iterator it;
//	
	
	while (command != "exit"){
		cout << "username >>> ";
		cin >> command;

		if(history.size()>=15){
			it = history.begin();
			history.erase(it);
		}
		if(command == "listdir"){
			system("ls");

		}else if(command == "mycomputername"){
			system("whoami");

		}else if(command == "whatsmyip"){
			system("hostname -i");

		}else if(command == "hellotext"){  ////// must do something else
			system("nano");

		}else if(command == "dididothat"){
			cin >> arg;
			int last = arg.find_last_of("\"");
			string checkCommand = arg.substr(1, last-1);
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
			if(arg.find(">") < arg.length()){
				string commandStr = "cat " + arg;
				system(commandStr.c_str());
			}
//			cout << arg;
		}else{
			getline(cin, arg);
			continue;
		}
		history.push_back(command);

	}
	return 0;
}
