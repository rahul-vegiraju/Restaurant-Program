
//The string header contains constants, macro definitions, and function/type declarations
#include <string.h>
//The stdio header is required to incorporate input/output functionalities into our application
#include <stdio.h>
//The stdlib header defines four variable types, a number of macros, and a number of functions for performing common tasks.
#include <stdlib.h>

//We set hashtable to null.
struct hash *hashTable = NULL;

//We declare variable itemMaxVal of type integer and set to 4.
int itemMaxVal = 4;


struct node {

    //We declare variable item of type integer.
    int item;

    //We declare variable Order_Number of type integer.
    int Order_Number;

    //We declare variable level of type char.
    char level[999];

    //We declare variable IdOfUser of type char.
    char IdOfUser[999];

    //We declare variable Order_Number of type integer.
    struct node *next;
};
//
struct hash {
    // We declare variable count of type integer.
    int count;
    //We create node called head to act as a middle point
    struct node *head;
};

//Node called createNode with parameters int item,char *IdOfUser, int Order_Number, and char *level.
struct node * createNode(int item,char *IdOfUser, int Order_Number,char *level) {
    //We create node called newNode
    struct node *newNode;

    //We set newNode
    newNode = (struct node *) malloc(sizeof(struct node));

    //We set to item
    newNode->item=item;

    //We set to Order_number
    newNode->Order_Number = Order_Number;

    //We use strcpy to copy one string to another
    strcpy(newNode->IdOfUser, IdOfUser);

    //We use strcpy to copy one string to another
    strcpy(newNode->level, level);

    //We set equal to null
    newNode->next = NULL;

    //We return value newNode
    return newNode;
}

//We create class hashInsert with parameters int item,char *name, int Order_Number,and char *level.
void hashInsert(int item,char *name, int Order_Number,char *level) {
    //we create variable hashIndex of data type integer and set it to item % itemMaxVal
    int hashIndex = item % itemMaxVal;

    //We set node newNode to creatNode with parameters item,name, Order_Number, and level.
    struct node *newNode = createNode(item,name, Order_Number, level);

    //We use .head and .count to access
    if (!hashTable[hashIndex].head) {
        //we set to newNode
        hashTable[hashIndex].head = newNode;
        //we set to 1
        hashTable[hashIndex].count = 1;
        //we return the value
        return;
    }


    newNode->next = (hashTable[hashIndex].head);

    //We set to newNode
    hashTable[hashIndex].head = newNode;

    //we use .count++ to increment
    hashTable[hashIndex].count++;
    //returns the vlaue
    return;
}

//This method hashDelete with parameter item.
void hashDelete(int item) {
    //we create variable hashIndex of data type integer and set it to item % itemMaxVal and mark set to 0
    int hashIndex = item % itemMaxVal, mark = 0;
    //we create node called myTemporary
    struct node *myTemporary;
    //We create node called myNode
    struct node *myNode;
    //We set myNode to hashTable[hashIndex].head
    myNode = hashTable[hashIndex].head;
    //Runs if not equal to myNode
    if (!myNode) {
        //Prints string below
        printf("Given data is not present in hash Table!!\n");
        //returns the value
        return;
    }
    //We set myTemporary to myNode
    myTemporary = myNode;
    //Runs while myNode is not equal to null
    while (myNode != NULL) {

        if (myNode->item == item) {
            //We set mark to 1
            mark = 1;
            //runs if myNode is equal to hashTable[hashIndex].head
            if (myNode == hashTable[hashIndex].head)
                //We set hashTable[hashIndex].head to myNode->next
                hashTable[hashIndex].head = myNode->next;
            //else
            else
                //We set myTemporary->next to myNode->next
                myTemporary->next = myNode->next;
            //Decrements
            hashTable[hashIndex].count--;
            //We free myNode
            free(myNode);
            //We exit out of the loop
            break;
        }
        //we set to myNode
        myTemporary = myNode;

        myNode = myNode->next;
    }
    //If loop runs when it is mark
    if (mark)

        //prints the string below
        printf("Data has beem deleted successfully from Hash Table\n");

    else

        //prints the string below
        printf("Given data isn't present in hash Table\n");

    //returns the value
    return;
}


void hashSearch(int item) {

    //We set variable hashIndex of data type integer to item % itemMaxVal and mark to 0.
    int hashIndex = item % itemMaxVal, mark = 0;

    //We create the node name myNode.
    struct node *myNode;

    myNode = hashTable[hashIndex].head;
    //if loop which runs when not equal to myNode
    if (!myNode) {

        //prints the string below
        printf("Search element unavailable in hash table\n");

        //returns the value
        return;
    }
    //While loop which runs when myNode is not equal to NULL.
    while (myNode != NULL) {

        //if loop runs when myNode->item is equal to item
        if (myNode->item == item) {

            //prints string and value
            printf("Name : %s\n", myNode->IdOfUser);

            //prints string and value
            printf("Order_Number : %d\n", myNode->Order_Number);

            //Prints string and value
            printf("Phone_Number : %s\n", myNode->level);

            //we set mark to 1
            mark = 1;

            //exits the loop
            break;
        }
    //We set myNode
        myNode = myNode->next;
    }
    //if loop for when not equal to mark
    if (!mark)
        //prints the string below
        printf("Search element unavailable in hash table\n");
    //returns the value
    return;
}

// main class is to execute the program
int main() {
    //variable z of data type integer.
    int z;

    //variable k of data type integer.
    int k;

    //variable item of data type integer.
    int item;

    //variable Order_Number of data type integer.
    int Order_Number;

    //variable z of data type char.
    char IdOfUser[100];

    //variable level of data type char.
    char level[100];

    //We have to set hashTable
    hashTable = (struct hash *) calloc(z, sizeof(struct hash));

    //We need to be able to repeat statements.
    while (1) {
        printf("----------------Menu----------------\n");
        printf("Item 1: Item 2: Item 3:\n");
        printf("Item 4: Item 5: Item 6:\n");
        printf("Item 7: Item 8: Item 9:\n");
        printf("Item 10: Item 11: Item 12:\n");
        printf("Item 13: Item 14: Item 15:\n");
        printf("\n1. Choosing an item"

               "\n2. Search the selected items\n");

        printf("3. Delete an item selected\n4. Complete Order\n enter your choice\n Press any item to continue ...");
        //allows user to input a value
        scanf("%d", &k);
        switch (k) {
            //Case 1 is for choosing the item
            case 1:
                //Prints the string below.
                printf("Enter the item value:");
                //Allows the user to input a value for item
                scanf("%d", &item);

                //We make a while loop to make sure that the user doesn't input more than 15 because there are 15 items.
                while (item > 15) {
                    //Prints the string below.
                    printf("ERROR choose an option from the list.\n");
                    //Allows the user to input a value for item.
                    scanf("%d", &item);
                }
                getchar();

                //This prints the string below.
                printf("Name:");

                //fgets reads a limited amt of characters.
                fgets(IdOfUser, 100, stdin);

                //We do length of string of IdOfUser -1
                IdOfUser[strlen(IdOfUser) - 1] = '\0';

                //The string below is printed.
                printf("Phone_Number:");

                //fgets reads a limited amt of characters.
                fgets(level, 100, stdin);

                //We do length of string of level -1
                level[strlen(level) - 1] = '\0';

                //This prints the string below.
                printf("Order_Number:");

                //Allows for the user to input a value for order number.
                scanf("%d", &Order_Number);
                //takes into account for item, IdOfUser, Order_Number, and level
                hashInsert(item, IdOfUser, Order_Number, level);

                //we use break to exit out the loop.
                break;
            //Second case is for searching the item.
            case 2:
                //This prints the string below.
                printf("Enter the item to search:");

                //This is so the user can input a value for the item.
                scanf("%d", &item);

                //This is to search the selected item.
                hashSearch(item);

                //we use break to exit out the loop.
                break;
            //Third case is for deleting the item.
            case 3:

                //Prints the string below
                printf("Enter the item to perform deletion:");

                //This is so the user can input a value for the item.
                scanf("%d", &item);

                //This is to delete the selected item.
                hashDelete(item);

                //we use break to exit out the loop.
                break;

                //Fourth case is for when the customer wants to finalize the order.
            case 4:
                printf("Thank you for ordering we will let you know when your items are ready.");
            //we set the default case as exit in case user chooses a number not from 1-4
            default:

                exit(0);
        }
    }
}

