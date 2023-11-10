//
// Created by SANA GHANI on 09/10/2023.
//

#ifndef HASHTABLEPROJECT_ABSTRACTLINEARPROBING_H
#define HASHTABLEPROJECT_ABSTRACTLINEARPROBING_H
class AbstractLinearProbing {
public:
    virtual void ScalarProbingInsert(int key) = 0;
    virtual int HorizontalVectorProbing(int key) = 0;
    virtual void LinearVerticalProbing() = 0;
    virtual void Clear() = 0;
};
#endif //HASHTABLEPROJECT_ABSTRACTLINEARPROBING_H
