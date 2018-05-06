#include <stdio.h>
#include <string.h>
#include "IntVector.h"
#include <stdlib.h>

int main ()
{
	printf ("Testing int vector new:\n");	

	printf ("\nClear mass with 5 elements\n");
	IntVector *mass = int_vector_new ( 5 );
	vector_print ( mass );

	printf ("---Int vector new test complete\n\n");

	printf ("Testing vector set item:\n");

	int_vector_set_item ( mass, 0, 8);
	int_vector_set_item ( mass, 1, 57);
	int_vector_set_item ( mass, 2, 1646);
	printf ("\nOther elements are empty\n");
	vector_print ( mass );

	printf ("\n---Vector set item test complete\n\n");

	printf ("Testing int vector copy:\n");

	IntVector *copy = int_vector_copy ( mass );
	vector_print ( copy );

	printf ("\n---Int vector copy test complete\n\n");

	printf ("Testing int vector get size & int vector get capacity:\n");

	printf ("Vector size is: %lu\n", int_vector_get_size ( mass ));
	printf ("Vector capacity is: %lu\n", int_vector_get_capacity ( mass ));

	printf ("---Int vector get size & int vector get capacity test complete\n\n");

	printf ("Testing int vector shrink to fit\n");

	int_vector_shrink_to_fit ( mass );
	printf ("Vector size after function is: %lu\n", int_vector_get_size ( mass ));
	printf ("Vector capacity after function is: %lu\n", int_vector_get_capacity ( mass ));

	printf ("---Int vector shrink to fit test complete\n\n");

	printf ("Testing int vector free");

	int_vector_free ( &mass );
	vector_print ( mass );

	printf ("---Int vector free test complete\n\n");

	printf ("Testing int vector pop back:\n");

	mass = int_vector_new ( 5 );

	int_vector_set_item ( mass, 0, 17);
	int_vector_set_item ( mass, 1, 369);
	int_vector_set_item ( mass, 2, 4);
	int_vector_set_item ( mass, 3, 146);

	vector_print ( mass );
	int_vector_pop_back ( mass );
	printf ("\nMass after pop back:\n");
	vector_print ( mass );

	printf ("\n---Vector pop back test complete\n\n");

	printf ("Testing int vector get item & int vector resize:\n");
	
	int_vector_get_item ( mass, 0);
	int_vector_get_item ( mass, 1);
	int_vector_get_item ( mass, 2);
	
	printf ("Start resizing\n");
	int_vector_resize ( mass, 7);
	printf ("Mass after resizing\n");
	vector_print ( mass );

	printf ("\n---Int vector get item & int vector resize test complete\n\n");

	printf ("Testing int vector push back:\n");

	printf ("\nSize: %lu\n", mass -> size);
	printf ("Capacity: %lu\n", mass -> capacity);
	
	int_vector_push_back ( mass, 1);
	vector_print ( mass ); 
	printf ("Capacity after vector push back: %lu\n", mass -> capacity);
	printf ("Size after vector push back: %lu\n", mass -> size);

	printf ("---Int vector push back test complete\n\n");

	printf ("Testing int vector reserve:\n");
	
	printf ("Capacity: %lu\n", mass -> capacity);
	int_vector_reserve ( mass, 17);
	printf ("Capacity after vector reserve: %lu\n", mass -> capacity);
	
	printf ("---Int vector reserve test complete\n\n");	
	printf ("-----ALL TEST ARE COMPLETE!!!\n");

	return 0;
}