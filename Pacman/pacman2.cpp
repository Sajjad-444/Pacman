//
#include"pacman1.h"
//
int main()
{
    welcome();
    if (level == l || level == m || level == h)
    {
        map[x_r0][y_r0] = 'E';
        map[x_r2][y_r2] = 'E';
    }
    if (level == m || level == h)
    {
        map[x_r1][y_r1] = 'E';
    }
    if (level == h)
    {
        map[x_r3][y_r3] = 'E';
    }

    map[x_p][y_p] = 'x';

    set_map();
    show_map_score();

    thread farar = thread(farar_pacman);
    thread roh = thread(move_roh);
    thread pacman = thread(move_pacman);
    thread end = thread(end_game);

    farar.join();
    roh.join();
    pacman.join();
    end.join();

    return 0;
}
//
