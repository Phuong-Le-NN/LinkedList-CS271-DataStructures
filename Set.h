//========================================================
// 
// November 2023
// Set.h
// This file contains the Set class declaration.  
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef SET_H
#define SET_H

template <class T> 
class Set
{
private:
	// struct for Node for linked set
	struct Node
	{
		T		item;
		Node 	*next;
	};
	
	Node	*head;		// the pointer for the linked set
	
public:
			Set		( void );
			Set		( const Set<T> &myset );
		   ~Set		( void );
Set<T>		operator=	( const Set<T> &myset );
string		to_string	( void ) const;	
void		insert		( const T &item	);
T &		operator[]	( int index );
void		remove		( int index );
Set<T>		operator+	( const Set<T> &myset ) const;
int		length		( void ) const;
bool		isEmpty		( void ) const;
void		clear		( void );
bool 		contains    (const T &item ) const;
bool		operator==    (const Set<T> &myset) const;
bool		operator<=    (const Set<T> &myset) const;
Set<T>		operator&	( const Set<T> &myset );
Set<T>		operator-	( const Set<T> &myset );
friend ostream & operator<< ( ostream &os, Set<T> &myset )
{
	Node *ptr = myset.head;
	os << "[ ";
	while ( ptr != NULL )
	{
		if ( ptr->next != NULL )
			os << ptr->item << ", ";
		else
			os << ptr->item << " ";
		ptr = ptr->next;
	}
	os << "]";
	return os;	
}


};


#include "Set.cpp"

#endif


