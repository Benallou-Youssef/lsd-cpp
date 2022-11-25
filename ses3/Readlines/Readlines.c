#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////	STRUCTURES	 ///////////////////////////////////////////////////////////////


typedef struct	character						//basically a list, each node contains 1 character.	
{
	char content;
	struct character* next;
}character;
typedef struct character* string;


////////////////////////////////////////////////////////////////	PROTOTYPES	 ////////////////////////////////////////////////////////////////


char* readlines(int);
int found_new_line(string);
int len_string(string);

////////////////////////////////////////////////////////////////	FUNCTIONS	 ///////////////////////////////////////////////////////////////


char* readlines(int fd){
	char* line;		//Will contain the line that we want to return.
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)	
		return (NULL);
	
	static string catbuf = NULL;		//a string(list) which will store everything we read. Is static because there could be some leftovers at the end of the function.	
	line = NULL;
	string* current = &catbuf;			//a pointer to the last node of catbuf that would be useful to fill it.
	int stop = 1;						//used to stop the while loop. turns into 0 if we read a \n.
	
	if(found_new_line(catbuf) == -1)	//we only read if there's no \n in catbuf as it could be find in leftovers.
	{
		while((*current) != NULL)		
			current = &((*current)->next);	//we move "current" to the last node.
		while(stop)
		{
			char buf[BUFFER_SIZE];			//will contain what we read temporarly. size = BUFFER_SIZE or less.
			int readcharcount = read(fd, buf, BUFFER_SIZE);		// we store max BUFFER_SIZE elements into buf, and readcount is the number of read chars.
			if (readcharcount <=0)			//if we are at the end of the file or there was a problem in read.
			{			
				break;
			}
			else
			{				
				for(int i=0;i<readcharcount;i++)
				{
					if(buf[i] == '\n')		
						stop = 0;			//we change stop to 0 if we find a \n in the read chars.
					string newchar =(string)malloc(sizeof(character));		//create a new node.
					newchar->content = buf[i];								//fill the new node.
					newchar->next = NULL;
					(*current) = newchar;									//add the node to catbuf.
					current = &((*current)->next);							//move to next.
				}	
			}
		}
	}
	
	if (catbuf == NULL)			//if catbuf is NULL it means we couldn't read anything and there was no leftovers from previous calls, thus we return NULL.
		return (NULL);
	
	int nl = found_new_line(catbuf)+1;	//length of the current line.
	if (nl == 0)	//if no \n was found it only means this is the final line of the file.
		nl = len_string(catbuf);	//we just use a function that returns the length of a list.
	line = malloc(nl+1);			//we allocate enough space for all characters of the line and +1 to add the \0.
	int i = 0;	
	while(i<nl)
	{	
		line[i++] = catbuf->content;	//we add the content of catbuf to the line.
		string temp = catbuf;			//a pointer the the current node.
		catbuf = catbuf->next;			//we move catbuf to the next one.
		free(temp);						//we free the previous node.
	}
	line[i] = '\0';						//we add the \0 at the end of "line".
	return line;
}


int found_new_line(string str1){		//takes a string(list) as arg and returns the position of the first \n in the string, -1 if not found.
	string temp = str1;
	int i = 0;
	int check = 0;
	while(temp)
	{
		if(temp->content == '\n')
		{	
			check = 1;
			break;
		}
		i++;
		temp = temp->next;
	}
	if(check)
		return i;
	return -1;
}

int len_string(string str1){			//takes a string(list) as arg and returns the length of it.
	string temp = str1;
	int i = 0;
	int count = 0;
	while(temp)
	{
		i++;
		temp = temp->next;
	}
	return i;
}
////////////////////////////////////////////////////////////////////	MAIN	///////////////////////////////////////////////////////////////////
int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	
	while (1)
	{
		line = readlines(fd);
		if (line == NULL)
			break ;
		printf("%s",line);
		free(line);
	}
	return (0);
}
