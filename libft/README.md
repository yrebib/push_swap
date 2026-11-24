*This project has been created as part of the 42 curriculum by yorebib.*
# Libft
    
    
## Description
Libft is the first project that every 42 student has to complete. Its purpose
is to reinforce the knowledge gained during the Pool and to bring all new
students to the same level in C.

The project is written in C and consists of rebuilding existing standard
library functions. The goal is to go beyond just using them: by mimicking
their implementation, I can see how they work, what errors they can cause,
and what inputs they can handle.

The library also includes additional functions. While writing all of these functions, I had to handle
problems such as segmentation faults and memory leaks ets.

## Instructions
 **Overview**

```
libft/
├── Makefile                 # Builds libft.a
├── README.md                # Project description and usage
├── libft.h                  # Prototypes, includes, and t_list struct
│
├── ft_isalpha.c             # Checks if a char is a letter
├── ft_isdigit.c             # Checks if a char is a digit (0-9)
├── ft_isalnum.c             # Checks if a char is a letter or digit
├── ft_isascii.c             # Checks if a value is in the ASCII range (0-127)
├── ft_isprint.c             # Checks if a char is printable (32-126)
├── ft_strlen.c              # Returns the length of a string
├── ft_memset.c              # Fills a memory block with a byte
├── ft_bzero.c               # Sets a memory block to zeros
├── ft_memcpy.c              # Copies n bytes between memory areas (no overlap)
├── ft_memmove.c             # Copies n bytes, safe when areas overlap
├── ft_strlcpy.c             # Copies a string with size limit, returns source length
├── ft_strlcat.c             # Appends a string with size limit, returns total length
├── ft_toupper.c             # Converts a lowercase letter to uppercase
├── ft_tolower.c             # Converts an uppercase letter to lowercase
├── ft_strchr.c              # Finds the first occurrence of a char in a string
├── ft_strrchr.c             # Finds the last occurrence of a char in a string
├── ft_strncmp.c             # Compares up to n chars of two strings
├── ft_memchr.c              # Finds a byte in a memory block
├── ft_memcmp.c              # Compares two memory blocks byte by byte
├── ft_strnstr.c             # Finds a substring within the first n chars of a string
├── ft_atoi.c                # Converts a string to an int
├── ft_calloc.c              # Allocates zero-initialized memory
├── ft_strdup.c              # Returns a malloc'd copy of a string
├── ft_substr.c              # Extracts a substring from a string
├── ft_strjoin.c             # Concatenates two strings into a new one
├── ft_strtrim.c             # Trims given chars from both ends of a string
├── ft_split.c               # Splits a string into an array using a delimiter char
├── ft_itoa.c                # Converts an int to a string
├── ft_strmapi.c             # Applies a function to each char, returns a new string
├── ft_striteri.c            # Applies a function to each char (with index) in place
├── ft_putchar_fd.c          # Writes a char to a file descriptor
├── ft_putstr_fd.c           # Writes a string to a file descriptor
├── ft_putendl_fd.c          # Writes a string plus newline to a file descriptor
├── ft_putnbr_fd.c           # Writes an int to a file descriptor
├── ft_lstnew.c              # Creates a new list node
├── ft_lstadd_front.c        # Adds a node at the beginning of a list
├── ft_lstsize.c             # Counts the nodes in a list
├── ft_lstlast.c             # Returns the last node of a list
├── ft_lstadd_back.c         # Adds a node at the end of a list
├── ft_lstdelone.c           # Frees one node's content and the node itself
├── ft_lstclear.c            # Deletes and frees a node and all that follow it
├── ft_lstiter.c             # Applies a function to each node's content
└── ft_lstmap.c              # Builds a new list by applying a function to each node
```
**Main Files**

### Makefile:

The `Makefile` is the file that builds the library. It tells `make` how to
compile every `.c` file into an object file (`.o`) and how to pack them all
into the static library `libft.a`. It contains these rules:

- `all`: builds `libft.a` (this is the default rule)
- `clean`: removes the object files (`.o`)
- `fclean`: removes the object files and `libft.a`
- `re`: runs `fclean` and then `all` to rebuild everything

if you want to run certain rule just run : 
```bash
make $rule
```


### libft.h:

`libft.h` is the header file of the library. It contains:

- the **prototypes** of all the functions, so other programs know how to call them
- the **standard headers** the functions need (such as `<stdlib.h>` and `<unistd.h>`)
- the `t_list` **structure** used by the linked list functions

Any program that wants to use the library must include it with `#include "libft.h"`.

#### Usage

To use a function from libft, include the header in your source file:

    #include "libft.h"

Then compile your program with `libft.a` added to the command:

    cc -Wall -Wextra -Werror main.c libft.a -o my_program

Run it with:

    ./my_program

### README.md:

`README.md` is the documentation of the project. It explains what Libft is,
how to compile and use it.
## Resources

 **References**

- [man pages](https://man7.org/linux/man-pages/): to check how each libc function should behave
- [POSIX](https://pubs.opengroup.org/onlinepubs/9699919799.2013edition/): to write the Makefile
- [Markdown youtub video](https://www.youtube.com/watch?v=f49LJV1i-_w): to write this README
- [Makefile youtube vidio](https://www.youtube.com/watch?v=4IDLCtEPtN8&t): Master Makefiles

- Discussions with other students.
- There is untracked resources.

 **AI usage**

I used AI to understand concepts. I wrote and tested the code myself.
- ai is mostly used for debuging but MAKES PEER LEARNING SOO WEEK.
- ai can give a lot of miss info or uncomplit.
- ai save you time when it cams to a certain info and code test cases.
- ai gives good help searching the web about info resources.

