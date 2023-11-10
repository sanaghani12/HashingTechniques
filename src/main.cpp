
#include <iostream>
#include "LinearProbingHashing.cpp"
#include "HopscotchHashing.cpp"
#include "distribution.h"
#include <chrono>  // Include the chrono library for timing

int main() {
    for (int dataSize = 100000; dataSize <= 300000; dataSize += 40000) {
        auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();;
        LinearProbingHashing hashtable1(dataSize); // Initialize with a size of 10
        HopscotchHashing hashtable2(dataSize);
        setGen(dataSize);

//  ----------------------DenseUniqueRandom--------------------------

        // Test HopScotchHorizontalProbe
        InitDenseUnique();
            start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HopScotchHorizontalProbe DenseUniqueRandom:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = DenseUniqueRandom();
            hashtable2.HopScotchHorizontalProbe(key, 4);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HopScotchHorizontalProbe DenseUniqueRandom: " << duration << " milliseconds " <<"dataSize "<<dataSize
        << std::endl;
        hashtable2.Clear();

        // Test HopScotchScalarProbe
        InitDenseUnique();
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HopScotchScalarProbe DenseUniqueRandom:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = DenseUniqueRandom();
            hashtable2.HopScotchScalarProbe(key, 4);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HopScotchScalarProbe DenseUniqueRandom:  " << duration << " milliseconds " <<"dataSize "<<dataSize << std::endl;
        hashtable2.Clear();

        //Test HorizontalVectorProbing
        InitDenseUnique();
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HorizontalVectorProbing DenseUniqueRandom:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = DenseUniqueRandom();
            int result = hashtable1.HorizontalVectorProbing(key);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HorizontalVectorProbing DenseUniqueRandom: " << duration << " milliseconds " <<"dataSize "<<dataSize
                  << std::endl;
        hashtable1.Clear();

        //Test ScalarProbingInsert
        InitDenseUnique();
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing ScalarProbingInsert DenseUniqueRandom:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = DenseUniqueRandom();
            hashtable1.ScalarProbingInsert(key);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken ScalarProbingInsert DenseUniqueRandom: " << duration << " milliseconds " <<"dataSize "<<dataSize << std::endl;
        hashtable1.Clear();


//  ----------------------UniformRandom--------------------------

        // Test HopScotchHorizontalProbe
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HopScotchHorizontalProbe UniformRandom:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = UniformRandom();
            hashtable2.HopScotchHorizontalProbe(key, 4);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HopScotchHorizontalProbe UniformRandom : " << duration << " milliseconds " <<"dataSize "<<dataSize << std::endl;
        hashtable2.Clear();

        // Test HopScotchScalarProbe
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HopScotchScalarProbe UniformRandom:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = UniformRandom();
            hashtable2.HopScotchScalarProbe(key, 4);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HopScotchScalarProbe UniformRandom:  " << duration << " milliseconds " <<"dataSize "<<dataSize << std::endl;
        hashtable2.Clear();

        //Test HorizontalVectorProbing
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HorizontalVectorProbing UniformRandom:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = UniformRandom();
            int result = hashtable1.HorizontalVectorProbing(key);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HorizontalVectorProbing UniformRandom: " << duration << " milliseconds " <<"dataSize "<<dataSize << std::endl;
        hashtable1.Clear();

        //Test ScalarProbingInsert
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing ScalarProbingInsert UniformRandom:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = UniformRandom();
            hashtable1.ScalarProbingInsert(key);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken ScalarProbingInsert UniformRandom: " << duration << " milliseconds " <<"dataSize "<<dataSize << std::endl;
        hashtable1.Clear();

//  ----------------------Exponential--------------------------

        // Test HopScotchHorizontalProbe
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HopScotchHorizontalProbe Exponential:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = Exponential();
            hashtable2.HopScotchHorizontalProbe(key, 4);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HopScotchHorizontalProbe Exponential : " << duration << " milliseconds " <<"dataSize "<<dataSize << std::endl;
        hashtable2.Clear();

        // Test HopScotchScalarProbe
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HopScotchScalarProbe Exponential:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = Exponential();
            hashtable2.HopScotchScalarProbe(key, 4);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HopScotchScalarProbe Exponential:  " << duration << " milliseconds " <<"dataSize "<<dataSize<< std::endl;
        hashtable2.Clear();

        //Test HorizontalVectorProbing
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HorizontalVectorProbing Exponential:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = Exponential();
            int result = hashtable1.HorizontalVectorProbing(key);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HorizontalVectorProbing Exponential: " << duration << " milliseconds " <<"dataSize "<<dataSize<< std::endl;
        hashtable1.Clear();

        //Test ScalarProbingInsert
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing ScalarProbingInsert Exponential:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = Exponential();
            hashtable1.ScalarProbingInsert(key);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken ScalarProbingInsert Exponential: " << duration << " milliseconds " <<"dataSize "<<dataSize<< std::endl;
        hashtable1.Clear();

        //  ----------------------Zipf--------------------------

        // Test HopScotchHorizontalProbe
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HopScotchHorizontalProbe zipf:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = zipf(genSize, 0.5);
            hashtable2.HopScotchHorizontalProbe(key, 4);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HopScotchHorizontalProbe zipf : " << duration << " milliseconds " <<"dataSize "<<dataSize<< std::endl;
        hashtable2.Clear();

        // Test HopScotchScalarProbe
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HopScotchScalarProbe zipf:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = zipf(genSize, 0.5);
            hashtable2.HopScotchScalarProbe(key, 4);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HopScotchScalarProbe zipf:  " << duration << " milliseconds " <<"dataSize "<<dataSize << std::endl;
        hashtable2.Clear();

        //Test HorizontalVectorProbing
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing HorizontalVectorProbing zipf:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = zipf(genSize, 0.5);
            int result = hashtable1.HorizontalVectorProbing(key);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken HorizontalVectorProbing zipf: " << duration << " milliseconds " <<"dataSize "<<dataSize<< std::endl;
        hashtable1.Clear();

        //Test ScalarProbingInsert
        start = std::chrono::high_resolution_clock::now();
        std::cout << "Testing ScalarProbingInsert zipf:" << std::endl;
        for (int i = 0; i < genSize; i++) {
            int key = zipf(genSize, 0.5);
            hashtable1.ScalarProbingInsert(key);
        }
        end = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken ScalarProbingInsert zipf: " << duration << " milliseconds " <<"dataSize "<<dataSize << std::endl;
        hashtable1.Clear();
    }
    return 0;
}
