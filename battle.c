/* battle.c - grab coins while ghosts hunt you
 *
 *     gcc battle.c -o battle && ./battle
 *
 * Arrow keys or WASD. Ghosts bite, and they shoot fireballs.
 */
#include "crayon.h"

void got_coin(void) {
    add_score(1);
    respawn();
    if (score() == 20) you_win("YOU WIN!");
}

int main(void) {
    window(900, 600);
    title("Ghost Battle");
    background("#1b1b2f");

    player("turtle.png");
    spawn("coin.png", 6, 0.8);
    on_touch("coin.png", got_coin);
    spin_all("coin.png", 4);

    enemies("ghost.png", 3, 1.2, 15);           /* 3 ghosts: speed 1.2, 15 damage a bite */
    shoots("ghost.png", "fireball.png", 2, 10); /* a fireball every 2 seconds, 10 damage */

    health(100);                                /* health bar */
    show_score();
}
