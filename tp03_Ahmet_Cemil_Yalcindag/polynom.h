/*
 * polynom.h
 *
 *  Created on: 29 Feb 2024
 *      Author: pinar
 */

#ifndef POLYNOM_H_
#define POLYNOM_H_

struct polynom {
	int factor;
	int degree;
	struct polynom *next;
};

/* parametre olarak sayi kadar dugume sahip bir liste olusturur
 * dugumdeki katsayi degerleri rasgele uretilip atanir
 * dereceler ise 0'dan basalayarak length-1'e kadar gider */
struct polynom* create_random_list(int length);

/* Polinomu su formatta ekrana bastirir:
 * Ornek: 3*x^0 + 2*x^1 + 4*x^2 */
void print_polynom(struct polynom *head);

/* Parametre olarak aldigi listenin uzunlugunu hesaplayip
 * dondurur */
int get_length(struct polynom *list);

/* Listede yer alan en buyuk katsayili dugumu bulup dondurur */
struct polynom* get_element_max_factor(struct polynom *head);

/* Listede yer alan en buyuk dereceli dugumu bulup dondurur */
struct polynom* get_element_max_degree(struct polynom *head);

/* Verilen dizi elemanlarindan liste olusturup dondurur.
 * Ornek: dizi[4] = {1,0,3,0}
 * liste = 1*x^0 + 0*x^0 + 3*x^2 + 0*x^0
 * Dizi eleman degeri 0 olsa da bunu liste
 * icerisinde bir eleman ile gosterin. */
struct polynom* array_to_list(int *array, int length);

#endif /* POLYNOM_H_ */
