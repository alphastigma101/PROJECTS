#include "code.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

/* NOTES
    What a usual ADT stack does:
    * See whether a stack is empty.
	• Add a new item to the stack.
	• Remove from the stack the item that was added most recently.
	• Get the item that was added to the stack most recently.
    A stack has the property that the last item placed on the stack will be the first item removed. This property is commonly referred to as last in, first out
    or simply LIFO 
    Operations such as pop and peek must take reasonable action when the stack is empty. 
    L = { s$s' : s is a possibly empty string of characters other than $ , s' = reverse(s )}
    A stack is useful in determining whether a given string is in L.
    
    If you manually convert a few infix expressions to postfix form, you will discover three important facts:
		• The operands always stay in the same order with respect to one another.
		• An operator will move only “to the right” with respect to the operands; 
        * that is, if in the infix expression the operand x precedes the operator op 
        * it is also true that in the postfix expression the operand x precedes the operator op .
		• All parentheses are removed.
        In any infix expression, a set of matching parentheses defines an isolated subexpression that consists of an operator and its two operands.
        Parentheses, operator precedence, and left-to-right association determine where to place operators in the postfix expression
    A palindrome is a string that reads the same from left to right as it does from right to left. For example, “radar” and “deed” are both palindromes.
    The identifers are also known as the operands!
    
    An example of what a identifer is int num = 5
    num being the identifier
    1. When you encounter an operand, append it to the output string postfixExp. 
        Justification: The order of the operands in the postfix expression is the same as the order in the infix expression, and the operands that appear to the left of an operator in the infix expression also appear to its left in the postfix expression.
	2. Push each “(” onto the stack.
	3. When you encounter an operator, if the stack is empty, push the operator onto the stack.
    However, if the stack is not empty, pop operators of greater or equal precedence from the stack and append them to postfixExp. 
    You stop when you encounter either a “(” or an operator of lower precedence or when the stack becomes empty.
    You then push the current operator in the expression onto the stack. Thus, this step orders the operators by precedence and in accordance with left-to-right association. Notice that you continue popping from the stack until you encounter an operator of strictly lower precedence than the current operator in the infix expression. You do not stop on equality, because the left-to-right association rule says that in case of a tie in precedence, the leftmost operator is applied first—and this operator is the one that is already on the stack.
	4. When you encounter a “)”, pop operators off the stack and append them to the end of postfix- Exp until you encounter the matching “(”Justification : Within a pair of parentheses, precedence and left-to-right association determine the order of the operators, and step 3 has already ordered the operators in accordance with these rules.
	5. When you reach the end of the string, you append the remaining contents of the stack to
postfixExp.

*/
std::vector<int> vec; int operand_1 = 0;


bool isPalindrome(std::string str) {
    size_t len = str.length();
    for ( int i = 0; i < len/2; i++) {
        if(str[i] != str[len-1-i]){
            return false;
        }
    }    

    return true;
}


int postFixCalc(std::string str) {
    // Read a postfix expression from left to right. 
    // When you read a number, push it inside a vector
    // When you read an operator, access the elements inside vec and apply the operation to it
    int total;
    size_t len = str.length();
    if (len != 0) {
        for (unsigned int i = 0; i <= len; i++ ) {
            if (( str[i] >= '0' ) && ( str[i] <= '9' )) {
                vec.push_back(static_cast<int>(str[i]));
                str.erase(str.begin() + i); // Segmentation fault happens here!
                return postFixCalc(str); // Want to return the string after it has been modified 
            }
            else {
                switch (str[i]) {
                    case '+':
                        if ( str.length() != 1 ) {
                            operand_1 = vec[0] + vec[1];
                            vec.clear();
                            return postFixCalc(str);
                        }
                        else {
                            total = operand_1 + vec[0];
                            return total;
                        }
                    case '-':
                        if ( str.length() != 1 ) {
                            operand_1 = vec[0] - vec[1];
                            vec.clear();
                            return postFixCalc(str);
                        }
                        else {
                            total = operand_1 - vec[0];
                            return total;
                        }
                    case '*':
                        if ( str.length() != 1 ) {
                            operand_1 = vec[0] * vec[1];
                            vec.clear();
                            return postFixCalc(str);
                        }
                        else {
                            total = operand_1 * vec[0];
                            vec.clear();
                            return total;
                        }
                    case '/':
                        if ( str.length() != 1 ) {
                            operand_1 = ((vec[0]) / (vec[1]));
                            vec.clear();
                            return postFixCalc(str);
                        }
                        else {
                            total = ((operand_1) / (vec[0]));
                            vec.clear();
                            return total;
                        }
                    case '^':
                        operand_1 = (pow(vec[0], vec[1]));
                        break;
                }
            }
        }
    }
    else { std::cout << "String is empty!" << std::endl; }
    return total;
}



