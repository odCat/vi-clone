#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

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

    if (NCURSES_MOUSE_VERSION > 0)
    {
        mousemask(BUTTON1_CLICKED, NULL);
    }

    int y, x;
    WINDOW *edit = newwin(LINES - 3, COLS, 0, 0);
    keypad(edit, TRUE);
    waddstr(edit, text);
    wmove(edit, 0, 0);
    getyx(edit, y, x);
    wrefresh(edit);

    WINDOW *status = newwin(1, COLS, LINES - 2, 0);
    wbkgd(status, COLOR_PAIR(1));

    mvwprintw(status, 0, 0, "%d,%d", y, x);
    wrefresh(status);
    wrefresh(edit);

    WINDOW *command = newwin(1, COLS, LINES - 1, 0);

    int ch;
    MEVENT mouse_event;
    while ((ch = wgetch(edit)))
    {
        switch (ch)
        {
            case KEY_LEFT:
            case 'h':
                wmove(edit, y, x - 1);
                break;
            case KEY_DOWN:
            case 'j':
                wmove(edit, y + 1, x);
                break;
            case KEY_UP:
            case 'k':
                wmove(edit, y - 1, x);
                break;
            case KEY_RIGHT:
            case 'l':
                wmove(edit, y, x + 1);
                break;
            case 'i':
                while ((ch = wgetch(edit)) != 27)
                {
                    if (ch == 127)
                    {
                        wmove(edit, y, --x);
                        wdelch(edit);
                    } else {
                        winsch(edit, ch);
                        wmove(edit, y, ++x);
                        wrefresh(edit);
                    }
                }
                break;
            case ':':
                char cmd[32];
                echo();
                mvwaddstr(command, 0, 0, ":");
                wgetnstr(command, cmd, 32);
                if (strcmp(cmd, "q") == 0)
                {
                    endwin();
                    exit(0);
                }
                wmove(command, 0, 0);
                wclrtoeol(command);
                wrefresh(command);
                noecho();
                break;
            case KEY_MOUSE:
                getmouse(&mouse_event);
                wmove(edit, mouse_event.y, mouse_event.x);
                break;
            default:
                break;

        }
        getyx(edit, y, x);
        mvwprintw(status, 0, 0, "%d,%d", y, x);
        wrefresh(status);
        wrefresh(edit);
    }

    endwin();
}
