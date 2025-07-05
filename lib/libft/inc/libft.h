/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:03:23 by spenning          #+#    #+#             */
/*   Updated: 2025/07/05 12:19:03 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/times.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

// Bonus struct

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// time struct
typedef struct s_time
{
	float			systime;
	float			usrtime;
	struct timespec	d;
}	t_time;

# ifndef DEBUG
#  define DEBUG 0
# endif

// STRING

/**
 * @brief
 * This function takes a pointer to s and creates a substring with len length 
 * starting from start index.
 * @param char const *s
 * @param int unsigned start
 * @param size_t len
 * @return
 * if start is longer than length of s, then 
 * function will return empty string. If the length is bigger than length of 
 * s starting from index start, then len will be adjusted to length of
 * s starting from index start. This function returns a char * to allocated 
 * substring 
* @exception
 *  if allocations failed it will return NULL
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief
 * This function takes a pointer to s1 and creates a new string with 
 * characters from set trimmed from beginning and end of s1. 
 * @param char const *s
 * @param char const set
 * @return function returns trimmed string.
* @exception
 *  If memory allocation fails function returns NULL
*/
char	*ft_strtrim(char const *s1, char const *set);
/**
 * @brief
 * This function takes big and try to find little 
 * @param char const *big
 * @param char const *little
 * @param size_t len 
 * @return If little is found then function returns a pointer 
 * to the start of the first occurence of little.
* @exception
 *  function returns NULL if little not found.
*/
char	*ft_strnstr(const char *big, const char *little, size_t len);
/**
 * @brief
 * This function takes s1 and compares s2 for n bytes 
 * @param char const *s1
 * @param char const *s2
 * @param size_t n
 * @return if s1 and s2 are equal return value is 0 
 * otherwise the difference in values of bytes being 
 * compared in that moment is returned which is nonzero
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief
 * This function takes pointer char *s, and expects a null terminated string.
 * then returns the length of the string. 
 * @param char const *s
 * @return size_t length of string
*/
size_t	ft_strlen(const char *s);
/**
 * @brief
 * Function will keep on copying until it reaches size - 1,
 * and there are still charachters to copy
 * from src. Afterwards it null terminates the result. 
 * @param char const *dst
 * @param char const *src
 * @param size_t size
 * @return function always returns the length of src
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/**
 * @brief
 * This function takes dst, src, and n bytes (full buffer) 
 * it needs to concatenate at the end. the size it should copy is always 
 * size - dst_len - 1.
 * @param char const *dst
 * @param char const *src
 * @param size_t size
 * @return If size is not bigger than dst, it cannnot concat
 * therefore it returns the length of the string it wanted to create
 * if the copy size is bigger than src len than it automatically makes
 * the copy size equal to the size of src_len to not run of the string
 * then after checking if there is enough space in dst and the amount it 
 * copies from src is the maximum it can copy the memory with memcpy and
 * null terminate the end.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/**
 * @brief
 * This function takes s1 and s2 and joins them together 
 * @param char const *s1
 * @param char const *s2
 * @return concatenation of s1 and s2
 * @exception if join fails or if malloc fails then function returns NULL.
*/
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief
 * This function returns copy of s 
 * @param char const *s
 * @return copy of s, if string is empty it will still return
 * copy of empty string.
 * @exception If malloc fails it will return NULL.
*/
char	*ft_strdup(const char *s);
/**
 * @brief This function takes null terminated s and checks for c 
 * @param char const *s
 * @param int c
 * @return function will return pointer to first instance found.
 * @return if c is \0 it will still return a pointer to the null terminator in s.
*/
char	*ft_strchr(const char *s, int c);
/**
 * @brief This function takes null terminated s and checks for c in reverse 
 * @param char const *s
 * @param int c
 * @return function will return pointer to first instance found.
 * @return if c is \0 it will still return a pointer to the null terminator in s.
*/
char	*ft_strrchr(const char *s, int c);
/**
 * @brief This function takes a char* nptr and it will return the int value 
 * found in nptr 
 * @param char const *nptr
 * @return function skips whitespaces, returns both plus or minus
 * values.
 * @exception If nptr is not well formated with multiple minusses or 
 * charachters in between operators and number then it will return NULL
*/
int		ft_atoi(const char *nptr);
/**
 * @brief This function takes n and it will return a malloced string with the 
 * string representation of n 
 * @param int n
 * @return return a malloced string with the 
 * string representation of n. If number is negative then it will first
 * put a '-'. it will end. 0 value is also accepted.
 * @exception If malloc fails it will return NULL.
*/
char	*ft_itoa(int n);
/**
 * @brief This function takes input and converts input to uppercase equivalent
 * if input was lowercase 
 * @param int input
 * @return Function returns conversion 
*/
int		ft_toupper(int input);
/**
 * @brief This function takes input and converts input to lowercase equivalent
 * if input was uppercase 
 * @param int input
 * @return Function returns conversion 
*/
int		ft_tolower(int input);
/**
 * @brief  This function takes null terminated s and splits s into multiple 
 * string with delimiter c. amount of splits depend on amount of occurences
 * of c. 
 * @param char const *s
 * @param char c
 * @return Function returns float char pointer. 
 * In which first array of pointers is ended with a NULL pointer, 
 * and all strings are null terminated. 
 * @exception If allocation fails then function 
 * returns NULL.
*/
char	**ft_split(char const *s, char c);

// MEMORY

/**
 * @brief This function takes a pointer to s and puts 0 for n consecutive memory 
 * locations from the memory location pointed to by s 
 * @param void *s
 * @param size_t n
 * @return This function returns nothing.
*/
void	ft_bzero(void *s, size_t n);
/**
 * @brief This function takes a pointer to s and puts c for n consecutive memory 
 * locations from the memory location pointed to by s 
 * @param void *s
 * @param int c
 * @param size_t n
 * @return This function returns nothing.
*/
void	*ft_memset(void *s, int c, size_t n);
/**
 * @brief This function takes a pointer to dest and puts data for n consecutive 
 * memory locations from the memory location pointed to by src. Memory areas
 * may overlap. Function is similar to memcpy.
 * @param void *dest
 * @param void const *src
 * @param size_t n
 * @return This function returns nothing.
*/
void	*ft_memmove(void *dest, const void *src, size_t n);
/**
 * @brief This function takes a pointer to dest and puts data for n consecutive 
 * memory locations from the memory location pointed to by src. 
 * if memory areas that need to be copied overlap then memmove should be used.
 * @param void *dest
 * @param void const *src
 * @param size_t n
 * @return This function returns nothing.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @brief This function takes a pointer to s1 and compares data for n 
 * consecutive 
 * memory locations from the memory location pointed to by s2 
 * if memory areas that need to be copied overlap then memmove should be used.
 * @param void const *s1
 * @param void const *s2
 * @param size_t n
 * @return This function
 * returns the difference in int values of the character compared which differ
 * at the moment of comparison, if function returns 0 then n was 0 or memory
 * was equal
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief This function takes a pointer to s and looks for n consecutive memory 
 * if memory areas that need to be copied overlap then memmove should be used.
 * @param void const *s
 * @param int c
 * @param size_t n
 * @return This function returns a void pointer to the 
 * location at which c was found, or NULL if nothing was found.
*/
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief This function takes allocates memory for nmemb elments of size 
 * bytes and 
 * returns pointer to the allocated memory.
 * @param size_t nmemb
 * @param size_t size
 * @return Returns pointer to the allocated memory
 * @exception If the multiplication of nmemb 
 * and size causes a integer overflow then function will return NULL, same
 * if allocation fails.
 * @note Pointer that is returned should later be 
 * freed with free()
*/
void	*ft_calloc(size_t nmemb, size_t size);
/**
 * @brief This function is used to free a 2d char array, assuming the 2d array
 * is null terminated. 
 * @param char **arr
 * @return Function returns nothing
*/
void	free_char_array(char **arr);

// IS
/**
 * @brief This function takes c and check if it is printable. 
 * @param int c
 * @return Returns nonzero if true, and zero if false.
*/
int		ft_isprint(int c);
/**
 * @brief This function takes c and check if it is a digit. 
 * @param int c
 * @return Returns nonzero if true, and zero if false.
*/
int		ft_isdigit(int c);
/**
 * @brief This function takes c and check if it is a ascii value.
 * @param int c
 * @return Returns nonzero if true, and zero if false.
*/
int		ft_isascii(int c);
/**
 * @brief This function takes c and check if it is in the alphabet.
 * @param int c
 * @return Returns nonzero if true, and zero if false.
*/
int		ft_isalpha(int c);
/**
 * @brief This function takes c and is equivalent of ft_isalpha || ft_isdigit.
 * @param int c
 * @return Returns nonzero if true, and zero if false.
*/
int		ft_isalnum(int c);

// WRITE

/**
 * @brief This function takes c and puts this c in fd file descriptor.
 * @param char c
 * @param int fd
 * @return Returns amount of characters written.
*/
int		ft_putchar_fd(char c, int fd);
/**
 * @brief This function takes char * s and puts this string in fd 
 * file descriptor.
 * with nl charachter at the end of the string in the file descriptor
 * @param char *s
 * @param int fd
 * @return Returns amount of characters written.
*/
void	ft_putendl_fd(char *s, int fd);
/**
 * @brief This function takes d and puts this integer value as a string in 
 * fd file descriptor.
 * @param int d
 * @param int fd
 * @return Returns amount of characters written.
*/
int		ft_putnbr_fd(int d, int fd);
/**
 * @brief This function takes char *s and puts this string in fd file descriptor.
 * @param char *s
 * @param int fd
 * @return Returns amount of characters written.
*/
int		ft_putstr_fd(char *s, int fd);

// FPOINTERS

/**
 * @brief This function will accept a string and a function pointer.
 * Then to each character of the string the function will be applied
 * until we reach the null terminator of the string
 * @param char *s
 * @param void (*f)(unsigned int, char*)
 * @return Returns nothing.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief This function created a new string based on s, and then applies f
 * function to every character in the new string that is based on s.
 * @param char const *s
 * @param char (*f) (unsigned int, char)
 * @return Returns string created by f function
*/
char	*ft_strmapi(char const *s, char (*f) (unsigned int, char));

// PRINTF
/**
 * @brief This function prints out the format string + variables 
 * depending on which format specifiers are given.
 * @example ft_printf("Hello %s", s1);
 * @param char const *format
 * @param (...) variadic parameters 
 * @note accepted formatters:
 * @note %s	=	char*
 * @note %d	=	int
 * @note %i	=	int
 * @note %p	=	void*
 * @note %u	=	unsigned int
 * @note %x	=	int
 * @note %X	=	int
 * @return Returns amount of characters written
*/
int		ft_printf(const char *format, ...);

// GNL
/**
 * @brief This function returns a null terminated string which represents
 * a line from the file descriptor (fd) given.Since the function 
 * uses the read system call function, it will remember where it 
 * left of reading in the file descriptor. Returns NULL when 
 * EOF is reached
 * @param int fd
 * @param int free_buf
 * @note It can be called with
 * -D BUFFER_SIZE=(int) to increase the buffer size that is read.
 * @note free_buf will accept 0 to have normal execution
 * @note free_buf will accept 1 to free buffer and do normal execution
 * @note free_buf will accept 2 to free buffer return
 * @note free_buf will be changed to return exit code instead 
 * of being flag for freeing
 * @return Returns malloced line that is read
 * @exception returns NULL when there is read error or malloc failure 
*/
char	*get_next_line(int fd, int free_buf);

// debug
/**
 * @brief
 * This function used to debug, if during compilation the debug flag is used
 *  parameters are the same as ft_printf
 *  with -D DEBUG=1
 * @param char *format
 * @param (...) variadic parameters
 * @return Function returns nothing
 */
void	ft_debug(char *format, ...);

// PROFILE

/**
 * @brief
 * This function is used to time code. This function should be called twice, 
 *  first time to start time registration, second time after code that has to be
 *  timed has finished. function is called like ft_time(1); 
 *  then the function will immediately print the time registered. 
 *  First return can be ignored such as (void)ft_time(0); 
 *  Second return can be captured such as t_time time = ft_time(0); 
 * @example
 * ```c
 * (void)ft_time(0);
 * function_to_be_profiled();
 * t_time time = ft_time(0);
 * ```
 * @param
 * int r(eturn)type
 * @return
 * function return t_time struct
*/
t_time	ft_time(int rtype);

// io
/**
 * @brief
 * This function is used to create a file based on path
 * @param
 * char *path
 * @return
 * function returns value for succesful operation
 *  0 is succesful operation
 * @exception
 *  1 is error
 */
int		ft_create_file(char *path);
/**
 * @brief
 * This function checks if a file exists. This works for 
 * both files and directories, because directories are also
 * files in linux
 * @param
 * char *path
 * @return
 * function returns value for if file exists or not
 *  0 is file exists
 *  1 is file does not exist
 */
int		ft_check_file(char *path);
/** 
 * @brief
 * This function tries to create a directory.
 * @param
 * char *path
 * @return
 * function returns value for succesful operation
 *  0 is succesful operation
 * @exception
 *  1 is error: 
 *  mkdir function failed or directory already exists.
 *  check with ft_check_file function.
 */
int		ft_create_dir(char *path);
/**
 * @brief
 * This function returns the directory path of a full 
 *  to a file.
 *  dir = ft_dirname("dir/sub/file")
 *  dir = "dir/sub"
 * @param
 * char *path
 * @return
 * function returns value for succesful operation
 *  0 is succesful operation
 * @exception
 *  1 is error: 
 *  mkdir function failed or directory already exists.
 *  check with ft_check_file function.
 */
char	*ft_dirname(char *path);
/**
 * @brief
 * This function writes the log message to the indicated log file.
 * log to directory/log.txt
 * ft_log("directory/log.txt", "%s%d\n", "log #", 1);
 * @param
 * char *path
 * @param
 * char *format
 * @param
 * (...) variadic parameters
 * @return
 * function returns value for succesful operation
 *  0 is succesful operation
 * @exception
 *  1 is error: 
 *  fopen failed to open file
 */
int		ft_log(char *path, char *format, ...);

// BONUS

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
