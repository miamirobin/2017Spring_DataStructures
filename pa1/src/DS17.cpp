#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <ext/slist>
#include <string>
#include <stdlib.h> 
using namespace std;
 

int main( int argc, char** argv ){
    
// Initial process
    vector<string> vecA;
    vector<int> vecB;
    vector<int> vecH[5];
    vector<int> count;
    vector<int> file;

    ifstream ffin(argv[1]);
    string x;
    while (ffin >> x){
        vecA.push_back(x);

    }
    ffin.close();
   
    for (int i=0;i<10;i++){
          count.push_back(0);
    }

    for (int i=0;i<100;i++){

         for (int j=0;j<vecA[i].size();j++){
                 int p=int(vecA[i][j])-48;
                 file.push_back(p);
       
                 count[p]+=1;
         }
    }

    
    for (int i=0;i<10;i++){
          vecB.push_back(i);
    }
    for (int i=0;i<10;i++){
	      for (int j=0;j<10;j++){
               if(count[vecB[i]]<count[vecB[j]]){
                    int temp=vecB[j];
                    vecB[j]=vecB[i];
                    vecB[i]=temp;
                }
          }
    }

    for (int i=0;i<10;i++){
         cout<<vecB[i]<<" "<<count[vecB[i]]<<endl;
    }
    
// 1.Optimal
    __gnu_cxx::slist<int> sl;
    for (int i=0;i<10;i++){
        sl.push_front(vecB[i]);
    }
    int sum=0;
    for (int t=0;t<file.size();t++){
        int q=1;
        for (__gnu_cxx::slist<int>::iterator it=sl.begin();it!=sl.end();it++){
 
           if(*it==file[t]){break;}
           q+=1;
        }
        sum+=q;
        if ((t+1)%50==0 and t>0){
             vecH[0].push_back(sum);
        }
     }


//2.Movefront
     __gnu_cxx::slist<int> s2;
     for (int i=9;i>=0;i--){
         s2.push_front(i);
     }

     int sum1=0;
     for (int t=0;t<file.size();t++){
         int q1=1;
         for (__gnu_cxx::slist<int>::iterator it=s2.begin();it!=s2.end();it++){
 
            if(*it==file[t]){
                int temp=*it;
                s2.erase(it);
                s2.push_front(temp);
                break;
            }
            q1+=1;
         }

         sum1+=q1;
         if ((t+1)%50==0 and t>0){
             vecH[1].push_back(sum1);
         }
      }


//3.Transpose
     __gnu_cxx::slist<int> s3;

     for (int i=9;i>=0;i--){
       s3.push_front(i);
     }

     int sum2=0;
     for (int t=0;t<file.size();t++){
          int q2=1;
          int o=0;
          for (__gnu_cxx::slist<int>::iterator it=s3.begin();it!=s3.end();it++){
                o+=1;
                if(*it==file[t]){

                    int temp=*it;
 
                    s3.erase(it);

                    s3.push_front(temp);
                    int a=0;
                    for (int l=1;l<o-1;l++){

                         __gnu_cxx::slist<int>::iterator it2= s3.begin();

                         for (int m=0;m<a;m++){

                              it2++ ;

                         }
                         int temp=*it2;
                         s3.erase(it2);

                         it2= s3.begin();
                         for (int m=0;m<a+1;m++){
                               it2++ ;
                         }
                         s3.insert(it2,temp);
                               a+=1;
                    }

                    break;
                 }
                       
                 q2+=1;
           }
           sum2+=q2;
           if ((t+1)%50==0 and t>0){
              vecH[2].push_back(sum2);
           }
    }

//4. Bit-1
    __gnu_cxx::slist<int> s4;

    for (int i=9;i>=0;i--){
        s4.push_front(i);
    }
    vector<int> vecX;
    for (int z=0;z<10;z++){
          int v2 = rand() % 2;
          vecX.push_back(v2);
    }

    int sum3=0;
    for (int t=0;t<file.size();t++){
         int q3=1;
         for (__gnu_cxx::slist<int>::iterator it=s4.begin();it!=s4.end();it++){
 
             if(*it==file[t]){

                if(vecX[*it]==1){vecX[*it]=0;}
                else{vecX[*it]=1;}
                if(vecX[*it]==1){
                   int temp=*it;
                   s4.erase(it);
                   s4.push_front(temp);
                }
                break;
              }
              q3+=1;
          }
          sum3+=q3;
          if ((t+1)%50==0 and t>0){
             vecH[3].push_back(sum3);
          }
      }
      vecX.clear();


//5. Bit-2
      __gnu_cxx::slist<int> s5;

      for (int i=9;i>=0;i--){
         s5.push_front(i);
      }
      vector<int> vecY;
      for (int z=0;z<10;z++){
         int  v3=rand() % 2;
         vecY.push_back(v3);
      }
      int sum4=0;
      for (int t=0;t<file.size();t++){
          int q4=1;
          for (__gnu_cxx::slist<int>::iterator it=s5.begin();it!=s5.end();it++){
 
               if(*it==file[t]){
                  if(vecY[*it]==1){vecY[*it]=0;}
                  else{vecY[*it]=1;}
                  if(vecY[*it]==1){
                    int temp=*it;
                    s5.erase(it);
                    s5.push_front(temp);
                  }
                  break;
               }
           q4+=1;
           }
           sum4+=q4;
           if ((t+1)%50==0 and t>0){
              vecH[4].push_back(sum4);
           }
       }

       vecY.clear();


// Output results
        cout<<"Optimal        ";
        for (int k=1;k<=20;k++){
             cout<<"("<<k*50<<", "<<vecH[0][k-1]<<") ";
        }
        cout<<" "<<endl;
        cout<<"Move-to-front  ";
        for (int k=1;k<=20;k++){
             cout<<"("<<k*50<<", "<<vecH[1][k-1]<<") ";
        }
        cout<<" "<<endl;
        cout<<"Transpose      ";
        for (int k=1;k<=20;k++){
             cout<<"("<<k*50<<", "<<vecH[2][k-1]<<") ";
        }
        cout<<" "<<endl;
        cout<<"Bit-1          ";
        for (int k=1;k<=20;k++){
             cout<<"("<<k*50<<", "<<vecH[3][k-1]<<") ";
        }
        cout<<" "<<endl;
        cout<<"Bit-2          ";
        for (int k=1;k<=20;k++){
             cout<<"("<<k*50<<", "<<vecH[4][k-1]<<") ";
        }
        cout<<" "<<endl;

    
} 
 
