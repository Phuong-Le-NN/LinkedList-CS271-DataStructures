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
// Pre condition: Nothing
// Post condition: This function sets head pointer to NULL
// Parameters: none
// Return value: none
//==========================================================================
template  <typename T> 
        Set<T>::Set		( void )
{
	head = NULL;
}
//==========================================================================
// Copy constructor: this function create a new set identical to an existing one.
// Pre condition: A Set object
// Post condition: A second Set object identical to the original
// Parameters: the set to copy from
// Return value: none
//==========================================================================
template  <typename T> 
        Set<T>::Set		( const Set<T> &myset )
{
	head = NULL;
	//Node * ptr = head;
	Node * ptr2 = myset.head; //node for iteration
	T i;
	
	while ( ptr2 != NULL) //iterate through list
	{
		
		i = ptr2->item; //get item
		insert(i);
		ptr2 = ptr2->next; //traverse list
		
	}
}
//==========================================================================
// Destructor
// This function cleans up the memory of the set.
// Pre: A Set object to be deleted
// Post: The memory used to hold the Set object is released
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
// Pre: Two Set objects on both sides of the operator
// Post: The Set object on the left side of the operator takes on the value of the object on theright side
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
		this->insert(i); //add each item to list
		ptr2 = ptr2->next;
		
	}
	//return
	return *this;
}

//==========================================================================
// Insert Method
// This function adds a new item onto the end of the set.
// Pre: A Set object and an item whos datatype is the same as the rest of the list to be appended
// Post: The item is added to the front of the list
// Parameters: An element of the same data type
// Return value: none
//==========================================================================
template  <typename T>
void		Set<T>::insert		( const T &item	)
{
	if (this->contains(item) == true)
		return;
	// Step 1: create new memory for new link
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
// Pre: A Set Object
// Post: The item at position i is returned
// Parameters: the position
// Return value: the element
//==========================================================================
template  <typename T> 
T &		Set<T>::operator[]	( int index )
{
	if (index >= cardinality()  || index < 0)
	{
		cout << "Error: index out of range" << endl; //account for out of bounds error
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
// Pre: A Set object and an item to be searched for and removed
// Post: The target item is removed from the list
// Parameters: the position
// Return value: none
//==========================================================================
template  <typename T>
void		Set<T>::remove		( T item )
{   if(head == NULL) //account for empty list
		return;
	if (head->item == item) //case when item is first in the list
	{
		Node* temp = head->next; //make next item new head
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
	Node *temp = ptr->next->next;//create link between the items around the item to be removed
	delete ptr->next;
	ptr->next = temp;
}
//==========================================================================
// Operator+ method
// This function creates the union of two sets.
// Pre: Two Set objects on both side of the operator
// Post: elements in the union set should be consistent with elements of the set on the right hand side of the operator 
// being inserted into the empty set followed by the elements the set on the left hand side of the operator
// Parameters: second set passed in by reference
// Return value: the new set
//==========================================================================
template  <typename T>
Set<T>		Set<T>::operator+	( const Set<T> &myset ) const
{
	
	Set<T> l4; // make new list to be added to
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
// Cardinality Method
// This function returns the number of items in the set.
// Pre: A Set object 
// Post: The amount of items in set is returned
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
		count ++; //counts while iterating
		ptr = ptr->next;
	}
	return count;
}
//==========================================================================
// Empty method
// This function returns true if the set is empty, false otherwise.
// Pre: A Set object 
// Post: a boolean value telling if the set is empty or not
// Parameters: none
// Return value: true if the function is empty and false otherwise
//==========================================================================
template  <typename T>
bool		Set<T>::empty	( void ) const
{
	return head == NULL; //if head is empty the whole list is empty
}
//==========================================================================
// Clear method
// This function removes all items from the set.
// Pre: A Set object to be cleared
// Post: The Set object is now empty
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
// Contains method
// This function tells if a certain item is present in a set
// Pre: A Set object and an item to be searched for
// Post: A boolean value telling if the item is in the set or not
// Parameters: An item passed by refrence
// Return value: Boolean value
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
			if(check->item == myitem){ //linear search for item
				return true;
			}
			check = check->next;	
		}
		if(check->item == myitem){ //check last item
				return true;
			}
		
		return false;
	}
}
//==========================================================================
// Operator ==
// This operator checks if 2 sets are identical.
// Pre: Two set objects on both sides of the operator
// Post: A boolean value telling if the two sets are identical
// Parameters: A Set object passed by reference
// Return value: Boolean value
//==========================================================================
template  <typename T>
bool        Set<T>::operator==    (const Set<T> &myset)	const
{
	if(myset.cardinality() != this->cardinality()){ //accounts for mismatched length and avoids out of bounds error
		return false;
	}
	if(myset.head == NULL)
	{
		return true;
	}
	Node * check = myset.head;
	while (check->next != NULL){
		if(this->contains(check->item) == false){//iterate through list and check if each item is in other list
			return false;
		}
		check = check->next;
		
	}
	return true;
}

//==========================================================================
// Operator <=
// This operator checks if the set on the left side of the operator is a subset of the set on the right side
// Pre: Two set objects on both sides of the operator
// Post: A boolean value telling if the set on the left is a subset of the right side
// Parameters: A Set object passed by reference
// Return value: Boolean value
//==========================================================================
template  <typename T>
bool	Set<T>::operator<=    (const Set<T> &myset)	const
{	if(head == NULL)
		return true;
	if(myset.cardinality() < this->cardinality()){ //right hand set must be equal size or bigger
		return false;
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
// Operator &
// This operator returns the intersection of two sets
// Pre: Two set objects on both sides of the operator
// Post: The intersection of the two sets is returned; Ordering of elements in the intersection 
// set should be consistent with inserting elements of the set on the left hand side of the operator into an empty set
// Parameters: A Set object passed by reference
// Return value: Set object containing the intersection of the two sets
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
			if(myset.contains(check->item) == 1){//inserts common items into new set
				ret.insert(check->item);
			}
			check = check->next;
		}
		if(myset.contains(check->item) == 1){ //check last item
				ret.insert(check->item);
			}
	return ret;
}
//==========================================================================
// Operator -
// This operator returns the difference of two sets
// Pre: Two set objects on both sides of the operator
// Post: The difference of the two sets is returned; Ordering of elements
// in the difference set should be consistent with inserting elements of the set on the left hand side of the operator into an empty set
// Parameters: A Set object passed by reference
// Return value: Set object containing the difference of the two sets
//==========================================================================
template  <typename T>
Set<T>		Set<T>::operator-	( const Set<T> &myset ){
	Set<T> ret; //new set to be returned
	if(head == NULL)
	{
		return ret;
	}
		Node * check = head;
		while (check->next != NULL){
			if(myset.contains(check->item) == 0){ //check for values only in left hand side
				ret.insert(check->item);
			}
			check = check->next;
		}
		if(myset.contains(check->item) == 0){
				ret.insert(check->item);
			}
	return ret;
}
//==========================================================================
// To_string method
// This function converts the Set object to a string
// Pre: A Set object 
// Post: A String object thats contains the values in the set with spaces between them is returned
// Parameters: none
// Return value: A String object
//==========================================================================
template  <typename T>
string		Set<T>::to_string	( void ) const{
	string s = "";
	if (head == NULL)
	{
		return s;
	}
	Node * check = head;
		while (check->next != NULL){
			
			s = s + std::to_string(check->item) + " "; //typecast to avoid errors
			check = check->next;
		}
		
		s = s + std::to_string(check->item);

	return s;
}
