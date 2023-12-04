#include<stdio.h>
#include<string.h>

struct StudentList{
	int id;
	char name[50];
	char birthday[50];
	char address[50];
	int status;
	
};

void displayList(struct StudentList arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("ID :%d\n", arr[i].id);
        printf("Ten :%s\n", arr[i].name);
        printf("Birthday:%s\n", arr[i].birthday);
        printf("Address:%s\n", arr[i].address);
        printf("Status:%d\n", arr[i].status);
        printf("------------------\n");
    }
}
int searchList(struct StudentList arr[], int size, char answer[50])
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].name, answer) == 0)
        {
            index = i;
        }
    }
    return index;
}
int searchListByAuthor(struct StudentList arr[], int size, char answer[50]);


int main(){
	struct StudentList St1={ 1,"Nguyen Van A","Muoi hai","Duong Giai Phong",0 };
	struct StudentList St2={ 2,"Nguyen Van B","Mot","Duong Giai Phong",1};
	struct StudentList sinhvien[100]={St1,St2};
	int CurrentList=2;
	int choice;
	while(choice!=8){
		printf("\n****Menu****\n");
		printf("1.In toan bo danh sach sinh vien co trong mang studentList tren cung mat hang\n");
		printf("2.Thuc hien chuc nang them moi sinh viên vao vi tri cuoi cung cua studentList\n");
		printf("3.Thuc hien chuc nang cap nhat thong tin cua mot sinh viên\n");
		printf("4.Thuc hien chuc nang xoa thông tin cua mot sinh viên\n");
		printf("5.Thuc hien chuc nang sap xep va in ra danh sach StudentList da sap sep\n");
		printf("6.Thuc hien chuc nang tim kiem va in ra thong tin sinh vien\n");
		printf("7.Thuc hien chuc nang tim kiem va in ra toan bo sinh vien theo status\n");
		
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice){
			case 1:
				displayList(sinhvien,CurrentList);
				break;
			case 2:
			printf("************* Sub-menu *************\n");
            printf("2.1. Them mot sinh vien \n");
            printf("2.3. Cap nhat sinh vien \n");
            printf("2.4. Xoa sinh vien \n");
            float subChoice;
            scanf("%f", &subChoice);
            fflush(stdin);

            if (subChoice == 2.1f)
            {
                // them sinh vien
                struct StudentList NewStudent;

                printf("nhap vao ID \n");
                scanf("%d", &NewStudent.id);
                fflush(stdin);

                printf("Nhap vao Ten \n");
                gets(NewStudent.name);

                printf("nhap vao Birthday \n");
                gets(NewStudent.birthday);

                printf("Nhap vao Address \n");
                gets(NewStudent.address);
                
                printf("nhap vao status \n");
                scanf("%d",&NewStudent.status);

                sinhvien[CurrentList] = NewStudent ;
                CurrentList++;

                displayList(sinhvien,CurrentList);
            }
            else if (subChoice == 2.3f)
            {
                // cap nhat thong tin sinh vien
                char answer[100];
                printf("Nhap vao thong tin sinh vien: \n");
                gets(answer);

                int updateIndex = searchList(sinhvien, CurrentList, answer); // -1, index

                if (updateIndex != -1)
                {
                    printf("Nhap vao ten cap nhat \n");
                    gets(sinhvien[updateIndex].name);

                    printf("Nhap vao ID \n");
                    scanf("%d",&sinhvien[updateIndex].id);

                    printf("Nhap vao Tuoi \n");
                    scanf("%f", &sinhvien[updateIndex].birthday);
                    fflush(stdin);

                    displayList(sinhvien, CurrentList);
                }
            }
            else if (subChoice == 2.4f)
            {
                // Xoa sinh vien
                char answer[100];
                printf("Nhap vao ten sinh vien xoa \n");
                gets(answer);

                int deleteIndex = searchList(sinhvien, CurrentList, answer); // -1, index

                if (deleteIndex != -1)
                {
                    
                    for (int i = deleteIndex; i < CurrentList; i++)
                    {
                        sinhvien[i] = sinhvien[i + 1];
                    }
                    CurrentList--;
                    displayList(sinhvien, CurrentList);
                }
            }
            
				break;
				
			case 5:
					
				break;
			case 6:
				
				break;
			case 7:
				
				break;
		}
	}
}
