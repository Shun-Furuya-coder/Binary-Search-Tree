#include "BinarySearchTree.h"  // BST ADT
#include "College.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>

using namespace std;

/* Write your code here */
void buildBST(const string &filename, BinarySearchTree<College> &);

void hDisplay(College &);
void vDisplay(College &);
void iDisplay(College &, int);

int main()
{
    string filename;
    BinarySearchTree<College> bst;

    cout << "What is the input file's name? ";
    cin >> filename;
     /* Write your code here: build the BST from an input file  */
    buildBST(filename, bst);
     
    char option;
    cout << "Display Inorder [Y/N]? ";
    cin >> option;
    if (option == 'y' || option == 'Y')
    {
        cout << endl << "Inorder: " << endl;
        /* Write your code here: use hDisplay */
        bst.inOrder(hDisplay);
        
        cout << endl;
    }
    cout << "Display Indented List [Y/N]? ";
    cin >> option;
    if (option == 'y' || option == 'Y')
    {
        cout << "Indented List: " << endl;
        /* Write your code here: use iDisplay */
        bst.printTree(iDisplay);
        
        cout << endl;
    }
    cout << "Display Leaf Nodes [Y/N]? ";
    cin >> option;
    if (option == 'y' || option == 'Y')
    {
        cout  << "Leaf Nodes: " << endl;
        /* Write your code here: use hDisplay */
        bst.printLeaf(hDisplay);
        
        cout << endl;
    }

   /* Write your code here: test driver for search (See previous homeowrk assignments  */
    string target = "";
    College aCollege;
    cout << "\n Search\n";
    cout <<   "=======\n";
    cin.ignore();
    
    while(toupper(target[0]) != 'Q'){
        
        cout << "\nEnter a college code (or Q to stop searching) : \n";
        getline(cin, target, '\n');

        if(toupper(target[0]) != 'Q')
        {
            transform(target.begin(), target.end(),target.begin(), ::toupper);
            College targetCollege;
            targetCollege.setCode(target);
            if(bst.search(targetCollege, aCollege))
                aCollege.vDisplay();
            else
                cout << "College \"" << target << "\" was not found in this list." << endl;
        }
    }
    cout << "___________________END SEARCH SECTION _____\n";
   
    return 0;
}

/* Write your code here */
void buildBST(const string &filename, BinarySearchTree<College> &bst)
{
    ifstream fin(filename);

    if(!fin)
    {
        cout << "Error opening the input file: \""<< filename << "\"" << endl;
        exit(EXIT_FAILURE);
    }

    string line;
    while (getline(fin, line))
    {
       int rank, cost;
       string code, name;
    
       stringstream temp(line);   // create temp with data from line
       temp >> rank;              // read from temp
       temp >> code;
       temp.ignore();             // to ignore space in front of name
       getline(temp, name, ';');  // stop reading name at ';'
       temp >> cost;
       // create a College object and initialize it with data from file
       College aCollege(rank, code, name, cost);
       bst.insert(aCollege);
    }

    fin.close();
}

/*
 horizontal display: all items on one line
*/
void hDisplay (College &item)
{
    cout << left;
    cout << " " << setw(4) << item.getCode() << "  ";
    cout << " " << setw(2) << item.getRank() << "  ";
    cout << " " << setw(27)<< item.getName() << "  ";
    cout << right;
    cout << " " << setw(7) << item.getCost() << " ";
    cout << left << endl;
}

/*
 vertical display: one item per line
*/
void vDisplay (College &item)
{
    cout << "              Rank: " << item.getRank() << endl;
    cout << "       School Name: " << item.getName() << endl;
    cout << "Cost of Attendance: $" << item.getCost() << endl;
}

/*
 indented tree display: one item per line, including the level number
*/
void iDisplay(College &item, int level)
{
    for (int i = 1; i < level; i++)
        cout << "..";
    cout << level << "). " << item.getCode() << endl;
}

