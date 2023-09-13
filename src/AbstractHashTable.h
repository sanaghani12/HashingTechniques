//
// Created by SANA GHANI on 6/26/2023.
//

#ifndef HASHTABLEPROJECT_ABSTRACTHASHTABLE_H
#define HASHTABLEPROJECT_ABSTRACTHASHTABLE_H
class AbstractHashTable {
public:
    virtual void ScalarProbingInsert(int key) = 0;
    virtual int HorizontalVectorProbing(int key) = 0;
    virtual void VerticalProbing() = 0;
    virtual int HopScotchScalarProbe(unsigned int key, int H) = 0;
    virtual void Evaluation(int size) = 0;
    virtual void Clear() = 0;
};
#endif //HASHTABLEPROJECT_ABSTRACTHASHTABLE_H
