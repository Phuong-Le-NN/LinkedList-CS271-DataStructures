//==============================================================
// 
// November 2023
// main.cpp
// This file is a driver for the Set class.
//==============================================================

#include <iostream>
using namespace std;
#include "Set.h"

//==============================================================
// main
//==============================================================

int main ( void )
{
    Set<int> s1;

    s1.insert(1);
    s1.insert(2);
    s1.insert(2);
    Set<int> s2 = s1;
    Set<int> s3;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
	
    s1.insert(2);
    cout << "s1 = " << s1 << endl;
    cout << "ls.length() = " << s1.length() << endl;
    
    s2.insert(100);
    
    s1[1] = 10;
    cout << "s1 = " << s1 << endl;
    cout << "s1.length() = " << s1.length() << endl;

    //s2.remove(0);
    cout << "s1 = " << s1 << endl;
    cout << "s1.length() = " << s1.length() << endl;

    s3 = s2 + s1;
    cout << "s3 = s2 + s1 = " << s3 << endl;
    cout << "s3.length() = " << s3.length() << endl;


    //l2.clear();
    //cout << "l2.clear() = " << l2 << endl;
    //cout << "l2.length() = " << l2.length() << endl;
    //cout << "l2 = " << l2 << endl;

    // Test the "doubling" ability of the set
    Set<char> s5;
    for ( char c = 'a'; c <= 'g'; c++ )
        s5.insert(c);
    Set<char> s6 = s5;
    for ( char c = 'h'; c <= 'z'; c++ )
        s5.insert(c);
    Set<char> s7 = s5;
    s5.remove(19);

    cout << "s5 = " << s5 << endl;
    cout << "s6 = " << s6 << endl;
    cout << "s7 = " << s7 << endl;
    //test for contains
    int result; 
    result = s2 <= s1;
    cout << "s2 <= l1: " << result << endl;

    return 0;


}
