/* controls.c - a settings page: slider, checkbox, switch, dropdown and a small terminal. No loops. */
#include "crayon.h"

void draw_title(void) {
    textsize(26);
    text_center(value("Dark mode") ? "{white}Settings" : "Settings", 0, 210);
}

/* runs every time "Dark mode" is clicked */
void dark_mode_changed(void) {
    background(value("Dark mode") ? "#1b1b1b" : "white");
    draw_title();
}

/* terminal commands */
void show_volume(void) { terminal_print("volume is {yellow}%d", value("Volume")); }
void show_color(void)  { terminal_print("color is {%s}%s", choice("Color"), choice("Color")); }
void show_music(void)  { terminal_print("music is %s", value("Music") ? "{lime}on" : "{red}off"); }

int main(void) {
    window(800, 500);
    background("white");
    draw_title();

    slider("Volume", 0, 100, -180, 120, 40);           /* name, min, max, x, y, start */
    checkbox("Dark mode", -230, 50);
    toggle("Music", -230, 0);
    dropdown("Color", "Red|Green|Blue|Purple", -180, -80);
    on_change("Dark mode", dark_mode_changed);

    terminal(80, -220, 380, 160, "{lime}$ ");           /* a terminal box: two corners + prompt */
    terminal_print("type {yellow}help");
    on_command("volume", show_volume);
    on_command("color", show_color);
    on_command("music", show_music);
}
