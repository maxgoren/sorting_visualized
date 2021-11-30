#include <iostream>
#include <vector>
#include <BearLibTerminal.h>
#include <random>
#include <thread>
using namespace std;

struct Sort_Bar {
	int val;
	int x;
	int y0, y1;
	bool being_sorted;
	Sort_Bar(int v, int X)
	{
		val = v;
		x = X;
		y0 = 19;
		y1 = y0 - v;
		being_sorted = false;
	}
};

void render(std::vector<Sort_Bar>& b);
void swap(std::vector<Sort_Bar>& bars, int i, int j)
{
        auto tmp = bars[i];
        bars[i] = bars[j];
        bars[j] = tmp;
}


void selection_sort(std::vector<Sort_Bar>& bar)
{
   int min_pos = 0;
   for (int i = 0; i < bar.size(); i++)
   {
     min_pos = i;
     bar[min_pos].being_sorted = true;
     render(bar);
     for (int j = i; j < bar.size(); j++)
     {
     	if (bar[j].val < bar[min_pos].val)
     	{
     	  bar[min_pos].being_sorted = false;
     	  min_pos = j;
     	  bar[min_pos].being_sorted = true;
     	  render(bar);
     	}
     }
     swap(bar, i, min_pos);
     render(bar);
     bar[min_pos].being_sorted = false;
     bar[i].being_sorted = false;
   }
}

void render(std::vector<Sort_Bar>& bars)
{
	terminal_clear();
	for (auto b = 0; b < bars.size(); b++)
	{
//	  cout<<b.x<<" "<<b.y0<<" "<<b.val<<"\n";
	  for (int y = bars[b].y1; y < bars[b].y0; y++)
	  {
	        if (bars[b].being_sorted)
	           terminal_color(color_from_name("red"));
	        else
	           terminal_color(color_from_name("white"));
	  	terminal_put(b, y, '#');
	  }
	}
	terminal_refresh();
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1,19);
	std::vector<Sort_Bar> bars;
	for (int i = 0; i < 40; i++)
	{
		bars.push_back(Sort_Bar(dist(gen), i+2));
	}
	terminal_open();
	terminal_set("window: size=40x20;");
	terminal_refresh();
	selection_sort(bars);
	while(true) 
	{
	 render(bars);
	}
	return 0;
}
