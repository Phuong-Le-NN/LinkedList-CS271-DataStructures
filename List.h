//========================================================
// Matt Kretchmar
// November 2023
// List.h
// This file contains the List class declaration.  
//========================================================

#include <iostream>
#include <string>
using namespace std;

#ifndef LIST_H
#define LIST_H

template <class T> 
class List
{
private:
	// struct for Node for linked list
	struct Node
	{
		T		item;
		Node 	*next;
	};
	
	Node	*head;		// the pointer for the linked list
	
public:
			List		( void );
			List		( const List<T> &mylist );
		   ~List		( void );
List<T>		operator=	( const List<T> &mylist );
string		to_string	( void ) const;	
void		insert		( const T &item	);
T &		operator[]	( int index );
void		remove		( int index );
List<T>		operator+	( const List<T> &mylist ) const;
int		length		( void ) const;
bool		isEmpty		( void ) const;
void		clear		( void );
bool 		contains    (const T &item ) const;
bool		operator==    (const List<T> &mylist) const;
bool		operator<=    (const List<T> &mylist) const;

friend ostream & operator<< ( ostream &os, List<T> &mylist )
{
	Node *ptr = mylist.head;
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


#include "List.cpp"

#endif


