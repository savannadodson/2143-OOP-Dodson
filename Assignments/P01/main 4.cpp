///////////////////////////////////////////////////////////////////////////////
//                   
// Author:           Savanna Dodson
// Email:            smdodson1105@my.msutexas.edu
// Label:            L02
// Title:            Array Based Stack Example
// Course:           2143
// Semester:         Fall 2020
//
// Description:
//       Example implementation of an array based stack that holds integers.
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
using namespace std;

/**
 * Stack
 * 
 * Description:
 *      Integer array based stack implementation
 * 
 * Public Methods:
 *      - Stack()
 *      - Stack(int)
 *      - void Push()
 *      - int Pop()
 *      - bool empty()
 *      - bool full()
 *      - void Print()
 * 
 * Private Methods:
 *      - None
 * 
 * Usage: 
 * 
 *  Stack S;
 *  S.Push(80);
 *  S.Push(90);
 *  S.Print();
 *  int x = S.Pop();
 *      
 */
class Stack {
private:
    int *S;       //array pointer
    int capacity; //max stack size
    int top;      //current top (index)
    int size;     //current num items
public:
    /**
     * Stack:
     *    Constructor.
     * Params:
     *    void
     * 
     * Returns:
     *     Void
     */
    Stack() {
        capacity = 10;          // set array size
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Stack:
     *    Constructor.
     * Params:
     *    int : capacity
     * 
     * Returns:
     *     Void
     */
    Stack(int cap) {
        capacity = cap;         // set array size      
        S = new int[capacity];  // allocate new memory
        top = -1;               // initialize top of stack
        size = 0;               // set stack to empty
    }

    /**
     * Push:
     *    Push item onto stack.
     * Params:
     *    int : data
     * 
     * Returns:
     *     Void
     */
    void Push(int data) {
        top++;              // move top of stack up
        size++;             // increment size
        S[top] = data;      // add item to array
    }

    /**
     * Pop:
     *    remove item from stack.
     * Params:
     *    void
     * 
     * Returns:
     *     int
     */
    int Pop() {
        int data = S[top];  // pull item from stack
        top--;              // shrink the stack
        size--;             // update our size
        return data;        // send item back
    }

    /**
     * Empty:
     *    is the stack empty?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is empty
     */
    bool Empty()
     {
       //if the stack is empty, it returns -1
       //in the main it will read -1 and print that
       //the stack is full
        if(top == -1)
        {
          return -1;
        }
        //if the stack is full, return false
        //the return of false will print in main 
        //that the stack is full
        return false;
        
    }

    /**
     * Full:
     *    is the stack full?
     * Params:
     *    void
     * 
     * Returns:
     *     bool : true == stack is full
     */
    bool Full() 
    {
        if(top == capacity - 1)
        {
         //allocating the new memory of the array and 
        //doubling the size of the original array
        int * STwo = new int [2*size];
        

    

        //copying each stack value into the new array
        for(int i = 0; i < size; i++)
        {
          STwo[i] = S[i]; 
        }

        //deleting the old array
        delete [] S;

        //copying the old array to
        //the new array
        S = STwo;

        size = 2*size;
        }
       
        return top == capacity - 1;
        
    }


    int getSize()
    {
      return size;
    }
    /**
     * Print:
     *    Used so we can inspect our stack.
     * Params:
     *    void
     * 
     * Returns:
     *     void
     */    
    void Print() {
        for (int i = top; i >= 0; i--) {
            cout << S[i] << endl;
        }
    }

    /**
     * Overloaded ostream <<
     *    Lets us print a stack using cout
     * Params:
     *    ostream &os   : instance of ostream passed in by reference
     *    const Stack   : instance of stack passed in using const so 
     *                    it cannot be changed
     * 
     * Returns:
     *     ostream 
     */
    friend ostream &operator<<(ostream &os, const Stack s) {
        os << "Overloaded!!" << endl;
        for (int i = s.top; i >= 0; i--) {
            os << s.S[i] << endl;
        }
        return os;
    }
};

/**
 * Person
 * 
 * Description:
 *      Example struct that represents a person.
 * 
 * Usage: 
 * 
 *  Person P1;
 * 
 *  P1.fname = "firstName";
 *  P1.lname = "lastName";
 *  P1.age = 99
 *  cout<<P1<<endl;
 * 
 *  Person P2("billy","bob",11);
 *  cout<<P2<<endl;
 */
struct Person {
    string fname;
    string lname;
    int age;

    Person();
    Person(string, string, int);

    friend ostream &operator<<(ostream &os, const Person p) {
        os << p.fname << "," << p.lname << " : " << p.age << endl;
        return os;
    }
};

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    void
 * 
 * Returns:
 *     void
 */   
Person::Person() {
    fname = "";
    lname = "";
    age = 0;
}

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    string    : first name
 *    string    : last name
 *    int       : persons age
 * 
 * Returns:
 *     void
 */ 
Person::Person(string f, string l, int a) {
    fname = f;
    lname = l;
    age = a;
}

int main() {
    Stack S1;           // calls default constructor
    Stack S2(25);       // calls overloaded constructor

    S1.Push(7);
    S1.Push(4);
    S1.Push(8);
    S1.Push(2);
    S1.Push(7);
    S1.Push(4);
    S1.Push(8);
    S1.Push(2);
    S1.Push(8);
    S1.Push(2);
    //prints if the stack is full or not
    if (S1.Empty() == false)
    {
      cout << "The Stack is full!";
    }
    else
    {
      cout << "Error: The stack is empty! ";
    }
    
    S1.Print();
    //gets the size of the first array
    cout << "The size is: " << S1.getSize() << '\n';
    S1.Full();
    S1.Print();
    //gets the size of the new array after it is doubled
    cout << "The size is: " << S1.getSize() << '\n';

//     cout << "Popped a: " << S1.Pop() << endl;
//     cout << "Popped a: " << S1.Pop() << endl;
    
//     S1.Push(9);

//     //S1.Print();           // old way to print!
//     cout << S1 << endl;     // cool way to print

//     Person P1;              // calls default constructor (no params)

//     P1.fname = "suzy";      // adds values to person P1
//     P1.lname = "queue";
//     P1.age = 14;

//     cout << P1 << endl;     // calls overloaded ostream method

//     Person P2("dudley", "doowright", 30);   // uses overloaded constructor

//     cout << P2 << endl;     // calls overloaded ostream method
}
