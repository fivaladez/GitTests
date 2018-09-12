#include <iostream>
#include <string>

using namespace std;

class numbers {
    public:
        static float n;
        float x,y;
        numbers(){n++;}
        numbers(float a, float b):x(a), y(b){}
};

numbers operator+ (numbers& first, numbers& second){
    numbers temp;
    temp.x = first.x + second.x;
    temp.y = first.y + second.y;
    return temp;
}

numbers operator- (numbers& first, numbers& second){
    numbers temp;
    temp.x = first.x - second.x;
    temp.y = first.y - second.y;
    return temp;
}

numbers operator* (numbers& first, numbers& second){
    numbers temp;
    temp.x = first.x * second.x;
    temp.y = first.y * second.y;
    return temp;
}

numbers operator/ (numbers& first, numbers& second){
    numbers temp;
    temp.x = first.x / second.x;
    temp.y = first.y / second.y;
    return temp;
}
float numbers::n=0;//Initialize a member

int main()
{
    numbers A(6, 4);
    numbers B(2, 2);
    numbers result;
    result = A + B;
    cout << result.x << " " << result.y << endl;
    cout << result.n << endl;
    result = A - B;
    cout << result.x << " " << result.y << endl;
    cout << result.n << endl;
    result = A * B;
    cout << result.x << " " << result.y << endl;
    cout << result.n << endl;
    result = A / B;
    cout << result.x << " " << result.y << endl;
    cout << result.n << endl;
    numbers *C = new numbers;//Creates a space to this pointer
    cout << numbers::n << endl;//We can do this because "n" is the same for all the classes numbers
    cout << C->n << endl;
    
    //cout << numbers::x << endl; This operation is an error

    return 0;
}
