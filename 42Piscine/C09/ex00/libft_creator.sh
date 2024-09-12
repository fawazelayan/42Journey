rm -f libft.a
find . -name "*.c" -type f -exec cc -Wall -Werror -Wextra -c {} \;
ar rc libft.a *.o
find . -name "*.o" -type f -delete
