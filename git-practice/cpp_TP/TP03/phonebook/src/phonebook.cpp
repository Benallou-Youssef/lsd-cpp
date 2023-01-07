#include "../include/phonebook.h"

using namespace std;

void contact::set_firstname(string name){
	firstname = name;
	return;
}

void contact::set_lastname(string name){
	lastname = name;
	return;
}

void contact::set_nickname(string name){
	nickname = name;
	return;
}

void contact::set_phonenumber(string number){
	phonenumber = number;
	return;
}

string contact::get_firstname(){
	return firstname;
}

string contact::get_lastname(){
	return lastname;
}

string contact::get_nickname(){
	return nickname;
}

string contact::get_phonenumber(){
	return phonenumber;
}



void phonebook::add_contact(){
	string fst,lst,nck,phnum;
	cout << endl << "first name : ";
	cin >> fst;
	cout << endl << "last name : ";
	cin >> lst;
	cout << endl << "nickname : ";
	cin >> nck;
	cout << endl << "phone number : ";
	cin >> phnum;
	contacts[contacts_number%8].set_firstname(fst);
	contacts[contacts_number%8].set_lastname(lst);
	contacts[contacts_number%8].set_nickname(nck);
	contacts[contacts_number%8].set_phonenumber(phnum);
	contacts_number++;
	cout << endl << "Added succefully." << endl;
	return;
}

string truncate(string str){		//If the length of the string is superior to 10, it keeps only the 9 first characters and add '.' as a 10th character
	if(str.size() > 10){
		str.resize(9);
		str += ".";
	}
	while(str.size()<10)
		str += " ";
	return str;
}
	
void phonebook::print_contacts(){
	cout << dashes <<endl;
	cout << "|ID|first name|last name |nickname  |phone number|" <<endl;
	cout << dashes <<endl;
	for(int i=0;i<contacts_number && i<8;i++){
        cout << "|" << i;
		cout << " |" << truncate(contacts[i].get_firstname());
        cout << "|" << truncate(contacts[i].get_lastname());
		cout << "|" << truncate(contacts[i].get_nickname());
		cout << "|" << truncate(contacts[i].get_phonenumber());
        cout << "  |" << endl << dashes << endl;
    }
	return;
}

void phonebook::search_contact(int id){
	if(id < 0 || id >= contacts_number || id > 7){
		cout <<"NO CONTACT FOUND WITH THE GIVEN ID"<<endl;
        return;
	}
	cout << dashes <<endl;
	cout << "|ID|first name|last name |nickname  |phone number|" <<endl;
	cout << dashes <<endl;
    cout << "|" << id;
	cout << "|" << truncate(contacts[id].get_firstname());
    cout << "|" << truncate(contacts[id].get_lastname());
	cout << "|" << truncate(contacts[id].get_nickname());
	cout << "|" << truncate(contacts[id].get_phonenumber());
    cout << "|" << endl << dashes << endl;
	return;
}
	