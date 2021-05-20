

#include "libft.h"
#include <stdio.h>
#include "ft_substr.c"

int main()
{
char str[] = "bonjour je suis a 42";
int i = 100;

printf("%s", ft_substr(str, i, 50 * sizeof(char)));

}