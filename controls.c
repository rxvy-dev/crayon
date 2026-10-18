#include "crayon.h"
void changed(void) {
    background(value("Dark mode") ? "#1b1b1b" : "white");
    textsize(26); text_center(value("Dark mode") ? "{white}Settings" : "Settings", 0, 210);
}
int main(void) {
    window(800, 500);
    background("white");
    textsize(26); text_center("Settings", 0, 210); textsize(16);
    slider("Volume", 0, 100, -180, 120, 40);
    checkbox("Dark mode", -230, 50);
    toggle("Music", -230, 0);
    dropdown("Color", "Red|Green|Blue|Purple", -180, -80);
    on_change("Dark mode", changed);
    terminal(80, -220, 380, 160);
    cli_print("{lime}crayon shell{white} - type help");
    cli_print("{gray}a very long line that should wrap around inside the little terminal box nicely");
    while (1) {
        const char *cmd = cli("{lime}rxvy{white}:~$ ");
        if (same(cmd, "help")) cli_print("commands: vol, color, music, echo, clear");
        else if (same(cmd, "vol")) cli_print("volume is {yellow}%d", value("Volume"));
        else if (same(cmd, "color")) cli_print("color is {%s}%s", choice("Color"), choice("Color"));
        else if (same(cmd, "music")) cli_print("music is %s", value("Music") ? "{lime}on" : "{red}off");
        else if (command("echo")) cli_print("%s", rest(1));
        else if (same(cmd, "clear")) cli_clear();
        else if (cmd[0]) cli_print("{red}unknown command: %s", cmd);
    }
}
