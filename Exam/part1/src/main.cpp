#include "../include/Library.h"

using namespace std;

int main(){
	cout << endl << "Welcome to our library! Please choose the command you want to use (ADD/SEARCH/EXIT) : ";
	library library;
	string choice;
	cin >> choice;
	while(choice != "EXIT" && choice != "exit"){
		if(choice == "ADD" || choice == "add"){
			library.ADD();
			library.printlibrary();	
		}
		
		if(choice == "SEARCH" || choice == "search"){
			int id;
			library.printlibrary();
			cout << endl <<"Please choose an id : ";
			cin >> id;
			library.SEARCH(id);
		}
		
		cout << endl << "Please choose the command you want to use (ADD/SEARCH/EXIT) : ";
		cin >> choice;
	}
	return 0;
}
		
		
		