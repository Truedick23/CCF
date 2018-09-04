#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<ctype.h>

using namespace std;

bool legal(char *s)
{
	for(int i=0;i<strlen(s);i++)//������ǺϷ��� URL��ַ����false
	   if(s[i]!='/'&&s[i]!='.'&&s[i]!='-'&&s[i]!='_'&&!(isalpha(s[i])||isdigit(s[i])))
		return false;
	return true;
}

bool int_right(string s) //�ж�һ���ַ�����ȫΪ����
{
	for(int i=0;i<s.length();i++)
	  if(!isdigit(s[i]))
	    return false;
	return true;
}

struct Rule{ //����
	vector<string>rule;//�洢����
	string name;//ƥ�������
	bool flag;//�����β�Ƿ��� / ������Ϊtrue����Ϊflase
}r[105];

vector<string>url;//�洢�����url·��
vector<string>para;//�洢����

int n; //����ĸ���

void init() //��ʼ���ѹ����ƥ�����洢��������
{
	string tmp;
	char a[110];//��ʱ�ַ�����
	int pos=0;
	for(int i=1;i<=n;i++){
		scanf("%s",a);//����url����
		int end=strlen(a);
		if(end>0&&a[end-1]=='/')
		  r[pos].flag=true;
		else
		  r[pos].flag=false;
		cin>>r[pos].name;//����urlƥ����
		char *sp=strtok(a,"/");//��б�ָܷ��ַ���
		while(sp){
			r[pos].rule.push_back(sp);
			sp=strtok(NULL,"/");
		}
		pos++;
	}
 }

bool postfix;//�����URL��ַ�ĺ�׺�Ƿ��� /

void match(char *a) //�ж�url��ַ���ַ�����a�洢�ģ��Ƿ�ƥ�����еĹ���
{
	url.clear();//��մ洢url������
	char *sp=strtok(a,"/");//��б�ָܷ��ַ���,���洢��url������
	while(sp){
		url.push_back(sp);
		sp=strtok(NULL,"/");
	}
	//ƥ��
	for(int i=0;i<n;i++){//ƥ�����е� n ������
	    int j,k;//k��ʾurl�Ķα��
	    para.clear();//��մ洢����������
	    bool flag=true;
		for(j=0,k=0;j<r[i].rule.size()&&k<url.size();j++,k++){//ÿ�����򱻷ָ����r[i].rule.size()��
		    string s=r[i].rule[j];
			//���һ
			if(s=="<int>"){
				if(!int_right(url[k])){//������������ִ��Ļ���ƥ��ʧ��
					flag=false;
					break;
				}
				else{//ȥ��ǰ��0
				    string str=url[k];
				    for(int t=0;t<str.length()&&str[t]=='0';t++)
				      str.erase(t,1);
				    if(str!="")
					  para.push_back(str);
				}
			}
			//�����
		    else if(s=="<str>")
		    	para.push_back(url[k]);
		    //�����
		    else if(s=="<path>"){
		    	string tmp=url[k++];
		    	for(;k<url.size();k++)
		    	  tmp=tmp+"/"+url[k];
		    	if(postfix)
		    	  tmp+="/";
		    	para.push_back(tmp);
			}
			//�����
			else{
				if(s!=url[k]){
					flag=false;
					break;
				}
			  }
			}
		if(flag&&j>=r[i].rule.size()&&k>=url.size()&&r[i].flag==postfix){
			cout<<r[i].name;
			for(int ii=0;ii<para.size();ii++)
			  cout<<" "<<para[ii];
			cout<<endl;
			return;
		}
	}
	cout<<"404"<<endl;
}

int main()
{
	int m;
	string s;
	cin>>n>>m;
	init();//��ʼ���洢n��url����
	while(m--){
		char a[110];//��ʱ�ַ�����
		scanf("%s",&a);//����url��ַ
		int end=strlen(a);
		if(end>0&&a[end-1]=='/')
		  postfix=true;
		else
		  postfix=false;
		if(!legal(a)){//������ǺϷ���url��ַ
			cout<<"404"<<endl;
			continue;
		}
		match(a);
	}
	return 0;
}
