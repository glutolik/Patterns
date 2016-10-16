class Singleton {
private:
    Singleton(): data(10){}
    ~Singleton(){}

public:
    int data;
    static bool specimen;
    static Singleton* sin;
    static Singleton * GetSin(){
        if(!specimen){
            specimen = true;
            sin = new Singleton();
        }
        return sin;
    }

//    int GetData ();
//    void SetSpecimen (int s);
};

//inline int Singleton::GetData(){
//    return data;
//}
//inline void Singleton::SetSpecimen(int s){
//    specimen = s;
//}
