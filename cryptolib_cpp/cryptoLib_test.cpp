// Compilation:
//   g++ -o cryptoLib cryptoLib_test.cpp
// Running:
//   ./cryptoLib

#include <stdio.h>
#include <iostream>
#include "cryptoLib.cpp"

int TestEEA(int a, int b, int gcd, int s, int t) {
    int temp[3];
    EEA(a,b, temp);
    if(temp[0] == gcd && temp[1]==s && temp[2]==t){
        return 0;
    }
    std::cout << "EEA failed for input " << a << "," << b << ". Got " <<
        temp[0] << "," <<  temp[1] << "," << temp[2] <<
        " expected values were " << gcd << "," << s << "," << t<< std::endl;
    return 1;
}

void TestEEA(){
    int errors=0;
    errors += TestEEA(5, 5, 5, 1, 0);
    errors += TestEEA(18, 1, 1, 0, 1);
    errors += TestEEA(1, 18, 1, 1, 0);
    errors += TestEEA(21, 22, 1, -1, 1);
    errors += TestEEA(157, 111, 1, -41, 58);
    errors += TestEEA(6, 68, 2, -11, 1);
    errors += TestEEA(12, 36, 12, 1, 0);
    errors += TestEEA(42, 25, 1, 3, -5);
    errors += TestEEA(150, 340, 10, -9, 4);
    std::cout << "Total errors in the EEA function " << errors << std::endl;

}

int TestEulerPhi(int input, int expected) {
    if (EulerPhi(input) == expected)
        return 0;
    std::cout << "EulerPhi failed for input " << input << ". Got " <<
        EulerPhi(input) << " expected " << expected << std::endl;
    return 1;
}

void TestEulerPhi(){
    int errors=0;
    errors += TestEulerPhi(-1, 0);
    errors += TestEulerPhi(13, 12);
    errors += TestEulerPhi(57, 36);
    errors += TestEulerPhi(111, 72);
    errors += TestEulerPhi(1000, 400);
    errors += TestEulerPhi(157, 156);
    std::cout << "Total errors in the EulerPhi function " << errors
        << std::endl;

}

int TestModInv(int n, int mod, int inv) {
    if (ModInv(n,mod) == inv)
    return 0;
    std::cout << "ModInv failed for input " << n << " and " << mod <<
        ". Got " << ModInv(n,mod) << " expected " << inv << std::endl;
    return 1;
}

void TestModInv(){
    int errors=0;
    errors += TestModInv(25, 42, 37);
    errors += TestModInv(11, 20, 11);
    errors += TestModInv(13, 50, 27);
    errors += TestModInv(8954, 123, 59);
    errors += TestModInv(-9, 823, 640);
    std::cout << "Total errors in the ModInv function " << errors << std::endl;

}

int TestFermatPT(int n, int expected) {
    if (FermatPT(n) == expected)
    return 0;
    std::cout << "FermatPT failed for input " << n << ". Got " <<
        FermatPT(n) << " expected " << expected << std::endl;
    return 1;
}

void TestFermatPT(){
    int errors=0;
    errors += TestFermatPT(7,0);
    errors += TestFermatPT(12,2);
    errors += TestFermatPT(53, 0);
    errors += TestFermatPT(111, 2);
    errors += TestFermatPT(157, 0);
    errors += TestFermatPT(158, 2);
    errors += TestFermatPT(341, 3);
    errors += TestFermatPT(1105, 5);
    errors += TestFermatPT(2821, 7);
    std::cout << "Total errors in the FermatPT function " << errors <<
        std::endl;
}


int TestHashCP(double n, double s, double expected) {
    if (HashCP(n,s)-expected<0.0000005 && HashCP(n,s)-expected>-0.0000005)
    return 0;
    std::cout << "HashCP failed for input " << n << " and " << s <<
        ". Got " << HashCP(n,s) << " expected " << expected << std::endl;
    return 1;
}

void TestHashCP(){
    int errors=0;
    errors += TestHashCP(24,356,0.547481);
    errors += TestHashCP(100,4096,0.704298);
    errors += TestHashCP(128,128,1);
    errors += TestHashCP(10,8202,0.00547355);
    std::cout << "Total errors in the HashCP function " << errors << std::endl;


}

int main(){
    TestEEA();
    TestEulerPhi();
    TestModInv();
    TestFermatPT();
    TestHashCP();
    return 0;
}
