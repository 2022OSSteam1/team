#include "product.h"

int selectMenu(){
        int menu;
        printf("\n***제품관리***\n");
        printf("1. 조회\n");
        printf("2. 추가\n");
        printf("3. 수정\n");
        printf("4. 삭제\n");
        printf("0. 종료\n");
        printf("입력하시오 : ");
        scanf("%d", &menu);
        return menu;
}

int listProduct(Product *s, int index){
        printf("\n***************************");
        for(int i=0; i<index; i++){
                if(s[i].price == -1) continue;
                printf("\n%2d 번 유통기한 제조일자 가격  재고수\n", i+1);
                readProduct(s[i]);
        }
        printf("***************************\n");
}


int createProduct(Product *p){
	getchar();
	printf("\n물품명 : ");
	fgets(p->name, 100, stdin);
	p->name[strlen(p->name)-1]='\0';

	printf("물품 유통기한(ex220502) : ");
	scanf("%d",&p->ex_date);

	printf("물품 제조일자(ex220502) : ");
	scanf("%d",&p->ma_date);

	printf("물품 가격 : ");
	scanf("%d",&p->price);

	printf("물품 재고 개수 : ");
	scanf("%d",&p->stock_num);

	printf("==> 추가됨\n");
	return 1;
}

void readProduct(Product p){
	printf(" %s %d %d %d %d\n", p.name, p.ex_date, p.ma_date, p.price, p.stock_num);
}

int updateProduct(Product *p){
	getchar();
    	printf("\n물품명 : ");
    	fgets(p->name, 100, stdin);
	p->name[strlen(p->name)-1]='\0';

    	printf("물품 유통기한(ex220502) : ");
    	scanf("%d",&p->ex_date);

    	printf("물품 제조일자(ex220502) : ");
    	scanf("%d",&p->ma_date);

    	printf("물품 가격 : ");
    	scanf("%d",&p->price);
    
    	printf("물품 재고 개수 : ");
    	scanf("%d",&p->stock_num);

    	printf("==> 추가됨\n");
    	return 1;
}

int deleteProduct(Product *p){
    	p->ex_date=-1;
    	p->ma_date=-1;
    	p->price=-1;
    	p->stock_num=-1;
    	printf("==> 삭제됨!\n");
   	return 0;
}

