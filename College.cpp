 /* Write your code here */

#include <iostream>
#include <iomanip>
#include <string>

#include "College.h"

using namespace std;

//**************************************************
// Constructor
//**************************************************
College::College()
{
    rank = -1;
    code = "";
    name = "";
    cost = -1;
}

//**************************************************
// Overloaded Constructor
//**************************************************
College::College(int rk, string cd, string nm, int ct)
{
    rank = rk;
    code = cd;
    name = nm;
    cost = ct;
}

//***********************************************************
// Displays the values of the College object member variables
// on one line (horizontal display)
//***********************************************************
void College::hDdisplay() const
{
    cout << left;
    cout << " " << setw(4) << code << "  ";
    cout << " " << setw(2) << rank << "  ";
    cout << " " << setw(27)<< name << "  ";
    cout << right;
    cout << " " << setw(7) << cost << " ";
    cout << left << endl;
}

//***********************************************************
// Displays the values of the College object member variables
// one per line (vertical display)
//***********************************************************
void College::vDisplay() const
{
    cout << "              Rank: " << rank << endl;
    cout << "       School Name: " << name << endl;
    cout << "Cost of Attendance: $" << cost << endl;
}

// overloaded operators
/* Write your code here to define the following oveloaded operator:
    - the stream insertion operator ( << )
 */


// This function is for comparing the value of code
// If right value is bigger, return true
bool College::operator < (const College &right)
{
    bool status = false;
    
    if(code < right.code){
        status = true;
    }
    return status;
}

// This function is for comparing the value of code
// If right value is smaller, return true
bool College::operator > (const College &right)
{
    bool status = false;
    
    if(code > right.code){
        status = true;
    }
    return status;
}

// This function is for comparing the value of code
// If right value is same to left, return true
bool College::operator == (const College &right)
{
    bool status = false;
    
    if(code == right.code){
        status = true;
    }
    return status;
}

// This function is for display the values
ostream &operator << (ostream &strm, const College &obj)
{
    cout << left;
    cout << " " << setw(4) << obj.code << "  ";
    cout << " " << setw(2) << obj.rank << "  ";
    cout << " " << setw(27)<< obj.name << "  ";
    cout << right;
    cout << " " << setw(7) << obj.cost << " ";
    cout << left << endl;
    
    return strm;
}
