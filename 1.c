#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10000
struct Book
{
    char class[20];
    char name[20];
    char no[10];
    char bookname[20];
    int overdue;
    float fine;
};
//����Ϊȫ�ֱ�������
int m;//��¼�ṹ�������е�Ԫ�ظ���
char filename[20];//�������ݵ��ļ����ļ���
char title[200]="Class                   Name                     Booknumber                   Bookname                 Overdue(day)                 Fine\n";
//��¼�ı��ļ��ı��⣨�༶��������ͼ���ŵȣ�
struct Book ep[N];//�趨һ���㹻��Ľṹ�����鴢������
int a=0;//���Ʋ˵����˳������ʹ��

//����Ϊ��������
void createfile(void);
void enter(struct Book bok[],int);//¼����Ϣ����--�ṹ����������Ԫ��
void enterfile(struct Book bok[],int n);//���ṹ������д���ļ�����
void show();//��ʾ���ݺ���
void change(struct Book bok[]);//�޸ĺ���
void delete(struct Book bok[]);//ɾ������
void search(struct Book bok[]);//��ѯ����
void count1(struct Book bok[]);//ͳ��ĳѧ���������
void count2(struct Book bok[]);//ͳ��ĳ�༶�������
int menu(void);//�˵�����
void cover(void);//���溯��
void image(char,int);//����˵����ź���

void add(struct Book bok[]);//׷���ļ����ݺ���
void my_backup(void);//���ݺ���
void sort(struct Book bok[]);//��������������

int main()
{
    cover();//��ʾ����
    while(a==0)
    {
        system("cls");
        a=menu();
        system("pause");
    }

}


//����Ϊ�Զ��庯������
void cover(void)
{

    printf("\n\n\n\n\n\n\t\t\t     Welcome to use the system!   \n\n\n");
    printf("\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("\t     *                                                       *\n\n");
    printf("\t     *            Overdue Book Management System             *\n\n");
    printf("\t     *                                                       *\n\n");
    printf("\t     * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n\n");
    printf("\t\t\t\t\t                                      Class 7\n\n");
    printf("\t\t\t\t\t                                      producer:Weng Jiayou     \n\n");
    printf("\t\t\t\t\t                                      Student ID:3122004583   \n\n");
    printf("       input 'enter' to continue!\n");
    getchar();
}

void image(char c,int n)
{
    int i;
    for(i=0;i<n;i++)
    putchar(c);
}

int menu(void)
{
    char flag;
    printf("*********************************************************\n");
    printf("*                        Menu                           *\n");
    printf("*********************************************************\n");
    printf("*      1.enter redords     *       2.display records    *\n");
    printf("*********************************************************\n");
    printf("*      3.change records    *       4.delete records     *\n");
    printf("*********************************************************\n");
    printf("*      5.search records    *       6.count records      *\n");
    printf("*********************************************************\n");
    printf("*      7.add records       *       8.sort records       *\n");
    printf("*********************************************************\n");
    printf("*      9.backup records    *       *.exit system       *\n");
    printf("*********************************************************\n");
    printf("\n\n\n");
    printf("                 input the number code\n");
    printf(" Tip:you must use funtion 1 before using other funtions!\n");
    scanf("%c",&flag);
    
    system("cls");
    switch(flag)
    {
        case '1':
        {
            int k;
            printf("input the number of new records:\n");
            scanf("%d",&k);//system("cls");
            createfile();
            enter(ep,k);
            enterfile(ep,m);
            break;
        }
        case '2':
        {
            show();
            break;
        }
        case '3':
        {
            change(ep);
            break;
        }
        case '4':
        {
            delete(ep);
            break;
        }
        case '5':
        {
            search(ep);
            break;
        }
        case '6':
        {
            int l;
            printf("input 0 to search for a student,or 1 for a class\n");
            scanf("%d",&l);
            if(l==0)count1(ep);
            else if(l==1)count2(ep);
            break;
        }
        case '7':
        {
            add(ep);
            break;
        }
        case '8':
        {
            sort(ep);
            break;
        }
        case '9':
        {
            my_backup();
            break;
        }
        case '*':
        {
            image('*',50);putchar(10);
            image('*',11);printf("thanks for using the system!");image('*',11);putchar(10);
            image('*',50);putchar(10);
            a=1;
            return 1;
            break;
        }
        case '\n':break;
        default:printf("wrong input!\n");break;
    }
    return 0;
}

void createfile(void)
{
    FILE *fp;
    char ch;
    printf("input the filename to save the data:\n");
    printf("tip:if making mistakes,use this function again.\n");
    scanf("%s",filename);
    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("cannot create the file!\n");
        exit(0);
    }
    fputs(title,fp);//������д���ļ�
    if(fp!=NULL)printf("create success!\n");
    fclose(fp);
    putchar(10);
}

void enter(struct Book bok[],int n)//n�����ӽṹ����������ĸ���
{
    int i;
    m=n;
    printf("input the information:\nclass   \t\tname\t\t\tbookno  \t\tbookname\t\toverdue \t\t\n");
    for(i=0;i<n;i++)
    {
        scanf("%s %s %s %s %d",&bok[i].class,&bok[i].name,&bok[i].no,&bok[i].bookname,&bok[i].overdue);
        getchar();
        bok[i].fine=bok[i].overdue*0.2;
    }
    if(bok[n-1].overdue!=0)printf("enter data success!\n");
}//¼��ṹ�������������

void enterfile(struct Book bok[],int n)
{
    FILE *fp;
    int i;
    if((fp=fopen(filename,"w+"))==NULL)
    {
        printf("cannot open the file!\n");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        fprintf(fp,"%-25s%-25s%-25s%-25s%-25d0.2*%-21d\n",bok[i].class,bok[i].name,bok[i].no,bok[i].bookname,bok[i].overdue,bok[i].overdue);
    }
    if(fp!=NULL)
    printf("sucess saving!\n");
    fclose(fp);

}//�ѽṹ����������ݶ����ļ�����,ÿһ�δ洢�����ǰһ�ε�����

void show()
{
    FILE *fp;
    char ch;
    if((fp=fopen(filename,"r"))==NULL)
    {
        printf("cannot read the file!\n");
        exit(0);
    }
    puts(title);
    ch=fgetc(fp);
    while(!feof(fp))
    {
        putchar(ch);
        ch=fgetc(fp);
    }
    putchar(10);
    fclose(fp);
}//��ʾ����

void change(struct Book bok[])
{
    FILE *fp;
    char no[10];
    int i,day;
    show();
    putchar(10);
    printf("input the number of the book you wanna change:\n");
    scanf("%s",no);
    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("cannot open the file!\n");
        exit(0);
    }
    
    for(i=0;i<N;i++)
    {
        if(strcmp(bok[i].no,no)==0)
        break;
    }
    
    if(i<N)
    {
        printf("the record you wanna change:\n");
        printf("%-25s%-25s%-25s%-25s%-25d0.2*%-21d\n",bok[i].class,bok[i].name,bok[i].no,bok[i].bookname,bok[i].overdue,bok[i].overdue);
    }//�������Ҫ�޸ĵ�������

    else if(i==N)
    printf("no records!\n");

    if(i<N)
    {
        printf("input the new overdue day:\n");
        scanf("%d",&day);
        bok[i].overdue=day;
        printf("the new record:\n");
        printf("%-25s%-25s%-25s%-25s%-25d0.2*%-21d\n",bok[i].class,bok[i].name,bok[i].no,bok[i].bookname,bok[i].overdue,bok[i].overdue);
    }
    fputs(title,fp);
    for(i=0;i<m;i++)
    {
        fprintf(fp,"%-25s%-25s%-25s%-25s%-25d0.2*%-21d\n",bok[i].class,bok[i].name,bok[i].no,bok[i].bookname,bok[i].overdue,bok[i].overdue);
    }//���޸ĺ����������д���ļ�
    if(i<N)
    printf("change success!\n");
    fclose(fp);
    
}//�޸ĺ���

void delete(struct Book bok[])
{
    FILE *fp;
    int i,t;
    char no[10];
    show();
    putchar(10);
    printf("input the no of the book you wanna delete:\n");
    scanf("%s",no);
    for(i=0;i<m;i++)
    {
        if(strcmp(bok[i].no,no)==0)
        t=i;
        //break;
    }
    for(i=t;i<m-1;i++)
    {
        //bok[i].overdue=bok[i+1].overdue;
        //bok[i].fine=bok[i+1].fine;
        //strcpy(bok[i].class,bok[i+1].class);
        //strcpy(bok[i].bookname,bok[i+1].bookname);
        //strcpy(bok[i].name,bok[i+1].name);
        //strcpy(bok[i].no,bok[i+1].no);
        bok[i]=bok[i+1];
    }//ֻ��t<m-1�Żᴥ����ѭ��
    if(t==m-1)
    {
        bok[i].overdue=0;
        bok[i].fine=0.0;
        strcpy(bok[i].class,"");
        strcpy(bok[i].bookname,"");
        strcpy(bok[i].name,"");
        strcpy(bok[i].no,"");
    }//��Ҫɾ���������һ����¼ʱ

    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("cannot open the file!\n");
        exit(0);
    }
    if(t<m)
    {
        fputs(title,fp);
        for(i=0;i<m-1;i++)
        {
            fprintf(fp,"%-25s%-25s%-25s%-25s%-25d0.2*%-21d\n",bok[i].class,bok[i].name,bok[i].no,bok[i].bookname,bok[i].overdue,bok[i].overdue);
        }//��ɾ�����ݺ�ı�������д�봢���ļ�
        printf("delete sucess!\n");
    }
    else if(t==m)printf("no records!\n");
    m--;
    fclose(fp);
}//ɾ������

void search(struct Book bok[])
{
    int i,flag=0;
    char yourclass[20];
    printf("input your class:\n");
    scanf("%s",yourclass);
    for(i=0;i<m;i++)
    {
        if(strcmp(yourclass,bok[i].class)==0)
        {flag=1;
        puts(title);
        printf("%-25s%-25s%-25s%-25s%-25d0.2*%-21d\n",bok[i].class,bok[i].name,bok[i].no,bok[i].bookname,bok[i].overdue,bok[i].overdue);
        putchar(10);
        }
    }
    if(flag==0)
    printf("no records!\n");
}

void count1(struct Book bok[])
{
    int i,flag=0;
    char yourname[20];
    float fine=0;
    printf("input yourname:\n");
    scanf("%s",yourname);

    for(i=0;i<m;i++)
    {
        if(strcmp(yourname,bok[i].name)==0)
        {flag=1;
        puts(title);
        printf("%-25s%-25s%-25s%-25s%-25d0.2*%-21d\n",bok[i].class,bok[i].name,bok[i].no,bok[i].bookname,bok[i].overdue,bok[i].overdue);
        fine+=bok[i].fine;
        }
    }
    if(flag==1)printf("total fine:%f\n",fine);
    if(flag==0)
    {
        printf("no records!\n");
    }
}

void count2(struct Book bok[])
{
    int i,flag=0;
    char class1[20];
    float fine=0;
    printf("input the class to count the fine:\n");
    scanf("%s",class1);

    for(i=0;i<m;i++)
    {
        if(strcmp(class1,bok[i].class)==0)
        {flag=1;
        puts(title);
        printf("%-25s%-25s%-25s%-25s%-25d0.2*%-21d\n",bok[i].class,bok[i].name,bok[i].no,bok[i].bookname,bok[i].overdue,bok[i].overdue);
        fine+=bok[i].fine;
        }
    }
    if(flag=1)printf("the whole class fine:%f\n",fine);
    else if(flag==0)printf("no records!\n");

}


void add(struct Book bok[])
{
    FILE *fp;
    char ch;

    if((fp=fopen(filename,"a"))==NULL)
    {
        printf("cannot open the file!\n");
        exit(0);
    }
    m++;
    printf("input the related information you wanna add.\n");
    printf("input the class:\n");
    scanf("%s",bok[m-1].class);
    printf("input the student name:\n");
    scanf("%s",bok[m-1].name);
    printf("input the number of book:\n");
    scanf("%s",bok[m-1].no);
    printf("input the bookname:\n");
    scanf("%s",bok[m-1].bookname);
    printf("input the overdue days:\n");
    scanf("%d",&bok[m-1].overdue);
    bok[m-1].fine=0.2*bok[m-1].overdue;
    printf("add sucess!\n");

    fprintf(fp,"%-25s%-25s%-25s%-25s%-25d0.2*%-21d\n",bok[m-1].class,bok[m-1].name,bok[m-1].no,bok[m-1].bookname,bok[m-1].overdue,bok[m-1].overdue);
    //׷�����ݵ��ļ���
    fclose(fp);
}//�ļ�׷�����ݺ���

void my_backup(void)
{
    FILE *out,*in;
    char c;

    if((out=fopen("backup.txt","w"))==NULL)
    {
        printf("cannot open the backup file!\n");
        exit(0);
    }
    if((in=fopen(filename,"r"))==NULL)
    {
        printf("cannot open the file gonna be backuped!\n");
        exit(0);
    }

    c=fgetc(in);
    while(!feof(in))
    {
        fputc(c,out);
        c=fgetc(in);
    }

    printf("backup success!\n");

    fclose(in);
    fclose(out);
}//���ݺ���

void sort(struct Book bok[])
{
    int flag;
    int i,j,min=0,max=0;
    struct Book t;
    FILE *fp;
    char ch;
    printf("choose low->high,input 1;otherwise,input 0;\n");
    scanf("%d",&flag);
    //����Ϊѡ������
    if(flag==1)
    {
        for(i=0;i<m-1;i++)
        {
            min=i;
            for(j=i+1;j<m;j++)
            {
                if(bok[j].overdue<bok[min].overdue)
                min=j;
                if(i!=min)
                {
                    t=bok[i];
                    bok[i]=bok[min];
                    bok[min]=t;
                }
            }
        }
        for(i=0;i<m-1;i++)
        {
            min=i;
            for(j=i+1;j<m;j++)
            {
                if(bok[j].overdue<bok[min].overdue)
                min=j;
                if(i!=min)
                {
                    t=bok[i];
                    bok[i]=bok[min];
                    bok[min]=t;
                }
            }
        }
    }//��С���������
    else if(flag==0)
    {
        for(i=0;i<m-1;i++)
        {
            max=i;
            for(j=i+1;j<m;j++)
            {
                if(bok[j].overdue>bok[max].overdue)
                max=j;
                if(i!=max)
                {
                    t=bok[i];
                    bok[i]=bok[max];
                    bok[max]=t;
                }
            }
        }
        for(i=0;i<m-1;i++)
        {
            max=i;
            for(j=i+1;j<m;j++)
            {
                if(bok[j].overdue>bok[max].overdue)
                max=j;
                if(i!=max)
                {
                    t=bok[i];
                    bok[i]=bok[max];
                    bok[max]=t;
                }
            }
        }
    }//�Ӵ�С������

    if((fp=fopen(filename,"w"))==NULL)
    {
        printf("cannot save the data in file!\n");
        exit(0);
    }
    fputs(title,fp);
    for(i=0;i<m;i++)
    {
        fprintf(fp,"%-25s%-25s%-25s%-25s%-25d0.2*%-21d\n",bok[i].class,bok[i].name,bok[i].no,bok[i].bookname,bok[i].overdue,bok[i].overdue);
    }//����������������д���ļ�
    if(flag==0||flag==1)
    printf("sort success!\n");
    else printf("sort fail\n");
    fclose(fp);
}

