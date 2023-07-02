//
// Created by SANA GHANI on 6/26/2023.
//
#include "AbstractHashTable.h"
#include <iostream>
#include <vector>

class LinearProbingHashing : public AbstractHashTable {
private:
    union Entry {
        int key;
    };

    std::vector<Entry> hashtable;
    int size;

public:
    LinearProbingHashing(int size) : size(size) {
        hashtable.resize(size); // Initialize all slots to 0 (indicating empty)
    }

    void ScalarProbingInsert(int key) override {
        int index = HashFunction(key);

        // Linear probing until an empty slot is found
        while (hashtable[index].key != 0) {
            if (hashtable[index].key == key) {
                std::cout << "Key " << key << " already exists." << std::endl;
                return;
            }
            index = (index + 1) % size; // Move to the next slot
        }

        // Insert the key into the empty slot
        hashtable[index].key = key;
        std::cout << "Key " << key << " inserted at index " << index << std::endl;
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

    bool ScalarProbingSearch(int key) {
        int index = HashFunction(key);

        // Perform linear probing to find the key
        while (hashtable[index].key != 0) {
            if (hashtable[index].key == key) {
                std::cout << "Key " << key << " found at index " << index << std::endl;
                return true; // Key found
            }
            index = (index + 1) % size; // Move to the next slot
        }
        std::cout << "Key " << key << " not found." << std::endl;
        return false; // Key not found
    }

    bool ScalarProbingRemove(int key) {
        int index = HashFunction(key);

        // Perform linear probing to find the key
        while (hashtable[index].key != 0) {
            if (hashtable[index].key == key) {
                hashtable[index].key = 0; // Mark the slot as empty
                std::cout << "Key " << key << " removed from index " << index << std::endl;
                return true; // Key removed
            }
            index = (index + 1) % size; // Move to the next slot
        }
        std::cout << "Key " << key << " not found for removal." << std::endl;
        return false; // Key not found
    }
private:
    int HashFunction(int key) {
        // Basic modulo hashing
        return key % size;
    }
};

