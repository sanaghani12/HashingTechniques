#include <iostream>
#include "LinearProbingHashing.cpp"
int main() {
    LinearProbingHashing hashtable(10);
    hashtable.VerticalProbing();
    hashtable.VectorProbing();
    hashtable.Evaluation();
    hashtable.ScalarProbingInsert(10);
    return 0;
}
