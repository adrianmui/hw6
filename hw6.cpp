/**
 * Homework 6: Recursive exercises
 */

#include <iostream>
#include <string>
using namespace std;

class TreeNode {
public:
	TreeNode(int d) : data(d), left(NULL), right(NULL) { }
	int data;
	TreeNode * left;
	TreeNode * right;
};

TreeNode * makeSampleTree() {
	TreeNode * root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(6);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(7);
	return root;
}

TreeNode * makeStraightTree() {
	TreeNode * root = new TreeNode(20);
	root->right = new TreeNode(35);
	root->right->right = new TreeNode(50);
	root->right->right->left = new TreeNode(37);
	return root;
}

// Returns "0" if 0, "1" if 1, "X" otherwise.
string intToString(int n) {
	if (n == 0) return "0";
	if (n == 1) return "1";
	return "X";
}

// *** Your assignment starts here! ***

// Returns the sum of all of the digits in n.
// You MUST use recursion to solve this problem.
int sumOfDigits(int n) {
    if (n == 0)
        return 0;
    return n % 10 + sumOfDigits(n/10);
    // Your code here!
}

// Returns true if s is a palindrome, or false if it is not.
// You MUST use recursion to solve this problem.
bool isPalindrome(string s) {
    if (s.length() <= 1)
        return true;
    return ((s[0]==s[s.length()-1]) && (isPalindrome(s.substr(1,s.length()-2))));
     // Your code here!
}

// Returns the nth fibonacci number.
// You MUST use recursion to solve this problem.
// Hint: fibonacci(0) = 1 and fibonacci(1) = 1
int fibonacci(int n) {
    if (n==0 || n==1)
        return 1;
    return fibonacci(n-1)+ fibonacci(n-2);
}

// Does an in-order traversal of the given binary tree rooted at root
// by printing the data element of each TreeNode in the correct order.
void inOrderTraversal(TreeNode * root) {
    if (root == NULL)
    {
        return;//donothing
    }
    inOrderTraversal(root->left);
    cout<<root->data<< endl;
    inOrderTraversal(root->right);
    
}
    // Your code here!

// Clears all memory used by the given binary tree rooted at root.
void clearTree(TreeNode * root) {
    if (root->left != NULL)
        clearTree(root->left);
    if (root->right != NULL)
        clearTree(root->right);
    delete root;
    
	// Your code here:
}

// Returns n!, which is n * n-1 * n-2 * ... * 2 * 1
// You MUST use recursion to solve this problem.
int factorial(int n) {
    if (n==0)
        return 1;
    return n * factorial(n-1); // Your code here!
}

// Returns the binary representation of the given integer.
// You MUST use recursion to solve this problem.
// Hint: Use the provided intToString helper function,
//       which turns 0 and  1 ints into "0" and "1" strings.
string intToBinary(int n) {
    
    if (n==1)
    {
        return "1";
    }
    if (n%2 == false)
    {
        return intToBinary(n/2)+"0";
    }
    else {
        return intToBinary(n/2)+"1";
    }
    return "";
// Your code here!
}

// Sums the entire given binary tree rooted at root.
int sumTree(TreeNode * root) {
    if (root == NULL)
        return 0;
    return root->data + sumTree(root->left) + sumTree(root->right);
}

int main() {
	TreeNode * root = makeSampleTree();
	TreeNode * root2 = makeStraightTree();
	cout << endl << "== Testing sumOfDigits ==" << endl;
	cout << "   sumOfDigits(1234): " << (sumOfDigits(1234) == 10 ? "Passed!" : "FAILED") << endl;
	cout << "  sumOfDigits(24680): " << (sumOfDigits(24680) == 20 ? "Passed!" : "FAILED") << endl;
	cout << "      sumOfDigits(2): " << (sumOfDigits(2) == 2 ? "Passed!" : "FAILED") << endl;
	cout << "sumOfDigits(9999999): " << (sumOfDigits(9999999) == 63 ? "Passed!" : "FAILED") << endl;
	cout << endl << "== Testing isPalindrome ==" << endl;
	cout << "    isPalindrome(\"racecar\"): " << (isPalindrome("racecar") ? "Passed!" : "FAILED") << endl;
	cout << "  isPalindrome(\"abbabacca\"): " << (!isPalindrome("abbabacca") ? "Passed!" : "FAILED") << endl;
	cout << "  isPalindrome(\"abbababba\"): " << (isPalindrome("abbababba") ? "Passed!" : "FAILED") << endl;
	cout << "isPalindrome(\"spaaaaaaace\"): " << (!isPalindrome("spaaaaaaace") ? "Passed!" : "FAILED") << endl;
	cout << endl << "== Testing fibonacci ==" << endl;
	cout << "fibonacci(5): " << (fibonacci(5) == 8 ? "Passed!" : "FAILED") << endl;
	cout << "fibonacci(6): " << (fibonacci(6) == 13 ? "Passed!" : "FAILED") << endl;
	cout << "fibonacci(8): " << (fibonacci(8) == 34 ? "Passed!" : "FAILED") << endl;
	cout << "fibonacci(9): " << (fibonacci(9) == 55 ? "Passed!" : "FAILED") << endl;
	cout << endl << "== Testing inOrderTraversal ==" << endl;
	cout << " inOrderTraversal(root): ";
	inOrderTraversal(root);
	cout << endl << "      ...you should see: 1234567" << endl;
	cout << "inOrderTraversal(root2): ";
	inOrderTraversal(root2);
	cout << endl << "      ...you should see: 20353750" << endl;
	cout << endl << "== Testing factorial ==" << endl;
	cout << "factorial(3): " << (factorial(3) == 6 ? "Passed!" : "FAILED") << endl;
	cout << "factorial(4): " << (factorial(4) == 24 ? "Passed!" : "FAILED") << endl;
	cout << "factorial(5): " << (factorial(5) == 120 ? "Passed!" : "FAILED") << endl;
	cout << "factorial(6): " << (factorial(6) == 720 ? "Passed!" : "FAILED") << endl;
	cout << endl << "== Testing intToBinary ==" << endl;
	cout << "  intToBinary(50): " << (intToBinary(50) == "110010" ? "Passed!" : "FAILED") <<intToBinary(50)<< endl;
	cout << "   intToBinary(1): " << (intToBinary(1) == "1" ? "Passed!" : "FAILED") << endl;
	cout << "intToBinary(1024): " << (intToBinary(1024) == "10000000000" ? "Passed!" : "FAILED") <<intToBinary(1024)<< endl;
	cout << "  intToBinary(33): " << (intToBinary(33) == "100001" ? "Passed!" : "FAILED") <<intToBinary(33)<< endl;
	cout << endl << "== Testing sumTree ==" << endl;
	cout << " sumTree(root): " << (sumTree(root) == 28 ? "Passed!" : "FAILED") << endl;
	cout << "sumTree(root2): " << (sumTree(root2) == 142 ? "Passed!" : "FAILED") << endl;
	cout << endl << "== Crazy test of 3 things at once! ==" << endl;
	cout << "fibonacci(sumOfDigits(sumTree(root2))): " << (fibonacci(sumOfDigits(sumTree(root2))) == 21 ? "Passed!" : "FAILED") << endl;
	cout << endl << "== Testing clearTree ==" << endl;
	clearTree(root);
	clearTree(root2);
	cout << "Call \"valgrind ./hw6\" to make sure you have no memory leaks!" << endl;
	cout << endl;
}
