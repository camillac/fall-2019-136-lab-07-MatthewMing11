# Code Review For Xinyi Lin

* tests.cpp has no tests and there are no examples to show that the program works
* extraneous include directive for climits when there is no instance of using climits variables
* program runs correctly but excessive use of function calls for countChar() decrease readability (possible solution is to store value into a variable)

Overall I found it surprising that Xinyi's approach was similar to my approach to the problem. The main differences I found were that I used helper functions to determine where the braces were while Xinyi used the .at() and .find() functions which served the same purpose.
