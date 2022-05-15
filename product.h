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

#endif

void readProduct(Product p); //물품 조회
int listProduct(Product *s, int index); //물품의 항목 리스트 띄우기위한 함수
int createProduct(Product *p); //물품 추가
int updateProduct(Product *p); //물품 정보 수정
int deleteProduct(Product *p); //물품 삭제

int selectMenu(); //번호
