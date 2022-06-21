#include "FibLFSR.hpp"
#include <iostream>
using namespace std;

FibLFSR::FibLFSR(string seed)
{
    //takes sets the seed to whatever the object is reading
    this->seed = seed;

}




int FibLFSR::step()
{
    // 00-01-02-03-04-05-06-07-08-09-10-11-12-13-14-15-16
    // 16-15-14-13-12-11-10-09-08-07-06-05-04-03-02-01
    
    int output = 0;

    
    tap10 = seed.at(6);
    tap12 =seed.at(4);
    tap13 =seed.at(3);
    tap15 = seed.at(0);

    //  "-'0'" converts if from char to it's int counterpart
    tap15 = seed.at(0) - '0';
    tap13 = seed.at(2) - '0';

    //Compares tap 15 & 13
    if((tap15 == 1 && tap13 == 1 ) || (tap15 == 0 && tap13 == 0)){
        output = 0;
    } else output = 1;

    //  "-'0'" converts if from char to it's int counterpart
    tap12 = seed.at(3) - '0';
    
    
    //compares result of preivous tap & tap12
    if((output == 1 && tap12 == 1 ) || (output == 0 && tap12 == 0)){
        output = 0;
    } else output = 1;

    //  "-'0'" converts if from char to it's int counterpart
    tap10 = seed.at(5) - '0';


    //compares result of preivous tap & tap10
    if((output == 1 && tap10 == 1 ) || ( output == 0 && tap10 == 0)){
        output = 0;
    } else output = 1;


     // shift the string left and put the output at the LSB
    seed.erase(0,1);
    seed.push_back(output + '0');

    return output;


}



//original idea that got two complicated in my head
/* 
    //convert seed into an integer
    int seed2Int[seed.length()];
    
    for(int i = 0; i< seed.length();i++)
    {
        if(seed[i]== '0')
        {
            seed2Int[i] = 0;
        }
        else if(seed[i]=='1')
        {
            seed2Int[i] = 1;
        }
    }
    //resultSeed = binSeed[0]^binSeed[2]^binSeed[3]^binSeed[5];
*/





int FibLFSR::generate(int k)
{
     // generate will call the step k times and return the final integer;
    int number = 0, bit = 0, i;

    for(i = 0; i < k; i++){
        bit = step();
        number = number*2 + bit;
    }

    return number;

}

string FibLFSR::getSeed(void)
{
    return seed;
}

ostream& operator<<(ostream& out, FibLFSR& fibLfsr )
{
   return out << fibLfsr.getSeed();
}