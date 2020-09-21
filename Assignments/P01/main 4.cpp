


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
//       Example implementation of an array based stack that holds        //       integers.
//
// Usage:
//       Nothing special right now.
//
// Files:            
//       None
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <string>
#include <fstream> 
#include <ctime>
#include <time.h>
#include <cmath>
#include<climits>
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
     *    Calls the function full to 
     *    see if the stack is full
     * Params:
     *    int : data
     * 
     * Returns:
     *     Void
     */
    void Push(int data)
     {
        top++;              // move top of stack up
        size++;             // increment size
        S[top] = data;      // add item to array

       Full();              //Calling the function full
                            //to see if the stack is full
     

      //  if(capacity == 0)
      //  {
      //    capacity = 10;
      //    return capacity;
      //  }
      //  if(capacity > 10)
      //  {
      //  capacity = capacity * 2;
      //  return capacity;
      //  }

    
   

		
  }

  

    /**
     * Pop:
     *    remove item from stack.
     *    If the stack is below half full 
     *    then the stack goes down to 
     *    half the size.
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
               // send item back

      if(size < capacity/2)
    {
      int * S2 = new int[capacity/2];
        
     ///Allocate new array twice as big
			// Copy data from S to S2
			for (int i = 0;i < capacity/2;i++)
		   {
			 	S2[i] = S[i];
			 }
       delete[] S;

			// // Point S to new array
			 S = S2;
       
  

    }
    //return
    return data; 
       
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
     *    if stack is full then the stack doubles
     *    and copies the values over. 
     * Params:
     *    void
     * 
     * Returns:
     *     void
     */
    void Full() 
    {   
        //checks to see if the stack is full
        if(top == capacity - 1)
        {
         //allocating the new memory of the array and 
        //doubling the size of the original array
        int * STwo = new int [2*size];
        

    

        //copying each stack value into the new array
        for(int i = 0; i < size * 2; i++)
        {
          STwo[i] = S[i]; 
        }

        //deleting the old array
        delete [] S;

        //copying the old array to
        //the new array
        S = STwo;

        //double the size of the stack
        size = 2*size;
        }



        
        
    }
    /**
     * getSize:
     *    used to return the size of the stack
     * Params:
     *    void
     * 
     * Returns:
     *     int
     */    

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
     * getCapacity:
     *    used to return the capacity of the stack
     * Params:
     *    void
     * 
     * Returns:
     *     int
     */    

int GetCapacity()
  {
    return capacity;
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
// struct Person {
//     string fname;
//     string lname;
//     int age;

//     Person();
//     Person(string, string, int);

//     friend ostream &operator<<(ostream &os, const Person p) {
//         os << p.fname << "," << p.lname << " : " << p.age << endl;
//         return os;
//     }
// };

/**
 * Constructor:
 *    Constructs the person structure
 * Params:
 *    void
 * 
 * Returns:
 *     void
 */   
// Person::Person() {
//     fname = "";
//     lname = "";
//     age = 0;
// }

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
// Person::Person(string f, string l, int a) {
//     fname = f;
//     lname = l;
//     age = a;
// }

int main()
 {
   //opeining the input file and output file
    ifstream fin;
    fin.open("input.txt");

    ofstream fout;
	fout.open("output.txt");

   //declaring the variables 
   int max_size = INT_MIN;
   int value;
   string action;

    Stack S1;           // calls default constructor
    Stack S2(10);       // calls overloaded constructor
   
  fout << "Name: Savanna Dodson" << '\n';
  fout << "Program: P01" << '\n';
  fout << "Date: 16 September 2020" << '\n';
   
    
    // S1.Push(7);
    // S1.Push(4);
    // S1.Push(8);
    // S1.Push(2);
    // S1.Push(7);
    // S1.Push(4);
    // S1.Push(8);
    // S1.Push(2);
    // S1.Push(8);
    // S1.Push(2);
    
    //printing out the start size of the stack
    fout << "Start size : " << S1.GetCapacity() << endl;
    while (!fin.eof())
	{
    //reading in push or pop
		fin >> action; 
    
    //if the command is push then it will do things
		if (action == "push") 
		{
      fin >> value;
			S1.Push(value);
			// S.increaseSize();
			//curr_size++;

     

			
		}
    //if the command is pop then it will do these actions
		else if (action == "pop") //if command = pop
		{
      //lets you know if the stack is empty/nothing is in it
			if(S1.Pop() == -1)
      {
        fout << "stack is empty! \n";
      }

			

			//fout << "-" << " : " << curr_size << " -> "
			//<< curr_size_pop << endl;
		}
    

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
//prints out the maximum size of the stack
//and prints the ending size of stack
     fout<< "Max size : " << max_size << endl;
      fout<< "Ending size : " << S1.getSize()<<endl;

  //closes the input and output file
  fin.close();
	fout.close();
 }
