#include "Linked_list.h"

using namespace std;

/////////////////////////////////////////////////		FUNCTIONS              //////////////////////////////////////////////////

void push(int x , linked_list* L){					//Create a new node,fills it with the choosed number,and make it the head of the list
	linked_list newnode=(linked_list)malloc(sizeof(node));
	newnode->content = x;
	newnode->next = *L;
	*L=newnode;
	return;
}

int pop(linked_list *L){							//Extract the head of the list's content, destroy the first node of the list and returns the extracted number
	if(*L != NULL){
		int x = (*L)->content;
		linked_list temp = *L;
		*L = (*L)->next;
		free(temp);
		return x;
	}
	else
		exit(EXIT_FAILURE);
}

void print_linked_list(linked_list L){				//Prints the given list, from head to tail
	linked_list temp = L;
	while(temp != NULL){
		cout << temp->content << " ";
		temp = temp->next;
	}
	printf("\n");
}

int list_len(linked_list L){						//Returns the number of nodes in the given list
	int n =0;
	linked_list temp =L;
	while(temp!=NULL){
		n++;
		temp=temp->next;
	}
	return n;
}

int list_check(int x, linked_list L){				//Checks if there's a node in the list that has the given number as content, if so returns 1.If not, returns 0
    linked_list temp= L;
    while(temp != NULL)
    {
        if (temp->content == x)
            return 1;
        temp=temp->next;
    }
    return 0;
}

void list_reverse(linked_list *L){					//Reverses the given list
	linked_list temp = NULL;
	while(*L != NULL)
		push(pop(&(*L)),&temp);
	*L = temp;
	return ;
}

void list_kreverse(int k , linked_list *L){			//Reverses each k elements of the given list.It's done by considering sub lists of k elements and reversing them
	int n = list_len(*L);
	linked_list temp = NULL;
	linked_list res = NULL;
	for(int i = 0 ; i< n%k ; i++){
		for(int j = 0 ; j < k ; j++)
			push(pop(&(*L)),&temp);
		while(temp != NULL)
			push(pop(&temp),&res);
	}
	while(*L != NULL)
		push(pop(&(*L)),&temp);
	while(temp != NULL)
		push(pop(&temp),&res);
	list_reverse(&res);
	*L=res;
	return;
}	

void del_duplicates(linked_list* L){				//Deletes all duplicates in the list so that every node's content is unique in the list	
	linked_list res = NULL;
	while(*L != NULL){
		int x = pop(&(*L));
		if(!list_check(x,*L))
			push(x,&res);
	}
	list_reverse(&res);
	*L=res;
	return;
}

int main(){
	linked_list L=NULL;
	push(1,&L);
	push(2,&L);
	push(3,&L);
	push(4,&L);
	push(5,&L);
	push(2,&L);
	push(3,&L);
	push(4,&L);
	printf("list used \t\t: ");
	print_linked_list(L);
	printf("reverse each 3 elements : ");
	list_kreverse(3,&L);
	print_linked_list(L);
	list_kreverse(3,&L);
	printf("delete the duplicates \t: ");
	del_duplicates(&L);
	print_linked_list(L);
	return 0;
}