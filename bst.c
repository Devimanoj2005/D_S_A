#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;
typedef struct StackNode {
    Node *treeNode;
    struct StackNode *next;
} StackNode;

StackNode *treeStackTop = NULL; 

void pushNode(Node *node) {
    StackNode *newStackNode = (StackNode*)malloc(sizeof(StackNode));
    if (!newStackNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newStackNode->treeNode = node;
    newStackNode->next = treeStackTop;
    treeStackTop = newStackNode;
}


Node* popNode() {
    if (!treeStackTop) return NULL;
    StackNode *temp = treeStackTop;
    Node *node = temp->treeNode;
    treeStackTop = treeStackTop->next;
    free(temp);
    return node;
}
typedef struct CharStackNode {
    char data;
    struct CharStackNode *next;
} CharStackNode;

CharStackNode *charStackTop = NULL;

void pushChar(char c) {
    CharStackNode *newNode = (CharStackNode*)malloc(sizeof(CharStackNode));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = c;
    newNode->next = charStackTop;
    charStackTop = newNode;
}

char popChar() {
    if (!charStackTop) return '\0'; 
    CharStackNode *temp = charStackTop;
    char data = temp->data;
    charStackTop = charStackTop->next;
    free(temp);
    return data;
}

char peekChar() {
    if (!charStackTop) return '\0';
    return charStackTop->data;
}

int isCharStackEmpty() {
    return charStackTop == NULL;
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

Node* createNode(char c) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = c;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void infixToPostfix(char *infix, char *postfix) {
    int i, j;
    char item;
    char x;

    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        item = infix[i];

        if (item == ' ' || item == '\t') {
            continue;
        } else if (isalnum(item)) { 
            postfix[j++] = item;
        } else if (item == '(') {
            pushChar(item);
        } else if (isOperator(item)) {
            while (!isCharStackEmpty() && peekChar() != '(' && precedence(peekChar()) >= precedence(item)) {
                postfix[j++] = popChar();
            }
            pushChar(item);
        } else if (item == ')') {
            while (!isCharStackEmpty() && (x = popChar()) != '(') {
                postfix[j++] = x;
            }
            
        } else {
           
        }
    }

    
    while (!isCharStackEmpty()) {
        postfix[j++] = popChar();
    }
    postfix[j] = '\0'; 
}

Node* buildTree(char *postfix) {
    while (treeStackTop != NULL) {
        popNode(); 
    }

    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isalnum(c)) { 
            pushNode(createNode(c));
        } else if (isOperator(c)) { 
            Node *right = popNode();
            Node *left = popNode();
            
            if (right == NULL || left == NULL) {
                 printf("Error: Invalid postfix expression - insufficient operands.\n");
                 if (left != NULL) free(left);
                 if (right != NULL) free(right);
                 return NULL;
            }
            
            Node *opNode = createNode(c);
            opNode->left = left;
            opNode->right = right;
            pushNode(opNode);
        }
    }
    return popNode(); 
}

void preorder(Node *root) {
    if (root) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

void freeTree(Node *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    char infix[100]; 
    char postfix[100];

    printf("Enter the infix exp (e.g., (a+b)*c): ");
    
    if (fgets(infix, sizeof(infix), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }
    infix[strcspn(infix, "\n")] = '\0';
    
    
    infixToPostfix(infix, postfix);
    
    Node *root = buildTree(postfix);

    if (root) {
        printf("Pre order expression: ");
        preorder(root);
        printf("\n");
        
        printf("Post order expression: ");
        postorder(root);
        printf("\n");
        
        
        freeTree(root);
    } else {
        printf("Error building expression tree. Please check your infix expression.\n");
    }

    return 0;
}
