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
  cin.getline(str, size + 1); //s4itue ves ryadok
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
    cout<<"class";
    return 0;
}
