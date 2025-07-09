/*
 * polynom.c
 *
 *  Created on: 29 Feb 2024
 *      Author: pinar
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#include"polynom.h"

/* parametre olarak sayi kadar dugume sahip bir liste olusturur
 * dugumdeki katsayi degerleri rasgele uretilip atanir
 * dereceler ise 0'dan basalayarak length-1'e kadar gider */
struct polynom* create_random_list(int length) {
	srand(time(NULL));
	struct polynom *temp = NULL;
	struct polynom *node;
	struct polynom *head;

	// ilk eleman icin bellekte yer ayirma ve ilk deger atama
	node = malloc(sizeof(struct polynom));
	if (node == NULL) {
		exit(1);
	}
	node->factor = rand() % 9 + 1;
	node->degree = 0;
	node->next = NULL;
	head = node;

	// length'e gore eleman ekleme
	for (int i = 1; i < length; i++) {
		temp = malloc(sizeof(struct polynom));
		if (temp == NULL) {
			exit(1);
		}
		temp->factor = rand() % 9 + 1;
		temp->degree = i;
		node->next = temp;
		node = temp;
	}
	node->next = NULL;
	return head;
}

/* Polinomu su formatta ekrana bastirir:
 * Ornek: 3*x^0 + 2*x^1 + 4*x^2 */
void print_polynom(struct polynom *head) {
	struct polynom *temp = head;
	printf("%d*x^%d ",temp->factor,temp->degree);
	temp=temp->next;
	while(temp)
	{
		printf("+ %d*x^%d ",temp->factor,temp->degree);
		temp=temp->next;
	}
}

/* Parametre olarak aldigi listenin uzunlugunu hesaplayip
 * dondurur */
int get_length(struct polynom *list) {
	struct polynom *temp = list;
	int i=0;
	while(temp)
	{
		i++;
		temp=temp->next;
	}
	return(i);
}

/* Listede yer alan en buyuk katsayili dugumu bulup dondurur
 * Ornek: Polinom 3*x^0 + 2*x^1 + 4*x^2 + 1*x^3
 * Donen deger: 4*x^2 */
struct polynom* get_element_max_factor(struct polynom *head) {
	struct polynom *temp = head;
	struct polynom *maxtemp=head;
	while (temp)
	{
		if(temp->factor>maxtemp->factor)
		{
			maxtemp=temp;
		}
		temp=temp->next;
	}
	return(maxtemp);
}

/* Listede yer alan en buyuk dereceli dugumu bulup dondurur
 * Ornek: Polinom 3*x^0 + 2*x^1 + 4*x^2 + 1*x^3
 * Donen deger: 1*x^3 */
struct polynom* get_element_max_degree(struct polynom *head) {
	struct polynom *temp = head;
	struct polynom *maxtemp=head;
	while (temp)
	{
		if(temp->degree>maxtemp->degree)
		{
			maxtemp=temp;
		}
		temp=temp->next;
	}
	return(maxtemp);
}

/* Verilen dizi elemanlarindan liste olusturup dondurur.
 * Ornek: dizi[4] = {1,0,3,0}
 * liste = 1*x^0 + 0*x^0 + 3*x^2 + 0*x^0
 * Dizi eleman degeri 0 olsa da bunu liste
 * icerisinde bir eleman ile gosterin. */
struct polynom* array_to_list(int *array, int length) {
	srand(time(NULL));
	struct polynom *temp = NULL;
	struct polynom *node;
	struct polynom *head;

	// ilk eleman icin bellekte yer ayirma ve ilk deger atama
	node = malloc(sizeof(struct polynom));
	if (node == NULL) {
		exit(1);
	}
	node->factor = array[0];
	node->degree = 0;
	node->next = NULL;
	head = node;

	// length'e gore eleman ekleme
	for (int i = 1; i < length; i++) {
		temp = malloc(sizeof(struct polynom));
		if (temp == NULL) {
			exit(1);
		}
		temp->factor = array[i];
		temp->degree = i;
		node->next = temp;
		node = temp;
	}
	node->next = NULL;
	return head;
}

