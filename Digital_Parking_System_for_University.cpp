#include <bits/stdc++.h>
using namespace std;
class Admin{
private:
string email;
int pass;
public:
Admin(){
    email="demo@gmail.com";
    pass=1234;
}

Admin(string email, int pass){
    this->email=email;
    this->pass=pass;
}


void get(){
    cout<<email<<" "<<pass<<endl;
}

};

int main()
{
  
  Admin a("tanjidnafis@gmail.com",12);

  a.get();
  

    return 0;
}