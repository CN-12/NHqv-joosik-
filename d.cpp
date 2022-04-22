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
    if(money - ((s -> value) * buy) - su < 0) cout << "���� ���� ���Ű� �����߽��ϴ�" << endl;
    else {
        money = money - ((s -> value) * buy) - su;
        s->amount += buy;
        cout << buy << "�� ���ſϷ�" << endl;
    }
}

void Lbuy(LG *(& s), int buy) {
    if(money - ((s -> value) * buy) - su < 0) cout << "���� ���� ���Ű� �����߽��ϴ�" << endl;
    else {
        money = money - ((s -> value) * buy) - su;
        s->amount += buy;
        cout << buy << "�� ���ſϷ�" << endl;
    }
}
void Kbuy(KAKAO *(& s), int buy) {
    if(money - ((s -> value) * buy) - su < 0) cout << "���� ���� ���Ű� �����߽��ϴ�" << endl;
    else {
        money = money - ((s -> value) * buy) - su;
        s->amount += buy;
        cout << buy << "�� ���ſϷ�" << endl;
    }
}
void Cbuy(COUPANG *(& s), int buy) {
    if(money - ((s -> value) * buy) - su < 0) cout << "���� ���� ���Ű� �����߽��ϴ�" << endl;
    else {
        money = money - ((s -> value) * buy) - su;
        s-> amount += buy;
        cout << buy << "�� ���ſϷ�" << endl;
    }
}
void buy() {
    char select;
    bool chan1=false;
    int buy;
    cout << "��� ���� ������ ����ּ���" << endl;
    cout << "������� 500���Դϴ�" << endl;
    cout << "���� ���� " << money << " �Դϴ�" <<endl;
    cout << "SAMSUNG " << s1 -> value << endl;
    cout << "LG " << s2 -> value << endl;
    cout << "KAKAO " << s3 -> value << endl;
    cout << "COUPANG " << s4 -> value << endl;
    while (1) {

        cin >> select;
        if (select =='q') return;

        cout << "�� �� ������ ���Ͻô°��� : ";
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
        cout << "���� ���� ���� " << money << endl;
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
    cout << "���� ������ �ִ� �ֽ���" << endl;
    cout << "�Ｚ: " << s1->amount <<  " ����: " << s2->amount << " ī��: " << s3->amount <<" ����: " << s4->amount << endl;
    return a;
}

void Ssell(Samsung *(& s), int sell) {
    if(sell > s-> amount) cout << "�ֽ��� �����ؼ� �Ǹſ� �����߽��ϴ�" << endl;
    else {
        money = money + (s -> value*sell) - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << sell << "�� �ǸſϷ�" << endl;
    }
}

void Lsell(LG *(& s), int sell) {
    if(sell > s-> amount) cout << "�ֽ��� �����ؼ� �Ǹſ� �����߽��ϴ�" << endl;
    else {
        money = money + (s -> value*sell) - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << sell << "�� �ǸſϷ�" << endl;
    }
}
void Ksell(KAKAO *(& s), int sell) {
    if(sell > s-> amount) cout << "�ֽ��� �����ؼ� �Ǹſ� �����߽��ϴ�" << endl;
    else {
        money = money + (s -> value*sell) - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << sell << "�� �ǸſϷ�" << endl;
    }
}

void Csell(COUPANG *(& s), int sell=0) {
    if(sell > s-> amount) cout << "�ֽ��� �����ؼ� �Ǹſ� �����߽��ϴ�" << endl;
    else {
        money = money + s -> value - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << sell << "�� �ǸſϷ�" << endl;
    }
}

void Csell(COUPANG *(& s), int sell, char * name) {
    if(sell > s-> amount) cout << "�ֽ��� �����ؼ� �Ǹſ� �����߽��ϴ�" << endl;
    else {
        money = money + s -> value - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << name << "���� " << sell << "�� �ǸſϷ�" << endl;
    }
}

void Csell(int sell) {
    COUPANG *(& s) = s4;
    if(sell > s-> amount) cout << "�ֽ��� �����ؼ� �Ǹſ� �����߽��ϴ�" << endl;
    else {
        money = money + s -> value - 500 - (s->value*0.01);
        s->amount -= sell;
        cout << sell << "�� �ǸſϷ�" << endl;
    }
}

void sell() {
   char select;
    bool chan1=false;
    int sell;
    char slow[10];
    char fast[10];
    cout << "�Ȱ� ���� ������ ����ּ���" << endl;
    cout << "������� 500���Դϴ�" << endl;
    cout << "SAMSUNG " << s1 -> value << endl;
    cout << "LG " << s2 -> value << endl;
    cout << "KAKAO " << s3 -> value << endl;
    cout << "COUPANG " << s4 -> value << endl;
    cout << "���� ���� " << money << " �Դϴ�" <<endl;
    cout << "���� ������ �ִ� �ֽ���" << endl;
    cout << "�Ｚ: " << s1->amount <<  " ����: " << s2->amount << " ī��: " << s3->amount <<" ����: " << s4->amount << endl;
    while (1) {
        srand(time(NULL));
        cin >> select;
        if (select =='q') break;
        cout << "�� �� �ǸŸ� ���Ͻô°��� : ";
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
                cout << "�Ǹ��ڴ��� �̸��� �����ּ��� : ";
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
//cout,cinŬ����
//�Լ� �����ε����
//�Լ� �Ű����� default
//bool ���
int main() {
    bool chan;
    char select;
    cout << "�ȳ��Ͻʴϱ�? NH���������Դϴ�" << endl;
    cout << "���Կ� ���� �˰� �ͽ��ϴ�" << endl;
    cout << "���� �����Ͻ� ���� �Է����ּ���" << endl;
    cin >> money;
    const int firstmoney = money;
    system("cls");
    while(1) {
        chan = false;
        cout << "0���� ����" << endl;
        cout << "1���� �ֽ� �Ÿ�" << endl;
        cout << "2���� �ֽ� �ŵ�" << endl;
        cout << "3���� ���� ������ �ֽ�" << endl;
        cout << "q�� ������" << endl;
        cin >> select;
        system("cls");
        switch (select) {
            case '0':
                change();
                break;
            case '1':
                cout << "���� �ֽ��� ��� �ͳ���?" << endl;
                buy();
                break;
            case '2':
                cout << "���� �ֽ��� �Ȱ� �ͳ���" << endl;
                sell();
                break;
            case '3':
                cout << "���� �ֽ��Դϴ�" << endl;
                cout << show(money) << endl;
                Sleep(5000);
                chan = true;
                break;
            case 'q':
                cout << "���� ����" << endl;
                cout << "�� �Ӵϴ� " << money << "�Դϴ�" << endl;
                cout << "���� NH�������Ǹ� �̿����ּż� �����մϴ�";
                exit(0);
            default:
                cout << "�ٽ� �Է����ּ���" <<endl;
        }

        system("cls");
    }
}
