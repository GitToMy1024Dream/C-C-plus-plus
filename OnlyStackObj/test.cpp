class AA  
{  
public:  
       static AA GetObject(int a)  
       {  
              return AA(a);  
       }  
protected:  
       AA(int a)  
       {  
              _a = a;  
       }  
private:  
       int _a;  
};  
void test()  
{  
       AA &a=AA::GetObject(10);  
} 