# README #

Labs for "TDA352 - Cryptography" course

-----------------------------------------------------------------

## Assignment 1 ##

The assignment consists of two largely independent parts. In the first (and main) part we will study a well-known attack on an SSL channel and answer some questions. In the second part, we will encrypt our solution using gpg before submitting it.

-----------------------------------------------------------------

## Assignment 2 ##

In this assignment we explore the ElGamal encryption system. Personal encrypted messages generated using the Chalmers linux machines.

-----------------------------------------------------------------

## Assignment 3 ##

In this assignment we will break some simple, faulty cryptographic protocols, by demonstrating attacks against them. Note that what we will have to find is attacks against the protocol, not against the encryption primitives.

-----------------------------------------------------------------

## Programming assignment ##

### cryptolib_cpp ###

In this assignment we implemented a library that provides a number of mathematical functions commonly used in cryptography, such as Euler's Phi Function (Totient), the Extended Euclidean Algorithm and some Primality Test. Our library successfully passed the test suite provided with the skeleton code.

Compilation:
```
g++ -o cryptoLib cryptoLib_test.cpp
```

Running:
```
./cryptoLib
```
-----------------------------------------------------------------

### fiat_shamir_java ###

We eavesdropped on a number of Fiat-Shamir protocol runs and we found that the same nonce was used twice. Due to the special soundness property we should now be able to retrieve the secret key used in the protocol. The fiat_shamir_java folder contains the skeleton code and the test suite.

Compilation:
```
javac FiatShamir.java
```

Running:
```
java FiatShamir.java
```
-----------------------------------------------------------------
