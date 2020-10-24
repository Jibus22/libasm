#include "libasm.h"

# define TNAME(current_test) "\n------------------"#current_test"\t\t"
# define BKSLSH "\b\b\b\b\b\b\b\b"
# define ERROR "----errno:%d\t\t"
# define ERR_RESET "\n!!ERRNO_RESET!!errno=%d______!!"

void		strlentest(char *s1, char *s2)
{
	printf(""TNAME(RETURN_STRLEN)"s1= %-3zd\ts2= %-3zd "TNAME(RETURN FT_STRLEN)"\
s1= %-3zd\ts2= %-3zd\n", strlen(s1), strlen(s2), ft_strlen(s1), ft_strlen(s2));
}

void		strcpytest(char *s1, char *s2)
{
	char	buf[35];
	char	buf2[35];
	char	ft_buf[35];
	char	ft_buf2[35];

	printf(""TNAME(RETURN_STRCPY)"s1= |%-s|\ts2= |%-s|"
			TNAME(RETURN_FTSTCP)"s1= |%-s|\ts2= |%-s|\n", strcpy(buf, s1),
			strcpy(buf2, s2), ft_strcpy(ft_buf, s1),ft_strcpy(ft_buf2, s2));
	printf(""TNAME(BUFFERS_STRCPY)"buf=\t|%-s|\tbuf2=\t|%-s|"
			TNAME(BUFFERS_FTSTCP)"ft_buf=\t|%-s|\tft_b2=\t|%-s|\n", buf, buf2,
			ft_buf, ft_buf2);
}

void		strcmptest(char *s1, char *s2)
{
	printf(""TNAME(STRCMP)"s1-s2= %-3d\ts2-s1= %-3d "TNAME(FTSTCMP)"\
s1-s2= %-3d\ts2-s1= %-3d\n", strcmp(s1, s2), strcmp(s2, s1), ft_strcmp(s1, s2),
ft_strcmp(s2, s1));
}

void		strduptest(char *s1, char *s2)
{
	char	*dup;
	char	*dup2;
	char	*ft_dup;
	char	*ft_dup2;

	printf(""TNAME(STR_STRDUP)"dups1=\t|%-s|\tdups2=\t|%-s|"
			TNAME(STR_FTSTDP)"ft_ds1=\t|%-s|\tft_ds2=\t|%-s|\n",
			(dup = strdup(s1)), (dup2 = strdup(s2)), (ft_dup = ft_strdup(s1)),
			(ft_dup2 = ft_strdup(s2)));
	free(dup);
	free(dup2);
	free(ft_dup);
	free(ft_dup2);
}

void		writetest(char *s1, char *s2)
{
	errno = 0;
	printf(""TNAME(RET_WRITE)"writes1=%3zd\twrites2=%3zd"
			TNAME(RET_FTWRT)"ftwrts1=%3zd\tftwrts2=%3zd\n",
	write(1, s1, strlen(s1)), write(1, s2, strlen(s2)),
	ft_write(1, s1, strlen(s1)), ft_write(1, s2, strlen(s2)));
	printf(""TNAME(RET_WRITE_nbytes0)""BKSLSH"writes1=%3zd\t\
writes2=%3zd"TNAME(RET_FTWRT_nbytes0)""BKSLSH"ftwrts1=%3zd\t\
ftwrts2=%3zd\n", write(1, s1, 0), write(1, s2, 0), ft_write(1, s1, 0),
ft_write(1, s2, 0));
	printf(""TNAME(RET_WRITE_nbytes-1)""BKSLSH"writes1=%3zd"ERROR"writes2=%3zd"
ERROR""ERR_RESET""TNAME(RET_FTWRT_nbytes-1)""BKSLSH"ftwrts1=%3zd"ERROR"ftwrts2=\
%3zd"ERROR"\n", write(1, s1, -1), errno, write(1, s2, -1), errno, errno=0,
ft_write(1, s1, -1), errno, ft_write(1, s2, -1), errno);
	printf(""TNAME(RET_WRITE_nullstr)""BKSLSH"writes1=%3zd"ERROR"writes2=%3zd"
ERROR""ERR_RESET""TNAME(RET_FTWRT_nullstr)""BKSLSH"ftwrts1=%3zd"ERROR"ftwrts2=\
%3zd"ERROR"\n", write(1, NULL, 10), errno, write(1, NULL, 10), errno, errno=0,
ft_write(1, NULL, 10), errno, ft_write(1, NULL, 10), errno);
	printf(""TNAME(RET_WRITE_bad_fd)""BKSLSH"writes1=%3zd"ERROR"writes2=%3zd"
ERROR""ERR_RESET""TNAME(RET_FTWRT_bad_fd)""BKSLSH"ftwrts1=%3zd"ERROR"ftwrts2=\
%3zd"ERROR"\n", write(10, s1, strlen(s1)), errno, write(10, s2, strlen(s2)),
errno, errno=0, ft_write(10, s1, strlen(s1)), errno, ft_write(10, s2,
strlen(s2)), errno);
}

void		clear_buf(char *buf1, char *buf2)
{
	int		i;

	i = -1;
	while (++i < 45)
	{
		buf1[i] = 0;
		buf2[i] = 0;
	}
}

void		readtest(char *file)
{
	char	buf[45];
	char	ft_buf[45];
	int		fd;

	errno = 0;
//test1
	clear_buf(buf, ft_buf);
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_READ10)"read  =%3zd\tbuf   :%s\n", read(fd, buf, 10),
buf);
	close(fd);
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_FTRD10)"ftread=%3zd\tft_buf:%s\n", read(fd, ft_buf, 10),
ft_buf);
	close(fd);
//test2
	clear_buf(buf, ft_buf);
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_READ42)"read  =%3zd\tbuf   :%s\n", read(fd, buf, 42),
buf);
	close(fd);
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_FTRD42)"ftread=%3zd\tft_buf:%s\n", read(fd, ft_buf, 42),
ft_buf);
	close(fd);
//test3
	clear_buf(buf, ft_buf);
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_READ0)"read  =%3zd\tbuf   :%s\n", read(fd, buf, 0), buf);
	close(fd);
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_FTRD0)"ftread=%3zd\tft_buf:%s\n", read(fd, ft_buf, 0),
ft_buf);
	close(fd);
//test4
	clear_buf(buf, ft_buf);
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_READ_bad_fd)""BKSLSH"read  =%3zd\t"ERROR"buf   :%s\n",
read(100, buf, 42), errno, buf);
	close(fd);
	errno = 0;
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_FTRD_bad_fd)""BKSLSH"ftread=%3zd\t"ERROR"ft_buf:%s\n",
read(100, ft_buf, 42), errno, ft_buf);
	close(fd);
	errno = 0;
//test5
	clear_buf(buf, ft_buf);
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_READ_nbytes-1)""BKSLSH"read  =%3zd\t"ERROR"buf   :%s\n",
read(fd, buf, -1), errno, buf);
	close(fd);
	errno = 0;
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_FTRD_nbytes-1)""BKSLSH"ftread=%3zd\t"ERROR"ft_buf:%s\n",
read(fd, ft_buf, -1), errno, ft_buf);
	close(fd);
	errno = 0;
//test6
	clear_buf(buf, ft_buf);
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_READ_nullbuf)""BKSLSH"read  =%3zd\t"ERROR"buf   :%s\n",
read(1, NULL, 42), errno, buf);
	close(fd);
	errno = 0;
	fd = open(file, O_RDONLY);
	printf(""TNAME(RET_FTRD_nullbuf)""BKSLSH"ftread=%3zd\t"ERROR"ft_buf:%s\n",
read(1, NULL, 42), errno, ft_buf);
	close(fd);
	errno = 0;
}

int			main(int ac, char **av)
{
	if (ac != 4)
	{
		write(1, "You must give me 2 strings & a file to read, try again", 54);
		return(0);
	}
	write(1, "\n\n\t\t--------------------STRLEN-----------------\n\n", 49);
	strlentest(av[1], av[2]);
	write(1, "\n\n\t\t--------------------STRCPY-----------------\n\n", 49);
	strcpytest(av[1], av[2]);
	write(1, "\n\n\t\t--------------------STRCMP-----------------\n\n", 49);
	strcmptest(av[1], av[2]);
	write(1, "\n\n\t\t--------------------STRDUP-----------------\n\n", 49);
	strduptest(av[1], av[2]);
	write(1, "\n\n\t\t--------------------WRITE-----------------\n\n", 48);
	writetest(av[1], av[2]);
	write(1, "\n\n\t\t--------------------READ-----------------\n\n", 47);
	readtest(av[3]);
	return (0);
}
