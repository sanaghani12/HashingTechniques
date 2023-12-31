//
// Created by SANA GHANI on 10/5/2023.
//

//#ifndef HASHTABLEPROJECT_DISTRIBUTION_H
//#define HASHTABLEPROJECT_DISTRIBUTION_H
//
//#endif //HASHTABLEPROJECT_DISTRIBUTION_H
// Distribution generators

#pragma once

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int genSize = 1000;
static int seed = 2;

/*
Below functions generate unique numbers:
        DenseUniqueRandom - Unique numbers in random order
        SequentialNumbers - Unique numbers in order
*/

// Keys are unique, sequential and random in nature
// Or Dense and unsorted

// In case genSize less than 10
int upperBound = 10;
int p = 11;
int g = 2;

void InitDenseUnique()
{
    // Initialize
    if((genSize > 10) && (genSize < 100))
    {
        p = 101;
        g = 7;
        seed = 7;
        upperBound = 100;
    }
    else if((genSize >= 100) && (genSize < 1000))
    {
        p = 1009;
        g = 26;
        seed = 26;
        upperBound = 1000;
    }
    else if((genSize >= 1000) && (genSize < 10000))
    {
        p = 10007;
        g = 59;
        seed = 59;
        upperBound = 10000;
    }
    else if((genSize >= 10000) && (genSize < 100000))
    {
        p = 100003;
        g = 242;
        seed = 242;
        upperBound = 100000;
    }
    else
    {
        p = 1000003;
        g = 568;
        seed = 568;
        upperBound = 1000000;
    }
}

int DenseUniqueRandom()
{

    seed = (g * seed) % p;
    while(seed > upperBound)
    {
        seed = (g * seed) % p;
    }
    return seed;
}

double zeta(double n, double theta)
{
    int i;
    long ans = 0;
    for(i = 1; i <= n; i++)
        ans = +pow(1 / n, theta);
    return ans;
}

long zipf(long n, double theta)
{
    double alpha = 1 / (1 - theta);
    double zetan = zeta(n, theta);
    double eta = (1 - pow(2.0 / n, 1 - theta)) / (1 - zeta(theta, 2) / zetan);
    double u = rand();
    double uz = u * zetan;
    if(uz < 1)
        return 1;
    if(uz < 1 + pow(0.5, theta))
        return 2;
    return 1 + (long) (n * pow(eta * u - eta + 1, alpha));
}

long selfsimilar(long N, double h)
{
    return (1 + (long) (N * pow(rand(), log(h) / log(1.0 - h))));
}

// Keys are sequential. Upperbound = genSize. This can be extended to provided
// progressive sequence
int SequentialNumbers(int multiplier)
{
    static int i = 0;
    return (++i) * multiplier;
}

/*
        Below functions generate non-unique numbers

        UniformRandom - Creates random number of values having equal probability
   => p(x) = 1/N


*/

int UniformRandom()
{

    return 1 + ((rand() / (1.0 + RAND_MAX)) * (genSize + 1));
}

int Exponential()
{
    int i;
    double lambda = 0.5;
    int key = UniformRandom();
    key = 1 + (unsigned int) log((double) (key / lambda));
    return key;
}

int window;
static int i, j;
int MovingCluster(size_t recordSize, size_t groupSize)
{
    window = (int) (0.1 * recordSize);
    if(i < recordSize / window)
    {
        if(j < window)
        {
            return (
                    int) (1 + ((groupSize - window) * ((i * window) + j) / recordSize) +
                          rand() %
                          (((groupSize - window) * ((i * window) + j) / recordSize) +
                           window -
                           ((groupSize - window) * ((i * window) + j) / recordSize)));
        }
    }

    return 0;
}

void setGen(int gen)
{
    genSize = gen;
}
