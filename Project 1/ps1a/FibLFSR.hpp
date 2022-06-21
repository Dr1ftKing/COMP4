
#ifndef HEADERFILE_H
#define HEADERFILE_H
#include <iostream>
#include <vector> 
#include <string>
using namespace std;

class FibLFSR {
 public:
    // Constructor to create LFSR with the given initial seed
    FibLFSR(string seed);
    
    // Simulate one step and return the new bit as 0 or 1
    int step();
    // Simulate k steps and return a k-bit integer
    int generate(int k);
    string getSeed(void);
 private:
    string seed;
    int tap13;
    int tap12;
    int tap10;
    int tap15;
};

ostream& operator<<(ostream&, const FibLFSR& lfsr);


#endif