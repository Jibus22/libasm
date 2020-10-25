#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/errno.h>

size_t		ft_strlen(const char *str) asm("ft_strlen");
char		*ft_strcpy(char *dst,const char *src) asm("ft_strcpy");
int		ft_strcmp(const char *s1,const  char *s2) asm("ft_strcmp");
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte) asm("ft_write");
ssize_t		ft_read(int fildes, void *buf, size_t nbyte) asm("ft_read");
char		*ft_strdup(const char *s1) asm("ft_strdup");

#endif
