/* coins.c - a whole game with no loops
 *
 *     gcc coins.c -o coins && ./coins
 *
 * Arrow keys or WASD to move. Grab coins, dodge the stars!
 */
#include "crayon.h"

void got_coin(void) {
    add_score(1);
    sound("coin.wav");
    respawn();                      /* the coin jumps somewhere new */
    if (score() == 15) you_win("YOU WIN!");
}

void got_hit(void) {
    lose_life();
    respawn();                      /* the star jumps away */
}

int main(void) {
    window(800, 560);
    title("Coin Grab");
    background("lightgreen");

    player("turtle.png");           /* you */
    spawn("coin.png", 5);           /* 5 coins */
    spawn("star.png", 2);           /* 2 enemies */

    on_touch("coin.png", got_coin);
    on_touch("star.png", got_hit);

    spin_all("coin.png", 4);        /* coins spin */
    chase("star.png", 1);           /* stars chase you (slowly) */

    show_score();
    lives(3);
}
