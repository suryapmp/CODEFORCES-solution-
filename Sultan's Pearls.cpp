
Sultan Suleiman was so rich that legends spread far and wide about his treasures. This problem is going to be about one of those legends.

One of the sultan's favorite treasures was a string of finest pearls that he kept on the bedside table. He never touched the string as it had too many pearls on it to wear. The sultan's cunning servant decided to take advantage of this fact and "borrow" a few pearls. The string consisted of n pearls, m of them hung down from the bedside table. In this problem we will consider the pearls indexed by integers from 1 to n, starting from the end that lies on the table, that is, pearls 1, 2,..., n-m were located on the table and pearls n-m+1, n-m+2,..., n hung down from it.


Sample for n=10 and m=3.


The servant decided to take exactly one pearl from one end of the string every day. But he had to be perfectly careful as every evening the sultan enjoyed looking at the string and counting the number of the hanging pearls. That's why after the servant took a pearl from the hanging end, he had to pull the string one pearl lower so that the number of the hanging pearls equalled m again. Certainly, if the servant took a pearl from the lying end, he had to leave the hanging part as it was.

Each pearl has some mass, and the string may fall down if the hanging part is too heavy. Of course, the servant must avoid that. The string must remain motionless after every action of the servant.

More formally, assume that the i-th pearl in the string has mass of wi. Also let's say that the total mass of the hanging m pearls equals Wh, and the total mass of the pearls on the table equals Wt. Then the hanging part pulls the whole string down, if Wh > k · Wt, where k is the coefficient of friction of the pearls against the table. The coefficient k is the same for all pearls.

The pearls on the string had not only different masses but also different prices: the i-th pearl costs ci dinars. The servant's aim was to steal the pearls for the maximum sum and avoid the sultan's suspicions. His plan didn't come out very well: he made a mistake somewhere in his calculations, his theft was discovered and he was executed.

Nobody is going to execute you, of course, so we suggest you to solve the problem that proved to be too hard for the sultan's servant.

Input
The first line contains three integers n, m and k (2 ≤ n ≤ 2 · 105, 1 ≤ m < n, 1 ≤ k ≤ 10). Each of the following n lines contains two integers wi and ci — the mass and the price of the i-th pearl (1 ≤ wi, ci ≤ 1000). It is guaranteed that initially the string is motionless, that is, the hanging part doesn't pull the whole string down.

Output
In the first line print two space-separated integers p and s — the number of pearls you can take to get the maximum sum of money, and the sum you can get. In the second line print the string consisting of p characters 'H' or 'T'. If the pearl that is the i-th to take should be taken from the hanging end, then the i-th character of the string must be 'H', otherwise — 'T'. If there are multiple optimal solutions, print any of them.

If the servant can't take any pearl, just print one line containing two zeroes. You may leave the second line empty or do not print it at all.

Example(s)
sample input
sample output
5 2 1
5 3
4 2
6 4
3 2
2 2
2 5
TT

sample input
sample output
20 7 2
3 4
8 4
8 5
6 14
5 10
3 18
2 5
2 4
1 6
3 11
4 3
3 5
2 8
4 6
9 14
7 2
7 6
6 4
8 2
10 5
11 60
HTHTHTHHHHH



Note
There is the explanation to the second sample.

Initially the mass of pearls on the table was Wt = 50, and the mass of the hanging pearls was Wh = 51. However, as the coefficient of friction equals 2, the string is motionless (50 · 2 = 100 > 51).

On the first step we take a pearl from the hanging part of the string (H), then we need to pull the string one pearl lower so that the hanging part contained 7 strings again. After that Wt = 48, and Wh = 43 (the pearl number 20 with value 5 will be stolen and the pearl number 13 will be the topmost pearl in the hanging part of the string).

On the second step we take a pearl from the end of the string that lies on the table (T). Wh = 43 still, Wt = 45, (45 · 2 > 43), the total price of the stolen treasure is S = 9.

The table describes the values of Wt, Wh and S after each step.





Step	End	Wt	Wh	S
1	H	48	43	5
2	T	45	43	9
3	H	42	38	11
4	T	34	38	15
5	H	30	36	19
6	T	22	36	24
7	H	19	32	30
8	H	18	26	32
9	H	16	19	46
10	H	14	17	52
11	H	11	18	60


Note that after the 11-th step it is impossible to take any more pearls without disrupting the balance.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
SOLUTION 
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int w[200010];
int c[200010];
int ww[200010];
int cc[200010];

int main()
{
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
  {
    scanf("%d%d", &w[i + 1], &c[i + 1]);
    ww[i + 1] = w[i + 1] + ww[i];
    cc[i + 1] = c[i + 1] + cc[i];
  }
 
  int l = n - m;
  int r = n;
  int p = 0, s = 0;
  
  int maxc = 0;
  int maxl = 0;
  int maxr = n;
  
  for (; r > m; r--)
  { 
    while (l < n - m && (ww[r-m] - ww[l+1]) * k >= ww[r] - ww[r-m]) 
      l++;    
    
    while (l > 0 && (ww[r-m] - ww[l]) * k < ww[r] - ww[r-m]) 
      l--;    
    
    if ((ww[r-m] - ww[l]) * k < ww[r] - ww[r-m])
      break;
    
    ll sm = cc[l] + (cc[n] - cc[r]);
       
    if (sm > maxc)
    {
      maxc = sm;
      maxl = l;
      maxr = r;
    }
  }
  
  printf("%d %d\n", maxl + (n - maxr), maxc);
  
  for (int i = maxr; i < n; i++)
    printf("H");
  for (int i = 0; i < maxl; i++)
    printf("T");
  
  printf("\n");

  return 0;
}