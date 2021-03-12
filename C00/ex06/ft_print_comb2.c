#include <unistd.h>

void print_nombre(int i)
{
    int Dizaine= 0;
    int Unite= 0;
    
    Dizaine= i/10 + 48;
    Unite= i%10 + 48;

    write(1,&Dizaine,1);
    write(1,&Unite,1);
}

void ft_print_comb2(void)
{
    int a=0;
    int b=0;

    while(a<=98)
    {
    b=a+1;
    while(b<=99)
    {
        print_nombre(a);
        write(1," ",2);
        print_nombre(b);
        if (!(a==98 && b==99))
        write(1,", ",2);
        b++;
    }
        a++;
        
    }
}

int main() {
    
    ft_print_comb2();

    return (0);
}
