/* place.c - putting buttons and text exactly where you want
 *
 *     gcc place.c -o place && ./place
 */
#include "crayon.h"

void hi(void)  { text_center("{green}You clicked a button!", 0, 40); }

int main(void) {
    window(800, 500);
    grid();                                   /* shows the coordinate numbers */
    show_coords();                            /* shows where the mouse is */

    button("Top left",     -320,  190, hi);
    button("Top right",     320,  190, hi);
    button("Middle",          0,    0, hi);
    button("Bottom left",  -320, -210, hi);
    button("Bottom right",  320, -210, hi);

    textsize(16);
    color("gray");
    text_center("The middle is (0, 0). This window goes from -400 to 400 across, -250 to 250 up/down.", 0, -120);
}
