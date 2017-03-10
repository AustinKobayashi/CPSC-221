#include <iostream>

#include "string_bst.hpp"
#include "max_heap.hpp"
#include "text_item.hpp"
#include "util.hpp"

using namespace std;

bool runWithTrees = false;

//--- PART 1A: Implementation and testing of heap insert
void heap_insert_tests(max_heap &hp) {
	text_item temp;
	std::string word = "item";
	int random_num;
	long int seed = long(time(0));    // seed for random number generator
	srand(seed);
	
	//--- Testing insert functionality
	std::cout << "*** TESTING INSERT ***" << std::endl;
	//--- This adds 5 items to the heap with random numbers
	//    and prints out the top, but it does not fully 
	//    test the correctness of the insert function.
	for (int i = 0 ; i < 5; i++) {
		random_num = rand() % 100;
		string text = word;
		text += std::to_string(i+1);
		std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
		hp.insert(text_item{text, random_num});	
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;		
	}
	/* !!!
    cout << "\n Heap:" << endl;
    hp.printHeap(0, 0);
     */

	//--- Specific insert functionality that should be tested:
	
	// insert without any swap_ups needed
    std::cout << "\n" << "*** TESTING INSERT NO SWAP_UPS ***" << std::endl;
	int freq = 0;
	string text = word;
	text += std::to_string(5 + 1);
	std::cout << "adding " << text << ",  with number " << freq << " to heap" << std::endl;
	hp.insert(text_item{ text, freq });
	temp = hp.top();
	std::cout << "Top of heap is: " << temp << std::endl;
    /* !!!
    cout << "\n Heap:" << endl;
    hp.printHeap(0, 0);
    */
    
    
    // insert with a swap_up / multiple swap_ups
    std::cout << "\n" << "*** TESTING INSERT WITH SOME SWAP_UPS ***" << std::endl;
    freq = hp.top().freq - 1;
    text = word;
    text += std::to_string(6 + 1);
    std::cout << "adding " << text << ",  with number " << freq << " to heap" << std::endl;
    hp.insert(text_item{ text, freq });
    temp = hp.top();
    std::cout << "Top of heap is: " << temp << std::endl;
    /* !!!
    cout << "\n Heap:" << endl;
    hp.printHeap(0, 0);
    */
    
    
	// insert with a swap_up / multiple swap_ups
    std::cout << "\n" << "*** TESTING INSERT WITH FULL SWAP_UPS ***" << std::endl;
    freq = hp.top().freq + 1;
    text = word;
    text += std::to_string(7 + 1);
    std::cout << "adding " << text << ",  with number " << freq << " to heap" << std::endl;
    hp.insert(text_item{ text, freq });
    temp = hp.top();
    std::cout << "Top of heap is: " << temp << std::endl;
    /* !!!
    cout << "\n Heap:" << endl;
    hp.printHeap(0, 0);
     */
}


//--- PART 1B: Implementation and testing of heap delete
void heap_delete_tests(max_heap &hp) {
	text_item temp;
    std::string word = "item";

	//--- Testing deleteMax functionality
	std::cout << "*** TESTING DELETEMAX ***" << std::endl;
    /* !!!
    cout << "\n" << "Heap Before Deleting:" << endl;
    hp.printHeap(0, 0);
    cout << "\n" << endl;
    */
    
	//--- This does not fully test delete_max functionality.
	if (hp.size() > 1) {
		temp = hp.delete_max();
		std::cout << "Item returned from heap delete: "<< temp << std::endl;
		temp = hp.top();
		std::cout << "Top of heap is now: " << temp << std::endl;	
	}
	
    /* !!!
    cout << "\n Heap:" << endl;
    hp.printHeap(0, 0);
    */
    
    //remake the heap so left child is guaranteed to be larger
    //than right child
    cout << "REMAKING HEAP" << endl;
    while(hp.size())
        hp.delete_max();
        
    for (int i = 3 ; i >= 0; i--) {
        string text = word;
        hp.insert(text_item{text, i * 2});	
        std::cout << "adding " << text << ",  with number " << i * 2 << " to heap" << std::endl;

    }
   
    /* !!!
    cout << "New heap:" << "\n" << endl;
    hp.printHeap(0, 0);
    */
    
    
	//--- Specific insert functionality that should be tested:
	// remove_max works when swap_down with left child
    std::cout << "*** TESTING SWAP_DOWN WITH LEFT CHILD ***" << std::endl;
    temp = hp.delete_max();
    std::cout << "Item returned from heap delete: " << temp << std::endl;
    /* !!!
    cout << "\n Heap:" << endl;
    hp.printHeap(0, 0);
	*/	
    
    
    //add more elements so right child is guaranteed to be larger
    //than left child
    cout << "\nADDING MORE ITEMS TO HEAP" << endl;
    for(int i = 1; i < 4; i++){
        string text = word;
        hp.insert(text_item{text, i});	
        std::cout << "adding " << text << ",  with number " << i << " to heap" << std::endl;

    }
    
    /* !!!
    cout << "New heap:" << "\n" << endl;
    hp.printHeap(0, 0);
    */
    
	// remove_max workd when swap_down with right child
    std::cout << "*** TESTING SWAP_DOWN WITH RIGHT CHILD ***" << std::endl;
    temp = hp.delete_max();
    std::cout << "Item returned from heap delete: " << temp << std::endl;
    /* !!!
    cout << "\n Heap:" << endl;
    hp.printHeap(0, 0);
    */
    
    
    //clear heap
    cout << "CLEARING HEAP" << endl;
    while(hp.size())
        hp.delete_max();
    
	// remove_max on an empty heap (should throw exception similar to top())
    try {
        temp = hp.delete_max(); //should throw and exception without items in heap
        std::cout << "Top of heap is: " << temp << std::endl;	
    } catch (std::logic_error e) {
        std::cout << e.what() << std::endl;
    }
}


// Helper function that will print the string_bst
void PrintTree(string_bst::node_t *root, int size, int d=0) {
    
    if(root == NULL)
        return;
    
    //print right child
    PrintTree(root->right, size, d+1);
    
    //print spacing
    for(int i = 0; i < 15 * d; i++)
        cout << " ";
    
    //print value
    cout << root->data << "\n" << endl;
    
    //print left child
    PrintTree(root->left, size, d+1);
}



//--- PART 2: Implementation and testing of BST word_frequency
void tree_tester(string_bst const &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 2" << std::endl;
	
	//--- Testing word_frequency functionality
	//--- This does not fully test word_frequency functionality.
	if (tree.size() > 1) {
		string to_find = "difficult";
		int num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;
	}
	
    if(runWithTrees)
        PrintTree (tree.get_root(), tree.size());
	//--- Specific word_frequency functionality that should be tested:
	
	// can search through both left and right subtrees if not found at current node
    
    //for sample1.txt, the smallest word is "a", searching for it will result in
    //searching down the entire left sub tree
    std::cout << std::endl << "SEARCHING ALL THE WAY DOWN LEFT SUBTREE" << std::endl;
    cout << "*** note: this test was structured to run on 'sample1.txt' ***" << endl;
    if (tree.size() > 1) {
        string to_find = "a";
        int num_times = tree.word_frequency(to_find);
        std::cout << "Found: "<< to_find << 
        " in the input file " << num_times 
        << " time(s)." << std::endl;
    }
    
    //for sample1.txt, the largest word is "writing", searching for it will result in
    //searching down the entire right sub tree
    std::cout << std::endl << "SEARCHING ALL THE WAY DOWN RIGHT SUBTREE" << std::endl;
    cout << "*** note: this test was structured to run on 'sample1.txt' ***" << endl;
    if (tree.size() > 1) {
        string to_find = "writing";
        int num_times = tree.word_frequency(to_find);
        std::cout << "Found: "<< to_find << 
        " in the input file " << num_times 
        << " time(s)." << std::endl;
    }
    
	// returns 0 if word is not found
    std::cout << std::endl << "SEARCHING FOR NON-EXISTING WORD" << std::endl;
    if (tree.size() > 1) {
        string to_find = "ThisIsANullWord";
        int num_times = tree.word_frequency(to_find);
        std::cout << "Found: "<< to_find << 
        " in the input file " << num_times 
        << " time(s)." << std::endl;
    }			
}






//--- PART 3: Implementation and testing of word frequency analysis
void overall_most_freq(max_heap hp) {
	std::cout << "*** Top 5 most frequent words: ***" << std::endl;
	
	//--- Add your code to print out the 5 most frequent words below:
	if (hp.size() > 1) {

        int size = hp.size();
        for(int i = 0; i < size && i < 5; i++)
            std::cout << "Most frequent text item: " << hp.delete_max() << std::endl;
        
	}
}



void at_least_length(max_heap hp, size_t num_letters) {
	cout << "*** Top 5 most frequent words with at least " 
		<< num_letters << " letters ***" << std::endl;
		
	//--- Add code to print out the 5 most common
	//--- words of length at least <num_letters>
    
    /* To make marking a bit easier I'll describe what this function does:
     * 1) Adds all items in hp to an array called fullHeap
     * 2) Adds all the items longer than num_letters to an array called longest
     * 3) Adds the words with the highest frequency from longest to topFive
     * 4) Prints out topFive (which may contain less than 5 elements)
     */
    
    int size = hp.size();
    int numWordsLonger = 0;
    text_item *fullHeap = new text_item[size];
      
    //add all elements to fullHeap
    for(int i = 0; i < size; i++){
        text_item temp = hp.delete_max();
        fullHeap[i] = temp;
        
        if(temp.word.length() >= num_letters)
            numWordsLonger++;
    }
        
    //add all elements longer than num_letters to longest
    text_item *longest = new text_item[numWordsLonger];
    int pos = 0;
    for(int i = 0; i < size; i++){
        
        if(fullHeap[i].word.length() >= num_letters){
            longest[pos] = fullHeap[i];
            pos++;
        }
    }
    
    //Initialize topFive with empty text_items
    text_item empty;
    empty.word = "";
    empty.freq = 0;
    text_item topFive[5] {empty, empty, empty, empty, empty};
    int added = 0;
    
    //add the most frequent words to topFive
    for(int i = 0; i < numWordsLonger; i++){
        int freq = longest[i].freq;
        
        if(freq > topFive[0].freq){
            topFive[0] = longest[i];
            added++;
        }else if(freq > topFive[1].freq){
            topFive[1] = longest[i];
            added++;
        }else if(freq > topFive[2].freq){
            topFive[2] = longest[i];
            added++;
        }else if(freq > topFive[3].freq){
            topFive[3] = longest[i];
            added++;
        }else if(freq > topFive[4].freq){
            topFive[4] = longest[i];
            added++;
        }
    }

    //print out the results
    for(int i = 0; i < added && i < 5; i ++)
        cout << topFive[i] << endl;
}




void starts_with(max_heap hp, char starts_with_letter) {
	cout << "*** Top 5 most frequent words that begin with " 
		<< starts_with_letter << " ***" << std::endl;
		
	//--- Add code to print out the 5 most common words
	//--- that start with the letter <starts_with_letter>
    
    /* To make marking a bit easier I'll describe what this function does:
     * 1) Adds all items in hp to an array called fullHeap
     * 2) Adds all the items that start with starts_with_letter to an array called withLetter
     * 3) Adds the words with the highest frequency from withLetter to topFive
     * 4) Prints out topFive (which may contain less than 5 elements)
     */
    
    int size = hp.size();
    int numWordsWithLetter = 0;
    text_item *fullHeap = new text_item[size];
    
    //add all elements to fullHeap
    for(int i = 0; i < size; i++){
        text_item temp = hp.delete_max();
        fullHeap[i] = temp;
        
        if(temp.word.at(0) == starts_with_letter)
            numWordsWithLetter++;
    }
    
    //add all elements that start with starts_with_letter to withLetter
    text_item *withLetter = new text_item[numWordsWithLetter];
    int pos = 0;
    for(int i = 0; i < size; i++){
        
        if(fullHeap[i].word.at(0) == starts_with_letter){
            withLetter[pos] = fullHeap[i];
            pos++;
        }
    }
    
    //Initialize topFive with empty text_items
    text_item empty;
    empty.word = "";
    empty.freq = 0;
    text_item topFive[5] {empty, empty, empty, empty, empty};
    int added = 0;
    
    
    //add the most frequent words to topFive
    for(int i = 0; i < numWordsWithLetter; i++){
        int freq = withLetter[i].freq;
        
        if(freq > topFive[0].freq){
            topFive[0] = withLetter[i];
            added++;
        }else if(freq > topFive[1].freq){
            topFive[1] = withLetter[i];
            added++;
        }else if(freq > topFive[2].freq){
            topFive[2] = withLetter[i];
            added++;
        }else if(freq > topFive[3].freq){
            topFive[3] = withLetter[i];
            added++;
        }else if(freq > topFive[4].freq){
            topFive[4] = withLetter[i];
            added++;
        }
    }
    
    //print out the results
    for(int i = 0; i < added && i < 5; i ++)
        cout << topFive[i] << endl;
}




void heap_tester() {	
	text_item temp;
	int heap_size = 10; //feel free to create heaps of other sizes when testing
	//cout << "How many items should be added to heap? ";
	//cin >> heap_size;
	max_heap hp(heap_size);
	std::cout << "Created heap of size " << heap_size << std::endl;
		
	//--- Testing heap size and top
	std::cout << "Current number of items in heap is: " << hp.size() << std::endl;
	try {
		temp = hp.top(); //should throw and exception without items in heap
		std::cout << "Top of heap is: " << temp << std::endl;	
	} catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}
	// PART 1A:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1A" << std::endl;
	heap_insert_tests(hp);
	// PART 1B:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1B" << std::endl;
	heap_delete_tests(hp);
}

void text_analysis_tester(string_bst &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 3" << std::endl;
	overall_most_freq(copy_to_heap(tree));
	std::cout << std::endl;
	at_least_length(copy_to_heap(tree), 6); // change the 8 to test other string-lengths
	std::cout << std::endl;
	starts_with(copy_to_heap(tree), 'c'); // change the 'c' to test words that starts_with_letter
											// with different characters
}

int main(int argc, char* argv[]) {
	
    cout << "\n" << "Would you like to run part 2 tests with PrintTree?" << "\n" <<
    "This will print out the entire tree (similar to lab4)" << "\n" <<
    "Would recommend 'n' for very large test texts files (eg. 'sample2.txt)'" << "\n" <<
    "(The functionality will not work correctly with large amounts of text)" << "\n" <<
    "(y/n)?" << endl;
     
    string input;
    cin >> input;
    
    if(input == "y")
        runWithTrees = true;
    else
        runWithTrees = false;
    
	//--- Part 1: max_heap implementation
	heap_tester(); 
	
	//--- Part 2: string_bst implementation
	string_bst tree;
	load_bst("sample2.txt", tree); // create a bst from an input file.
	tree_tester(tree);			//sample2.txt contains a much bigger file
	
	//--- Part 3: word frequency analysis of text files
	text_analysis_tester(tree);

}
