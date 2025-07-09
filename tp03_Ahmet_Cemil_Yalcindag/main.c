#include <stdio.h>
#include "polynom.h"

int main(int argv, char *argc[]) {

	// create_random_list'i cagirarak bir polinom yaratin
	int length=7;
	struct polynom *polynom;
	polynom=create_random_list(length);

	// Ekrana bastirin
	printf("Polynom : ");
	print_polynom(polynom);

	// Polinomun uzunlugunu bastirin
	printf("\nLength: %d",get_length(polynom));

	// Polinomdaki en yuksek katsayili dugumu bulup ekrana bastirin
	printf("\nMax Factor: %d*x^%d",get_element_max_factor(polynom)->factor,get_element_max_factor(polynom)->degree);

	// Polinomdaki en yuksek dereceli dugumu bulup ekrana bastirin
	printf("\nMax Degree: %d*x^%d",get_element_max_degree(polynom)->factor,get_element_max_degree(polynom)->degree);

	// Bir sayi dizisi tanimlayin, bu diziyi kullanarak liste turunde
	// bir polinom yaratip ekrana bastirin
	int array[4] = {2, 4, 6 ,8};
	printf("\nNew Polynom: ");
	print_polynom(array_to_list(array, 4));

	return 0;
}
