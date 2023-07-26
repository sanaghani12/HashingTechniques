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
    int stepSize; // Step size for Horizontal Linear Probing


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


    int VectorProbing(int key) override {
        //Hash the key
        unsigned int foffset = HashFunction(key);
        __m128i mask0 = _mm_setzero_si128();
        __m128i tmp;
        register __m128i slot;
        register __m128i k;

        while(foffset<size){
            __m128i slot = _mm_set_epi32(keys.key[foffset + 3], keys.key[foffset + 2], keys.key[foffset + 1], keys.key[foffset]);
            k = _mm_set_epi32(key,key,key,key);

            //Compare the values in the registers and add to payload
            //Compare registers
            tmp = _mm_cmpeq_epi32(k,slot);
            if(_mm_movemask_epi8(tmp)){
                //Add to Payload
                payloads.vectorKeys[foffset] = _mm_sub_epi32( payloads.vectorKeys[foffset],tmp);
                return 1;
            }
            //Check if there are zeros
            __m128i zeroPos = _mm_cmpeq_epi32(mask0,slot);
            int resMove = _mm_movemask_epi8(zeroPos);
            if(resMove){

                // Insert values
                // Shift the values
                payloads.vectorKeys[foffset] = _mm_bslli_si128(payloads.vectorKeys[foffset], 4);
                keys.vectorKeys[foffset] = _mm_bslli_si128(keys.vectorKeys[foffset], 4);

                // Place the key in the first position
                int* valkey = (int*)&keys.vectorKeys[foffset];
                int* val = (int*)&payloads.vectorKeys[foffset];
                val[0] = 1;
                valkey[0] = key;
//                SIMDProbeEnd = clock();
//                SIMDTime = SIMDTime + ((long double)SIMDProbeEnd - (long double)SIMDProbeBegin);
                return 2;
            }

            foffset = (foffset++)%size;

        }
        return -1;
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

