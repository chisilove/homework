#include <iostream>
using namespace std;

class String {
  private:
  char* str;
  int size;
  int count;
  public:
  String(int s){
    size = s;
    str = new char[size++]
    str[0] = " ";
    count++
  }
  
  String() : String(80){
  //80 symbols tak yak v zavdanni
  }
  
  String(const char* userstr) : String(strlen(userstr)){
  strcpy(str, userstr)
  }
  
  ~String(){
  delete[] str;
  count--;
  }

  void input(){
  cout << "enter text. u can enter max" << size << "symbols: ";
  cin.getline(str, size + 1);
  }

  void output(){
  cout << "output: ";
  cout << str;
  }

  static int getCount(){
    return count;
  }
}

int count = 0;


int main()
{
    cout<<"string count first: " << String::getCount();
    String s1;
    s1.input();

    String s2(15);
    s2.input();

    String s3("test string");
//output stringiv
    cout << "ready: \n";
    cout << "string 1: " << s1.print();
    cout << "string 2: " << s2.print();
    cout << "string test: " << s3.print();
    cout << "string count: " << String::getCount();
  

    return 0;
}
