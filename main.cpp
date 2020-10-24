/*
#include <iostream>

int main()
{
    int n[10];
    int sum=0;
    for(int i=1;i<=5;i++)
    {
        std::cout <<i<< "번째 정수입력: ";
        std::cin >> n[i];
    }
    sum+=n[1]+n[2]+n[3]+n[4]+n[5];
    std::cout <<"합계: "<<sum<<std::endl;
    return 0;
}
*/
/*
#include <iostream>
int main()
{
    char name[100];
    char call[20];
    std::cin>>name>>call;
    std::cout <<"이름: "<<name<<" 전화번호: "<<call<<std::endl;
    return 0;
}*/
/*
#include <iostream>
int main()
{
    int n;
    std::cin>>n;
    for(int i=1;i<=9;i++)
    {
        std::cout <<n<<'x'<<i<<"= "<<n*i<<std::endl;
    }
    return 0;
}*/

/*
#include <iostream>
int main()
{
    int n;
    while(true)
    {
        std::cout <<"판매 금액을 만원 단위로 입력(-1 to end)";
        std::cin>>n;
        if(n==-1)break;
        else
            std::cout <<"이번 달 급여: "<<(50+n*0.12)<<"만원"<<std::endl;
    }
    std::cout<<"프로그램을 종료합니다."<<std::endl;

    return 0;
}
*/
/*
#include <iostream>
void MyFunc(void)
{
    std::cout<<"MyFunc(void) called"<<std::endl;
}
void MyFunc(char c)
{
    std::cout<<"MyFunc(char c) called"<<std::endl;
}
void MyFunc(int a,int b)
{
    std::cout<<"MyFunc(int a,int b) called"<<std::endl;
}
int main()
{
    MyFunc();
    MyFunc('A');
    MyFunc(12,13);
    return 0;
}
*/
/*
#include <iostream>
void swap(int*a,int*b)
{
    int asdf;
    asdf=*a;
    *a=*b;
    *b=asdf;
}
void swap(char*a,char*b)
{
    char asdf;
    asdf=*a;
    *a=*b;
    *b=asdf;
}
void swap(double*a,double*b)
{
    double asdf;
    asdf=*a;
    *a=*b;
    *b=asdf;
}
int main()
{
    int ia=20,ib=30;
    swap(&ia,&ib);
    std::cout<<ia<<' '<<ib<<std::endl;

    char cha='A',chb='Z';
    swap(&cha,&chb);
    std::cout<<cha<<' '<<chb<<std::endl;

    double da=1.111,db=5.555;
    swap(&da,&db);
    std::cout<<da<<' '<<db<<std::endl;
}
*/
/*
#include <iostream>
int adder(int num1=1,int num2=2);

int main()
{
    std::cout<<adder()<<std::endl;
    std::cout<<adder(5)<<std::endl;
    std::cout<<adder(3,5)<<std::endl;
    return 0;
}

int adder(int num1,int num2)
{
    return num1+num2;
}
*/
/*
#include <iostream>
int boxvol(int length,int width=1,int height=1);

int main()
{
    std::cout<<"[3, 3, 3] : "<<boxvol(3,3,3)<<std::endl;
    std::cout<<"[5, 5, D] : "<<boxvol(5,5)<<std::endl;
    std::cout<<"[7, D, D] : "<<boxvol(7)<<std::endl;
    //std::cout<<"[D, D, D] : "<<boxvol()<<std::endl;
    return 0;
}

int boxvol(int length,int width,int height)
{
    return length*width*height;
}
*/
/*
#include <iostream>
int boxvol(int length,int width,int height);
int boxvol(int length,int width);
int boxvol(int length);
int main()
{
    std::cout<<"[3, 3, 3] : "<<boxvol(3,3,3)<<std::endl;
    std::cout<<"[5, 5, D] : "<<boxvol(5,5)<<std::endl;
    std::cout<<"[7, D, D] : "<<boxvol(7)<<std::endl;
    //std::cout<<"[D, D, D] : "<<boxvol()<<std::endl;
    return 0;
}

int boxvol(int length,int width,int height)
{
    return length*width*height;
}
int boxvol(int length,int width)
{
    return length*width;
}
int boxvol(int length)
{
    return length;
}
*/
/*
#include <iostream>

namespace bestcom
{
    void func(void);
}

namespace progcom
{
    void func(void);
}

int main()
{
    bestcom::func();
    progcom::func();
    return 0;
}

void bestcom::func(void)
{
    std::cout<<"bestcom"<<std::endl;
}
void progcom::func(void)
{
    std::cout<<"progcom"<<std::endl;
}
*/
/*
#include <iostream>


namespace bestcom
{
    void func(void);
}

namespace bestcom
{
    void nice(void);
}

namespace progcom
{
    void func(void);
}

int main()
{
    bestcom::func();
    return 0;
}

void bestcom::func(void)
{
    std::cout<<"bestcom"<<std::endl;
    nice();
    progcom::func();
}
void bestcom::nice(void)
{
    std::cout<<"nice"<<std::endl;
}
void progcom::func(void)
{
    std::cout<<"progcom"<<std::endl;
}
*/
#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN=20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum {MAKE=1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

typedef struct{
int accID;
int balance;
char cusName[NAME_LEN];
} Account;

Account accArr[100];
int accnum=0;

int main()
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout<<"선택: ";
        cin>>choice;
        cout<<endl;

        switch (choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout<<"Illegal selection.."<<endl;
        }
    }
    return 0;
}

void ShowMenu()
{
    cout<<"-----Menu------"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void MakeAccount()
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout<<"[계좌개설]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"이 름: ";cin>>name;
    cout<<"입금액: ";cin>>balance;
    cout<<endl;

    accArr[accnum].accID=id;
    accArr[accnum].balance=balance;
    strcpy(accArr[accnum].cusName,name);
    accnum++;
}

void DepositMoney()
{
    int money;
    int id;
    cout<<"[입   금]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"입금액: ";cin>>money;

    for(int i=0;i<accnum;i++)
    {
        if(accArr[i].accID==id)
        {
            accArr[i].balance+=money;
            cout<<"입금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void WithdrawMoney()
{
    int money;
    int id;
    cout<<"[출   금]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"출금액: ";cin>>money;

    for(int i=0;i<accnum;i++)
    {
        if(accArr[i].accID==id)
        {
            if(accArr[i].balance<money)
            {
                cout<<"잔액부족"<<endl<<endl;
                return;
            }
            accArr[i].balance-=money;
            cout<<"출금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID 입니다."<<endl<<endl;
}

void ShowAllAccInfo()
{
    for(int i=0;i<accnum;i++)
    {
        cout<<"계좌ID: "<<accArr[i].accID<<endl;
        cout<<"이 름: "<<accArr[i].cusName<<endl;
        cout<<"잔 액: "<<accArr[i].balance<<endl;
    }
}
