/*
 * structpoint.c
 *
 *  Created on: 17 Feb 2024
 *      Author: pinar
 */

#include<stdio.h>
#include "structpoint.h"

/* Bu fonksiyon parametre olarak aldigi iki nokta
 * arasindaki Euclide uzakligi hesaplayip dondurur. */
double distance(struct Point *a, struct Point *b) {
	/* TODO */
}

/* Bu fonksiyon parametre olarak aldigi iki noktanin
 * ayni olup olmadigini test eder, noktalar ayni ise 1,
 * degilse 0 dondurur. */
int same_points(struct Point *p1, struct Point *p2) {
	if(p1->x-p2->y==0 && p1->y-p2->y==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* Bu fonksiyon parametre olarak aldigi iki noktanin
 * x ve y pozisyonlarini toplar, yeni bir nokta
 * degiskenine atama yapar.
 * Ornek: girdi: p1=(1,2) p2=(3,4)
 *        cikti: p3=((1+3),(2+4)) */
struct Point sum_points(struct Point *p1, struct Point *p2) {
	struct Point pt;

	pt.x=p1->x+p2->x;
	pt.y=p1->y+p2->y;

	return(pt);
}

/* Parametre olarak aldigi nokta ve dikdortgene bakip,
 * noktanin dikdortgen icinde olup olmadigini test eder.
 * Icinde ise 1, degilse 0 dondurur. */
int point_in_rectangle(struct Point *pt, struct Rectangle *r) {
	if(pt->x>(r->corner.x) && (r->corner.x+r->width)>pt->x && pt->y>(r->corner.y) && (r->corner.y+r->height)>pt->y)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/* Parametre olarak verilen iki noktaya bakarak bir
 * dikgortgen olusturur. Dikdortgenin kose noktasi
 * iki noktanin konumuna gore, uzunluk ve genisligi
 * ise noktalar arasi uzakliga gore hesaplanir.*/
struct Rectangle point_to_rectangle(struct Point *p1, struct Point *p2) {
	struct Rectangle r;
	struct Point corner1=*p1;
	struct Point corner2=*p2;
	
	if(corner1.x>corner2.x)
	{
  		r.width=corner1.x-corner2.x;
	}
	else
	{
  		r.width=corner2.x-corner1.x;
	}
	if(corner1.y>corner2.y)
	{
  		r.height=corner1.y-corner2.y;
	}
	else
	{
  		r.height=corner2.y-corner1.y;
	}

	if ((corner1.x-corner2.x)<0 && (corner1.y-corner2.y)<0)
	{
		r.corner=corner1;
	}
	else if ((corner1.x-corner2.x)>0 && (corner1.y-corner2.y)<0)
	{
		r.corner.x=corner1.x-r.width;
		r.corner.y=corner1.y;
	}
	else if ((corner1.x-corner2.x)<0 && (corner1.y-corner2.y)>0)
	{
		r.corner.x=corner1.x;
		r.corner.y=corner1.y-r.height;
	}
	else
	{
		r.corner=corner2;
	}

	return(r);
}
