 #include<stdio.h> 
struct Node {
int value;
struct Node *left, *right;
};

struct Node* createNode(int value) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->value = value;
newNode->left = newNode->right = NULL;
return newNode;
}

struct Node* insert(struct Node* root, int value) {
if (root == NULL) {
return createNode(value);
}

if (value < root->value) {
root->left = insert(root->left, value);
} else if (value > root->value) {
root->right = insert(root->right, value);
}

return root;
}
struct Node* search(struct Node* root, int value) {
if (root == NULL || root->value == value) {
return root;
}

if (value < root->value) {
return search(root->left, value);
} else {
return search(root->right, value);
}
}
struct Node* findMin(struct Node* root) {
while (root->left != NULL) {
root = root->left;
}
return root;
}
struct Node* delete(struct Node* root, int value) {
if (root == NULL) {
return root;
}
if (value < root->value) {
root->left = delete(root->left, value);
}
else if (value > root->value) {
root->right = delete(root->right, value);
}
else {
if (root->left == NULL) {
struct Node* temp = root->right;
free(root);
return temp;
} else if (root->right == NULL) {
struct Node* temp = root->left;
free(root);
return temp;
}
struct Node* temp = findMin(root->right);
root->value = temp->value;
root->right = delete(root->right, temp->value);
}
return root;
}
void display(struct Node* root) {
if (root != NULL) {
printf("%d ", root->value);
display(root->left);
display(root->right);
}
}


int main() {
struct Node* root = NULL;
int choice, value;

while (1) {
printf("\n1. Insert\n2. Search\n3. Delete\n4. Display \n5. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter value to insert: ");
scanf("%d", &value);
root = insert(root, value);
break;
case 2:
printf("Enter value to search: ");
scanf("%d", &value);
if (search(root, value)) {
printf("Value found in the BST.\n");
} else {
printf("Value not found in the BST.\n");
}
break;
case 3:
printf("Enter value to delete: ");
scanf("%d", &value);
root = delete(root, value);
break;
case 4:
printf("Display: ");
display(root);
printf("\n");

break;
case 5:
exit(0);
}
}
return 0;
}

