#include <iostream>
#include <array>

int A[10];

void fill_array(int first_value, int increment){
    for(int i = 0; i < 10; i++)
        ::A[i] = first_value + i * increment;
}


int main(void){
    
    int first_value;
    int increment;
    std::cout << "Enter First Value:" << std::endl;
    std::cin >> first_value;
    std::cout << "Enter Increment:" << std::endl;
    std::cin >> increment;
    std::cout << "-----------------" << std::endl;
    fill_array(first_value, increment);
    
    for(int i = 0; i < 10; i++)
        std::cout << ::A[i] << std::endl;
    
    return 0;
}
