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