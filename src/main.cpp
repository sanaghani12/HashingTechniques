#include <iostream>
#include "LinearProbingHashing.cpp"
int main() {
    LinearProbingHashing hashtable(10);
    hashtable.VerticalProbing();
    int result = hashtable.VectorProbing(10);
    hashtable.Evaluation();
    hashtable.ScalarProbingInsert(10);
    std::cout << "result: "  << result << std::endl;
//    hashtable.HorizontalProbingInsert(4);
    return 0;
}
