// ShuntingYardTemplateSol.cpp : Defines the entry point for the console application.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <stack>

using namespace std;

string inputFileNameStr = "expressions.txt";                  // Default location in solution folder

class OperatorMapClass {

private:
  typedef map<char, int>    OperatorPrecedenceMapType;
  OperatorPrecedenceMapType operatorMapObj;

public:

  OperatorMapClass() {
    operatorMapObj.insert(OperatorPrecedenceMapType::value_type('+', 1));
    operatorMapObj.insert(OperatorPrecedenceMapType::value_type('-', 1));
    // xxx insert code here to insert * and / in the map object
  }//OperatorMapClass ()

  bool isStackOperatorHigherPrecedence(char operatorChar, char operatorStackChar) {
    return((operatorMapObj.count(operatorStackChar))
      &&
      (operatorMapObj.at(operatorStackChar) >= operatorMapObj.at(operatorChar)));
  }//isStackOperatorHigherPrecedence()

  bool  isOperator(char token) {
      // xxx check if token operator Map Object is 0 or not to return true or false
      return true; // dummy return
   
  }//isOperator()

};//OperatorMapClass

OperatorMapClass  operatorMapObj;

class ShuntingYardClass {

public:

  string createPostFixFrom(string infixString) {

    string       outputString;
    stack <char> operatorStackObj;

    for (char token : infixString) {
      switch (token) {
      case '/': case '*': case '+': case '-':
        // xxx insert code here
        /*

         while (the stack is not empty
                  AND
                the top of the stack token is not a left parenthesis
                  AND
                precedence of the current operator <= precedence of the top of the stack token
               )
         {
              Push back the stack top token to the output string
              Pop the stack top and discard it
          }//while-end

           Push the current operator token onto the stack
        */
        break;
      case '(':                                                       // left parenthesis                   
          // xxx insert code here
          // push this token on the stack
        break;
      case ')':
        // xxx insert code here                                                      // right parenthesis
        /*

        while (the stack is not empty AND the top stack token is not a left parenthesis)
        {
           Push back the stack top token to the output string
        }//while-end

        Pop the left parenthesis from the stack and discard it
        */
        break;
      default:                                                        // operand                                                         
          // xxx insert code here
          // push back the operand symbol to the output string 
        break;
      }//switch
    }//for

    // xxx insert code here
    /*
     while (the stack is not empty)
     {
       //Push back any remaining stack tokens to the output string
    }//while-end
    */
    return(outputString);

  }//postfix()	

};//ShuntingYardClass



class TreeNodeClass {

public:
    TreeNodeClass* left;
    char            value;
    TreeNodeClass* right;

};//TreeNodeClass

TreeNodeClass* BuildNewNodeObjPtrMethod(char value) {

    // xxx new a new TreeNodeClass pointer
    // set value in new node and left and right pointers
    // return new node pointer

    return nullptr; // dummy return
};


TreeNodeClass* ConstructBET(string postFixStr) {
    stack<TreeNodeClass*>   parseStack;
    TreeNodeClass*          newNodePtr;
    OperatorMapClass        OperatorMapObj;

    // xxx must develop code here
    // Process each character of the post-fix expression into token
    char token=' ';
    {
        // Form a new node pointer
        newNodePtr = BuildNewNodeObjPtrMethod(token);
        // check if an operator
        {
            // parse stack nodes into a new subtree as children
            // Save/Add this sub tree node to the stack
        }
        // not operator
        {
            // operand, push node onto stack
        
        }
    }

    //  Place formed root node on the stack into tree
    
    return newNodePtr;
}

string buildString;

void preorder(TreeNodeClass* treeNode) {
    //xxx do pre order transversal to build string
    buildString += treeNode->value;
}

bool areParensRequired(TreeNodeClass* treeNode, char value) {
    OperatorMapClass operatorMapObj;
    if (operatorMapObj.isOperator(value) &&
        operatorMapObj.isOperator(treeNode->value) &&
        operatorMapObj.isStackOperatorHigherPrecedence(treeNode->value, value)) {
        buildString += '(';
        return true;
    }
    return false;
}

void inorder(TreeNodeClass* treeNode) {
    //xxx do in order transversal to build string
    bool parensRequired = false;
    if (treeNode) {
        // xxx check if parens required pass arguments treeNode->left, treeNode->value
        // go left
       
        // add value to build string 
        // xxx check if parens required pass arguments treeNode->right, treeNode->value
        // go right
         // check if parens required 
            //add ) to buildString
     
    }//if
}

void postorder(TreeNodeClass* treeNode) {
    //xxx do post order transversal to build string
        buildString += treeNode->value;
    
}



int main() {

  ifstream  inputFileStreamObj(inputFileNameStr);

  if (inputFileStreamObj.fail()) {
    cout << "File could not be opened !" << endl;

    return (EXIT_FAILURE);
  }//if

  string  infixExpressionStr,
          postfixExpressionStr;

  ShuntingYardClass shuntingYardObj;

  while (inputFileStreamObj >> infixExpressionStr) {

      cout << "InFix   Expression : " << infixExpressionStr << endl;
      postfixExpressionStr = shuntingYardObj.createPostFixFrom(infixExpressionStr);
      cout << "PostFix Expression : " << postfixExpressionStr << endl << endl;

      TreeNodeClass* expressionTreeRootPtr = ConstructBET(postfixExpressionStr);

      buildString = "";  preorder(expressionTreeRootPtr);
      cout << "Tree  pre-order expression is " << endl << buildString << endl << endl;

      buildString = "";  inorder(expressionTreeRootPtr);
      cout << "Tree   in-order expression is " << endl << buildString << endl << endl;

      buildString = "";  postorder(expressionTreeRootPtr);
      cout << "Tree post-order expression is " << endl << buildString << endl << endl;

      cout << endl << endl;

  };//while

  inputFileStreamObj.close();

  cout << "Press the enter key once or twice to end." << endl;  

  return EXIT_SUCCESS;

}//main()

