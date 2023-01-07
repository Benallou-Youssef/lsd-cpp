#include "../include/phonebook.h"

using namespace std;

int main(){
	phonebook phonebook;
	cout << "This is a phonebook program. Please choose between the numbers or commands from the following list :"<<endl;
	cout << "1 - ADD : "<<endl;
	cout << "2 - SEARCH : "<<endl;
	cout << "3 - EXIT: "<<endl;
	cout << "Your choice : "<<endl;
	string choice;
	cin >> choice;
	while(choice != "3" &&  choice != "EXIT" && choice != "exit"){
		if(choice == "1" || choice == "ADD" || choice == "add"){
			phonebook.add_contact();
			phonebook.print_contacts();
		}
		if(choice == "2" || choice == "SEARCH" || choice == "search"){
			int id;
			cout << "Please give the id of the contact you want to search : ";
            cin >> id;
			phonebook.search_contact(id);
		}
		cout << "choose another command : ";
		cin >> choice;
	}
	return 0;
}
			