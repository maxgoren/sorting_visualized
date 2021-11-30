# Visualizing Sorting in C++

This is an example for visualizing the process of sorting algorithms.
Each arrat member is represented by a bar thats height is indicative of
its value. The bar currently being evaluated is colored red, all others
are displayed as white. each time a swap takes place, the bars are re-rendered
to show there re-ordering (sorting!).

So far i have only implemented selection sort as a proof of concept, as
its rather simple to code, but insertion sort, bubble sort, shell sort,
quick sort, and mergesort(yikes!) are soon to come.

## Other Librares
This program is dependent upon BearLibTerminal for visual rendering.
BearLibTerminal is MIT license compliant. And for this reason combined
with its ease of use is why i choose this method for visualizing sorting.
