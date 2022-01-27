
Alex worked at a big IT-company called Macrohard. Once, when he faced a large amount of data, he decided to leave this company and develop his own database which would be much better than all existing ones. When he was done with this he realized that the performance of some database queries might be improved. Alex uses AQL (Alex Query Language) which accidentally turned out to be exactly the same as the popular SQL. One of the most important problems he faced was the following.

Consider n objects. The i-th object has ki (1 ≤ ki ≤ 4) properties in the form of key=value. Any object can't have two or more properties with the same key. Alex needs to improve the performance of the following query:

SELECT COUNT(*) FROM Objects WHERE key1=value1 AND...  AND keyl=valuel
(1 ≤ l ≤ 4, all keys are distinct)
This means that Alex's database has to find the number of objects which have properties key1, key2,..., keyl with the values value1, value2,..., valuel respectively. Even if an object has extra properties it should be counted.

Your task is to help Alex to write an efficient program to process such queries.

Input
The first line of the input contains a single integer n (1 ≤ n ≤ 5 · 104) — the number of objects. Following n lines describe objects by their properties. Each line contains the integer ki (1 ≤ ki ≤ 4) followed by ki tokens in the form of keyi,j=valuei,j separated by a single space. Both keyi,j and valuei,j consist of digits and lowercase Latin letters. The keyi,j are distinct for each object. It is possible that different objects have exactly the same set of properties.

The next line of the input contains a single integer m (1 ≤ m ≤ 105) — the number of queries. The following m lines describe the queries. Each line contains a single integer li (the number of properties that describe the i-th query) followed by li (1 ≤ li ≤ 4) tokens keyi,j=valuei,j separated by a single space, where keyi,j and valuei,j consist of digits and lowercase Latin letters. The keyi,j are distinct for each query.

Lengths of keyi,j and valuei,j both for objects and queries are between 1 and 5 characters inclusive.

Output
Print m lines, the i-th line should contain the result of the i-th query.

Example(s)
sample input
sample output
4
3 width=5 ht=3 len=10
2 name=circ rad=5
2 name=circ rad=5
3 name=sqr width=5 ht=3
4
2 ht=3 width=5
1 name=circ
1 name=sqr
2 width=5 ht=03
2
2
1
0
----------------------------------------------------------------------------------------------

----------------------------------------------------------------------------------------------

#include <cstdio>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string,int> cont;

int main(){
    int N,Q;
    char aux[20];
    string prop[4];
    
    scanf("%d",&N);
    
    for(int i = 0,sz;i < N;++i){
        scanf("%d",&sz);
        
        for(int j = 0;j < sz;++j){
            scanf("%s",aux);
            prop[j] = string(aux);
        }
        
        sort(prop,prop + sz);
        
        for(int mask = 0;mask < (1 << sz);++mask){
            string s;
            
            for(int j = 0;j < sz;++j)
                if(mask >> j & 1)
                    s += prop[j] + " ";
            
            ++cont[s];
        }
    }
    
    scanf("%d",&Q);
    
    for(int i = 0,sz;i < Q;++i){
        scanf("%d",&sz);
        
        for(int j = 0;j < sz;++j){
            scanf("%s",aux);
            prop[j] = string(aux);
        }
        
        sort(prop,prop + sz);
        
        string s;
        
        for(int j = 0;j < sz;++j)
            s += prop[j] + " ";
        
        printf("%d\n",cont[s]);
    }
    
    return 0;
}



