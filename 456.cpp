#include<stdio.h>
typedef struct man
{
    char name[20];
    long long phon;
}People;
People p[1000];
int main()
{
    freopen("数据.txt","r",stdin);//文件输入
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",p[i].name);
        scanf("%lld",&p[i].phon);
    }
    freopen("con","r",stdin);//取消文件读入
    printf("========================================\n");//菜单栏
    printf("=                菜单                  =\n");
    printf("=            1.顺序查找。              =\n");
    printf("=            2.逆序查找。              =\n");
    printf("=            3.二分查找。              =\n");
    printf("=            4.退出程序。              =\n");
    printf("========================================\n");
    while(1)
    {
        printf("请输入你想要使用的功能：\n");
        int t;
        scanf("%d",&t);
        long long number;
        int ass=0,ans=0;
        if(t==1)//顺序查找
        {
            printf("请输入你想要查询的电话号码（11位数字）：\n");
            scanf("%lld",&number);
            for(int i=0;i<n;i++)
            {
                ans++;
                if(number==p[i].phon)
                {
                    ass=1;
                    printf("该号码对应的名字是：%s\n",p[i].name);
                    printf("查询次数为：%d\n",ans);
                    break;
                }
            }
        }
        else if(t==2)//逆序查找
        {
            printf("请输入你想要查询的电话号码（11位数字）：\n");
            scanf("%lld",&number);
            for(int i=n;i>=0;i--)
            {
                ans++;
                if(number==p[i].phon)
                {
                    ass=1;
                    printf("该号码对应的名字是：%s\n",p[i].name);
                    printf("查询次数为：%d\n",ans);
                    break;
                }
            }
        }
        else if(t==3)//二分查找
        {
            printf("请输入你想要查询的电话号码（11位数字）：\n");
            scanf("%lld",&number);
            for(int i=0;i<n;i++)//二分查找首先要有序，所以要先根据号码排序
            {
                for(int j=i+1;j<n;j++)
                {
                    if(p[i].phon>p[j].phon)
                    {
                        People a=p[i];
                        p[i]=p[j];
                        p[j]=a;
                    }
                }
            }
            int l=0,r=n-1;
            while(r>=l)
            {
                ans++;
                int mid=(l+r)/2;
                if(p[mid].phon==number)
                {
                    ass=1;
                    printf("该号码对应的名字是：%s\n",p[mid].name);
                    printf("查询次数为：%d\n",ans);
                    break;
                }
                else if(p[mid].phon<number)
                {
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
        }
        else
        {
            break;
        }
        if(!ass)
            printf("抱歉！没有你想要查询的号码。\n");
    }
    printf("谢谢使用！\n");
    return 0;
}
