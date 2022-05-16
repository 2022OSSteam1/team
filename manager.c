#include "manager.h"

void saveData(Product p[], int count){
        FILE* fp;

        fp= fopen("product.txt","wt");
        for(int i=0;i<count;i++){
                if(p[i].price == -1) continue;
                fprintf(fp, "%s %d %d %d %d\n", p[i].name, p[i].ex_date, p[i].ma_date, p[i].price, p[i].stock_num);
        }

        fclose(fp);
        printf("저장됨!\n");
}

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
                        printf("\n=> %d 번 ", i+1);
                        readProduct(p[i]);
                        scnt++;
                }
		printf("%d개 물품 검색죔!\n", scnt);
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
                        printf("\n=> %d 번 ", i+1);
                        readProduct(p[i]);
                        scntt++;
                }
		printf("%d개 물품 검색됨!\n", scntt);
        }
        if(scntt==0) printf("\n=> 검색된 데이터 없음!");
                printf("\n");
}



int searchMa(Product *p, int count){
        int ma;
	int count_ma=0;
        printf("찾으시는 유통기한을 입력하세요: ");
        scanf("%d", &ma);

        for(int i=0;i<count;i++){
                if(p[i].ma_date == ma){
			printf("\n=> %d 번 ", i+1);
                        readProduct(p[i]);
                        count_ma++;
                }
        	printf("%d개 물품 검색됨!\n", count_ma);
	}
        if(count_ma==0) printf("=> 제조일자가 %d인 물품은 존재하지 않습니다.\n", ma);
        return 0;
}

int searchEx(Product p[], int count){
        int ex;
	int count_ex=0;
        printf("찾으시는 유통기한을 입력하세요: ");
        scanf("%d", &ex);

        for(int i=0;i<count;i++){
                if(p[i].ex_date == ex){
			printf("\n=> %d 번 ", i+1);
                        readProduct(p[i]);
                        count_ex++;
                }
		printf("%d개 물품 검색됨!\n", count_ex);
        }
        if(count_ex==0) printf("=> 유통기한이 %d인 물품은 존재하지 않습니다.\n", ex);
        return 0;
}

int searchRemain(Product p[], int count){
        int remain;
	int count_remain = 0;
        printf("\n찾으시는 재고 개수를 입력하세요: ");
        scanf("%d", &remain);

        for(int i=0;i<count;i++){
                if(p[i].stock_num == remain){
			printf("\n=> %d 번 ", i+1);
                        readProduct(p[i]);
                count_remain++;
                }
		printf("%d개 물품 검색됨!\n", count_remain);
        }
        if(count_remain == 0) printf("=>재고 개수가 %d인 물품은 존재하지 않습니다.\n", remain);
        return 0;
}

