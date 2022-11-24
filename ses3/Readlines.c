#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////	STRUCTURES	 ///////////////////////////////////////////////////////////////


typedef struct	character
{
	char content;
	struct character* next;
}character;
typedef struct character* string;


////////////////////////////////////////////////////////////////	PROTOTYPES	 ////////////////////////////////////////////////////////////////


char* read_lines(int);
int found_new_line(string);
int len_string(string);

////////////////////////////////////////////////////////////////	FUNCTIONS	 ///////////////////////////////////////////////////////////////


char* read_lines(int fd){
	char* line;			
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)	
		return (NULL);
	static string catbuf = NULL;		
	line = NULL;
	string* current = &catbuf;	
	int stop = 1;
	if(found_new_line(catbuf) == -1)
	{
		while((*current) != NULL)
			current = &((*current)->next);
		while(stop)
		{
			char buf[BUFFER_SIZE];			
			int readcharcount = read(fd, buf, BUFFER_SIZE);		
			if (readcharcount <=0)		
			{			
				break;
			}
			else
			{				
				for(int i=0;i<readcharcount;i++)
				{
					if(buf[i] == '\n')
						stop = 0;
					string newchar =(string)malloc(sizeof(character));
					newchar->content = buf[i];
					newchar->next = NULL;
					(*current) = newchar;
					current = &((*current)->next);
				}	
			}
		}
	}
	if (catbuf == NULL)
		return (NULL);
	int nl = found_new_line(catbuf);
	if (nl == -1)
		nl = len_string(catbuf) -1;
	line = malloc(nl+2);
	int i = 0;
	while(i<nl+1)
	{	
		line[i++] = catbuf->content;
		string temp = catbuf;
		catbuf = catbuf->next;
		free(temp);
	}
	line[i] = '\0';
	return line;
}


int found_new_line(string str1){
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

int len_string(string str1){
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
		line = read_lines(fd);
		if (line == NULL)
			break ;
		printf("%s",line);
		free(line);
	}
	return (0);
}
