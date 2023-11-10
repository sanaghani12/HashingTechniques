//
// Created by SANA GHANI on 6/26/2023.
//
#include "AbstractLinearProbing.h"
#include <iostream>
#include <vector>
#include <emmintrin.h>
#include <smmintrin.h>
#include <immintrin.h>
#include <cstdlib>
#include <algorithm>
#include <functional>

class LinearProbingHashing : public AbstractLinearProbing {
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
    void Clear() override{
        for (int i = 0; i < size; i++) {
            keys.key[i] = 0;
            payloads.key[i] = 0;
        }
    }
    void ScalarProbingInsert(int key) override {
        int index = HashFunction(key);
        int initialIndex = index; // Store the initial index

//        std::cout <<"index: "<<index <<"\n";
        for(int i=0; i<size; i++)
        {
//            std::cout << "hello2 " << keys.key[index];
            if(keys.key[index] == 0)
            {
                keys.key[index]= key;
                payloads.key[index] = 1;
//                std::cout << "Key " << key << " inserted at index " << index << std::endl;
                return;
            }
            else if(keys.key[index] == key)
            {
              payloads.key[index]++;
//              std::cout << "Key " << key << " already exists." << std::endl;
//                std::cout << " payload" <<  payloads.key[index] << std::endl;
              return;
            }
            else {
                index = (index + 1) % size;
//                std::cout << "Key " << key << " hashed at index " << index << std::endl;
                if (index == initialIndex) {
                    std::cout << "Table is full, cannot insert key " << key << std::endl;
                    return;
                }
            }

        }
    }

    int HorizontalVectorProbing(int key) override { //Vector probing is horizontal probing
        //Hash the key
        unsigned int foffset = HashFunction(key)/4;
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
                std::cout << "Key " << key << " added to Payload at index " << foffset << std::endl;

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
//                std::cout << "Key " << key << " inserted at index " << foffset << std::endl;

                return 2;
            }

            foffset = (foffset+1)%size;

        }
        return -1;
    }

    void LinearVerticalProbing() override {
        // Implementation of VerticalProbing
        // ...
    }

//    void Evaluation(int n) override {
//        // Implementation of Evaluation
////        int data[] = {1, 1, 1, 1, 1}; // Example data array, you can modify as needed
//        int *data= new int[n];     // Array to store the generated values
//
//        // Generate n random values and store them in the data array
//        std::generate_n(data, n, []() {
//            // Generate a random value and return it
//            int random = rand();
//            //std::cout<<random << " \n";
//            return random; // This generates a random integer, you can adjust as needed
//        });
//
//        for (int i = 0; i < n; i++) {
//            ScalarProbingInsert(data[i]);
//            HorizontalVectorProbing(data[i]);
//            HopScotchScalarProbe(data[i], 4);
//            HopScotchHorizontalProbe(data[i], 4);
//        }
//    }

private:
    unsigned int HashFunction(int key) {
        // Basic modulo hashing
//        std::cout<<"size in hashfunction: "<<size <<std::endl;
       return (unsigned int)1300000077* key % size; //using this
//        return ((unsigned long)((unsigned int)1300000077*key)* size)>>32;
//        std::hash<int> hasher;
//        return hasher(key) % size;
    }
//    unsigned int hash2(int key){
//        return 4*((13*key)%size);
//    }
};

