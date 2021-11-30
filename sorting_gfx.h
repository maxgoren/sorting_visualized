#include <BearLibTerminal.h>
#include <vector>
#include <thread>
#include "sortbar.h"

void render(std::vector<Sort_Bar>& bars)
{
	terminal_clear();
	for (auto b = 0; b < bars.size(); b++)
	{
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