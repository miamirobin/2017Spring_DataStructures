/*
Author: yochi
Last update: 5/20/2017
Department: Design and Verification lab
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <string>
#include <stdlib.h> 
#include "binTree.h"
#include <cassert>
#include <cmath>
using namespace std;

vector<string> tokens;

/* define when we stop to read input*/
string readUntil(ifstream& ifs, char end) {
    std::string str;
    char c;
    while (!ifs.eof()) {
        ifs.get(c);
        str += c;
        if (c == end) break;
    }
    return str;
}

/* split the input if encounter "-", "(" , ")"  */
vector<string> split(const string& str, const string& sep) {
    unsigned n = str.size();
    vector<string> vec;
    string token;
    for (unsigned i = 0; i < n; ++i) {
        if (sep.find(str[i]) == string::npos) {
            token += str[i];
        } else if (token.size() > 0) {
            vec.push_back(token);
            token.clear();
        }
    }
    if (token.size() > 0)
        vec.push_back(token);
    return vec;
}

/* read the input and parse them into vector */
void parse(const std::string& filename) {
    ifstream ifs(filename.c_str());
    string str;
    
    while (!ifs.eof()) {
        str = readUntil(ifs, '\n');
        tokens = split(str, " -()\t");
        unsigned n = tokens.size();
        for (int i=0;i<n;i++){
           // cout<<tokens[i]<<endl;
        }

    }
    ifs.close();
}

int main( int argc, char** argv )
{
   
    /*read in tree.txt and print out it by the required way */
    parse(argv[1]);
    BinarySearchTree b;
    for (int i=0;i<tokens.size();i++){
        int q=stoi(tokens[i]);
        b.insert(q);
    }
    cout<<"step (2) printTree(T):"<<endl;
    cout<<" "<<endl;
    b.printTree();
    cout<<" "<<endl;
    
    
    
    /* read in op.txt*/
    vector<string> vecA;
    ifstream ffin(argv[2]);
    string x;
    while (ffin >> x)
    {
        vecA.push_back(x);
        
    }
    ffin.close();
    
    vector<int> vecH[2];
    
    /* construct a vector to count the frequency of 0~9, respectively */
    vector<int> count;
    for (int i=0;i<10;i++){
        count.push_back(0);
    }
    
    
     /* construct a vector to store the input number */
    vector<int> file;
        for (int i=0;i<100;i++){
            
            for (int j=0;j<vecA[i].size();j++){
                int p=int(vecA[i][j])-48;
                file.push_back(p);  // store the input number
                count[p]+=1;        // counter update
            }
        }
    
     /* construct a vector to store 0~9 */
        vector<int>vecB;
        for (int i=0;i<10;i++){
            vecB.push_back(i);
        }
    
    
      /* change the order by the frequency of number */
      /* the number with highest frequency become first element*/
        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                if(count[vecB[i]]>=count[vecB[j]] ){
                    int temp=vecB[j];
                    vecB[j]=vecB[i];
                    vecB[i]=temp;
                }
            }
        }
    
    
    
      /*  insert the key by the order of frequency */
        BinarySearchTree b1;
        for (int i=0;i<vecB.size();i++){
            int q=vecB[i];
            b1.insert(q);
        }
    
        /*   print out the tree*/
        cout<<"step (5) printTree(T’):"<<endl;
        cout<<" "<<endl;
        b1.printTree();
        cout<<" "<<endl;
        int sum=0;
        cout<<"Ordinary BST      ";

    
        /* use sum to count the cumulative comparisons of Ordinary BST */
        for (int i=0;i<file.size();i++){
            sum+=b1.search(file[i]);
            
            if ((i+1)%50==0){                       // print out the sum for every 50 inputs
                cout<<"("<<i+1<<", "<<sum<<") ";
            }
        }
        cout<<" "<<endl;
        
    
    
       /*  use sum1 to count the cumulative comparisons of Sply Tree */
        int sum1=0;
        cout<<"Splay Tree        ";
        for (int i=0;i<file.size();i++){
            sum1+=b1.search(file[i]);
            b1.SplaySearch(file[i]);         // call SplaySearch after each search
            
            if ((i+1)%50==0){                      // print out the sum for every 50 inputs
                cout<<"("<<i+1<<", "<<sum1<<") ";
        
            }
        }
       cout<<" "<<endl;
       cout<<" "<<endl;
       cout<<"step (7) printTree(T’):"<<endl;
       cout<<" "<<endl;
       b1.printTree();                 //print out the final SPlay Tree


    
    
    
    
    
}
