#include <iostream>
#include <vector>
#include <BearLibTerminal.h>
#include <random>
#include <thread>
#include "visual_sorting.h"
using namespace std;


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
	insertion_sort(bars);
	while(true) 
	{
	 render(bars);
	}
	return 0;
}
