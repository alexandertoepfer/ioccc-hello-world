#include <iostream>
#include <cstring>
#include <sstream>
#include "constants.hpp"

                         #define chr unsigned char
                     /*+-+-+-+-*/#define puts(x) ot(x)
                   #define t(x,y) tp[x] = st[y]/*+-+-+*/
                 /*+-+-+-+*/#define tn(x,y) tc[x] = tc[y]
                #define ts(x,y) tc[x] = s[tc[y]]/*+-+-+-+*/
               #define t1(v,w,x,          y,z) tp[v]=(chr)\
              m2[st[w]]^m3[st                 [x]]^st[y]^st\
             [z]/*+Alex+-+-                    +-+-Toepfer-*/
             #define t2(v,                       w,x,y,z) tp[\
             v]=(chr)st[w                        ]^m2[st[x]]^\
             m3[st[y]]^st                        [z]/*+2020+*/
             #define t3(v                        ,w,x,y,z) tp\
             [v]=(chr)st[                        w]^st[x]^m2[\
             st[y]]^m3[st                        [z]]/*+-+-+*/
             #define t4(v                        ,w,x,y,z) tp\
             [v]=(chr)m3[                        st[w]]^st[x]\
             ^st[y]^m2[st                        [z]]/*+-+-+*/
             void ark(chr                        *st,chr*rk) {
            for(int i=0;i                        <16;i++)st[i ]
      ^=rk[i];}void rnd(chr*st,chr*ky,bool lt){for(int i=0;i<16;i++){
     st[i]=s[st[i]];}chr tp[16];t(0,0);t(1,5);t(2,10);t(3,15);t(4,4);t (
    5,9);t(6,14);t(7,3);t(8,8);t(9,13);t(10,2);t(11,7);t(12,12);t(13,1);t
    (14,6);t(15,11);for(int i=0;i<16;i++){st[i]=tp[i];}if(!lt){t1(0,0,1,2
    ,3);t2(1,0,1,2,3);t3(2,0,1,2,3);t4(3,0,1,2,3);t1(4,4,5,6,7);t2(5,4,5,
    6,7);t3(6,4,5,6,7);t4(7,4,5,6,7);t1(8,8,9,10,11);t2(9,8,9,10,11);t3 (
    10,8,9,10,11);t4(11,8,9,10,11);t1(12,12,13,14,15);t2(13,12,13,14,15);
    t3(14,12,13,14,15);t4(15,12,13        ,14,15);for(int i=0;i<16;i++) {
    st[i]=tp[i];}}ark(st,ky);}/*            */void aes(chr*ms,chr*ek,chr*
    em){chr st[16];for(int i=0;              i<16;i++){st[i]=ms[i];}ark (
    st,ek);for(int i=0;i<9;i++                ){rnd(st,ek+(16*(i+1)),!!0)
    ;}rnd(st,ek+160,true);for(                int i=0;i<16;i++){em[i]=st[
    i];}}class ot{ public:ot()=              default; ~ot()=default; void
    operator()(const char*ms){int           pl=strlen(ms);int ol=pl;if( (
    pl%16)!=0){pl=(pl/16+1)*16;}chr      *pm=new chr[pl];for(int i=0;i<pl
    ;i++){if(i>=ol){pm[i]=0;}else {      pm[i]=ms[i];}}chr*em=new chr[pl]
    ;std::string sr( "48 79 85 F3 6B B8 0D 69 EB 9A 49 AD C3 57 5E 5F" );
    std::istringstream hx(sr);chr ky[16]; int i=0;unsigned int ch;while (
    hx>>std::hex>>ch){ky[i]=ch;i++;}chr ek[176];for(int i=0;i<16;i++){ek[
    i]=ky[i];}int bg=16,ri=1;chr tc[4];while(bg<176){for(int i=0;i<4;i++)
    {tc[i]=ek[i+bg-4];}if(bg%16==0){chr tm=tc[0];tn(0,1);tn(1,2);tn(2,3);
    tc[3]=tm;ts(0,0);ts(1,1);ts(2,2);ts(3,3);tc[0]^=rc[ri++];}for(chr a=0
     ;a<4;a++){ek[bg]=ek[bg-16]^tc[a];bg++;}}for(int i=0;i<pl;i+=16){aes
       (pm+i,ek,em+i);}for(int i=0;i<pl;i++){std::cout<<std::hex<<(int
         )em[i]<<' ';}em[pl]='\0';std::cout<<std::endl<<em; delete[]
             pm;delete[]em;/*+-+-+-*/};/*+-+-+-*/};/*+-+*/ot ot;

int main() {
    puts("Hello World!");
}
