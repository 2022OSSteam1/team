#include "product.h"
#include "manager.h"

int main(void){
        Product p[100];
        int count=0,index=0,menu,num=0;

	count = loadData(p);
	index = count;

        while(1){
                menu = selectMenu();
                if(menu == 0) break;
                if(menu == 1){
                        if(count==0) continue;
                        else {
                                listProduct(p,index);
                        }
                }
                else if(menu ==2){
                        count+=createProduct(&p[index++]);
                }
                else if(menu==3){
                        int number;
                        listProduct(p,index);
                        printf("\n수정할 번호?(취소:0) : ");
                        scanf("%d", &number);
                        
			if(number==0){
                        printf("=>취소됨");
                        continue;
                        }
                        else updateProduct(&p[number-1]);
                }
                else if(menu==4){
                        int number=0;
                        listProduct(p,index);
                        printf("\n삭제할 번호?(취소:0) : ");
                        scanf("%d", &number);

                        if(number==0){
                        	printf("=>취소됨");
                        	continue;
                        }
                        else{
                        	deleteProduct(&p[number-1]);
                                count-=1;
                        }
        	}
		else if(menu==5) {
			if(count == 0) printf("데이터가 없습니다!\n");
			else saveData(p, index);
		}
		else if(menu==6) searchName(p, index);
		else if(menu==7) searchPrice(p, index);
		else if(menu == 8){
            		listProduct(p, index);
        		if (count==0) printf("데이터가 없습니다!\n");
           		else searchEx(p, count);
          	}
          	else if(menu == 9){
            		listProduct(p, index);
            		if (count==0) printf("데이터가 없습니다!\n");
            		else searchRemain(p, count);
          	}
          	else break;
	}
        printf("종료됨!\n");
        return 0;
}
                                                                         
