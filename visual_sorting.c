#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

int MAX_Y;
int MAX_X;

enum bar_state {
    SELECTED,
    SWAPPING,
    PLACED,
    UNPLACED
};

typedef struct sort_bar {
	int x;
	int y0, y1;
        int value;
	enum bar_state current_state;
} sort_bar;

sort_bar* new_bar(int x, int val)
{
   sort_bar *n = malloc(sizeof(sort_bar));
   n->x = x + 5;
   n->value = val;
   n->y0 = MAX_Y - 3;
   n->y1 = n->y0 - val;
   n->current_state = UNPLACED;
   return n;
}

void swap_bar(sort_bar* arr[], int x, int y)
{
  sort_bar *tmp = arr[x];
  arr[x] = arr[y];
  arr[y] = tmp;
}

int randVal(int min, int max)
{
  return (rand() % (max + 1 - min)) + min;
}

void draw_bar(sort_bar* curr, int x)
{
  int y;
  enum bar_state state = curr->current_state;
  switch (state)
  {
    case SWAPPING:
        attron(COLOR_PAIR(SWAPPING)); 
	break;
    case PLACED:
        attron(COLOR_PAIR(PLACED)); 
	break;
    case UNPLACED:
	attron(COLOR_PAIR(UNPLACED)); 
	break;
    case SELECTED:
	attron(COLOR_PAIR(SELECTED)); 
	break;
    default:
	attron(COLOR_PAIR(UNPLACED)); break;
  }
  for (y = curr->y0; y > curr->y1; y--)
  {
    mvaddch(y, x, '#');
  }
  attroff(COLOR_PAIR(state));
}

void draw_bars(sort_bar* bars[], int n)
{
  clear();
  for (int i = 0; i < n; i++)
  {
    draw_bar(bars[i], i);
  }
  refresh();
  usleep(100000);
}

void selsort(sort_bar* bars[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int min = i;
    bars[i]->current_state = SELECTED;
    for (int j = i; j < n; j++)
    {
      bars[j]->current_state = SELECTED;
      if (bars[j]->value < bars[min]->value)
      {
         bars[min]->current_state = UNPLACED;
	 min = j;
         draw_bars(bars, n);
      }
    }
    if (min != i) {
       bars[min]->current_state = SWAPPING;
       bars[i]->current_state = SWAPPING;
       draw_bars(bars, n);
       usleep(500000);
       swap_bar(bars, min, i);
       draw_bars(bars, n);
       usleep(500000);
       bars[min]->current_state = UNPLACED;
    }
    bars[i]->current_state = PLACED;
  }
}

void setup()
{
  initscr();
  start_color();
  init_pair(SWAPPING, COLOR_RED, COLOR_BLACK);
  init_pair(SELECTED, COLOR_CYAN, COLOR_BLACK);
  init_pair(PLACED, COLOR_GREEN, COLOR_BLACK);
  init_pair(UNPLACED, COLOR_WHITE, COLOR_BLACK);
  cbreak();
  noecho();
  clear();
  getmaxyx(stdscr, MAX_Y, MAX_X);
}

int main()
{
   setup();
   refresh();
   int n = MAX_X-5;
   sort_bar* bars[n];
   for (int i = 1; i <= n; i++)
   {
     bars[i-1] = new_bar(i, randVal(2, 20));
   }
   draw_bars(bars, n);
   getch();
   selsort(bars, n);
   getch();
   endwin();
   return 0;
}
