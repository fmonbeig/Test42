

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include "ft_strtrim.c"

int main()
{
char dst[] = "bonlajour laje suisla ici la";
char set[] = "la";

int i = 100;

printf("%s\n", ft_strtrim(dst,set));

return(0);
}