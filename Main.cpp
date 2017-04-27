#include <iostream>

using namespace std;

#undef NULL

const int  NULL = 0;

// The following is a typedef statement and it is used for repetition
// Range-checking data validation for the element data tye.
typedef int element;

// TO DO: Change into a Char #
//const element SENTINEL = 1;
// Creating a constant that takes a single character "#" to be 
// programmed as sentinel variable. 
const char SENTINEL = '#';

// Prototype for a basic repetition type-checking dat validation
// Functions.
element read_element();

// Creating a class called listnode that will be the basic blueprint
// Of the public listings: Data type element of variable data.
// Also, the listnode pointing to the next address of another listnode.
class listnode {
        public:
                element data;
                listnode * next;
        };

// Creating a class called LList that will be the main blueprint of
// two different sections: private and public.
class LList {
        private:
                // listnode pointing to the head section of the data
                listnode * head;

                // listnode pointing to the tail section of the data
                listnode * tail;
        public:
                // The constructor of the LList that will have a PRE 
                // condition of none. Also, a POST condition of valid
                // and empty.
                LList();

                // The Destructor of the LList that will have a valid
                // PRE condition. Also, a POST condition of valid and 
                // empty and the listnodes will be deleted.
                ~LList();

                // This is the void Menu method that will display the 
                // different commands and actions that the user has to 
                // decided on.
                void Menu();

                // This is the void EnterVigesimal method that will be 
                // called after pressing the command action "e" to enter
                // elements of numbers in.
                void EnterVigesimal();

                // This is the void AddVigesimal method that will be called
                // after pressing the command action "a" to add the current
                // number will a new vigesimal number entered.
                void AddVigesimal();

                // This is the void MultiplyVigesimal method that will be
                // called after pressing the command action "m" to multiply
                // the current number and another number entered by the user.
                void MultiplyVigesimal();

                // This is the void HelpCommand method that will be called
                // after pressing the command action "h" to display the other
                // options of commands within the program. The user will be
                // prompted to press h at the beginning of the program to 
                // assist the user.
                void HelpCommand();


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

// Inside my main man, main.
int main() {

        // 
        LList L;

        // Display the version of the vigesimal calculator and end the line.
        cout << "Vigesimal Calculator, Version 1.0" << endl;

        // Display the year with the programmers name and end the line.
        cout << "(c) 2017, Brandon Hartman" << endl;

        // Method call the function Menu from the LList class.
        L.Menu();
}


element read_element() {

//      int  userval;
        // Create a variable 
        char userval;

//      cin >> boolalpha >>  userval;
        cin >> userval;

        while (! cin.good()) {

                cin.clear();
                cin.ignore(80, '\n');

                cout << "Invalid data type, should be an element" << endl;
                cout << "Try again: ";

//              cin >> boolalpha >> userval;
                cin >> userval;
        }

        return userval;
}

LList::LList() {
        // PRE: none
        // POST: The N. O. LList is valid and empty

        head = NULL;
        }


LList::~LList() {
        // PRE: The N. O. LList is valid
        // POST: The N. O. LList is valid and empty, and its listnodes
        //       have been deleted.

        Clean();
        }

void LList::Menu() {

//      int  userInput;
        char userCharValue;
        int userInput;

        userInput = 0;
        
        cout << "Current vigesimal number is: ";
//      Print();
        cout << "Command (h for help): ";

        userCharValue = read_element();
        userInput = userCharValue;

        if ((userInput == 101) || (userInput == 69))
                EnterVigesimal();

        else if ((userInput == 97) || (userInput == 65))
                AddVigesimal();

        else if ((userInput == 109) || (userInput == 77))
                MultiplyVigesimal();

        else if ((userInput == 104) || (userInput == 72))
                HelpCommand();

        else if ((userInput == 113) || (userInput == 81))
                // Quit the program
                cout << "Finishing Vigesimal Calculator, version 1.0";
        else
                cout << "Invalid input. Please try again." << endl;
                Menu();
        }

void LList::EnterVigesimal() {

        }

void LList::AddVigesimal() {

        cout << "Adding a new vigesimal number to the current vig. number."
                << endl;

        cout << "Adding completed." << endl;
        }

void LList::MultiplyVigesimal() {

        cout << "Multiplying a new vigesimal number by the current vig."
                << " number." << endl;

        cout << "Multiplying completed." << endl;
        }

void LList::HelpCommand() {

        // Display a prompt for the Valid Commands and end the line
        cout << "Valid commands are:" << endl;

        // Display a prompt for "e" to be assigned as enter and that
         // the user can enter the current number and end the line.
        cout << "   e   enter     enter the current vigesimal number"
                << " from the keyboard" << endl;

        // Display a prompt for "a" to be assigned as "Add" and that 
        // the user can add a new number to the current vig. number
        // and end the line.
        cout << "   a   add       add a new vigesimal number to the"
                << " current vig. number" << endl;

        // Display a prompt for "m" to be assigned as "Multiply" and
        // that the user can multiply a new number to 
        cout << "   m   multiply  multiply a new vigesimal number by"
                << " the current vig. number" << endl;

        cout << "   h   help      show this help menu" << endl;

        cout << "   q   quit      quit the program" << endl;

        Menu();
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
        cout << "Enter element, " << SENTINEL << " to stop: ";
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
