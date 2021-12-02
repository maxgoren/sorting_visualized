# Visualizing Sorting in C++

This is an example for visualizing the process of sorting algorithms.
Each arrat member is represented by a bar thats height is indicative of
its value. The bar currently being evaluated is colored red, all others
are displayed as white. each time a swap takes place, the bars are re-rendered
to show there re-ordering (sorting!).

Sorts implemented: insertion, selection, bubble

## Other Librares
This program is dependent upon BearLibTerminal for visual rendering.
BearLibTerminal is MIT license compliant. And for this reason combined
with its ease of use is why i choose this method for visualizing sorting.

# a new fork!
I've created a branch 'NCURSES-C' where i've rewritten the code to use the 
ncurses library and implemented the functions in C. This isnt really a fork
as the code base is 100% rewritten, but the project is the same so i've
decided to include it here. I decided to write this version as it will be
able to compile on most modern POSIX systems without the need to install the 
BearLibTerminal library required by the C++ version.

sorts implemented: selection
