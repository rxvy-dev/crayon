/* move.c - slide and spin pictures and text
 *
 *     gcc move.c -o move && ./move
 */
#include "crayon.h"

int main(void) {
    window(800, 400);
    background("sky");

    Thing turtle = add_image("turtle.png", -300, 0);     /* a picture you can move */
    textsize(40);
    bold(1);
    Thing title = add_text("{rainbow}Hello! 🐢", 0, 150);  /* text you can move */

    move_to(turtle, 300, 0, 5);       /* slide to (300, 0) at speed 5, wait until it's there */
    spin(turtle, 180, 6);             /* turn around, wait */

    glide(turtle, -300, 0, 4);        /* slide back... (doesn't wait) */
    start_spin(title, 360, 3);        /* ...while the title spins at the same time */
    wait_for(3);

    move_to(title, 0, -100, 8);       /* drop the title down */
    change_text(title, "{green}Done! ✅");
}
