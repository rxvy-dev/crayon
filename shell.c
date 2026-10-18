/* shell.c - a little terminal. No loops: each command is just a function. */
#include "crayon.h"

void hi(void)    { terminal_print("{party}hello there!!"); }
void ls(void)    { run("ls"); terminal_print("%s", run_output()); }
void echo(void)  { terminal_print("%s", rest(1)); }           /* rest(1) = everything after "echo" */
void add(void)   { terminal_print("%g", number(1) + number(2)); }   /* add 2 3  ->  5   (%g for numbers from number()) */
void name(void) {
    const char *n = terminal_input("{yellow}what's your name? ");   /* ask something and wait */
    terminal_print("nice to meet you {lime}%s", n);
}

int main(void) {
    window(800, 500);
    title("rxvy shell");

    terminal("{lime}rxvy@arch{white}:{blue}~{white}$ ");     /* the whole window is a terminal */
    terminal_print("{lime}Welcome!{white} type {yellow}help{white} to see the commands");

    on_command("hi", hi);
    on_command("ls", ls);
    on_command("echo", echo);
    on_command("add", add);
    on_command("name", name);
}
