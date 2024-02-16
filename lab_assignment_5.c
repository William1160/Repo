#include <stdio.h>
#include <stdlib.h>
typedef struct node {
char letter;
struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
    int length = 0;
    if (head->next == NULL){
        return 1;
    }
    while (head->next != NULL){
        length++;
        head=head->next;
    }
    return length;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
    int size = length(head);
    char *str = (char *) malloc((size+2)*sizeof(char));
    if (str == NULL){
        return NULL;
    }
    
    int i = 0;
    while (head != NULL){
        str[i] = head->letter;
        head = head->next;
        i++;
    }

    str[(size+1)]='\0';
    return str;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->letter = c;
    newNode->next = NULL;

    if (*pHead == NULL) {
        *pHead = newNode;
        return;
    }

    node* head = *pHead;
    while (head->next != NULL){
        head = head->next;
    }
    head->next = newNode;
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
    node* head = *pHead;

    while(*pHead != NULL){
        node* temp;
        temp = *pHead;
        *pHead = (*pHead)->next;
        free(temp);
    }
}
int main(void)
{
int i, strLen, numInputs;
node* head = NULL;
char* str;
char c;
FILE* inFile = fopen("input.txt","r");
fscanf(inFile, " %d\n", &numInputs);
while (numInputs-- > 0)
{
fscanf(inFile, " %d\n", &strLen);
for (i = 0; i < strLen; i++)
{
fscanf(inFile," %c", &c);
insertChar(&head, c);
}
str = toCString(head);
printf("String is : %s\n", str);
free(str);
deleteList(&head);
if (head != NULL)
{
printf("deleteList is not correct!");
break;
}
}
fclose(inFile);
}