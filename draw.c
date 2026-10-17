/* draw.c - all the ways to draw on the window
 *
 *     gcc draw.c -o draw && ./draw
 */
#include "crayon.h"

int main(void) {
    window(800, 500);
    background("white");
    speed(0);                                 /* draw instantly */

    /* lines: the pen walks and leaves a line */
    color("red");
    thickness(4);
    go_to(-350, 150);                         /* jump without drawing */
    forward(120);                             /* a line going right */

    /* a square */
    color("blue");
    go_to(-350, 50);
    repeat(4) { forward(80); right(90); }

    /* a filled triangle */
    color("orange");
    go_to(-180, 50);
    begin_fill();
    repeat(3) { forward(90); left(120); }
    end_fill();

    /* a line from one spot to another */
    color("purple");
    go_to(0, 150);
    walk_to(150, 50);

    /* circles and dots */
    color("green");
    go_to(250, 50);
    circle(50);
    color("pink");
    go_to(320, 150);
    dot(40);

    /* boxes: x, y = the middle */
    color("navy");
    box(-280, -130, 140, 70);
    color("gold");
    round_box(-80, -130, 140, 70, 20);
    color("teal");
    outline(120, -130, 140, 70, 10);

    /* a picture */
    image("turtle.png", 300, -130);

    /* words */
    textsize(18);
    color("black");
    text("line", -350, 170);
    text("square", -350, 75);
    text("filled", -180, 145);
    text("walk_to", 20, 170);
    text("circle + dot", 230, 175);
    text_center("{white}box", -280, -136);
    text_center("round_box", -80, -136);
    text_center("outline", 120, -136);
    text_center("image", 300, -195);
}
