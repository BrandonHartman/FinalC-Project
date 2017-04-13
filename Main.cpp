#include <iostream>

using namespace std;

#undef NULL

const int NULL = 0;

typedef int element;

const element SENTINEL = -1;

element read_element();

class listnode {
        public:
                element data;
                listnode * next;
        };

class LList {
        private:
                listnode * head;
                listnode * tail;
        public:
                LList();
                ~LList();
                void Print();
                void InsertHead(element thing);
                void InsertTail(element thing);
                element DeleteHead();
                void ReadForward();
                void ReadBackward();
                void Clean();
                void Steal(LList & Victim);
                void Duplicate(LList & Source);
                void Reverse();
        };

int main() {

        LList L;

        cout << "Object created and constructed, calling Print" << endl;
        L.Print();

        cout << "Object read forward, calling Print" << endl;
        L.ReadForward();

        cout << "Object printed, calling ReadBackward" << endl;
        L.ReadBackward();

        cout << "Object read backward, calling Print" << endl;
        L.Print();

        cout << "Object printed, calling Clean" << endl;
        L.Clean();

        cout << "Object cleaned, calling Print" << endl;
        L.Print();
        cout << "Object printed" << endl;
        }

//--------------------------READ_ELEMENT-------------------------
element read_element() {

        element userval;

        cin >> boolalpha >>  userval;

        while (! cin.good()) {

                cin.clear();
                cin.ignore(80, '\n');

                cout << "Invalid data type, should be an element";
                cout << "Try again: ";

                cin >> boolalpha >> userval;
        }

        return userval;
}
// -----------------------CONSTRUCTOR----------------------------
LList::LList() {
        // PRE: none
        // POST: The N. O. LList is valid and empty

        head = NULL;
        }

//-------------------------DESTRUCTOR-----------------------------
LList::~LList() {
        // PRE: The N. O. LList is valid
        // POST: The N. O. LList is valid and empty, and its listnodes
        //       have been deleted.

        Clean();
        }


void LList::Print() {
        // PRE: The N. O. LList is valid
        // POST: The N. O. LList is unchanged, and its elements
        //       have been displayed
        listnode * temp;

        temp = head;
        while (temp != NULL) {
                cout << temp -> data << endl;
                temp = temp -> next;
                }
        }

void LList::InsertHead(element thing) {
        // PRE: The N. O LList is valid
        // POST: The N. O. LList is unchanged, except that a new
        //       listnode containing element thing has been inserted
        //       at the head end of the list

        listnode * temp;

        temp = new listnode;
        temp -> data = thing;
        temp -> next = head;
        if (head == NULL)
                tail = temp;
        else
                ;
        head = temp;
        }

void LList::InsertTail(element thing) {
        // PRE: The N. O. LList is valid
        // POST: The N. O. LList is unchanged, except that a new
        //       listnode containing element thing has been inserted
        //       at the tail end of the lsit.

        listnode * temp;

        temp = new listnode;
        temp -> data = thing;
        temp -> next = NULL;
        if (head == NULL)
                head = temp;
        else
                tail -> next = temp;
        tail = temp;
        }

element LList::DeleteHead() {
        // PRE: The N. O. LList is valid and not empty
        // POST: The N. O. LList is unchanged, except that the listnode
        //       at the head end of the list has been deleted, and its
        //       data element has been returned
        listnode * temp;
        element thing;

        temp = head;
        head = head -> next;
        thing = temp -> data;
        delete temp;
        return thing;
        }

void LList::ReadForward() {
        // PRE: The N. O. LList is valid
        // POST: The N. O. LList is valid, all of its previous listnodes
        //       have been deleted, and it now consists of new listnodes
        //       containing elements given by the user in forward order.

        element userval;

        Clean();
        cout << "Enter element, " << SENTINEL << " to stop: ";
        userval = read_element();
        while (userval != SENTINEL) {
                InsertTail(userval);
                userval = read_element();
                }
        }
void LList::ReadBackward() {
        // PRE: The N. O. LList is valid
        // POST: The N. O. LList is valid, all of its previous listnodes
        //       have been deleted, and it now consists of new listnodes
        //       containing elements given by the user in backward order.

        element  userval;

        Clean();
        cout << "Enter elements, " << SENTINEL << " to stop: ";
        userval = read_element();
        while (userval != SENTINEL) {
                InsertHead(userval);
                userval = read_element();
                }
        }

void LList::Clean() {
        // PRE: The N. O. LList is valid
        // POST: The N. O LList is valid and empty, and all of its
        //       listnodes have been deleted.

        while (head != NULL)
                DeleteHead();
        }

void LList::Steal(LList & Victim) {
        // PRE: The N. O. and Victim LLists are valid
        // POST: The Victim LList is valid and empty
        //       the N. O. LList is valid, all of its previous listnodes
        //       have been deleted, and it now consists of the listnodes
        //       originally on the Victim LList

        Clean();
        head = Victim.head;
        tail = Victim.tail;
        Victim.head = NULL;
        }

void LList::Duplicate(LList & Source) {
        // PRE: The N. O. and the Soure LLists are valid
        // POST: The Source LList is unchanged
        //       the N. O. LList is valid, all of its previous listnodes
        //       have been deleted, and it now consists of listnodes
        //       containing the same elements and in the same order
        //       as on the Source LList

        listnode * temp;

        Clean();
        temp = Source.head;
        while (temp != NULL) {
                InsertTail(temp -> data);
                temp = temp -> next;
                }
        }

void LList::Reverse() {
        // PRE: The N. O.LList is valid
        // POST: The N. O. LList is unchanged, except its elements are
        //       in reverse order.

        listnode * temp;
        LList Helper;

        temp = head;
        while (temp != NULL) {
                Helper.InsertHead(temp -> data);
                temp = temp -> next;
                }
        Steal(Helper);
        }
                       
