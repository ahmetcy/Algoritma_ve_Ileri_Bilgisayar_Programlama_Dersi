/*
 * structpoint.h
 *
 *  Created on: 17 Feb 2024
 *      Author: pinar
 */

#ifndef STRUCTPOINT_H_
#define STRUCTPOINT_H_

struct Point {
	float x;
	float y;
};

/* Rectangle yapisi:
 * struct Point tipinde bir kose,
 * tamsayi tipinde genislik ve uzunluk
 * alanlarindan olusur. */
struct Rectangle {
	struct Point corner; // Kose noktasi
	int width; // Genislik
	int height; // Yukseklik
};

/* Bu fonksiyon parametre olarak aldigi iki nokta
 * arasindaki Euclide uzakligi hesaplayip dondurur. */
double distance(struct Point *a, struct Point *b);

/* Bu fonksiyon parametre olarak aldigi iki noktanin
 * ayni olup olmadigini test eder, noktalar ayni ise 1,
 * degilse 0 dondurur. */
int same_points(struct Point *p1, struct Point *p2);

/* Bu fonksiyon parametre olarak aldigi iki noktanin
 * x ve y pozisyonlarini toplar, yeni bir nokta
 * degiskenine atama yapar.
 * Ornek: girdi: p1=(1,2) p2=(3,4)
 *        cikti: p3=((1+3),(2+4)) */
struct Point sum_points(struct Point *p1, struct Point *p2);

/* Parametre olarak aldigi nokta ve dikdortgene bakip,
 * noktanin dikdortgen icinde olup olmadigini test eder.
 * Icinde ise 1, degilse 0 dondurur. */
int point_in_rectangle(struct Point *pt, struct Rectangle *r);

/* Parametre olarak verilen iki noktaya bakarak bir
 * dikgortgen olusturur. Dikdortgenin kose noktasi
 * iki noktanin konumuna gore, uzunluk ve genisligi
 * ise noktalar arasi uzakliga gore hesaplanir.*/
struct Rectangle point_to_rectangle(struct Point *p1, struct Point *p2);

#endif /* STRUCTPOINT_H_ */
