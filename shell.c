#include "crayon.h"
int main(void) {
    window(800, 500);
    title("rxvy shell");
    terminal();
    cli_print("{lime}Welcome to rxvy shell!{white} Commands: ls, hi, quit");
    for (int i = 1; i <= 40; i++) cli_print("{gray}boot line %d ... {lime}ok", i);
    while (1) {
        const char *cmd = cli("{lime}rxvy@arch{white}:{blue}~{white}$ ");
        if (same(cmd, "ls")) { run("ls /"); cli_print("%s", run_output()); }
        else if (same(cmd, "hi")) cli_print("{party}hello!!");
        else if (same(cmd, "quit")) quit();
    }
}
