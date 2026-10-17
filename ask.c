/* ask.c - a little "ask me anything" bot
 *
 *     gcc ask.c -o ask && ./ask
 */
#include "crayon.h"

void page(void) {
    clear();                                   /* wipe the old answer */
    image("turtle.png", 0, 120, 2);
    textsize(22);
    text_center("{white}Ask the turtle anything!", 0, 40);
}

int main(void) {
    window(1000, 500);
    background("black");
    page();

    while (1) {
        const char *input = userinput("?:");
        page();                                /* fresh screen for every question */

        textsize(20);
        if (strstr(input, "gnu"))
            text_center("{white}GNU is free software you can use, change and share.", 0, -100);
        else if (strstr(input, "linux"))
            text_center("{white}Linux is a kernel made by {yellow}Linus Torvalds{white}.", 0, -100);
        else if (strstr(input, "hello") || strstr(input, "hi"))
            text_center("{green}Hello there!", 0, -100);
        else
            text_center("{gray}I don't know \"%s\" yet", 0, -100, input);
    }
}
