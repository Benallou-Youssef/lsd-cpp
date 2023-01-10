#include "../include/Library.h"

using namespace std;

string book::getname(){
	return name;
}

string book::getISBN(){
	return ISBN;
}

string book::getauthor(){
	return author;
}

string book::getlink(){
	return link;
}


string truncate(string str){
	if(str.size() > 10){
		str.resize(9);
		str += ".";
	}
	while(str.size()<10)
	str = " " + str;
	return str;
}

void book::setname(string str){
	name = str;
	return;
}

void book::setISBN(string str){
	ISBN = str;
	return;	
}

void book::setauthor(string str){
	author = str;
	return;
}

void book::setlink(string str){
	link = str;
	return;
}

void library::printlibrary(){
	cout << " ________________________________ " << endl;
	cout << "|ID        |Book name |author    |" << endl;
	for(int i=0;i<booksnumb && i<8;i++){
		cout << dashes << endl;
		cout << "|" << "         " << i;
		cout << "|" << truncate(books[i].getname());
		cout << "|" << truncate(books[i].getauthor());
		cout << "|" << endl;
    }
	cout << " ________________________________ ";
	return;
}

void library::ADD(){
	string name,ISBN,author,link;
	
	cout << endl << "name of the book : ";
	cin >> name;
	cout << endl << "ISBN number of the book : ";
	cin >> ISBN;
	cout << endl << "name of the author of the book : ";
	cin >> author;
	cout << endl << "link to the book : ";
	cin >> link;
	
	books[booksnumb%8].setname(name);
	books[booksnumb%8].setISBN(ISBN);
	books[booksnumb%8].setauthor(author);
	books[booksnumb%8].setlink(link);
	booksnumb++;
	
	cout << endl << "Book added succefully !" << endl;
	return;
}

void library::SEARCH(int id){
	if(id < 0 || id >= booksnumb || id > 7){
		cout <<"ERROR : No book found with the given ID"<<endl;
        return;
	}
	cout << " ________________________________ " << endl;
	cout << "|ID        |Book name |author    |" << endl;
	cout << dashes << endl;
	cout << "|" << "         " << id;
	cout << "|" << truncate(books[id].getname());
	cout << "|" << truncate(books[id].getauthor());
	cout << "|" << endl;
	cout << " ________________________________ ";
	return;
}


	
	
	
	
	