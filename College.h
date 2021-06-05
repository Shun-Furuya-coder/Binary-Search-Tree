// Specification file for the College class
// Written By: A. Student
// Changed By: Shun Furuya
// IDE: Xcode

#ifndef COLLEGE_H
#define COLLEGE_H

  
#include<string>

using std::string;
using std::ostream;

class College; // Forward Declaration

// Function Prototypes for Overloaded Stream Operators
ostream &operator << (ostream &, const College &);

class College
{
    private:
        /* Write your code here */
        string code;
        string name;
        int rank;
        int cost;

    public:
        //constructors
        /* Write your code here */
        College();
        College(int, string, string, int);
    
        //setters
         /* Write your code here */
        void setCode(string cd){ code = cd;}
        void setName(string nm){ name = nm;}
        void setRank(int rk){ rank = rk;}
        void setCost(int cs){ cost = cs;}

        //getters
        /* Write your code here */
        string getCode() const {return code;}
        string getName() const {return name;}
        int getRank() const {return rank;}
        int getCost() const {return cost;}

        //other functions if any
        /* Write your code here */
        void hDdisplay()const;
        void vDisplay()const;
    
        // overloaded operators
         /* Write your code here */
        bool operator < (const College &);
        bool operator > (const College &);
        bool operator == (const College &);
    
        // Friends
        friend ostream &operator << (ostream &, const College &);
};

#endif
