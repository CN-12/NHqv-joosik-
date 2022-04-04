#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <string.h>
using namespace std;

int money;
const int su = 500;

typedef struct Samsung{
    int value = 5000;
    int amount = 0;
}Samsung;

typedef struct LG{
    int value = 3000;
    int amount = 0;
}LG;
	
typedef struct KAKAO {
    int value = 1000;
    int amount = 0;
}KAKAO;

typedef struct COUPANG {
    int value = 500;
    int amount = 0;
}COUPANG;

Samsung * s1 = new Samsung;
LG * s2 = new LG;
KAKAO * s3 = new KAKAO;
COUPANG * s4 = new COUPANG;

void Sbuy(Samsung *(& s), int buy) {
    if(money - ((s -> value) * buy) - su < 0) cout << "돈이 없어 구매가 실패했습니다" << endl;
    else {
        money = money - ((s -> value) * buy) - su;
        s->amount += buy;
        cout << buy << "개 구매완료" << endl;
    }
}

void Lbuy(LG *(& s), int buy) {
    if(money - ((s -> value) * buy) - su < 0) cout << "돈이 없어 구매가 실패했습니다" << endl;
    else {
        money = money - ((s -> value) * buy) - su;
        s->amount += buy;
        cout << buy << "개 구매완료" << endl;
    }
}
void Kbuy(KAKAO *(& s), int buy) {
    if(money - ((s -> value) * buy) - su < 0) cout << "돈이 없어 구매가 실패했습니다" << endl;
    else {
        money = money - ((s -> value) * buy) - su;
        s->amount += buy;
        cout << buy << "개 구매완료" << endl;
    }
}
void Cbuy(COUPANG *(& s), int buy) {
    if(money - ((s -> value) * buy) - su < 0) cout << "돈이 없어 구매가 실패했습니다" << endl;
    else {
        money = money - ((s -> value) * buy) - su;
        s-> amount += buy;
        cout << buy << "개 구매완료" << endl;
    }
}
void buy() {
    char select;
    bool chan1=false;
    int buy;
    cout << "사고 싶은 종목을 골라주세요" << endl;
    cout << "수수료는 500원입니다" << endl;
    cout << "현재 돈은 " << money << " 입니다" <<endl;
    cout << "SAMSUNG " << s1 -> value << endl;
    cout << "LG " << s2 -> value << endl;
    cout << "KAKAO " << s3 -> value << endl;
    cout << "COUPANG " << s4 -> value << endl;
    while (1) {

        cin >> select;
        if (select =='q') return;

        cout << "몇 개 구입을 원하시는가요 : ";
        cin >> buy;
        switch (select)
        {
        case '1':
            Sbuy(s1, buy);
            break;
        case '2':
            Lbuy(s2, buy);
            break;
        case '3':
            Kbuy(s3, buy);
            break;
        case '4':
            Cbuy(s4, buy);
            break;
        case 'q':
            chan1 = true;
            break;
        default:
            chan1 = true;
        }
        if(chan1) return;
        cout << "현재 가진 돈은 " << money << endl;
    }
}

void change() {
    if((rand() % 3)) s1 -> value = s1 -> value + (s1 -> value/(rand() % 15));
    else s1 -> value = s1 -> value - (s1 -> value /(rand() % 15));
    if((rand() % 3)) s2 -> value = s2 -> value + (s2 -> value/(rand() % 15));
    else s2 -> value = s2 -> value - (s2 -> value/(rand() % 15));
    if((rand() % 3)) s3 -> value = s3 -> value + (s3 -> value/(rand() % 15));
    else s3 -> value = s3 -> value - (s3 -> value/(rand() % 15));
    if((rand() % 3)) s4 -> value = s4 -> value + (s4 -> value/(rand() % 15));
    else s4 -> value = s4 -> value - (s4 -> value/(rand() % 15));
}

int & show(int & a) {
    cout << "현재 가지고 있는 주식은" << endl;
    cout << "삼성: " << s1->amount <<  " 엘지: " << s2->amount << " 카톡: " << s3->amount <<" 쿠팡: " << s4->amount << endl;
    return a;
}

void Ssell(Samsung *(& s), int sell) {
    if(sell > s-> amount) cout << "주식이 부족해서 판매에 실패했습니다" << endl;
    else {
        money = money + s -> value - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << sell << "개 판매완료" << endl;
    }
}

void Lsell(LG *(& s), int sell) {
    if(sell > s-> amount) cout << "주식이 부족해서 판매에 실패했습니다" << endl;
    else {
        money = money + s -> value - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << sell << "개 판매완료" << endl;
    }
}
void Ksell(KAKAO *(& s), int sell) {
    if(sell > s-> amount) cout << "주식이 부족해서 판매에 실패했습니다" << endl;
    else {
        money = money + s -> value - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << sell << "개 판매완료" << endl;
    }
}
void Csell(COUPANG *(& s), int sell=0) {
    if(sell > s-> amount) cout << "주식이 부족해서 판매에 실패했습니다" << endl;
    else {
        money = money + s -> value - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << sell << "개 판매완료" << endl;
    }
}

void Csell(COUPANG *(& s), int sell, char * name) {
    if(sell > s-> amount) cout << "주식이 부족해서 판매에 실패했습니다" << endl;
    else {
        money = money + s -> value - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << name << "님이 " << sell << "개 판매완료" << endl;
    }
}
void Csell(int sell) {
    COUPANG *(& s) = s4;
    if(sell > s-> amount) cout << "주식이 부족해서 판매에 실패했습니다" << endl;
    else {
        money = money + s -> value - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << sell << "개 판매완료" << endl;
    }
}
void sell() {
   char select;
    bool chan1=false;
    int sell;
    char slow[10];
    char fast[10];
    cout << "팔고 싶은 종목을 골라주세요" << endl;
    cout << "수수료는 500원입니다" << endl;
    cout << "SAMSUNG " << s1 -> value << endl;
    cout << "LG " << s2 -> value << endl;
    cout << "KAKAO " << s3 -> value << endl;
    cout << "COUPANG " << s4 -> value << endl;
    cout << "현재 돈은 " << money << " 입니다" <<endl;
    cout << "현재 가지고 있는 주식은" << endl;
    cout << "삼성: " << s1->amount <<  " 엘지: " << s2->amount << " 카톡: " << s3->amount <<" 쿠팡: " << s4->amount << endl;
    while (1) {
        srand(time(NULL));
        cin >> select;
        if (select =='q') break;
        cout << "몇 개 판매를 원하시는가요 : ";
        cin >> sell;
        switch (select)
        {
        case '1':
            Ssell(s1, sell);
            break;
        case '2':
            Lsell(s2, sell);
            break;
        case '3':
            Ksell(s3, sell);
            break;
        case '4':
            if(sell == 0) Csell(s4);
            else {
                cout << "판매자님의 이름을 적어주세요 : ";
                cin >> slow;
                if(slow[0] == ' ')
                    Csell(sell);
                else {
                    strcpy(fast, slow);
                    Csell(s4, sell, fast);
                }
            }
            break;
        case 'q':
            chan1 = true;
            break;
        default:
            chan1 = true;
        }
    }
}
//cout,cin클리어
//함수 오버로딩사용
//함수 매개변수 default
//bool 사용
int main() {
    bool chan;
    char select;
    cout << "안녕하십니까? NH투자증권입니다" << endl;
    cout << "고객님에 대해 알고 싶습니다" << endl;
    cout << "현재 소유하신 돈을 입력해주세요" << endl;
    cin >> money;
    const int firstmoney = money;
    system("cls");
    while(1) {
        chan = false;
        cout << "0번은 존버" << endl;
        cout << "1번은 주식 매매" << endl;
        cout << "2번은 주식 매도" << endl;
        cout << "3번은 현재 보유한 주식" << endl;
        cout << "q는 나가기" << endl;
        cin >> select;
        system("cls");
        switch (select) {
            case '0':
                change();
                break;
            case '1':
                cout << "무슨 주식을 사고 싶나요?" << endl;
                buy();
                break;
            case '2':
                cout << "무슨 주식을 팔고 싶나요" << endl;
                sell();
                break;
            case '3':
                cout << "현재 주식입니다" << endl;
                cout << show(money) << endl;
                Sleep(5000);
                chan = true;
                break;
            case 'q':
                cout << "실행 종료" << endl;
                cout << "총 머니는 " << money << "입니다" << endl;
                cout << "저희 NH투자증권를 이용해주셔서 감사합니다";
                exit(0);
            default:
                cout << "다시 입력해주세요" <<endl;
        }

        system("cls");
    }
}
