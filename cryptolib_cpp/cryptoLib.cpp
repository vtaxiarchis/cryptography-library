/********************************************************************
* Authors
*
* Vaios Taxiarchis - 19910309-8514 (used to generate the skeleton code)
* Rickard Johansson - 19930415-4512
*
********************************************************************/
// Compilation (compile the test file, which includes this file):
//   g++ -o cryptoLib cryptoLib_test.cpp
// Running:
//   ./cryptoLib
//
#include <stdio.h>
#include <cmath>
#include <cstring>
#include <iostream>
#include <cstdlib>
#define ll long long
using namespace std;

/**
 * Assigns to the array "result" the values "result[0] = gcd", "result[1] = s"
 * and "result[2] = t" such that "gcd" is the greatest common divisor of "a" and
 * "b", and "gcd = a * s + b * t".
 **/
void EEA(int a, int b, int result[]) {
    // Note: as you can see in the test suite,
    // your function should work for any (positive) value of a and b.
    //local variables
    int q, r, x1, x2, y1, y2;
    x2 = 1, x1 = 0, y2 = 0, y1 = 1;
    //if b is equal to zero then gcd=a, s=1 and t=0
    if (b == 0) {
      result[2] = a, result[0] = x2, result[1] = y2;
      return;
    }
    //if a = b then gcd=a, s=1 and t=0
    if (a == b){
      result[0] = a, result[1] = x2, result[2] = y2;
    }
    else{
      //base base where both a and b are greater than zero
      while (b > 0) {
        q = a / b, r = a - q * b;
        result[0] = x2 - q * x1, result[1] = y2 - q * y1;
        a = b, b = r;
        x2 = x1, x1 = result[0], y2 = y1, y1 = result[1];
      }
    //result[0]=gcd, result[1]=s and result[2]=t where "gcd = a * s + b * t"
    result[0] = a, result[1] = x2, result[2] = y2;
    }
}

/**
 * Returns Euler's Totient for value "n".
 **/
int EulerPhi(int n){
  //local variables
  int i, result = n;
  //for loop for base case
  for (i=2;i*i<=n;i++){

      if (n%i==0){
        result-=result/i;
      }
      while(n%i==0){
        n/=i;
      }
  }
  //corner cases
  if (n!=1){
    result-=result/n;
  }
  if (n==-1){
    result=0;
  }

  return result;
}

/**
 * Utility - Naive modular exponentiation
 *         - Returns 'r' where r = n mod p.
 **/
int modulo(int n, int p){
  //local variable
  int r = n%p;
  //base case for computation of modulo
  if(((p > 0) && (r < 0)) || ((p < 0) && (r > 0))){
      r += p;
  }
  return r;
}

/**
 * Returns the value "v" such that "n*v = 1 (mod m)".
 * Returns 0 if the modular inverse does not exist.
 **/
int ModInv(int n, int m){
  //local variable is equal to n modulo m
  int v = modulo(n, m);
  //for loop for base case
  for(int x = 1; x < m; x++) {
      //Returns the value "v" such that "n*v = 1 (mod m)".
      if(modulo(v*x, m) == 1){
        return x;
      }
  }
  //returns 0 if the modular inverse does not exist.
  return 0;
}

/*
 * Utility - Modular exponentiation
 */
ll modulo_extended(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

/**
 * Returns 0 if "n" is a Fermat Prime, otherwise it returns the lowest Fermat
 * Witness. Tests values from 2 (inclusive) to "n/3" (exclusive).
 **/
int FermatPT(int n){
  //corner case for n=1
  if (n == 1)
  {
    return 1;
  }
  //for loop starting from i = 2 and computing i^{n-1} mod n
  for (int i = 2; i < n/3; i++)
  {
      //if it is not equal to 1 then returns the i (witness)
      //otherwise we parse the loop without get into the if
      if (modulo_extended(i, n - 1, n) != 1)
      {
          return i;
      }
  }
  //returns 0 if n is not a prime
  return 0;
}

/**
 * Returns the probability that calling a perfect hash function with "n_samples"
 * (uniformly distributed) will give one collision (i.e. that two samples result
 * in the same hash) -- where "size" is the number of different output values
 * the hash function can produce.
 **/
double HashCP(double n_samples, double size){
    //local variable for result set to 1 because we use it inside the loop and in the first interation it must be 1
    double res=1;
    //for loop for calculating the probability of having a collision using the birthday problem and the paradox
    for (int i=size;i>size-n_samples;i--){
      res = res * (i/size);
    }
    //the probability of having a collision is p = 1-p',
    res = 1 - res;
    return res;
}
