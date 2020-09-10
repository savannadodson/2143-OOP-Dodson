///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Author:           Savanna Dodson
// Email:            smdodson1105@my.msutexas.edu
// Label:            A01
// Title:            Comments
// Course:           CMPS 2143
// Semester:         Fall 2020
//
// Description:
//       This program uses Lists and makes it possible to add to the list,
//       remove from the list, insert a value into the list, print the last
//       number in the list, and print the list.
//
//
// Usage:
//       how to use the program if necessary
//
// Files:
//       main.cpp    : driver program
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

int A[100]; //declaring the array of 100

struct Node
{
    int x;
    Node *next;
    Node()
    {
        x = -1;
        next = NULL;
    }
    Node(int n)
    {
        x = n;
        next = NULL;
    }
};
    /**
    * Class Name: List
    *
    * Description:    This class can push values, insert values, pop values, and print the list
    *
    *
    * Public Methods:
    *                             List()
    *      void                Push(int val)
    *      void                Insert(int val)
    *      void                PrintTail()
    *      int                   pop()
    *      int                   operator[ ] (int index)
    *
    *
    * Private Methods:
    *      Node              *Head
    *      Node              *Tail
    *      int                    Size
    *
    * Usage:
    *
    *      L1.Push(i);                                  //put values into the list
    *
    *      L1.PrintTail();                              //print the tail of the List
    *
    *
    *
    */

class List
{
  private:
    Node *Head; //pointer for the beginning of the list
    Node *Tail; //pointer for the end of the list
    int Size;   //the number of how many values are in the list

  public:
    List()
    {
        Head = Tail = NULL;
        Size = 0;
    }
    
    /**
    * Public : Push
    *
    * Description:
    *      Adds new values to the top of the stack.
    *
    * Params:
    *
    *      int     :  value added to the stack
    *
    * Returns:
    *            - the list with the new added value
    */

    void Push(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        if (!Head && !Tail) //
        {
            Head = Tail = Temp;
        }
        else
        {
            Tail->next = Temp;
            Tail = Temp;
        }
        Size++;
    }

    /**
    * Public : Insert
    *
    * Description:
    *     Adds a value into anywhere in the list.
    *
    * Params:
    *
    *      int     :  value inserted into the stack
    *
    * Returns:
    *            - the list with the new added value
    */

    void Insert(int val)
    {
        // allocate new memory and init node
        Node *Temp = new Node(val);

        // figure out where it goes in the list

        Temp->next = Head;
        Head = Temp;
        if (!Tail)
        {
            Tail = Head;
        }
        Size++;
    }
    /**
    * Public : PrintTail
    *
    * Description:
    *      Prints the last value of the List.
    *
    * Params:
    *
    *      NONE
    *
    * Returns:
    *            - the last value of the list.
    */

    void PrintTail()
    {
        cout << Tail->x << endl;
    }

    string Print()
    {
        Node *Temp = Head;
        string list;

        while (Temp != NULL)      //if the List is not empty then print the list
        {
            list += to_string(Temp->x) + "->";
            Temp = Temp->next;
        }

        return list;
    }

    // not implemented
    int Pop()
    {
        Size--;
        return 0;
    }

    List operator+(const List &Rhs)
    {
        // Create a new list that will contain both when done
        List NewList;

        // Get a reference to beginning of local list
        Node *Temp = Head;

        // Loop through local list and Push values onto new list
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Get a reference to head of Rhs
        Temp = Rhs.Head;

        // Same as above, loop and push
        while (Temp != NULL)
        {
            NewList.Push(Temp->x);
            Temp = Temp->next;
        }

        // Return new concatenated version of lists
        return NewList;
    }

    // Implementation of [] operator.  This function returns an
    // int value as if the list were an array.
    int operator[](int index)
    {
        Node *Temp = Head;

        if (index >= Size)
        {
            cout << "Index out of bounds, exiting";
            exit(0);
        }
        else
        {

            for (int i = 0; i < index; i++)
            {
                Temp = Temp->next;
            }
            return Temp->x;
        }
    }

    friend ostream &operator<<(ostream &os, List L)
    {
        os << L.Print();
        return os;
    }
};

int main(int argc, char **argv)
{
    List L1; //declaring the first List
    List L2; //declaring the second List

    //adding 25 values to a list
    for (int i = 0; i < 25; i++)
    {
        L1.Push(i);
    }
    //adding 50 values to the list
    for (int i = 50; i < 100; i++)
    {
        L2.Push(i);
    }

    //cout << L1 << endl;
    L1.PrintTail();
    L2.PrintTail();

    //List 3 is List One and Two combined
    List L3 = L1 + L2;
    cout << L3 << endl;
    
    //printing out the value at position 5 of the third List
    cout << L3[5] << endl;
    return 0;
}
