//
// Created by SANA GHANI on 10/20/2023.
//

// Constructor
//
// Created by SANA GHANI on 6/26/2023.
//
#include "AbstractHopscotchProbing.h"
#include <iostream>
#include <vector>
#include <emmintrin.h>
#include <smmintrin.h>
#include <immintrin.h>
#include <cstdlib>
#include <algorithm>
#include <functional>

class HopscotchHashing : public AbstractHopscotchProbing {
private:
    union Entry {
        int* key;
        __m128i* vectorKeys;
    };

    Entry keys;
    Entry payloads;
    int size;


public:
    HopscotchHashing(int size) : size(size) {
        keys.key = new int[size];
        payloads.vectorKeys = new __m128i[size/4]; //or new int[size] both keys and payloads should be of same size. Payloads is for keeping track of aggregation value in our case the count

    }
    void Clear() override{
        for (int i = 0; i < size; i++) {
            keys.key[i] = 0;
            payloads.key[i] = 0;
        }
    }

    int HopScotchScalarProbe(unsigned int key, int H) { // Scalar hopscotch probing

        unsigned int foffset = HashFunction(key);
        unsigned int i;
        //check if the key is present within its neighborhood
        for (i = foffset; i < size; i++) {
            int *valkey = (int*)&keys.key[i];
            int *val = (int*)&payloads.key[i];

            if (i < (foffset + H)) {
                for (int j = 0; j < 4; j++) {
                    if (valkey[j] == key) {
                        val[j] += 1;
//                        std::cout << "Key " << key << " found at index " << i << ", slot " << j << " with value " << val[j] << std::endl;
                        return 1;
                    } else if (valkey[j] == 0) {
                        val[j] = 1;
                        valkey[j] = key;
//                        std::cout << "Key " << key << " inserted at index " << i << ", slot " << j << " with value " << val[j] << std::endl;
                        return 1;
                    }
                }
            }
            if ((valkey[0] == 0)) { // to send the exact bucket and slot of the empty location to the insert function
//                std::cout << "Key " << key << " can be inserted at index " << i << ", slot 0" << std::endl;
                return i * 4;
            }
            if ((valkey[1] == 0)) {
//                std::cout << "Key " << key << " can be inserted at index " << i << ", slot 1" << std::endl;
                return (i * 4) + 1;
            }
            if ((valkey[2] == 0)) {
//                std::cout << "Key " << key << " can be inserted at index " << i << ", slot 2" << std::endl;
                return (i * 4) + 2;
            }
            if ((valkey[3] == 0)) {
//                std::cout << "Key " << key << " can be inserted at index " << i << ", slot 3" << std::endl;
                return (i * 4) + 3;
            }
        }
        std::cout << "Key " << key << " could not be inserted." << std::endl;
        return 0;
    }

    int HopScotchHorizontalProbe(unsigned int key, int H) { //SIMDProbe
        unsigned int foffset = HashFunction(key)/4;

        __m128i mask0 = _mm_setzero_si128();
        __m128i tmp;
        register __m128i slot;
        register __m128i k;

        k = _mm_set_epi32(key,key,key,key);

        for (int i = foffset; i < size; i++) {

            slot = _mm_set_epi32(keys.key[i + 3], keys.key[i + 2], keys.key[i + 1], keys.key[i]);

            if (i < (foffset + H)) {

                k = _mm_set_epi32(key, key, key, key);
                tmp = _mm_cmpeq_epi32(k, slot);

                if (_mm_movemask_epi8(tmp)) {

                    payloads.vectorKeys[i] = _mm_sub_epi32(payloads.vectorKeys[i], tmp);
                    std::cout << "Key " << key << " found at index " << i << ", slot " << (i - foffset) << " with value " << payloads.vectorKeys[i][0] << std::endl;
                    return 1;
                }

                __m128i zeroPos = _mm_cmpeq_epi32(mask0, slot);
                int resMove = _mm_movemask_epi8(zeroPos);

                if (resMove) {

                    payloads.vectorKeys[i] = _mm_bslli_si128(payloads.vectorKeys[i], 4);
                    keys.vectorKeys[i] = _mm_bslli_si128(keys.vectorKeys[i], 4);

                    int* valkey = (int*)&keys.vectorKeys[i];
                    int* val = (int*)&payloads.vectorKeys[i];

                    val[0] = 1;
                    valkey[0] = key;

//                    std::cout << "Key " << key << " inserted at index " << i << ", slot " << (i - foffset) << " with value " << payloads.vectorKeys[i][0] << std::endl;
                    return 0;
                }
            } else {

                __m128i zeroPos = _mm_cmpeq_epi32(mask0, slot);
                int* pt = (int*)&zeroPos;
                int resMove = _mm_movemask_epi8(zeroPos);

                if (resMove) {
                    if (pt[0] == -1) {
//                        std::cout << "Key " << key << " can be inserted at index " << i << ", slot 0" << std::endl;
                        return i * 4;
                    }
                    if (pt[1] == -1) {
//                        std::cout << "Key " << key << " can be inserted at index " << i << ", slot 1" << std::endl;
                        return (i * 4) + 1;
                    }
                    if (pt[2] == -1) {
//                        std::cout << "Key " << key << " can be inserted at index " << i << ", slot 2" << std::endl;
                        return (i * 4) + 2;
                    }
                    if (pt[3] == -1) {
//                        std::cout << "Key " << key << " can be inserted at index " << i << ", slot 3" << std::endl;
                        return (i * 4) + 3;
                    }
                }
            }
        }

        std::cout << "Key " << key << " could not be inserted." << std::endl;
        return 0;
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

};

