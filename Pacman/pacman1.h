//
#include <iostream>

#include <unistd.h>

#include <conio.h>

#include <thread>

using namespace std;
//
//
enum grade
{
    h,
    m,
    l
};
//
//
grade level;
//
//
char map[18][32] = {
    "###############################",
    "#                             #",
    "#                             #",
    "#                             #",
    "#                             #",
    "#                             #",
    "#                             #",
    "########...............########",
    "#.............................#",
    "########....#######....########",
    "#                             #",
    "#                             #",
    "#                             #",
    "#                             #",
    "#                             #",
    "#                             #",
    "#.............................#",
    "###############################"};
//
// pacman_location
int x_p = 16;
int y_p = 15;
int old_x_p;
int old_y_p;
int will_x_p;
int will_y_p;
//
// roh1_location
int x_r1 = 3;
int y_r1 = 15;
int old_x_r1;
int old_y_r1;
int will_x_r1;
int will_y_r1;
//
// roh0_location
int x_r0 = 7;
int y_r0 = 15;
int old_x_r0;
int old_y_r0;
int will_x_r0;
int will_y_r0;
//
// roh2_location
int x_r2 = 10;
int y_r2 = 15;
int old_x_r2;
int old_y_r2;
int will_x_r2;
int will_y_r2;
//
// roh3_location
int x_r3 = 13;
int y_r3 = 15;
int old_x_r3;
int old_y_r3;
int will_x_r3;
int will_y_r3;
//
//
bool running = true;
//
//
char operaitor;
char operaitor_;
//
//
void get_operator_()
{
    if (running == true)
    {
        operaitor_ = getch();
    }
}
//
//
int score = 0;
int frute = 80;
//
//
void show_map_score()
{
    system("clear");
    for (int i = 0; i < 18; i++)
    {
        printf("%s\n", map[i]);
    }

    cout << endl
         << "Your Score Is:" << score << endl
         << endl
         << "The Rest Of Frute Is:" << frute << endl;
}
//
//
void get_operaitor()
{
    if (running == true)
    {
        operaitor = getch();
    }
}
//
//
void welcome()
{
    system("clear");
    cout << "Welcome To Pacman Game" << endl;
    usleep(1000000 * 2);
    system("clear");
    cout << "Choose Difficulty" << endl;
    usleep(1000000 * 2);
    system("clear");
    cout << "Enter h For High Level" << endl;
    cout << "Enter m For Midd Level" << endl;
    cout << "Enter l For Low Level" << endl
         << endl;
    get_operator_();
    if (operaitor_ == 'h' || operaitor_ == 'm' || operaitor_ == 'l')
    {
        if (operaitor_ == 'h')
        {
            level = h;
        }
        else if (operaitor_ == 'm')
        {
            level = m;
        }
        else if (operaitor_ == 'l')
        {
            level = l;
        }

        system("clear");
        usleep(1000000 * 2);
        cout << "Begin" << endl;
        usleep(1000000 * 2);
    }
    else
    {
        cout << endl
             << "Retry" << endl;
        usleep(1000000 * 2);
        system("clear");
        welcome();
    }
}
//
//
void move_pacman()
{
    while (running == true)
    {
        get_operaitor();

        while (!kbhit())
        {
            //
            old_x_p = x_p;
            old_y_p = y_p;
            will_x_p = x_p;
            will_y_p = y_p;
            //

            switch (operaitor)
            {
            case 'w':
            {

                will_x_p--;
                if (map[will_x_p][will_y_p] != '#' && will_x_p < 18 && will_y_p < 32)
                {
                    if (map[will_x_p][will_y_p] == '.')
                    {
                        score += 10;
                        frute--;
                    }
                    if (running == true)
                    {
                        x_p--;
                        map[old_x_p][old_y_p] = ' ';
                        map[x_p][y_p] = 'x';
                        usleep(1000000 * 0.22);
                        show_map_score();
                    }
                }
                break;
            }
            case 's':
            {
                will_x_p++;
                if (map[will_x_p][will_y_p] != '#' && will_x_p < 18 && will_y_p < 32)
                {
                    if (map[will_x_p][will_y_p] == '.')
                    {
                        score += 10;
                        frute--;
                    }
                    if (running == true)
                    {
                        x_p++;
                        map[old_x_p][old_y_p] = ' ';
                        map[x_p][y_p] = 'x';
                        usleep(1000000 * 0.22);
                        show_map_score();
                    }
                }

                break;
            }
            case 'a':
            {
                will_y_p--;
                if (map[will_x_p][will_y_p] != '#' && will_x_p < 18 && will_y_p < 32)
                {
                    if (map[will_x_p][will_y_p] == '.')
                    {
                        score += 10;
                        frute--;
                    }
                    if (running == true)
                    {
                        y_p--;
                        map[old_x_p][old_y_p] = ' ';
                        map[x_p][y_p] = 'x';
                        usleep(1000000 * 0.22);
                        show_map_score();
                    }
                }
                break;
            }
            case 'd':
            {
                will_y_p++;
                if (map[will_x_p][will_y_p] != '#' && will_x_p < 18 && will_y_p < 32)
                {
                    if (map[will_x_p][will_y_p] == '.')
                    {
                        score += 10;
                        frute--;
                    }
                    if (running == true)
                    {
                        y_p++;
                        map[old_x_p][old_y_p] = ' ';
                        map[x_p][y_p] = 'x';
                        usleep(1000000 * 0.22);
                        show_map_score();
                    }
                }
                break;
            }
            }
        }
    }
}
//
//
int counter = 0;
//
//
void sum_counter()
{
    counter++;
}
//
//
int random_number_generator0()
{

    int result;
    srand(counter);
    result = rand() % 4;
    sum_counter();
    return result;
}
//
//
int random_number_generator1(int baghimandeh)
{
    int result;
    srand(time(0));

    result = rand() % baghimandeh;
    return result;
}
//
//
void move_roh0()
{
    int operaitor_number;

    //
    old_x_r0 = x_r0;
    old_y_r0 = y_r0;
    will_x_r0 = x_r0;
    will_y_r0 = y_r0;
    //

    operaitor_number = random_number_generator0();
    switch (operaitor_number)
    {
    case 0: // w
    {

        will_x_r0--;
        if (map[will_x_r0][will_y_r0] != '#' && will_x_r0 < 18 && will_y_r0 < 32)

        {

            if (map[will_x_r0][will_y_r0] == '.')
            {
                x_r0--;
                map[old_x_r0][old_y_r0] = '.';
                map[x_r0][y_r0] = 'E';
            }
            else
            {
                x_r0--;
                map[old_x_r0][old_y_r0] = ' ';
                map[x_r0][y_r0] = 'E';
            }
        }
        break;
    }
    case 1: // s
    {
        will_x_r0++;
        if (map[will_x_r0][will_y_r0] != '#' && will_x_r0 < 18 && will_y_r0 < 32)
        {

            if (map[will_x_r0][will_y_r0] == '.')
            {
                x_r0++;
                map[old_x_r0][old_y_r0] = '.';
                map[x_r0][y_r0] = 'E';
            }
            else
            {
                x_r0++;
                map[old_x_r0][old_y_r0] = ' ';
                map[x_r0][y_r0] = 'E';
            }
        }
        break;
    }
    case 2: // a
    {
        will_y_r0--;
        if (map[will_x_r0][will_y_r0] != '#' && will_x_r0 < 18 && will_y_r0 < 32)
        {

            if (map[will_x_r0][will_y_r0] == '.')
            {
                y_r0--;
                map[old_x_r0][old_y_r0] = '.';
                map[x_r0][y_r0] = 'E';
            }
            else
            {
                y_r0--;
                map[old_x_r0][old_y_r0] = ' ';
                map[x_r0][y_r0] = 'E';
            }
        }
        break;
    }
    case 3: // d
    {
        will_y_r0++;
        if (map[will_x_r0][will_y_r0] != '#' && will_x_r0 < 18 && will_y_r0 < 32)
        {

            if (map[will_x_r0][will_y_r0] == '.')
            {
                y_r0++;
                map[old_x_r0][old_y_r0] = '.';
                map[x_r0][y_r0] = 'E';
            }
            else
            {
                y_r0++;
                map[old_x_r0][old_y_r0] = ' ';
                map[x_r0][y_r0] = 'E';
            }
        }
        break;
    }
    }
}
//
//
void move_roh2()
{
    int operaitor_number;

    //
    old_x_r2 = x_r2;
    old_y_r2 = y_r2;
    will_x_r2 = x_r2;
    will_y_r2 = y_r2;
    //

    operaitor_number = random_number_generator0();
    switch (operaitor_number)
    {
    case 0: // w
    {

        will_x_r2--;
        if (map[will_x_r2][will_y_r2] != '#' && will_x_r2 < 18 && will_y_r2 < 32)

        {

            if (map[will_x_r2][will_y_r2] == '.')
            {
                x_r2--;
                map[old_x_r2][old_y_r2] = '.';
                map[x_r2][y_r2] = 'E';
            }
            else
            {
                x_r2--;
                map[old_x_r2][old_y_r2] = ' ';
                map[x_r2][y_r2] = 'E';
            }
        }
        break;
    }
    case 1: // s
    {
        will_x_r2++;
        if (map[will_x_r2][will_y_r2] != '#' && will_x_r2 < 18 && will_y_r2 < 32)
        {

            if (map[will_x_r2][will_y_r2] == '.')
            {
                x_r2++;
                map[old_x_r2][old_y_r2] = '.';
                map[x_r2][y_r2] = 'E';
            }
            else
            {
                x_r2++;
                map[old_x_r2][old_y_r2] = ' ';
                map[x_r2][y_r2] = 'E';
            }
        }
        break;
    }
    case 2: // a
    {
        will_y_r2--;
        if (map[will_x_r2][will_y_r2] != '#' && will_x_r2 < 18 && will_y_r2 < 32)
        {

            if (map[will_x_r2][will_y_r2] == '.')
            {
                y_r2--;
                map[old_x_r2][old_y_r2] = '.';
                map[x_r2][y_r2] = 'E';
            }
            else
            {
                y_r2--;
                map[old_x_r2][old_y_r2] = ' ';
                map[x_r2][y_r2] = 'E';
            }
        }
        break;
    }
    case 3: // d
    {
        will_y_r2++;
        if (map[will_x_r2][will_y_r2] != '#' && will_x_r2 < 18 && will_y_r2 < 32)
        {

            if (map[will_x_r2][will_y_r2] == '.')
            {
                y_r2++;
                map[old_x_r2][old_y_r2] = '.';
                map[x_r2][y_r2] = 'E';
            }
            else
            {
                y_r2++;
                map[old_x_r2][old_y_r2] = ' ';
                map[x_r2][y_r2] = 'E';
            }
        }
        break;
    }
    }
}
//
//
void w_roh1()
{

    will_x_r1--;
    if (map[will_x_r1][will_y_r1] != '#' && will_x_r1 < 18 && will_y_r1 < 32)

    {

        if (map[will_x_r1][will_y_r1] == '.')
        {
            x_r1--;
            map[old_x_r1][old_y_r1] = '.';
            map[x_r1][y_r1] = 'E';
        }
        else
        {
            x_r1--;
            map[old_x_r1][old_y_r1] = ' ';
            map[x_r1][y_r1] = 'E';
        }
    }
}
//
//
void s_roh1()
{

    will_x_r1++;
    if (map[will_x_r1][will_y_r1] != '#' && will_x_r1 < 18 && will_y_r1 < 32)
    {

        if (map[will_x_r1][will_y_r1] == '.')
        {
            x_r1++;
            map[old_x_r1][old_y_r1] = '.';
            map[x_r1][y_r1] = 'E';
        }
        else
        {
            x_r1++;
            map[old_x_r1][old_y_r1] = ' ';
            map[x_r1][y_r1] = 'E';
        }
    }
}
//
//
void a_roh1()
{

    will_y_r1--;
    if (map[will_x_r1][will_y_r1] != '#' && will_x_r1 < 18 && will_y_r1 < 32)
    {

        if (map[will_x_r1][will_y_r1] == '.')
        {
            y_r1--;
            map[old_x_r1][old_y_r1] = '.';
            map[x_r1][y_r1] = 'E';
        }
        else
        {
            y_r1--;
            map[old_x_r1][old_y_r1] = ' ';
            map[x_r1][y_r1] = 'E';
        }
    }
}
//
//
void d_roh1()
{

    will_y_r1++;
    if (map[will_x_r1][will_y_r1] != '#' && will_x_r1 < 18 && will_y_r1 < 32)
    {

        if (map[will_x_r1][will_y_r1] == '.')
        {
            y_r1++;
            map[old_x_r1][old_y_r1] = '.';
            map[x_r1][y_r1] = 'E';
        }
        else
        {
            y_r1++;
            map[old_x_r1][old_y_r1] = ' ';
            map[x_r1][y_r1] = 'E';
        }
    }
}
//
//
void w_roh3()
{

    will_x_r3--;
    if (map[will_x_r3][will_y_r3] != '#' && will_x_r3 < 18 && will_y_r3 < 32)

    {

        if (map[will_x_r3][will_y_r3] == '.')
        {
            x_r3--;
            map[old_x_r3][old_y_r3] = '.';
            map[x_r3][y_r3] = 'E';
        }
        else
        {
            x_r3--;
            map[old_x_r3][old_y_r3] = ' ';
            map[x_r3][y_r3] = 'E';
        }
    }
}
//
//
void s_roh3()
{

    will_x_r3++;
    if (map[will_x_r3][will_y_r3] != '#' && will_x_r3 < 18 && will_y_r3 < 32)
    {

        if (map[will_x_r3][will_y_r3] == '.')
        {
            x_r3++;
            map[old_x_r3][old_y_r3] = '.';
            map[x_r3][y_r3] = 'E';
        }
        else
        {
            x_r3++;
            map[old_x_r3][old_y_r3] = ' ';
            map[x_r3][y_r3] = 'E';
        }
    }
}
//
//
void a_roh3()
{

    will_y_r3--;
    if (map[will_x_r3][will_y_r3] != '#' && will_x_r3 < 18 && will_y_r3 < 32)
    {

        if (map[will_x_r3][will_y_r3] == '.')
        {
            y_r3--;
            map[old_x_r3][old_y_r3] = '.';
            map[x_r3][y_r3] = 'E';
        }
        else
        {
            y_r3--;
            map[old_x_r3][old_y_r3] = ' ';
            map[x_r3][y_r3] = 'E';
        }
    }
}
//
//
void d_roh3()
{

    will_y_r3++;
    if (map[will_x_r3][will_y_r3] != '#' && will_x_r3 < 18 && will_y_r3 < 32)
    {

        if (map[will_x_r3][will_y_r3] == '.')
        {
            y_r3++;
            map[old_x_r3][old_y_r3] = '.';
            map[x_r3][y_r3] = 'E';
        }
        else
        {
            y_r3++;
            map[old_x_r3][old_y_r3] = ' ';
            map[x_r3][y_r3] = 'E';
        }
    }
}
//
//
void move_roh1()
{

    //
    old_x_r1 = x_r1;
    old_y_r1 = y_r1;
    will_x_r1 = x_r1;
    will_y_r1 = y_r1;
    //

    if (x_p - x_r1 > 0 && y_p - y_r1 > 0)
    {
        d_roh1();
    }

    else if (x_p - x_r1 < 0 && y_p - y_r1 > 0)
    {
        d_roh1();
    }

    else if (x_p - x_r1 < 0 && y_p - y_r1 < 0)
    {
        w_roh1();
    }

    else if (x_p - x_r1 > 0 && y_p - y_r1 < 0)
    {
        s_roh1();
    }

    else if (x_p == x_r1 && y_p - y_r1 > 0)
    {
        d_roh1();
    }

    else if (x_p == x_r1 && y_p - y_r1 < 0)
    {
        a_roh1();
    }

    else if (y_p == y_r1 && x_p - x_r1 > 0)
    {
        s_roh1();
    }

    else if (y_p == y_r1 && x_p - x_r1 < 0)
    {
        w_roh1();
    }
}
//
//
void move_roh3()
{

    //
    old_x_r3 = x_r3;
    old_y_r3 = y_r3;
    will_x_r3 = x_r3;
    will_y_r3 = y_r3;
    //

    if (x_p - x_r3 > 0 && y_p - y_r3 > 0)
    {
        d_roh3();
    }

    else if (x_p - x_r3 < 0 && y_p - y_r3 > 0)
    {
        d_roh3();
    }

    else if (x_p - x_r3 < 0 && y_p - y_r3 < 0)
    {
        w_roh3();
    }

    else if (x_p - x_r3 > 0 && y_p - y_r3 < 0)
    {
        s_roh3();
    }

    else if (x_p == x_r3 && y_p - y_r3 > 0)
    {
        d_roh3();
    }

    else if (x_p == x_r3 && y_p - y_r3 < 0)
    {
        a_roh3();
    }

    else if (y_p == y_r3 && x_p - x_r3 > 0)
    {
        s_roh3();
    }

    else if (y_p == y_r3 && x_p - x_r3 < 0)
    {
        w_roh3();
    }
}
//
//
void end_game()
{
    while (running == true)
    {
        if (frute == 0)
        {

            running = false;

            usleep(1000000 * 1);

            system("clear");
            cout << endl
                 << "Victory" << endl;
        }
        else if (level == l && x_p == x_r0 && y_p == y_r0 || x_p == x_r2 && y_p == y_r2)
        {
            running = false;

            usleep(1000000 * 1);

            system("clear");
            cout << endl
                 << "You Lose" << endl;
        }
        else if (level == m && x_p == x_r0 && y_p == y_r0 || x_p == x_r2 && y_p == y_r2 || x_p == x_r1 && y_p == y_r1)
        {
            running = false;

            usleep(1000000 * 1);

            system("clear");
            cout << endl
                 << "You Lose" << endl;
        }
        else if (level == h && x_p == x_r0 && y_p == y_r0 || x_p == x_r2 && y_p == y_r2 || x_p == x_r1 && y_p == y_r1 || x_p == x_r3 && y_p == y_r3)
        {
            running = false;

            usleep(1000000 * 1);

            system("clear");
            cout << endl
                 << "You Lose" << endl;
        }
    }
}
//
//
void move_roh()
{
    usleep(1000000 * 5);
    while (running == true)
    {
        if (level == l || level == m || level == h)
        {
            move_roh0();
            move_roh2();
        }
        if (level == m || level == h)
        {
            move_roh1();
        }
        if (level == h)
        {
            move_roh3();
        }

        usleep(1000000 * 0.3);

        show_map_score();
    }
}
//
//
void farar_pacman()
{
    while (running == true)
    {
        if (x_p == 8 && y_p == 1)
        {
            map[8][1] = ' ';
            x_p = 8;
            y_p = 29;
            show_map_score();
        }
        else if (x_p == 8 && y_p == 29)
        {
            map[8][29] = ' ';
            x_p = 8;
            y_p = 1;
            show_map_score();
        }
    }
}
//
//
void diagram(int x, int y)
{
    int num = random_number_generator1(4);

    switch (num)
    {
    case 0:
    {

        map[x][y] = '#';
        map[x][y + 1] = '#';
        map[x + 1][y] = '#';
        map[x + 1][y + 1] = '#';
        map[x][y - 1] = '#';
        map[x + 1][y - 1] = '#';

        break;
    }
    case 1:
    {

        map[x][y] = '.';
        map[x][y + 1] = '.';
        map[x + 1][y] = '.';
        map[x + 1][y + 1] = '.';
        map[x][y - 1] = '.';
        map[x + 1][y - 1] = '.';
        frute += 6;

        break;
    }
    case 2:
    {
        map[x][y] = '.';
        map[x + 1][y - 1] = '.';
        map[x + 1][y] = '.';
        map[x + 1][y + 1] = '.';
        frute += 4;
        break;
    }
    case 3:
    {
        map[x][y] = '#';
        map[x + 1][y - 1] = '#';
        map[x + 1][y] = '#';
        map[x + 1][y + 1] = '#';

        break;
    }
    }
}
//
//
void set_map()
{

    diagram(1, 5);
    usleep(1000000 * 0.11);
    diagram(1, 10);
    usleep(1000000 * 0.11);
    diagram(1, 15);
    usleep(1000000 * 0.11);
    diagram(1, 20);
    usleep(1000000 * 0.11);
    diagram(1, 25);
    usleep(1000000 * 0.33);
    diagram(4, 5);
    usleep(1000000 * 0.11);
    diagram(4, 10);
    usleep(1000000 * 0.11);
    diagram(4, 15);
    usleep(1000000 * 0.11);
    diagram(4, 20);
    usleep(1000000 * 0.11);
    diagram(4, 25);
    usleep(1000000 * 0.33);
    diagram(11, 5);
    usleep(1000000 * 0.11);
    diagram(11, 10);
    usleep(1000000 * 0.11);
    diagram(11, 15);
    usleep(1000000 * 0.11);
    diagram(11, 20);
    usleep(1000000 * 0.11);
    diagram(11, 25);
    usleep(1000000 * 0.33);
    diagram(14, 5);
    usleep(1000000 * 0.11);
    diagram(14, 10);
    usleep(1000000 * 0.11);
    diagram(14, 15);
    usleep(1000000 * 0.11);
    diagram(14, 20);
    usleep(1000000 * 0.11);
    diagram(14, 25);
}
//