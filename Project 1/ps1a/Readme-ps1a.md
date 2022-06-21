# PS0: Hello SFML

## Contact
Name: Juan  Lopez
Section: 011
Time to Complete: 7hrs


## Description
We discussed me turning this in late due to my 4 day drill weekend last monday.
The projects takes a 16bits and apllies the LFSR fibonacci sequence to it. It does this according to the ammount of times we tell it to through the generate functions.

### Features
I used an if-else statement method
I started off by creating integer varaibles that can hold the taps we were instructed to tap and an output variable.
The output varaible holds the tap as moves down the taps and is rewritten with the new tap.
Once it reaches the final tap it returns whatever us held in output. I had an idea of converting the string seed into an integer array,
but I managed to find a method that allows me to convert a char into an INT as needed instead of converting the whole string to an int.
At the bottom of my step() function I am also able to add in a new char and remove once I get the INT.

### Issues
Does not check for valid input and takes a little longer to compile first time

### Tests
The tests I am running check to make sure that the two parameters have equal value.
I added a third test case with a string of 16 0's to see if the program would fall into a loop, but it passed accordingly.
The second test I added makes sure that my getSeed() function works and returns the string being input.


## Acknowledgements
https://www.boost.org/doc/libs/1_65_0/libs/test/doc/html/boost_test/testing_tools/extended_comparison/strings.html
https://stackoverflow.com/questions/7965437/undefined-reference-to-main-collect2-ld-returned-1-exit-status
https://stackoverflow.com/questions/61827714/c-warning-pragma-once-in-main-file
https://m.cplusplus.com/reference/string/string/erase/