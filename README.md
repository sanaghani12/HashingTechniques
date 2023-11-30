# Hashing Techniques Implementation

This repository showcases implementations of Linear Probing and Hopscotch Hashing, including scalar and SIMD versions. These techniques aim to enhance the efficiency of grouped aggregation functions by addressing collision-related challenges in hashing.

## Table of Contents

- [Overview](#overview)
- [Implemented Techniques](#implemented-techniques)
  - [Linear Probing](#linear-probing)
  - [Hopscotch Hashing](#hopscotch-hashing)
- [SIMD Acceleration](#simd-acceleration)
- [Results](#results)
- [Contributing](#contributing)

## Overview

Grouped aggregation functions commonly encounter performance issues due to collisions in hashing techniques. This project explores the implementation of two prominent hashing techniques—Linear Probing and Hopscotch Hashing. Both scalar and SIMD versions are included to provide a comprehensive understanding of their performance in various scenarios.

## Implemented Techniques

### Linear Probing

Linear Probing is a simple yet effective hashing technique that sequentially searches for the nearest empty slot for insertion. If a key is found during the search, the aggregate result is updated; otherwise, the aggregate is initialized at the first empty slot.

### Hopscotch Hashing

Hopscotch Hashing introduces a user-defined neighborhood parameter, ensuring that any key is available within a specific range from its originally hashed location. The insertion process involves searching for an empty location and swapping existing keys until an empty slot is available within the defined neighborhood.

## SIMD Acceleration

To address the inefficiencies in traditional hashing techniques, Single Instruction Multiple Data (SIMD) acceleration is implemented. This approach allows the simultaneous processing of multiple slots, significantly improving scanning efficiency.

## Results

The repository includes the code to analyze the performance of Linear Probing and Hopscotch Hashing under different scenarios, including dense unique random distribution and uniform distribution.

## Contributing

If you find any issues or have suggestions for improvements, feel free to contribute! Please check the [contribution guidelines](CONTRIBUTING.md) before submitting a pull request.

