Austin Kobayashi
42376153
L4L0B

When running main, it will prompt for an input on whether to run the tests with
a function called PrintTree. This is a helper function that can be found above the part
2 tests and it will simply print out the tree. The reason that this helper function was
added was to aid in tests that search through both left and right subtrees. In particular,
when searching through the right subtree, it is much easier to see what word we have to
search for when the tree is printed out. So if we are searching through the entire right subtree for sample1.txt, we would be searching for the largest value. For sample1.txt, that value is “writing”. So printing the tree allowed me to easily see what the largest and smallest values were in sample1.txt so I could structure my tests accordingly. I would recommend to no run with PrintTree when using very large text file (Eg, sample2.txt), as it will print out an extremely large tree, and the structure of the tree will be incorrect due to line overflow (Elements will be put on new lines since the tree is much larger than what can be displayed in terminal).

Some tests in part 1 required swapping with a specific child when calling remove_max. To ensure that this test swapped with the correct child, a new heap was made. I originally had a helper function in max_heap that would print out the heap so that the marker could see the new heaps; however, the function has been commented out since it included changes to max_heap.hpp. If you would like to see the tests run with the function, you must uncomment it in: max_heap.cpp, max_heap.hpp, and in the part 1 tests of main (there are many areas of the part1 tests that have the code commented out, so to make it easier to uncomment them, they are tagged with “!!!” so you can search for that). 

The tests in part 2 that tested searching down the left and right subtrees were structured to be run on sample1.txt

