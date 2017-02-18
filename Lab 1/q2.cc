#include <iostream>
#include <string>
#include <fstream>

int main(void) {
    
    std::ifstream in("infile.txt");       // input file-stream
    std::ofstream out("outfile.txt");     // output file-stream 
    std::string ss;
    
    // getline() puts next line in ss and discards any newline characters
    while (getline(in, ss))   
        out << ss << std::endl; // add each line to the new file, appending endl 
    
    std::cout << "End of program" << std::endl;
    return 0;
}
