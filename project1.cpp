#include <iostream>
#include <unistd.h>
#include <bits/stdc++.h>
using namespace std;

void listDir(){
	system("ls");
}

int main(int argc, char *argv[]){
	cout << "username >>> ";
	string command;
	cin >> command;
	vector <string> commandVector;
	
	while (command != "exit"){
		if(command == "listdir"){
			listDir();
		}
		cout << "username >>> ";
		cin >> command;
	}
}
