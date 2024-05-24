//실전문제 6번 2차원 행렬을 추상화한 Matrix 클래스를작성하고, show 멤버 함수와 다음과 같은 연산이 가능하도록 구현;
//(1) 클래스의 멤버 함수로 구현하기

/*#include<iostream>

using namespace std;

class Matrix{
    int m[2][2];
public:
    Matrix(int m1 = 0, int m2 = 0, int m3 = 0, int m4 = 0){
        m[0][0] = m1;
        m[0][1] = m2;
        m[1][0] = m3;
        m[1][1] = m4;
    }
    void show(){
        cout << "Matrix : { ";
        for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
        cout << m[i][j] << ' ';
        cout << "}" << endl;   
    }
    Matrix operator +(Matrix mat);
    Matrix& operator +=(Matrix mat);
    bool operator ==(Matrix mat);
};

Matrix Matrix :: operator +(Matrix mat){
    Matrix tmp;
    for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
    tmp.m[i][j] = m[i][j] + mat.m[i][j];
    return tmp;

}

Matrix& Matrix :: operator +=(Matrix mat){
    for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
        m[i][j] += mat.m[i][j];
        return* this;
}

bool Matrix :: operator ==(Matrix mat){
    for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
    if(m[i][j] == mat.m[i][j])
    return true;
    else 
    return false;
}

int main(){
    Matrix a(1,2,3,4), b(2,3,4,5), c;
    c = a + b;
    a += b;
    a.show();
    b.show();
    c.show();
    if(a==c)
    cout << "a and c are the same" << endl;
}*/


// 6 - 프렌드 함수로 구현하기

/*
#include<iostream>
using namespace std;



class Matrix{
    int m[2][2];
public:
    Matrix(int m1 = 0, int m2 = 0, int m3 = 0, int m4 = 0){
        m[0][0] = m1;
        m[0][1] = m2;
        m[1][0] = m3;
        m[1][1] = m4;
    }
    void show(){
        cout << "Matrix : { ";
        for(int i=0; i<2; i++)
        for(int j=0; j<2; j++)
        cout << m[i][j] << ' ';
        cout << "}" << endl;   
    }
    friend Matrix operator +(Matrix mat1, Matrix mat2);
    friend Matrix& operator +=(Matrix& mat1, Matrix mat2);
    friend bool operator ==(Matrix mat1, Matrix mat2);
   
};

Matrix operator +(Matrix mat1, Matrix mat2){
    Matrix tmp;
    for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
    tmp.m[i][j] = mat1.m[i][j] + mat2.m[i][j];
    return tmp;
 }

 Matrix& operator+=(Matrix& mat1, Matrix mat2){ 
    for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
    mat1.m[i][j] += mat2.m[i][j];
    return mat1;
 }

 bool operator ==(Matrix mat1, Matrix mat2){
    for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
    if(mat1.m[i][j] == mat2.m[i][j])
    return true;
    else
    return false;
 }


int main(){
    Matrix a(1,2,3,4), b(2,3,4,5), c;
    c = a + b;
    a += b;
    a.show();
    b.show();
    c.show();
    if(a==c)
    cout << "a and c are the same" << endl;
}
*/

//실전문제 7 2차원 행렬을 추상화한 Matrix 클래스를 활용하는 코드임
// 1.  >> << 연사자를 클래스 내부 멤버함수로 구현하기
/*#include<iostream>
using namespace std;

class Matrix{
    int m[4];
public:
    Matrix(int m1 =0, int m2 =0 , int m3 =0, int m4 = 0){
        m[0] = m1;
        m[1] = m2;
        m[2] = m3;
        m[3] = m4;
    }
    void show(){
        cout<< "Matrix = { ";
        for(int i=0; i<4; i++){
            cout << m[i] << ' ';
        }
        cout << " } " << endl;
    }
    Matrix& operator << (int mat[4]); 
    void operator >> (int mat [4]);

};
Matrix& Matrix :: operator <<(int mat[4]){
    for(int i=0; i<4; i++)
    m[i] = mat[i];
    return* this;    
} 

void Matrix :: operator >> (int mat[4]){
    for(int i = 0; i<4; i++)
    mat[i] = m[i];
}



int main(){
    Matrix a(4,3,2,1), b;
    int x[4], y[4] = {1,2,3,4};
    a >> x; //a의 각원소를 배열 x에 복사
    b << y; //배열 y의 원소 값을 b의 원소에 설정

    for(int i=0; i<4; i++)
    cout<<x[i]<<' ';
    cout << endl;
    b.show();
}*/

//7-2 friend 함수로 구현

/*#include<iostream>
using namespace std;

class Matrix{
    int m[4];
public:
    Matrix(int m1 =0, int m2 =0 , int m3 =0, int m4 = 0){
        m[0] = m1;
        m[1] = m2;
        m[2] = m3;
        m[3] = m4;
    }
    void show(){
        cout<< "Matrix = { ";
        for(int i=0; i<4; i++){
            cout << m[i] << ' ';
        }
        cout << " } " << endl;
    }
    friend Matrix& operator <<(Matrix& mat1, int mat2[4]);
    friend void operator >>(Matrix mat1, int mat2[4]);

};
Matrix& operator<<(Matrix& mat1, int mat2[4]){
    for(int i=0; i<4; i++)
    mat1.m[i] = mat2[i];
    
    return mat1;
}

void operator >> (Matrix mat1, int mat2[4]){
    for(int i=0; i<4; i++)
    mat2[i] = mat1.m[i];
}


int main(){
    Matrix a(4,3,2,1), b;
    int x[4], y[4] = {1,2,3,4};
    a >> x; //a의 각원소를 배열 x에 복사
    b << y; //배열 y의 원소 값을 b의 원소에 설정

    for(int i=0; i<4; i++)
    cout<<x[i]<<' ';
    cout << endl;
    b.show();
}*/


//실전문제 8 원을 추상화한 Circle 클래스  프렌드 함수로 구현하기

/*#include<iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(int radius = 0){
        this->radius = radius;
    }
    void show(){
        cout << "radius = " << radius << "인 원" << endl;
    }
    friend Circle& operator++(Circle& c1); // 전위 연산자 
    friend Circle  operator++(Circle& c1, int r); // 후위 연산자
    
};

Circle& operator++(Circle& c1){
   c1.radius++;
   return c1;
}

Circle operator++(Circle& c1, int r){
    Circle tmp = c1; // 변경하기 전의 c1 상태 저장
    c1.radius ++;
    return tmp;
}


int main(){
    Circle a(5), b(4);
    ++a; //전위 연산자 구현(반지름을 1 증가 시킴);
    b = a++;  //후위 연산자 구현(반지름을 1 증가 시킴);
    a.show();
    b.show();
}
*/



// -------------------------------클래스 멤버함수로 전위 후위 연산자 구현 ---
/*#include<iostream>
using namespace std;

class Circle{
    int radius;
public:
    Circle(int radius = 0){
        this->radius = radius;
    }
    void show(){
        cout << "radius = " << radius << "인 원" << endl;
    }
     Circle& operator++(); // 전위 연산자 
     Circle  operator++(int r); // 후위 연산자 여기서 int r 은 임의의 정수
    
};

Circle& Circle :: operator++(){
    radius++;
    return* this;
}

Circle Circle :: operator++(int r){
    Circle tmp = *this;
    radius++;
    return tmp;
}

int main(){
    Circle a(5), b(4);
    ++a; //전위 연산자 구현(반지름을 1 증가 시킴); // 여기서 a의 반지름은 6
    b = a++;  //후위 연산자 구현(반지름을 1 증가 시킴); // a는 증가했지만 b는 a가 증가하기 이전의 값인 6을 반환
    a.show();
    b.show();
}
*/


//실전 문제 9번 Circle 클래스 참조 문제

/*#include<iostream>
using namespace std;


class Circle{
    int radius;
public:
    Circle(int radius = 0){
        this->radius = radius;
    }
    void show(){
        cout << "radius = " << radius << "인 원" << endl;
    }
    friend Circle operator+(int r, Circle c);
};

Circle operator+(int r, Circle c){
    Circle tmp;
    tmp.radius = r + c.radius;
    return tmp;
}




int main(){
    Circle a(5), b(4);
    b = 1 + a; //b의 반지름을 a의 반지름에 1을 더한것으로 변경하기 b = 6 이 출력되게...
    a.show();
    b.show();
}
*/

// 실전문제 10 통계를 내는 STatic 클래스를 만들기.

/*#include<iostream>
using namespace std;

class Statistics{
    int* statis;
    int size;
    int idx;
public:
    Statistics(int size=0, int idx =0){
        this->size = size;
        this->statis = new int[size]; // 동적 할당
    }
    Statistics& operator << (int n);
    void operator ~();
    void operator >> (int& ave);    
    bool operator !();
    ~Statistics(){
        delete [] statis;
    }
    
};

Statistics& Statistics :: operator<<(int n){    
    statis[size] = n;    
    size++;
    return* this;
}

void Statistics :: operator~(){
    for(int i=0; i<size; i++){
    cout<<statis[i]<<' '; 
    }
    cout << endl;
}

void Statistics :: operator >> (int& ave){
    int sum = 0;
    for(int i=0; i<size; i++){
        sum = sum + statis[i];
    }
  ave = sum/size;  
} 

bool Statistics :: operator !(){
    if(statis && size == 0)
    return true;
    else
    return false;
}

int main(){
    Statistics stat;
    if(!stat)
    cout << "현재 통계 데이터가 없습니다. " << endl;

    int x[5];
    cout << "5개의 정수를 입력하라>>";
    for(int i=0; i<5; i++)
    cin >> x[i];

    for(int i=0; i<5; i++)  //x[i] 값을 통계 객체에 삽입하기
    stat << x[i];
    stat << 100 << 200; // 100, 200을 통계 객체에 삽입하기.
    ~stat; // 통계 데이터를 모두 출력하기

    int avg;
    stat >> avg; // 통계 객체로부터 평균을 받기 
    cout << "avg = " << avg << endl;
}
*/

//예제 11 stack 클래스의  stack을 만들고  push용 으로 << 연산자를 pop을 위해 >> 연산자를, 
//비어있는 스택인지 알기위해 ! 연산자를 작성하라

/*#include<iostream>
using namespace std;

class Stack{
    int *st;
    int size;
    public:
    Stack(int size = 0){
        this->size =size;
        st = new int[size];
    }
    Stack& operator << (int x);
    bool operator !();
    void operator >>(int& x);
    ~Stack(){
        delete [] st;
    }
};
Stack& Stack :: operator <<(int x){
    st[size] = x; // 0,1,2 -> 차례로 3,5,10 들어옴 
    size++;
    return* this;
}
bool Stack :: operator !(){
    if(size == 0)
    return true;
    else
    return false;
}

void Stack :: operator >>(int& x){
    x = st[size-1]; // stack에 맨 위에 요소에 접근하기 위함. 
    size--;
}

int main(){
    Stack stack;
    stack << 3 << 5 << 10; // 3, 5, 10  순선대로 스택에 push -> 후입 선출
    while(1){
        if(!stack) break; // stack empty 유무
        int x;
        stack >> x; //stack에 탑에 있는 정수 팝
        cout << x << ' ';
    }
    cout << endl;
}
*/

//실전문제 12번 정수배열을 항상 증가 순으로 유지하는 SortArray 클래스를 작성하고자 한다
// + = 연산자도 작성, 아래 클래스가 작동하도록 main 작성


/*
#include<iostream>
using namespace std;

class SortArray{
    int size;
    int *p;
    void sort(); // 정수 배열을 오름차순으로 정렬.
    public:
    SortArray(); // p는 null로 size는 0으로 초기화.
    SortArray(SortArray& src); // 복사생성자
    SortArray(int p[], int size);// 생성자. 정수 배열과 크기를 전달받음
    ~SortArray(); // 소멸자
    SortArray operator +(SortArray& op2); // 현재 배열에 op2 배열 추가
    SortArray& operator = (const SortArray& op2); // 현재 배열에 op2 배열복사 
    void show(); // 배열의 원소 출력
};
void SortArray :: sort(){
    for(int i=0; i<size-1; i++){
        for(int j=1; j<size-i; j++){
            if(p[j-1]>p[j]){
                int temp = p[j-1];
                p[j-1] = p[j];
                p[j] = temp;
            }
        }
    }
}

SortArray :: SortArray(){
    p = NULL;
    size = 0;
}

SortArray :: SortArray(SortArray& src){ // 깊은 복사생성자 구현 // +연산자는  객체를 리턴하므로 복사 생성자가 반드시 필요
this->size = src.size; //원본 객체의 size를 복사
this->p = new int[src.size]; //원복 객체의 배열 크기만큼 새로운 배열을 동적 할당
for(int i=0; i<src.size; i++) // 원본 객체의 요소를 하나씩 복사.
    this->p[i] = src.p[i];
}
// -> 깊은 복사생성자가 없다면 두 객체 배열은 같은 배열을 공유하게 됨 -> 한 객체에서 배열을 변경하면 다른객체도 영향을 받게 되서 필요.

SortArray :: SortArray(int p[], int size){
    this->size = size;
    this->p = new int[size];
    for(int i=0; i<size; i++)
    this->p[i] = p[i];
}

SortArray :: ~SortArray(){
    delete [] p;
}

SortArray SortArray :: operator +(SortArray& op2){ // 두 배열을 합쳐서 새로운 배열로 초기화
    SortArray tmp; // 새로운 SortArray 임시 객체 생성
    tmp.size = this->size +op2.size; // 새로운 객체의 배열의 크기를 현재 객체와 op2의 객체의 크기의 합으로 나타내겠다 main에서 c의 배열크기를 a배열크기 + b의 배열 크기를 나타냄
    tmp.p = new int[tmp.size]; // 새롭게 배열 c 배열 크기만큼 동적 메모리 할당
    for(int i=0; i<this->size; i++) //현재 객체의 배열 요소를 tmp 객체에 배열 복사
        tmp.p[i] = this->p[i]; 
    for(int i=0; i<op2.size; i++) //op2 객체의 배열요소를 tmp 객체에 배열 복사
        tmp.p[i+this->size] = op2.p[i]; //여기서 i+this->size는 결국 i가 늘어난 만큼 배열의 크기가 설정됨 op2의 배열요소를 tmp에 이어서 복사.

    return tmp;

}
SortArray& SortArray :: operator=(const SortArray& op2){ // 배열을 복사하고 기존의 배열을 해체
    delete [] this->p; // 기존 배열 메모리 해체
    this-> p = new int[op2.size]; //새로운 배열 할당
    this->size = op2.size; // 새로운 배열 크기 설정
    for(int i=0; i<op2.size; i++)
    this->p[i] = op2.p[i]; // 배열 요소 복사 

    return* this; // 객체 반환.
}

// -> 동적 메모리를 가지는 클래스에서 깊은 복사를 사용하여 복사한 두 객체가 독립적인 메모리를 가지게 하는것이 중요,
// 깊은 복사 수행.
// 메모리관리 등

void SortArray :: show(){
    this->sort();
    cout << "배열 출력 : ";
    for(int i=0; i<this->size; i++){
        cout << p[i] << ' ';
    }
    cout << endl;
}

int main(){
    int n[]={2, 20, 6};
    int m[]={10,7,8,30};
    SortArray a(n,3), b(m,4), c;

    c = a + b;
    // +연산자가 sortArray객체를 리턴하므로 복사 생성자가 필요.
    a.show();
    b.show();
    c.show();
}
*/
