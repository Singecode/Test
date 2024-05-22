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

 Matrix& operator+=(Matrix &mat1, Matrix mat2){
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