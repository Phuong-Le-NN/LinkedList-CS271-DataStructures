//==================================================
// Phuong Le
// List.cpp
// December 2023
// The method definitions for the Linked List Class
//==================================================

#include <string>
#include <iostream>
#include "List.h"

using namespace std;

//------------------------------------
// define List class
//------------------------------------


//==========================================================================
//Default constructor
// This function set head pointer to NULL
// Parameters: none
// Return value: none
//==========================================================================
template  <typename T> 
        List<T>::List		( void )
{
	head = NULL;
}
//==========================================================================
//copy constructorThis function create a new list identical to an existing one.
// Parameters: the list to copy from
// Return value: none
//==========================================================================
template  <typename T> 
        List<T>::List		( const List<T> &mylist )
{
	head = NULL;
	//Node * ptr = head;
	Node * ptr2 = mylist.head;
	T i;
	
	while ( ptr2 != NULL)
	{
		
		i = ptr2->item;
		insert(i);
		ptr2 = ptr2->next;
		
	}
}
//==========================================================================
// Destructor
// This function cleans up the memory of the list.
// Parameters: None
// Return value: none
//==========================================================================
template  <typename T> 
        	List<T>::~List		( void )
{
	clear();
}
//==========================================================================
//Assignment Construction
// This function can assign one list to another.
// Parameters: An object of list class passed in by reference
// Return value: the calling object
//==========================================================================
template  <typename T> 
List<T>		List<T>::operator=	( const List<T> &mylist )
{
	//delete
	clear();
	//copy
	head = NULL;
	//Node * ptr = head;
	Node * ptr2 = mylist.head;
	T i;
	
	while ( ptr2 != NULL)
	{
		
		i = ptr2->item;
		this->insert(i);
		ptr2 = ptr2->next;
		
	}
	//return
	return *this;
}

//==========================================================================
//Insert Method
// This function adds a new item onto the end of the list.
// Parameters: An element of the same data type
// Return value: none
//==========================================================================
template  <typename T>
void		List<T>::insert		( const T &item	)
{
	if (this->contains(item) == true)
		return;
	// Step 1: creat new memory for new link
	Node * ptr = new Node;
	
	// Step 2: put data into data field of new link
	ptr->item = item;
	
	// Step 4: set new link pointing to the rest of the list
	ptr->next = head;
	
	// Step 3: insert ptr to the appropriate place
	{
		ptr->next = head;
		head = ptr;
	}
}
//==========================================================================
//Operator []
// This function accesses (by reference) the element at position i.
// Parameters: the position
// Return value: the element
//==========================================================================
template  <typename T> 
T &		List<T>::operator[]	( int index )
{
	if (index >= length()  || index < 0)
	{
		cout<<"Error: index out of range"<<endl;
		exit(1);
	}
	Node *ptr = head;
	for (int i = 0; i < index; i ++)
	{
		ptr = ptr->next;
	}
	return ptr->item;
}

//==========================================================================
// Remove method
// This function removes the item at the specified position.
// Parameters: the position
// Return value: none
//==========================================================================
template  <typename T>
void		List<T>::remove		( int index )
{
	if (index >= length() || index < 0)
	{
		cout<< "Error: index out of range"<< endl;
		exit(1);
	}
	if (index == 0)
	{
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	else
	{
		Node *ptr = head;
		for ( int i = 0; i < index - 1; i++ )
		{
			ptr = ptr->next;
		}
	
		Node *temp = ptr->next;
		ptr->next = temp->next;
		delete temp;
	}
}
//==========================================================================
// Operator+ method
// This function concatenates two lists into a new list.
// Parameters: second list passed in by reference
// Return value: the new list
//==========================================================================
template  <typename T>
List<T>		List<T>::operator+	( const List<T> &mylist ) const
{
	List l3(*this);
	Node * ptr2 = mylist.head;
	T i;
	
	while ( ptr2 != NULL)
	{
		i = ptr2->item;
		if (l3.contains(i) == false)
			l3.insert(i);
		ptr2 = ptr2->next;
		
	}
	return l3;
}
//==========================================================================
// Length Method
// This function returns the number of items in the list.
// Parameters: none
// Return value: the length of the list
//==========================================================================
template  <typename T>
int		List<T>::length		( void ) const
{
	Node *ptr = head;
	int count = 0;
	while (ptr != NULL)
	{
		count ++;
		ptr = ptr->next;
	}
	return count;
}
//==========================================================================
// IsEmpty method
// This function returns true if the list is empty, false otherwise.
// Parameters: none
// Return value: true if the function is empty and false otherwise
//==========================================================================
template  <typename T>
bool		List<T>::isEmpty	( void ) const
{
	return head == NULL;
}
//==========================================================================
// Clear method
// This function removes all items from the list.
// Parameters: none
// Return value: none
//==========================================================================
template  <typename T>
void		List<T>::clear		( void )
{
	Node *ptr = head;
	while ( head != NULL)
	{
		//step 1: jump ptr ahead of head
		ptr = head->next;
		//step 2: delete head
		delete head;
		//step 3: catch up head
		head = ptr;
	}
}
//==========================================================================
// contains method
//
//
//
//==========================================================================
template  <typename T>
bool		List<T>::contains (const T &myitem)	const
{
	if (head == NULL)
	{
		return false;
	}
	else
	{
		Node * check = head;
		while (check->next != NULL) 
		{
			if(check->item == myitem){
				return true;
			}
			check = check->next;	
			if(check->item == myitem){
				return true;
			}
		}
		
		return false;
	}
}
//==========================================================================
// Operator ==
//
//
//
//
//
//===================================================
template  <typename T>
bool        List<T>::operator==    (const List<T> &mylist)	const
{
	if(mylist.length() != this->length()){
		return false;
	}
	Node * check = mylist.head;
	
	while (check->next != NULL){
		if(this->contains(check->item) == false){
			return false;
		}
		check = check->next;
		
	}
	return true;
}

//==========================================================================
// Operator <=
//
//
//
//
//
//===================================================
template  <typename T>
bool	List<T>::operator<=    (const List<T> &mylist)	const
{
	if(mylist.length() < this->length()){
		return false;
	}
	Node * check = this->head;
	
	while (check->next != NULL){
		if(mylist.contains(check->item) == false)
		{
			return false;
		}
		check = check->next;
		
	}
	return true;
}
template  <typename T>
List<T>		List<T>::operator&	( const List<T> &mylist ){
	List<T> ret;
		Node * check = head;
		while (check->next != NULL){
			if(mylist.contains(check->item) == 1){
				ret.insert(check->item);
			}
			check = check->next;
		}
	return ret;
}