#include<stdio.h>
#include<string.h>
#define MAX 1000
int main1(void)
{
    int n,i,j,t,s;
    char a[102],b[102],temp[105]={ 0 },sum[MAX]={ 0 };
    int len1, len2, flag;
    scanf("%d",&n);
    while(n--)
    {
        flag=0;
        scanf("%s%s",a,b);
        len1 = strlen(a);
        len2 = strlen(b);
        for(j=len2-1;j>=0;j--)
        {
            for(t=len1,i=len1-1;i>=0;i--,t--)
            {
                temp[t]=(a[i]-0x30)*(b[j]-0x30);
            }
            for(t=len1;t>=1;t--)
            {
                if(temp[t]>9)
                {
                    temp[t-1]+=temp[t]/10;
                    temp[t]%=10;
                }
            }
            for(s=len1+len2-flag,t=len1;t>=0;t--,s--)
                sum[s]+=temp[t];
            for(t=len1;t>=0;t--)
                temp[t]=0;
            for(s=len1+len2;s>=1;s--)
            {
                if(sum[s]>9)
                {
                    sum[s-1]+=sum[s]/10;
                    sum[s]%=10;
                }
            }
            flag++;
        }
        sum[len1+len2+1]='\0';
        for(s=0;s<=len1+len2;s++) {
              sum[s]=sum[s]+0x30;
        }
        for(s=0;s<len1+len2;s++) {
            if(sum[0]==0x30) {
                for(t=0;t<=len1+len2-s;t++)
                    sum[t]=sum[t+1];
            }
            else break;
        }
        printf("%s * %s = %s\n",a,b,sum);
        if(n!=0) {
            printf("/n");
        }
        for(s=len1+len2+1;s>=0;s--) {
            sum[s]=0;
        }
    }
    return 0;
}
