#include<stdio.h>
typedef struct man
{
    char name[20];
    long long phon;
}People;
People p[1000];
int main()
{
    freopen("����.txt","r",stdin);//�ļ�����
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",p[i].name);
        scanf("%lld",&p[i].phon);
    }
    freopen("con","r",stdin);//ȡ���ļ�����
    printf("========================================\n");//�˵���
    printf("=                �˵�                  =\n");
    printf("=            1.˳����ҡ�              =\n");
    printf("=            2.������ҡ�              =\n");
    printf("=            3.���ֲ��ҡ�              =\n");
    printf("=            4.�˳�����              =\n");
    printf("========================================\n");
    while(1)
    {
        printf("����������Ҫʹ�õĹ��ܣ�\n");
        int t;
        scanf("%d",&t);
        long long number;
        int ass=0,ans=0;
        if(t==1)//˳�����
        {
            printf("����������Ҫ��ѯ�ĵ绰���루11λ���֣���\n");
            scanf("%lld",&number);
            for(int i=0;i<n;i++)
            {
                ans++;
                if(number==p[i].phon)
                {
                    ass=1;
                    printf("�ú����Ӧ�������ǣ�%s\n",p[i].name);
                    printf("��ѯ����Ϊ��%d\n",ans);
                    break;
                }
            }
        }
        else if(t==2)//�������
        {
            printf("����������Ҫ��ѯ�ĵ绰���루11λ���֣���\n");
            scanf("%lld",&number);
            for(int i=n;i>=0;i--)
            {
                ans++;
                if(number==p[i].phon)
                {
                    ass=1;
                    printf("�ú����Ӧ�������ǣ�%s\n",p[i].name);
                    printf("��ѯ����Ϊ��%d\n",ans);
                    break;
                }
            }
        }
        else if(t==3)//���ֲ���
        {
            printf("����������Ҫ��ѯ�ĵ绰���루11λ���֣���\n");
            scanf("%lld",&number);
            for(int i=0;i<n;i++)//���ֲ�������Ҫ��������Ҫ�ȸ��ݺ�������
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
                    printf("�ú����Ӧ�������ǣ�%s\n",p[mid].name);
                    printf("��ѯ����Ϊ��%d\n",ans);
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
            printf("��Ǹ��û������Ҫ��ѯ�ĺ��롣\n");
    }
    printf("ллʹ�ã�\n");
    return 0;
}
