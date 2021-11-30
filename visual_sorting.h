#include "sorting_gfx.h"
#include <vector>

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

void insertion_sort(std::vector<Sort_Bar>& bars)
{
  int i, j, k;
  for (int i = 1; i < bars.size(); i++)
  {
    int j = i;
    auto v = bars[i];
    bars[j].being_sorted = true;
    render(bars);
    while (bars[j-1].val > v.val && j > 0)
    {
      bars[j].being_sorted = false;
      bars[j+1].being_sorted = true;
      bars[j] = bars[j-1];
      bars[j].being_sorted = true;
      bars[j+1].being_sorted = false;
      j--;
      render(bars);
    }
    bars[j].being_sorted = false;
    bars[j] = v;
    render(bars);
  }
}

void bubble_sort(std::vector<Sort_Bar>& bars)
{
  for (int i = bars.size()-1; i > 0; i--)
  {
    for (int j = 0; j < i; j++)
    {
      bars[j+1].being_sorted = true;
      bars[j].being_sorted = true;
      render(bars);
      if (bars[j+1].val < bars[j].val)
        swap(bars, j, j+1);
      bars[j].being_sorted = false;
      bars[j+1].being_sorted = false;
      render(bars);
    }
  }
}