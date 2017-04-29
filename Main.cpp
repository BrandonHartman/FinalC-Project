
#include <iostream>

using namespace std;

// The #undef directive removes the current definition of NULL
#undef NULL

// Which allows the programmer to make a constant of data type 
// integer and define it as NULL and assign zero to it.
const int  NULL = 0;

// The following is a typedef statement and it is used for repetition
// Range-checking data validation for the element data tye.
typedef int element;

// TO DO: Change into a Char #
//const element SENTINEL = 1;
// Creating a constant that takes a single character "#" to be 
// programmed as sentinel variable. 
const char SENTINEL = '#';

// Prototype for a basic repetition type-checking data validation
// Functions.
element read_element();

// Prototype for a basic repetition type-checking data validation
// functions.
char read_char();

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

                // The Destructor of the LList that will have a valid // PRE condition. Also, a POST condition of valid and 
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

                // This is the void Quit program that will be called
                // after pressing the command "q" to quit the program in 
                // all.
                void QuitProgram();

                // PRE: The N. O. LList is valid  POST: The N. O. LList
                //  is unchanged, and its elements have been displayed
                void Print();

                // PRE: The N. O LList is valid
                // POST: The N. O. LList is unchanged, except that a new
                // listnode containing element thing has been inserted
                // at the head end of the list
                void InsertHead(element thing);

                // PRE: The N. O. LList is valid
                // POST: The N. O. LList is unchanged, except that a new
                // listnode containing element thing has been inserted
                // at the tail end of the lsit.
                void InsertTail(element thing);

                // PRE: The N. O. LList is valid and not empty
                // POST: The N. O. LList is unchanged, except that the listnode
                // at the head end of the list has been deleted, and its
                // data element has been returned
                element DeleteHead();

                // PRE: The N. O. LList is valid
                // POST: The N. O. LList is valid, all of its previous listnodes
                // have been deleted, and it now consists of new listnodes
                // containing elements given by the user in forward order.
                void ReadForward();

                // PRE: The N. O. LList is valid
                // POST: The N. O. LList is valid, all of its previous listnodes
                // have been deleted, and it now consists of new listnodes
                // containing elements given by the user in backward order.
                void ReadBackward();

                // PRE: The N. O. LList is valid
                // POST: The N. O LList is valid and empty, and all of its
                // listnodes have been deleted.
                void Clean();

                // PRE: The N. O. and Victim LLists are valid
                // POST: The Victim LList is valid and empty
                // the N. O. LList is valid, all of its previous listnodes
                // have been deleted, and it now consists of the listnodes
                // originally on the Victim LList
                void Steal(LList & Victim);

                // PRE: The N. O. and the Soure LLists are valid
                // POST: The Source LList is unchanged
                // the N. O. LList is valid, all of its previous listnodes
                // have been deleted, and it now consists of listnodes
                // containing the same elements and in the same order
                // as on the Source LList
                void Duplicate(LList & Source);

                // PRE: The N. O.LList is valid
                // POST: The N. O. LList is unchanged, except its elements are
                // in reverse order.
                void Reverse();
        };
// Inside my main man, main.
int main() {


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
        // Create a variable named userval and assign the data type as
        // a char.
        char userval;

//      cin >> boolalpha >>  userval;
        // Get the user's input and assign that to the userval character.
        cin >> userval;

        // While the user's input is not good
                // Clear the input
                // Ignore 80 characters of code and newlines
                // Display the input entered was invalid and to try again.
                // Get user's input and assign it to the userval.
        // Return the userval.
        while (! cin.good()) {

                cin.clear();
                cin.ignore(80, '\n');

                cout << "Invalid data type, should be an character" << endl;
                cout << "Try again: ";

//              cin >> boolalpha >> userval;
                cin >> userval;
        }

        return userval;
}

// ----------------READ_CHAR TEST
char read_char() {

    // PRE:  the user must enter a series of zero or more
    //       non-valid int values, followed by a valid int value
    //
    // POST: all entered non-valid int values will be successfully
    //       discarded, and the first valid int value entered will
    //       be returned

    char userval;    // used to collect the user's input value

    // attempt to get an input value whose data type is an char
    cin >> userval;

    // repeat the following as long as this attempt failed,
    // presumably because the data type of the user's input was
    // not an int
    while (! cin.good()) {

        // re-enable the just-disabled cin object
        cin.clear();

        // from the input buffer, discard up to 80 keystrokes
        // or until the enter key is seen, whichever comes
        // first
        cin.ignore(80, '\n');

        // tell the user what happened, and to try again
        cout << "Invalid data type, should be a whole "
             << "number, try again: ";

        // attempt to get an input value whose data type is an
        // char
        cin >> userval;
    }
 // return the valid char value given by the user
    return userval;
}

// LList calls LList to make a constuctor within the program
LList::LList() {

        // PRE: none
        // POST: The N. O. LList is valid and empty

        // Assign NULL to the head
        head = NULL;
        }

// LList calls LList to make a destructor within the program.
LList::~LList() {
        // PRE: The N. O. LList is valid
        // POST: The N. O. LList is valid and empty, and its listnodes
        //       have been deleted.

        // Call the Clean method. 
        Clean();
        }

// The Menu that the users will be able to interact with  
void LList::Menu() {

        // Create a variable defined as the currentVigNumber and
        // assign it to zero and the data type is char.
        char currentVigNumber = 0;

        // Display the Current vigesimal number and show what the
        // current number is.
        cout << "Current vigesimal number is: "<< currentVigNumber ;

        // Display that the Command (h for help)
        cout << "Command (h for help): ";

        // Declare and define the char userval.
        char userval;

        // Run userval through the read_char which does data validation
        // for the input.
        userval = read_char();

        // Head into a if/esle statement for the menu options.
        //      if userval equals 'e' OR 'E'
        //              Head into the EnterVigesimal method
        //      else if userval equals 'a' OR 'A'
        //              Head into the AddVigesimal method
        //      else if userval equals 'm' OR 'M' 
        //              Head into the MultiplyVigesimal method
        //      else if userval equals 'h' OR 'H'
        //              Head into the HelpCommnad method
        //      else if userval equals 'q' OR 'Q"
        //              Head into the QuitProgram method
        //      else
        //              Display input was invalid and to try again.
        //              Head into the Menu method

        if ((userval == 'e') || (userval == 'E'))
                EnterVigesimal();
//              Menu();
        else if ((userval == 'a') || (userval == 'A'))
                AddVigesimal();
//              Menu(); 
        else if ((userval == 'm') || (userval == 'M'))
                MultiplyVigesimal();
//              Menu(); 
        else if ((userval == 'h') || (userval == 'H'))
                HelpCommand();
        else if ((userval == 'q') || (userval == 'Q'))
                QuitProgram();
        else
                cout << "Invalid input. Please try again." << endl;
                Menu();
        }
// WORKING PROGRESS ON THE QUIT PROGRAM 
void LList::QuitProgram() {

        // Display Finishing Vig. Calculator, Version 1
        cout << "Finishing Vigesimal Calculator, Version 1.0";
        return;
        }
// WORKING PROGRESS ON THE ENTERPROGRAM
void LList::EnterVigesimal() {

        char currentVigNum = 0;

        // Display a prompt allowing the user to type in characters until
        // the user puts in the sentinel and end the line.
//      cout << "Enter a vigesimal number, followed by " << SENTINEL
//              << ": " << endl;

        // Call the ReadBackward method to use it's functions
        ReadBackward();

        // Display that the entering is completed. 
        cout << "Entering completed.";
        }


void LList::AddVigesimal() {



        // Display that the program is adding a new vig.number to the 
        // current vig. number and end the line.
        cout << "Adding a new vigesimal number to the current vig. number."
                << endl;

        // Display that the adding is completed and end the line.
        cout << "Adding completed." << endl;
          }

void LList::MultiplyVigesimal() {

        LList Helper;
        // Display a prompt that tells the user to multiplying a new vig.
        // number by the current vig. number and end the line.
        cout << "Multiplying a new vigesimal number by the current vig."
                << " number." << endl;
        Helper.ReadBackward();
        // Display that the Multiplying is completed and end the line.
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
        // that the user can multiply a new number by the current vig.
        // number and end the line.
        cout << "   m   multiply  multiply a new vigesimal number by"
                << " the current vig. number" << endl;

        // Display a prompt for 'h' to be assigned as the help command
        // and once pressed will show the menu.
        cout << "   h   help      show this help menu" << endl;

        // Display a prompt for the 'q' to be assigned as the program
        // will end and quit the calc.
        cout << "   q   quit      quit the program" << endl;

//      Menu();
        }

void LList::Print() {

        // PRE: The N. O. LList is valid
        // POST: The N. O. LList is unchanged, and its elements
        //       have been displayed

        // temp is pointing to listnode
        listnode * temp;

        // temp is equaled to head
        temp = head;

        // While temp is not NULL
        //      Print temp pointing point to data and end the line
        //      temp is now assigned to what was temp pointing to 
        //              the next memory address. 
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

        // temp is pointing to listnode
        listnode * temp;

        // Temp is assigned as a new creating listnode
        temp = new listnode;

        // temp points to the data that is equaled to thing
        temp -> data = thing;

        // temp points to the next part of the listnode that is 
        // equaled to the head.
        temp -> next = head;

        // if head is equaled to NULL
        //      tail and temp are assigned together
        // else
        //      return nothing
        // Head and temp are assigned together
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

        // temp is pointing to listnode 
        listnode * temp;

        // A new listnode is created and declared and defined as temp
        temp = new listnode;

        // temp is a pointer to data that is declared and define as thing
        temp -> data = thing;

        // temp is a pointer to next that is declared and defined as NULL
        temp -> next = NULL;

        // if head is equaled to NULL
        //      head and temp are assigned together
        // else 
        //      tail is a pointer to next that is declared and designed 
        //      as temp.
        // Tail and temp are assigned together.
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

        // temp is pointing to a listnode
        listnode * temp;

        // a element data type defined as thing is created.
        element thing;

        // temp and head are assigned together
        temp = head;

        // Head is defined as a head pointer to next
        head = head -> next;

        // Thing is defined as a temp pointer to data
        thing = temp -> data;

        // DESTROY temp by deleting it
        delete temp;
        // Return thing
        return thing;
        }

//==========================STILL ELEMENTS NOT CHARS
void LList::ReadForward() {

        // PRE: The N. O. LList is valid
        // POST: The N. O. LList is valid, all of its previous listnodes
        //       have been deleted, and it now consists of new listnodes
        //       containing elements given by the user in forward order.

        // Declare and define a element data type variable called 
        // userval
        element userval;

        // Call the Clean method that wipes it of all data.
        Clean();

        cout << "Enter a vigesimal number, followed by " << SENTINEL
                 << ": ";
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

//      element  userval;
        // Declare and define a char data type called userval
        char userval;

        // Call the clean method that wipes it clean of data.
        Clean();

        // Display a prompt that tells the user to enter in vig. 
        // numbers and the sentinel to end.
        cout << "Enter a vigesimal number, followed by " << SENTINEL
                 << ": ";

        // user's input will go through data validation to make sure
        // correct data is going through the program
        userval = read_char();

        // while userval is not the sentinel
        //      call the InsertHead method with the parameters of userval
        //      user vall goes through data validation
        
        while (userval != SENTINEL) {
                InsertHead(userval);
                userval = read_char();
                }
        }

void LList::Clean() {

        // PRE: The N. O. LList is valid
        // POST: The N. O LList is valid and empty, and all of its
        //       listnodes have been deleted.

        // while head is not NULL
        //      Method DeleteHead is called     
        while (head != NULL)
                DeleteHead();
        }

void LList::Steal(LList & Victim) {

        // PRE: The N. O. and Victim LLists are valid
        // POST: The Victim LList is valid and empty
        //       the N. O. LList is valid, all of its previous listnodes
        //       have been deleted, and it now consists of the listnodes
        //       originally on the Victim LList

        // Method clean is called and wipes it clear of data and junk
        Clean();

        // Victim.head is assigned as the head.
        head = Victim.head;

        // Victim.tail is assigned as tail
        tail = Victim.tail;

        // Vicitm.Head is assigned as NULL
        Victim.head = NULL;
        }

void LList::Duplicate(LList & Source) {

        // PRE: The N. O. and the Soure LLists are valid
        // POST: The Source LList is unchanged
        //       the N. O. LList is valid, all of its previous listnodes
        //       have been deleted, and it now consists of listnodes
        //       containing the same elements and in the same order
        //       as on the Source LList

        // temp is pointing to a listnode
        listnode * temp;

        // Method Clean is called to wipe all the data away
        Clean();

                // Source.head is assigned as temp
        temp = Source.head;

        // while temp is not NULL
        //      InsertTail is called with the parameters of temp pointer to
        //      data
        //      temp pointer to next is assigned as temp
        while (temp != NULL) {
                InsertTail(temp -> data);
                temp = temp -> next;
                }
        }



void LList::Reverse() {

        // PRE: The N. O.LList is valid
        // POST: The N. O. LList is unchanged, except its elements are
        //       in reverse order.

        // temp pointing to a listnode
        listnode * temp;

        // Class LList declares and defines a helper
        LList Helper;

        // temp and head are assigned as the same
        temp = head;

        // While temp is not NULL
        //      Helper.InsertHead is called with the arguments of temp as
        //      a pointer to data.
        //      the pointer to temp points to next and is assigned as temp
        // Method call Steal with the parameters of the Helper
        while (temp != NULL) {
                Helper.InsertHead(temp -> data);
                temp = temp -> next;
                }
        Steal(Helper);
        }
