#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef _Manager_H_
#define _Manager_H_

typedef struct{
	char name[50];
	int ex_date; // 유통기한
	int ma_date; // 제조일자
	int price; // 가격
	int stock_num;// 물품 재고 수
}Product;

int listProduct(Product *p, int index); //제품의 목록 리스트 띄우기 위한 함수
int readProduct(Product p); // 물품 조회

#endif
int loadData(Product *p);	// 파일에서 불러오기
void searchName(Product *p, int index);	//이름으로 검색
void searchPrice(Product *p, int index);	// 가격으로 검색
