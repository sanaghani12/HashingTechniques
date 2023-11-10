//
// Created by SANA GHANI on 10/20/2023.
//

#ifndef HASHTABLEPROJECT_ABSTRACTHOPSCOTCHPROBING_H
#define HASHTABLEPROJECT_ABSTRACTHOPSCOTCHPROBING_H
class AbstractHopscotchProbing {
public:
    virtual int HopScotchScalarProbe(unsigned int key, int H) = 0;
    virtual int HopScotchHorizontalProbe(unsigned int key, int H) = 0;
    virtual void Clear() = 0;
};
#endif //HASHTABLEPROJECT_ABSTRACTHOPSCOTCHPROBING_H
