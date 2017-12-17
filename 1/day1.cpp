#include <iostream>

using namespace std;

class Node
{
public:
    /** Node data */
    int data;
    /** Pointer to the next node */
    Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node( int x )
    {
        data = x;
        next = NULL;
    }

};

class CircularLinkedList
{
public:
    /** Head Node of the list */
    Node* head;
    Node* tail;

    /**
     * Adds a Node to the front of the list and returns
     * the position of the added node.
     * @param n The Node to add.
     * @return the position the node was added.
     */
    int addToFront( Node* n )
    {
        int pos = 0;

        if ( head == NULL ) {
            n->next = head;
            head = n;
            pos++;
        } else {
            n->next = head;
            tail->next = n;
            head = n;
            pos++;
        }
        
        return pos;
    }

    /**
     * Returns true if head is NULL.
     * @return true if head is NULL.
    */
    bool isEmpty()
    {
        return head == NULL;
    }

    /**
     * Adds a Node to the end of the list and returns
     * the position of the added node.
     * @param n The Node to add.
     * @return the position the node was added.
     */
    void addToEnd( Node* n )
    {
        if ( head == NULL ) {
            head = n;
            tail = n;
            n->next = NULL;
        } else {
            tail->next = n;
            n->next = head;
            tail = n;
        }
    }

    /**
     * Searches for an element x and returns its Node if it exists.
     * @param x The element to search for.
     * @return the Node that contains data x, or NULL if it doesn't exist.
     */
    Node* search( int x )
    {
        Node* ptr = head;

        while ( ptr != NULL && ptr->data != x ) {
            ptr = ptr->next;
        }

        return ptr;
    }

    /**
     * Deletes the Node with data x from the list if it exists.
     * @param x The data of the Node to delete.
     * @return the Node deleted.
     */
    Node* deleteNode( int x )
    {
        // Finds the Node to delete
        Node* n = search( x );
        Node* ptr = head;
        
        if ( ptr == NULL ) {
            return NULL;
        } else if ( ptr == n ) {
            ptr->next = n->next;
            return n;
        } else {
            while ( ptr->next != n ) {
                ptr = ptr->next;
            }

            ptr->next = n->next;
            return n;
        }
    }

    /**
     * Constructor for the CircularLinkedList.
     */
    CircularLinkedList() {
        head = NULL;
        tail = NULL;
    }

};

/**
 * Main function for Day 1.
 */
int main( int argc, char* argv[] )
{
    if ( argc < 2 ) {
        cout << "You must specify an input file." << endl;
        return EXIT_FAILURE;
    }

    FILE *stream = fopen( argv[ 1 ], "r" );
    if ( stream == NULL ) {
        cout << "Invalid input file." << endl;
        return EXIT_FAILURE;
    }

    CircularLinkedList list;
    int ch;
    int sum = 0;

    while ( ( ch = getc( stream ) ) != EOF ) {
        ch = ch - '0';

        if ( list.tail != NULL && list.tail->data == ch ) {
            sum += ch;
        }

        Node* n = new Node( ch );
        list.addToEnd( n );
    }

    fclose( stream );

    if (list.tail != NULL && list.tail->data == list.head->data ) {
        sum += list.head->data;
    }

    cout << "Sum: " << sum << endl;

    // Free the memory
    /*Node* n = list.head;
    while ( n != NULL ) {
        Node* temp = n->next;
        delete n;
        n = temp;
    }*/
    return EXIT_SUCCESS;
}