#include <iostream>
#include <string>

using namespace std;

class humanBeing12 {
   protected:
    int weight;
    float height;
   public:
    humanBeing(int a, float b):weight(a),height(b){}
    virtual float IMC(void)=0;
}; 

class man : public humanBeing {
    int age;
    string name;
  public:
    man(int a, string b, int c, float d):age(a),name(b),humanBeing(c,d){}
    float IMC(void){return weight/(height*height);}
    friend class woman;
};

class woman : public humanBeing{
    int age;
    string name;
  public:
    ~woman(){age = 0; name = "_";}//Destructor at the end of life-time
    woman(int a, string b, int c, float d):age(a),name(b),humanBeing(c,d){}
    float IMC(void){return weight/(height*height);}
    friend void printInfo(const woman&);//Friend function - Read-only
    void printInfoMan(const man& i){//Due to friend class
        cout<<i.name<<", you are "<<i.age<< endl;
    }
};

void printInfo(const woman& x){//Friend function
    cout << x.name << ", you are " << x.age << endl;
}

int main()
{
    man Ivan(22,"Ivan",84, 1.74);
    woman Susana(22, "Susana", 53, 1.69);
    
    Susana.printInfoMan(Ivan);//Due to friend class
    printInfo(Susana);//Friend function
    
    humanBeing *p1 = &Ivan;
    humanBeing *p2 = &Susana;
    
    cout << "Ivan, your MIC is: " << p1 -> IMC() << endl;
    cout << "Susana, your MIC is: " << p2 -> IMC() << endl;
    
    humanBeing *p3 = new man(23,"Francisco",70, 1.74);
    cout << "Francisco, your MIC is: " << p3 -> IMC() << endl;
    delete p3;
    

    return 0;
}
