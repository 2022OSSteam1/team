***
주제: 편의점 물품 관리 서비스  
***
소개: 편의점의 물품들을 분류하고 검색하는 서비스입니다.  
이미지:  ![](https://cdn.pixabay.com/photo/2019/03/06/23/36/store-4039197_960_720.png)   
기능:  
1. 물품 추가 - 물품을 새로 추가하는 함수이다.  
2. 물품 조회 - 물품의 리스트를 전부 띄우는 함수이다.  
3. 물품 수정 - 이미 편의점에 있는 물품을 수정하는 함수이다.  
4. 물품 삭제 - 편의점에 있는 물품을 삭제하는 함수이다.  
5. 파일 저장 함수 - 물품 리스트를 저장하는 함수이다.  
6. 파일 불러오기 함수 - 저장된 물품 리스트를 불러오는 함수이다.  
7. 물품 이름으로 검색 - 물건을 이름으로 검색하는 함수이다.  
8. 가격으로 검색 - 물건을 가격의 범위를 지정해서 검색한다.  
9. 유통기한 검색 - 남은 유통기한을 알려주는 함수이다.  
10. 물품 재고 검색 - 검색한 물품의 재고를 알려주는 함수이다.  
함수 정의:  
typedef struct{
char name[20];
int ex_date; //유통기한
int ma_date; //제조일자(manufacturing date)
int price; //가격
int stock_num; //물품 재고 개수
}Product;

int createProduct(Product *p); //물품 추가
void readProduct(Product *p); //물품 조회
int updateProduct(Product *p); //물품 정보 수정
int deleteProduct(Product *p); //물품 삭제
void saveData(Product *p, int count); //데이터를 파일에 저장
int loadData(Product *p); //파일에서 데이터를 불러오기
int selectMenu(); //번호
int searchName(Product *p);//물품 이름으로 검색
int searchPrice(Produtct *p)//가격으로 검색
int searchEx(Product *p)//유통기한으로 검색
int searchRemain(product *p)//물품 재고 검색

개발환경: linux, github  
언어: C언어  
팀소개: 유재혁 , 오성진  
역할:  
오성진 : CRUD, 파일 관련 함수  
유재혁 : 검색 기능 함수
