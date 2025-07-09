/*
 * main.c
 *
 *  Created on: 17 Feb 2024
 *      Author: pinar
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#include "structpoint.h"

int main() {
	struct Point pt1;
	struct Point *p1 = &pt1;
	p1->x = 7;
	p1->y = 3;
	

	struct Point pt2;
	struct Point *p2 = &pt2;
	p2->x = 11;
	p2->y = 9;
	


	struct Rectangle r1;
	struct Rectangle *pr1 = &r1;

	pr1 -> corner.x = 1;
	pr1 -> corner.y = 2;
	pr1 -> width = 11;
	pr1 -> height = 10;

	struct Point pt3 = sum_points(p1,p2);
	printf("Ucuncu nokta (%.0f, %.0f) noktasidir\n\n",pt3.x,pt3.y);

	if(point_in_rectangle(p1,pr1))
	{
		printf("Birinci nokta (%.0f, %.0f); sol alt kosesi (%.0f, %.0f), genisligi %d birim, yuksekligi %d birim olan dikdortgenin icindedir\n",pt1.x, pt1.y, r1.corner.x, r1.corner.y, r1.width, r1.height);
	}
	else
	{
		printf("Birinci nokta (%.0f, %.0f); sol alt kosesi (%.0f, %.0f), genisligi %d birim, yuksekligi %d birim olan dikdortgenin icinde degildir\n",pt1.x, pt1.y, r1.corner.x, r1.corner.y, r1.width, r1.height);
	}

	if(point_in_rectangle(p2,pr1))
	{
		printf("Ikinci nokta (%.0f, %.0f); sol alt kosesi (%.0f, %.0f), genisligi %d birim, yuksekligi %d birim olan dikdortgenin icindedir\n",pt2.x, pt2.y, r1.corner.x, r1.corner.y, r1.width, r1.height);
	}
	else
	{
		printf("Ikinci nokta (%.0f, %.0f); sol alt kosesi (%.0f, %.0f), genisligi %d birim, yuksekligi %d birim olan dikdortgenin icinde degildir\n",pt2.x, pt2.y, r1.corner.x, r1.corner.y, r1.width, r1.height);
	}

	if(point_in_rectangle(&pt3,pr1))
	{
		printf("Ucuncu nokta (%.0f, %.0f); sol alt kosesi (%.0f, %.0f), genisligi %d birim, yuksekligi %d birim olan dikdortgenin icindedir\n\n",pt3.x, pt3.y, r1.corner.x, r1.corner.y, r1.width, r1.height);
	}
	else
	{
		printf("Ucuncu nokta (%.0f, %.0f); sol alt kosesi (%.0f, %.0f), genisligi %d birim, yuksekligi %d birim olan dikdortgenin icinde degildir\n\n",pt3.x, pt3.y, r1.corner.x, r1.corner.y, r1.width, r1.height);
	}

	struct Point pt4;
	struct Point *p4 = &pt4;
	p4->x = 3;
	p4->y = 13;

	struct Rectangle r2;
	r2 = point_to_rectangle(p1,p4);
	
	printf("(%.0f, %.0f) ve (%.0f, %.0f) noktalari ile olusturulan dikdortgenin sol alt kosesi (%.0f, %.0f) noktasidir, genisligi %d birim, yuksekligi %d birimdir.",pt1.x, pt1.y, pt4.x, pt4.y, r2.corner.x, r2.corner.y, r2.width, r2.height);


	return 0;
}
