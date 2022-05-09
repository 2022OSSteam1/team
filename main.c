#include "product.h"

int main(void){
        Product s[100];
        int count=0,index=0,menu,num=0;

        while(1){
                menu = selectMenu();
                if(menu == 0) break;
                if(menu == 1){
                        if(count==0) continue;
                        else {
                                listProduct(s,index);
                        }
                }
                else if(menu ==2){
                        count+=createProduct(&s[index++]);
                }
                else if(menu==3){
                        int number;

                        listProduct(s,index);
                        printf("\n수정할 번호?(취소:0) : ");
                        scanf("%d", &number);

                        if(number==0){
                        printf("=>취소됨");
                        continue;
                        }
                        else updateProduct(&s[number-1]);
                }
                else if(menu==4){
                        int number=0;

                        listProduct(s,index);
                        printf("\n삭제할 번호?(취소:0) : ");
                        scanf("%d", &number);

                        if(number==0) {
                                printf("=>취소됨");
                                continue;
                        }
                        else{
                        	deleteProduct(&s[number-1]);
                                count-=1;
                        }
        	}
	}
        printf("종료됨!\n");
        return 0;
}
                                                                         
