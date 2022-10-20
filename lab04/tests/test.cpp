#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() -     only do this in one cpp file

#include "../code.h"
#include "../ArrayStack.h"
#include "../ArrayStackRS.h"
#include "../StackPeek2.h"
#include "catch.hpp"

TEST_CASE( "### Palindrome ###", "[test1]" ) {
    REQUIRE( isPalindrome("madamimadam") );
    REQUIRE( isPalindrome("hello world") == false );
    REQUIRE( isPalindrome("dadseesdad") );
}

TEST_CASE( "### postFixCalc ###", "[test2]" ) {
    REQUIRE( postFixCalc("4 5 + 2 *") == 18 );
    REQUIRE( postFixCalc("4 5 + 2 3 + *") == 45 );
    REQUIRE( postFixCalc("4 5 * 2 3 * +") == 26 );
    REQUIRE( postFixCalc("4 5 + 2 + 3 +") == 14 );
}

/*TEST_CASE( "### ArrayStack ###", "[test3]" ) {
    ArrayStackRS<int> myStack;
    for(int i = 0; i < 7; i++){
        myStack.push(i);
    }
    REQUIRE( myStack.getSize() == 10 );
    for(int i = 0; i < 27; i++){
        myStack.push(i);
    }
    REQUIRE( myStack.getSize() == 40 );
}



TEST_CASE( "### Peek2 ###", "[test4]" ) {
    StackPeek2<int> myStack;
    // peek2 should fail (stack size is zero), make sure
    // it throws an exception
    REQUIRE_THROWS_AS( myStack.peek2(), std::exception);
    for(int i = 0; i < 7; i++) {
        myStack.push(i);
    }
    REQUIRE( myStack.peek2() == 5 );

}*/
