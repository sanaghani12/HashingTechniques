#include <iostream>
#include "LinearProbingHashing.cpp"
int main() {
    LinearProbingHashing hashtable(10);// 2 pow 20 1048576
//    hashtable.VerticalProbing();
//    int result = hashtable.VectorProbing(10);
    hashtable.Clear(); // Clear the hash table
    hashtable.Evaluation(10);
//    hashtable.ScalarProbingInsert(10);
//    std::cout << "result: "  << result << std::endl;
//    hashtable.HorizontalProbingInsert(4);
    return 0;
}
