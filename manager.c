#include "manager.h"

int loadData(Product *p){   // 파일에서 불러오기
        int count=0, i=0, enter;
        FILE *fp;
        fp = fopen("product.txt", "rt");

        if(fp==NULL){
                printf("\n=>파일 없음\n");
        return 0;
        }
        else{
                for(; i<100; i++){
                        fgets(p[i].name, 100, fp);
                        if(feof(fp)) break;
                        fscanf(fp, "%d", &p[i].ex_date);
                        fscanf(fp, "%d", &p[i].ma_date);
                        fscanf(fp, "%d", &p[i].price);
                        fscanf(fp, "%d", &p[i].stock_num);
                }
                printf("=> 로딩 성공!\n");
                fclose(fp);
        return i;
        }
}

void searchName(Product *p, int index){	// 이름으로 검색
        int scnt = 0;
        char search[100];

        getchar();
        printf("검색할 이름? ");
        scanf("%[^\n]s", search);

        for(int i=0; i<index; i++){
                if(p[i].price == -1) continue;
                if(strstr(p[i].name, search)){
                        printf("\n%d 번 ", i+1);
                        readProduct(p[i]);
                        scnt++;
                }
        }
        if(scnt==0) printf("\n=> 검색된 데이터 없음!");
        printf("\n");
}

void searchPrice(Product *p, int index){	// 가격으로 검색
        int min, max,scntt=0;

        getchar();
        printf("\n최소가격은? : ");
        scanf("%d", &min);
        printf("최대가격은? : ");
        scanf("%d", &max);

        for(int i=0; i<index; i++){
                if(p[i].price == -1) continue;
                if(p[i].price >= min && p[i].price <=max ){
                        printf("\n%d 번 ", i+1);
                        readProduct(p[i]);
                        scntt++;
                }
        }
        if(scntt==0) printf("\n=> 검색된 데이터 없음!");
                printf("\n");
}
