//
// Created by SANA GHANI on 6/26/2023.
//

#ifndef HASHTABLEPROJECT_ABSTRACTHASHTABLE_H
#define HASHTABLEPROJECT_ABSTRACTHASHTABLE_H
class AbstractHashTable {
public:
    virtual void ScalarProbingInsert(int key) = 0;
    virtual void VectorProbing() = 0;
    virtual void VerticalProbing() = 0;
    virtual void Evaluation() = 0;
};
#endif //HASHTABLEPROJECT_ABSTRACTHASHTABLE_H
