#include <stdio.h>
#include <stdlib.h>
#include "IntVector.h"

IntVector *int_vector_new(size_t initial_capacity)
{
    IntVector *mass = malloc ( sizeof ( IntVector ) );
	if (mass == NULL) {
	    printf ("\nInt_vector_new failed");
		return NULL;
	}

	mass -> capacity = initial_capacity;
	mass -> begin = malloc ( mass -> capacity * sizeof ( int ) );	
	if (mass -> begin == NULL) {
		printf ("\nInt_vector_new failed");
		return NULL;
	}
	mass -> size = 0;
    printf ("\nReady\n");
	return mass;
}

IntVector *int_vector_copy(const IntVector *v)
{
	IntVector *mass = malloc ( sizeof ( IntVector ) );
	if (mass == NULL) {
		printf ("\nint_vector_copy failed");
		return NULL;
	}
	mass -> capacity = v -> capacity;	

	mass -> begin = malloc ( v -> capacity * sizeof ( int ) );
	if ( mass -> begin == NULL) {
		printf ("\nint_vector_copy failed");
		return NULL;
	}

	for ( size_t i = 0; i < v -> capacity; i++) {
		mass -> begin [i] = v -> begin [i];
	}

	mass -> size = v -> size; 	
	return mass;
}

void int_vector_free (IntVector **v)
{
	free ( (*v) -> begin );
	free ( *v );
	printf ("\nMemory is clear");
	*v = NULL; 
}

int int_vector_get_item (const IntVector *v, size_t index) 
{
	if ( index > v -> capacity - 1 ) {
		printf ("\nint_vector_get_item failed");
		return 0;
	}
	return v -> begin [index];
}

void int_vector_set_item (IntVector *v, size_t index, int item)
{
	if (index > v -> capacity - 1) {
		printf  ("\nint_vector_set_item failed");
		return;
	}
	
	v -> size ++;

	v -> begin [index] = item;
}
size_t int_vector_get_size(const IntVector *v) 
{
	return v -> size;
}

size_t int_vector_get_capacity(const IntVector *v)
{
	return v -> capacity;
}

int int_vector_push_back(IntVector *v, int item)
{
	if ( v -> size + 1 < v -> capacity ) {
		v -> begin  [ v -> size] = item;
		v -> size ++;
		return 0;
	} else {
		printf ("\nExpanding vector with x2 capacity\n");

		v -> begin = realloc ( v -> begin, v -> capacity * 2 * sizeof ( int ) );
		if ( v == NULL ) {
			printf ("Error of reallocation\n");
			return -1;
		}

		v -> capacity = v -> capacity * 2;
		v -> begin [ v -> size ] = item;
		v -> size ++;
		return 0;
		}
	return -1;
}
void int_vector_pop_back ( IntVector *v )
{
	if ( v -> size == 0 ) {
		printf ("Vector size = 0");
		return;
	}

	v -> begin [ v -> size - 1] = 0;
	v -> size --;
}

int int_vector_shrink_to_fit ( IntVector *v )
{
	v -> begin = realloc ( v -> begin, v -> size * sizeof ( int ) );
	if ( v == NULL ) {
		printf ("Reallocation error");
		return -1;
	}

	v -> capacity = v -> size;

	return 0;
}

int int_vector_resize ( IntVector *v, size_t new_size )
{
	if ( new_size > v -> capacity ) {

		v -> begin = realloc ( v -> begin, new_size * sizeof ( int ) );
		if ( v == NULL) {
			printf ("Reallocation error");
			return -1;
		}

		v -> capacity = new_size;

		for ( size_t i = v -> size; i < v -> capacity; i++) {
			v -> begin [ i ] = 0;
		}

		v -> size = new_size;

		return 0;
	}

	if ( new_size > v -> size && new_size <= v -> capacity ) {
		for ( size_t i = v -> size; i < new_size; i++) {
			v -> begin [i] = 0;
		}

		v -> size = new_size;
	}

	if ( new_size < v -> size ) {
		return int_vector_shrink_to_fit ( v );
	}

	return -1;
}

int int_vector_reserve ( IntVector *v, size_t new_capacity )
{
	if ( new_capacity > v -> capacity ) {
		v -> begin = realloc ( v -> begin, new_capacity * sizeof ( int ) );
		if ( v == NULL ) {
			printf ( "Reallocation error");
			return -1;
		}

		v -> capacity = new_capacity;

		return 0;
	}else{
		printf ("New size smaller or equals then previous");
		return 0;
	}
	
	return -1;
}

void vector_print ( IntVector *v)
{
	if ( v == NULL ) {
		printf ("\nNULL\n");
		return;
	}
	
	for ( size_t i = 0; i < v -> size; i++) {
		printf ("%d ", v -> begin [i]);
	}
	printf ("\n");
}