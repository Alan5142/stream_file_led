#include <stdio.h>
#include <unistd.h>

int main()
{
    FILE *f = fopen("/dev/urandom", "r");
    FILE *led = fopen("/sys/class/leds/gpio-led/brightness", "w+");

    if (f == NULL || led == NULL)
    {
        perror("Error opening file");
        return 1;
    }
    while (1)
    {
        char c =  fgetc(f) > 128 ? '1' : '0';
        fputc(c, led);
        printf("%c\n", c + '0');
        fflush(led);
        sleep(1);
    }
}