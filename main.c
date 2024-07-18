#include <ncurses.h>
#include <stdlib.h>

int main()
{
    char *text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Phasellus congue convallis laoreet. Aliquam at pulvinar magna. Mauris rutrum, quam vitae tincidunt tempus, metus risus semper nisi, a porta nunc est et odio. Proin id lorem sed elit consequat vulputate id ac augue. Ut ultrices lectus nec congue condimentum. Phasellus a est a ex porttitor luctus in sed velit. Fusce quis aliquet nulla. Sed quam ante, rutrum id pulvinar non, feugiat nec lectus. Nulla pellentesque nibh nec consequat pellentesque. In sagittis pellentesque lobortis. Nam eu nibh ut quam imperdiet luctus in eget metus. Vestibulum pellentesque et ante vel dapibus. Proin venenatis massa id malesuada placerat. Suspendisse sollicitudin, sem quis consequat porttitor, lacus nulla consectetur nisl, vel viverra ante eros vel tortor. In ut urna vel mi convallis rutrum.\0";

    initscr();
    noecho();

    if (has_colors())
    {
        start_color();

        init_pair(1, COLOR_BLACK, COLOR_WHITE);
    }

    addstr(text);
    move(0, 0);

    int ch;
    while ((ch = getch()))
    {
        int y, x;
        getyx(stdscr, y, x);
        switch (ch)
        {
            case 'h':
                move(y, x - 1);
                break;
            case 'j':
                move(y + 1, x);
                break;
            case 'k':
                move(y - 1, x);
                break;
            case 'l':
                move(y, x + 1);
                break;
            case ':':
                int cmd;
                echo();
                mvaddstr(LINES - 1, 0, ":");
                cmd = getch();
                if (cmd == 'q')
                {
                    endwin();
                    exit(0);
                }
                noecho();
                break;
            default:
                break;

        }

    }

    endwin();
}
