//==================================================
// 
// Set.cpp
// December 2023
// The method definitions for the Linked Set Class
//==================================================

#include <string>
#include <iostream>
#include "set.h"

using namespace std;

//------------------------------------
// define Set class
//------------------------------------


//==========================================================================
// Default constructor
// This function set head pointer to NULL
// Parameters: none
// Return value: none
//==========================================================================
template  <typename T> 
        Set<T>::Set		( void )
{
	head = NULL;
}
//==========================================================================
// copy constructor this function create a new set identical to an existing one.
// Parameters: the set to copy from
// Return value: none
//==========================================================================
template  <typename T> 
        Set<T>::Set		( const Set<T> &myset )
{
	head = NULL;
	//Node * ptr = head;
	Node * ptr2 = myset.head;
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
// This function cleans up the memory of the set.
// Parameters: None
// Return value: none
//==========================================================================
template  <typename T> 
        	Set<T>::~Set		( void )
{
	clear();
}
//==========================================================================
// Assignment Construction
// This function can assign one set to another.
// Parameters: An object of set class passed in by reference
// Return value: the calling object
//==========================================================================
template  <typename T> 
Set<T>		Set<T>::operator=	( const Set<T> &myset )
{
	//delete
	clear();
	//copy
	head = NULL;
	//Node * ptr = head;
	Node * ptr2 = myset.head;
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
// Insert Method
// This function adds a new item onto the end of the set.
// Parameters: An element of the same data type
// Return value: none
//==========================================================================
template  <typename T>
void		Set<T>::insert		( const T &item	)
{
	if (this->contains(item) == true)
		return;
	// Step 1: creat new memory for new link
	Node * ptr = new Node;
	
	// Step 2: put data into data field of new link
	ptr->item = item;
	
	// Step 4: set new link pointing to the rest of the set
	ptr->next = head;
	
	// Step 3: insert ptr to the appropriate place
	{
		ptr->next = head;
		head = ptr;
	}
}
//==========================================================================
// Operator []
// This function accesses (by reference) the element at position i.
// Parameters: the position
// Return value: the element
//==========================================================================
template  <typename T> 
T &		Set<T>::operator[]	( int index )
{
	if (index >= cardinality()  || index < 0)
	{
		cout << "Error: index out of range" << endl;
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
void		Set<T>::remove		( int item )
{   if(head == NULL)
		return;
	if (head->item == item)
	{
		Node* temp = head->next;
		delete head;
		head = temp;
		return;
	}
	if (head->next == NULL)
	{
		return;
	}
	Node *ptr = head;
	while (ptr->next != NULL && ptr->next->item != item)
	{	
		ptr = ptr->next;
	}
	if (ptr->next == NULL)
	{
		return;
	}
	Node *temp = ptr->next->next;
	delete ptr->next;
	ptr->next = temp;
}
//==========================================================================
// Operator+ method
// This function concatenates two sets into a new set.
// Parameters: second set passed in by reference
// Return value: the new set
//==========================================================================
template  <typename T>
Set<T>		Set<T>::operator+	( const Set<T> &myset ) const
{
	
	Set<T> l4;
	Node * ptr2 = myset.head;
	T i;
	while ( ptr2 != NULL)
	{	
		//makes the 2nd set backwards(inserts all elements)
		i = ptr2->item;
		l4.insert(i);
		ptr2 = ptr2->next;	
	}
	ptr2 = this->head;
	while ( ptr2 != NULL)
	{	
		//checks 1st set for values not present in 2nd set and inserts them
		i = ptr2->item;
		if (l4.contains(i) == false)
			l4.insert(i);
		ptr2 = ptr2->next;	
	}
	return l4;
}
//==========================================================================
// Length Method
// This function returns the number of items in the set.
// Parameters: none
// Return value: the length of the set
//==========================================================================
template  <typename T>
int		Set<T>::cardinality		( void ) const
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
// This function returns true if the set is empty, false otherwise.
// Parameters: none
// Return value: true if the function is empty and false otherwise
//==========================================================================
template  <typename T>
bool		Set<T>::empty	( void ) const
{
	return head == NULL;
}
//==========================================================================
// Clear method
// This function removes all items from the set.
// Parameters: none
// Return value: none
//==========================================================================
template  <typename T>
void		Set<T>::clear		( void )
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
bool		Set<T>::contains (const T &myitem)	const
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
		}
		if(check->item == myitem){
				return true;
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
//==========================================================================
template  <typename T>
bool        Set<T>::operator==    (const Set<T> &myset)	const
{
	if(myset.cardinality() != this->cardinality()){
		return false;
	}
	if (myset.head == NULL)
	{
		return true;
	}
	Node * check = myset.head;
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
//==========================================================================
template  <typename T>
bool	Set<T>::operator<=    (const Set<T> &myset)	const
{	if(head == NULL)
		return true;
	if(myset.cardinality() < this->cardinality()){
		return false;
	}
	if(head == NULL)
	{
		return true;
	}
	Node * check = this->head;
	while (check->next != NULL){
		if(myset.contains(check->item) == false)
		{
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
//==========================================================================
template  <typename T>
Set<T>		Set<T>::operator&	( const Set<T> &myset ){
	Set<T> ret;
	if(head == NULL)
	{
		return ret;
	}
		Node * check = head;
		while (check->next != NULL){
			if(myset.contains(check->item) == 1){
				ret.insert(check->item);
			}
			check = check->next;
		}
		if(myset.contains(check->item) == 1){
				ret.insert(check->item);
			}
	return ret;
}
//==========================================================================
// Operator <=
//
//
//
//
//
//==========================================================================
template  <typename T>
Set<T>		Set<T>::operator-	( const Set<T> &myset ){
	Set<T> ret;
	if(head == NULL)
	{
		return ret;
	}
		Node * check = head;
		while (check->next != NULL){
			if(myset.contains(check->item) == 0){
				ret.insert(check->item);
			}
			check = check->next;
		}
		if(myset.contains(check->item) == 0){
				ret.insert(check->item);
			}
	return ret;
}
template  <typename T>
string		Set<T>::to_string	( void ) const{
	string s = "";
	if (head == NULL)
	{
		return s;
	}
	Node * check = head;
		while (check->next != NULL){
			
			s = s + std::to_string(check->item) + " ";
			check = check->next;
		}
		
		s = s + std::to_string(check->item);

	return s;
}
