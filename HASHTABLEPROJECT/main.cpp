#include <iostream>
#include "LinearProbingHashing.cpp"
int main() {
    LinearProbingHashing hashtable(10);
    hashtable.VerticalProbing();
    hashtable.VectorProbing();
    hashtable.Evaluation();
    hashtable.ScalarProbingInsert(10);
    hashtable.ScalarProbingInsert(5);
    hashtable.ScalarProbingInsert(15);
    hashtable.ScalarProbingInsert(25);
    hashtable.ScalarProbingInsert(7);

    hashtable.ScalarProbingSearch(15);
    hashtable.ScalarProbingSearch(10);

    hashtable.ScalarProbingRemove(15);
    hashtable.ScalarProbingRemove(10);
    return 0;
}
