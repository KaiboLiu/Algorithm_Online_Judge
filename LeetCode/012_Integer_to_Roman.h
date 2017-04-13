//#include <iostream>
//using namespace std;

/*
 #ifndef
...
 #endif
*/
    string Rom(int a,int b){
        string tmp = "",map[3];
        
//        if (b == 0) map = "IVX";
//        else if (b == 1) map = "XLC";
//        else if (b == 2) map = "CDM";
//        else if (b == 3) map = "MAA";

        if (b == 0) { map[0] = "I";  map[1] = "V";  map[2] = "X";}
        else if (b == 1) { map[0] = "X";  map[1] = "L";  map[2] = "C";}
        else if (b == 2) { map[0] = "C";  map[1] = "D";  map[2] = "M";}
        else if (b == 3) { map[0] = "M";  map[1] = "A";  map[2] = "A";}

//        cout<<map<<endl<<map[0]<<endl<<endl<<map[0]<<map[0]<<endl;

        if (a == 1) tmp += map[0];
        else if (a == 2) tmp += map[0]+map[0];
        else if (a == 3) tmp += map[0]+map[0]+map[0];
        else if (a == 4) tmp += map[0]+map[1];
        else if (a == 5) tmp += map[1];
        else if (a == 6) tmp += map[1]+map[0];
        else if (a == 7) tmp += map[1]+map[0]+map[0];
        else if (a == 8) tmp += map[1]+map[0]+map[0]+map[0];
        else if (a == 9) tmp += map[0]+map[2];

//cout<<tmp<<endl;
        return tmp;
    }
    
    string intToRoman(int num) {
        
        int tmp = num,l=0;
        int n[4]={0};
        string s="";
        while (tmp > 0){
            n[l] = tmp % 10;
            l++;
            tmp = tmp / 10;
        }
        for (int i = l-1;i>=0;i--)
            s = s + Rom(n[i],i);
        return s;
    }
    




   int main(){
       int num;
       cout<<endl<<"Input Arabic Number:";
       cin>>num;
       while(num>0 && num<4000)
           {
              cout<<"The Roman Number is "<<intToRoman(num)<<endl;
              cin>>num;
           }
        return 0;
    }
/*

   int main(){
       int num[] = {1,4,8,17,36,62,934,3998};

       for (int i=0;i<8;i++)
           {
              cout<<num[i]<<":The Roman Number is "<<intToRoman(num[i])<<endl;

           }
        return 0;
    }
*/
