//
// Created by SANA GHANI on 6/26/2023.
//
#include "AbstractHashTable.h"
#include <iostream>
#include <vector>
#include <emmintrin.h>
#include <smmintrin.h>

class LinearProbingHashing : public AbstractHashTable {
private:
    union Entry {
        int* key;
        __m128i* vectorKeys;
    };

    Entry keys;
    Entry payloads;
    int size;

public:
    LinearProbingHashing(int size) : size(size) {
        keys.key = new int[size];
        payloads.vectorKeys = new __m128i[size/4]; //or new int[size] both keys and payloads should be of same size. Payloads is for keeping track of aggregation value in our case the count
    }

    void ScalarProbingInsert(int key) override {
        int index = HashFunction(key);

        for(int i=0; i<size; i++)
        {
//            std::cout << "hello2 " << keys.key[index];
            if(keys.key[index] == 0)
            {
                keys.key[index]= key;
                payloads.key[index] = 1;
                std::cout << "Key " << key << " inserted at index " << index << std::endl;
                return;
            }
            else if(keys.key[index] == key)
            {
              payloads.key[index]++;
              std::cout << "Key " << key << " already exists." << std::endl;
              return;
            }
            else {
                index = (index + 1) % size;
//                std::cout << "Key " << key << " hashed at index " << index << std::endl;
            }

        }
    }


    void VectorProbing() override {
        // Implementation of VectorProbing
        // ...
    }

    void VerticalProbing() override {
        // Implementation of VerticalProbing
        // ...
    }

    void Evaluation() override {
        // Implementation of Evaluation
        // ...
    }

private:
    int HashFunction(int key) {
        // Basic modulo hashing
        return 1300000077*key % size;
        //return ((unsigned long)((unsigned int)1300000077*key)* size)>>32;
    }
};

