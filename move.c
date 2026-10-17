/* move.c - move and turn pictures and text
 *
 *     gcc move.c -o move && ./move
 *
 * Everything inside the { } moves that picture (or text).
 */
#include "crayon.h"

int main(void) {
    window(800, 400);
    background("sky");

    image("turtle.png", -300, 0) {
        move_to(300, 0);        /* slide to (300, 0) */
        lt(90);                 /* turn left 90 */
        move_by(0, 100, 8);     /* go up 100, at speed 8 */
        rt(180);                /* turn right 180 */
        spin(360, 12);          /* spin all the way around, fast */
    }

    textsize(40);
    bold(1);
    label("{rainbow}Hello! 🐢", 0, -200) {
        move_to(0, -100);       /* slide up */
        rt(20);                 /* tilt it */
    }

    image("star.png", -300, 150);   /* no { } = just show the picture */
}
