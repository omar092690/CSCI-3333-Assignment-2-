//***********************************************************************************
// CSCI 3333 Spring 2026
// Instructor: Dr. Andres Figueroa
// Programming Assignment 2: Movies Dataset using BST
// Student Name and SID#:
//
//***********************************************************************************

#include <iostream>
#include <string>
#include <fstream>

#include "BST.h"

using namespace std;


int main()
{
    //create an empty BST object
    BinarySearchTree bst;

    string inputFilename;
    cout << "Enter the input filename: ";
    cin >> inputFilename;
    
    ifstream inFile(inputFilename); //open and read inoput text file
    string line;
    string rest;
    string id;
    string title;
    string region;
    int pos = 0;

    if (!inFile.is_open())
    {
        cout << "Unable to open the input file";
        system("pause");
        exit(1);
    }
    // each line in the input file must be a tab delimited string
    // in the format: id<tab>title<tab>region
    // reading and inserting one movie at the time
    while (getline(inFile, line))
    {
        pos = (int)line.find('\t');
        id = line.substr(0,pos); //get the first pos characters from line
        rest = line.substr(pos+1); //copy the rest of the string from position pos
        pos = (int)rest.find('\t');
        title = rest.substr(0,pos); //get the first pos characters from rest
        region = rest.substr(pos+1, 2); //get the following two characters from position pos+1
        //inserting an item into the BST
        bst.insert(id, title, region);
    }
    inFile.close();
        
    cout << "\nThe input file contains " << bst.size()
        << " movie titles. A corresponding BST was created. Repeated records were discarted.\n";
    cout << "The height of the the BST is: " << bst.height() << endl;
    cout << "The balance factor of the BST is: " << bst.balanceFactor() << endl;
    cout << "The height of the left subtree is: " << bst.leftHeight() << endl;
    cout << "The height of the right subtree is: " << bst.rightHeight() << endl;
    bst.longestPath();

    //parsing file name from file extension
    pos = (int)inputFilename.find('.');
    string filename = inputFilename.substr(0,pos);

    //name of outputfile for inorder
    string outputFilename = filename + "-inorder.txt";
    ofstream outFile(outputFilename);
    cout << "\n\nPrinting the BST in-order. The output is saved in the file: "
        << inputFilename << "-inorder.txt\n";
    if (outFile.is_open()) {
        bst.inOrder(outFile);
    }
    else{
        cerr << "Error creating output file." << endl;
    }
    outFile.close();
    
    
    return 0;
}
