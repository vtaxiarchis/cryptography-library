# README #

Labs for "TDA352 - Cryptography" course

-----------------------------------------------------------------

### Assignment 1 --- cryptolib_cpp ###

In this assignment we implemented a library that provides a number of mathematical functions commonly used in cryptography, such as Euler's Phi Function (Totient), the Extended Euclidean Algorithm and some Primality Test. Our library successfully passed the test suite provided with the skeleton code.

Compilation/Running:
* g++ -o cryptoLib cryptoLib_test.cpp
* ./cryptoLib

-----------------------------------------------------------------

### Assignment 2 --- fiat_shamir_java ###

We eavesdropped on a number of Fiat-Shamir protocol runs and we found that the same nonce was used twice. Due to the special soundness property we should now be able to retrieve the secret key used in the protocol. The fiat_shamir_java folder contains the skeleton code and the test suite.

-----------------------------------------------------------------
