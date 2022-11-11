#include "read_lines_head.h"
#include <fcntl.h>

char	*read_lines(int fd)
{
	static t_list	*stash = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	
	read_and_stash(fd, &stash);			//read from fd and add to linked list
	if (stash == NULL)
		return (NULL);

	extract_line(stash, &line);			//extract from stash to line
	
	clean_stash(&stash);				//clean stash from the already printed characters
	
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}



void	read_and_stash(int fd, t_list **stash)				//uses the function read() to add characters to the stash
{
	char	*buf;
	int		readed;

	readed = 1;
	while (!found_newline(*stash) && readed != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return ;
		readed = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && readed == 0) || readed == -1)
		{
			free(buf);
			return ;
		}
		buf[readed] = '\0';
		add_to_stash(stash, buf, readed);
		free(buf);
	}
}


void	add_to_stash(t_list **stash, char *buf, int readed)				//adds the buffer (the read characters) to the end of the stash
{
	int		i;
	t_list	*last;
	t_list	*new_node;
	new_node = malloc(sizeof(t_list));
	
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (readed + 1));
	
	if (new_node->content == NULL)
		return ;
	i = 0;
	
	
	while (buf[i] && i < readed)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	
	new_node->content[i] = '\0';
	
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	
	last = ft_lst_get_last(*stash);
	last->next = new_node;
}


void	extract_line(t_list *stash, char **line) //extracting all the characters from stash and store them in line. stops when \n
{
	int	i;
	int	j;

	if (stash == NULL)
		return ;
	generate_line(line, stash);
	if (*line == NULL)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = stash->content[i];
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}



void	clean_stash(t_list **stash)				//removes the returned characters from the stash
{
	t_list	*last;
	t_list	*clean_node;
	int		i;
	int		j;

	clean_node = malloc(sizeof(t_list));
	if (stash == NULL || clean_node == NULL)
		return ;
	clean_node->next = NULL;
	last = ft_lst_get_last(*stash);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content && last->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * ((ft_strlen(last->content) - i) + 1));
	if (clean_node->content == NULL)
		return ;
	j = 0;
	while (last->content[i])
		clean_node->content[j++] = last->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

int	found_newline(t_list *stash)				//Looks for a newline character in the given linked list
{
	int		i;
	t_list	*current;

	if (stash == NULL)
		return (0);
	current = ft_lst_get_last(stash);
	i = 0;
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


t_list	*ft_lst_get_last(t_list *stash)				//Returns a pointer to the last node in our stash
{
	t_list	*current;

	current = stash;
	while (current && current->next)
		current = current->next;
	return (current);
}


void	generate_line(char **line, t_list *stash)				//Calculates the number of chars in the current line
{
	int	i;
	int	len;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_stash(t_list *stash)				//Frees the entire stash
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}


/*********************************************************************************************/
int	main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (1)
	{
		line = read_lines(fd);
		printf("%s", line);
		if (line == NULL)
			break ;
		free(line);
	}
	return (0);
}
