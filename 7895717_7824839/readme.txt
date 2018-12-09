Huairuo Yang 7895717
Yifei Du 7824839

=================================================================
./project contains the original project with TEST_BOARD disabled.

Input "expert" to start expert mode or anything to start normal mode.
you should follow the game procedure and input card step by step.

==================================================================
./testProject contains the source code without main but with a "testEntry" file.

function testEntry covers a detailed run for expert mode and a detailed run for normal mode:
for both mode, card sequences are chose randomly, target for experts skills are chose randomly

just include the testEntry file in your main and call the test function,

or use the following code as your main file for testing:


#include <iostream>
#include "testEntry.hpp"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "enter test\n";
    Test a;
    a.testEntry();
    return 0;
}
