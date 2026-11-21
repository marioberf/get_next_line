*This project has been created as a part of the 42 curriculum, created by mariober*

## Description

get_next_line (GNL) is a function that, given any file descriptor (FD), returns its first line if first time called or the next one in ascending order if called more times.

* Will return ```NULL``` if:
	* It surpasses the end of the FD
	* There's an error during the read operation
	* The FD given is invalid

### get_next_line_bonus
Does and works the same way as GNL, except this one has the capacity to handle multiple FD's at the same time (up to ```1024```, can be modified).

## Instructions

### How to install

In order to use it you must add the header file from the GNL you want to use into your project's directory (as well as the scripts) and import the header into your script. Or turn it into an archive (```.a```)


### Usage

GNL reads chunk by chunk, defined on the header file as ```BUFFER_SIZE```, the value is ```42``` by default but it can  be changed by compiling with the flag: ```-D BUFFER_SIZE=n```

The function returns with a memory allocated ```line```, it's the user's responsability to free it after its no longer needed as well as closing the FD

A ```main.c``` for testing purposes could look like this:

```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// prints every line
int	main()
{
	char	*c;
	int fd = open("test.txt", O_RDONLY);
	while ((c = get_next_line(fd)))
	{
		printf("%s", c);
		free(c);
	}
	close(fd);
	return (0);	
}
```

## Resources

This project was made by myself, with the help of other 42 Madrid Student, the ```man``` linux manual command, and useful websites (to understand concepts from) like geeksforgeeks, IBM docs website page etc.

AI was used during the development of this project to consolidate knowledge and aid with some specific issues, never as the main programmer of this project.