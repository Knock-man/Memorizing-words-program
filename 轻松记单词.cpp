/*
��Ŀ�������ɼǵ��� 

��Ŀʱ�䣺2020��7��11��

��Ŀ�ˣ�Ф����

��Ŀ������Ŀǰ�����ϵļǵ�������޷�����Լ��Ĵʿ⣬���ݴʿ�������䣬
          ���������ʵ���Լ����ôʿ⣬�����������ʿ��ڵĵ��ʵĹ��ܣ�Э�����ʼ��� 
          
����˵����������������� 

�ڶ����޸�(2020��7��11��)�����Ӵʿ⹦�ܣ����ӿɲ鿴�ʿ��б����Ӱ�����
                           �Ż��˵����Ż����ز���,�����A��bug,���������
						   ������ֿ�ѡ��������bug����Ӳ��ҵ��ʹ��ܣ��˵��˳����ܣ�
						
�������޸ģ�2020��7��16�գ������ӵ��ո�ϰ���Թ��ܣ��������ε����Զ�����ʿ�

�������޸�(2020��7��28��)���ʿ�鿴��ʽ������
*/
#include<iostream>
#include<algorithm>
#include<ctime>
#include<string>
#include<cstdio>
#include<map>
#include<cstring>
#include<cstdlib>
#include<set>
#include<fstream>
using namespace std;
const int M=9999999;
int choose,wordnumber=0,mark=1,score=0;
map<string,string> English;
map<string,string> chinese;
struct Node{
	string wEnglish;
	string wchinese;
}; 
Node words[M];
//�˵� 
void list(){
	system("cls"); 
	printf("             ||* * * * * * * * * * * * * * * * * * * * * *���˵��� * * * * * * * * * * * * * *  * * * * * * * * *||\n             ||                                                                                                  ||\n             ");
	printf("||                   1.����µ���             2.Ĭд����            3.ĬдӢ��                      ||\n             ||                                                                                                  ||\n ");
	printf("            ||                   4.��������ѡ��Ӣ��       5.����Ӣ��ѡ������    6.�鿴�ʿ��б�                  ||\n             ||                                                                                                  ||\n             ||                   7.���ҵ���               8.���츴ϰ            9.�鿴����                      ||\n" ) ;
	printf("             ||                                                                                                  ||\n             ||                   10.�˳�����                                                                    ||\n" ) ;
	printf("             ######################################################################################################\n\n"); 
	printf("                                              ��ѡ�������������Ӧ��ţ�:");
}
//����µ���
int  addwords(){
	system("cls");
	int k=0;
	printf("��ֱ����뵥����Ӣ����˼�ÿո����,����m��ʾ����:\n\n");
	while(1){
		string Englishword;
		string chineseword; 
		//���뵥Ӣ�� 
		cin>>Englishword;
		//�˳�����
		if(Englishword=="q"){
			printf("\n\n                                �����ܹ���%d��!!!                                \n\n",score); 
			exit(0);
		} 
		//�򿪲˵� 
		if(Englishword=="m"){
			system("cls");
			if(k>=1){
				printf("\n              ���ʵ���ʿ�ɹ������ι�����%d�����ʣ���\n\n\n",k);
					
			}else{
				printf("\n               ��û�е����κε��ʣ���\n\n\n");
			}
				printf("<�س������ز˵�>"); 
				getchar();
				getchar(); 
				return 1;
		}
		//���뵥������ 
		cin>>chineseword;
		//�˳�����
		if(Englishword=="q"){
			printf("\n\n                                �����ܹ���%d��!!!                                \n\n",score);
			exit(0);
		} 
		//�򿪲˵�
		if(chineseword=="m"){
			system("cls");
			if(k>=1){
				printf("\n              ���ʵ���ʿ�ɹ������ι�����%d�����ʣ���\n\n\n",k);
					
			}else{
				printf("\n              ��û�е����κε��ʣ���\n\n\n");
			}
			printf("<�س������ز˵�>"); 
			getchar();
			getchar(); 
			return 1;
		}
		//������ӵ�map��
		English[Englishword]=chineseword;
		chinese[chineseword]=Englishword;
		words[k].wchinese= chineseword;
		words[k++].wEnglish=Englishword;
		//���ʼ���ʿ�
		FILE *fp=fopen("�ʿ�.txt","a+");
		char e[100],c[100];
		//���ַ���תΪ�ַ����� 
		strncpy(e,Englishword.c_str(),Englishword.length()+1);
		strncpy(c,chineseword.c_str(),chineseword.length()+1);
		//�ж��Ƿ�Ϊ��һ�����ʿ��ƻ��� 
		if(English.size()<=1){
			fprintf(fp,"%s ",e);
	    	fprintf(fp,"%s",c);
		}else{
			fprintf(fp,"\n%s ",e);
	    	fprintf(fp,"%s",c);
		}
		fclose(fp);
		wordnumber++;//������ͳ�� 	
	}
}
//��ȡ����� 
int random(int num){
	srand(time(NULL));
	int magic=rand()%num+1;
	return magic;
} 
//Ĭд����
int writechinese(){
	system("cls");
	//��֤�е��ʼ� 
	if(English.size()==0){
		printf("\n                                   �ʿ�Ϊ�գ�������ӵ��ʣ�����\n\n");
		printf("<���س������ز˵�>");
		getchar();
		getchar();
		return 1;
	}
	while(1){
		string answer;
		map<string,string>::iterator it=English.begin();
		int count=0;
		int suji=random(English.size());
		//ȷ���������λ�� 
		for(it=English.begin();it!=English.end();++it){
			count++;
			if(count>=suji){
				cout<<"�����뵥�ʡ�"<<it->first<<"����������˼������m���ز˵�����";
				cin>>answer;
				if(answer=="q"){
					printf("\n\n                                �����ܹ���%d��!!!                                \n\n",score);
					exit(0);
				}
				if(answer=="m"){
					return 1;
				}
				if(it->second==answer){
					score++;
					printf("\n��ϲ�����ˣ�����,������%d\n\n",score);
				}else{
					cout<<endl<<"����ˡ�"<<it->first<<"����������˼��:"<<it->second<<endl<<endl;
				}
				break;
			}
		}
		printf("<�س���һ��>");
	       getchar();
	       getchar();
	      system("cls");
	}
		
}
//ĬдӢ��
int writeEnglish(){
	system("cls");
	string answer;
	//��֤�е��ʼ� 
	if(English.size()==0){
		printf("\n                                   �ʿ�Ϊ�գ�������ӵ��ʣ�����\n\n");
		printf("<���س������ز˵�>");
		getchar();
		getchar();
		return 1;
	}
	while(1){
     	map<string,string>::iterator it=chinese.begin();
	    int count=0;
	    int suiji=random(English.size());
	    for(it=English.begin();it!=English.end();++it){
			count++;
			if(count>=suiji){
				cout<<"�����뵥�ʡ�"<<it->second<<"����Ӣ����˼������m���ز˵�����";
				cin>>answer;
				if(answer=="q"){
					printf("\n\n                                �����ܹ���%d��!!!                                \n\n",score);
					exit(0);
				}
				if(answer=="m"){
					return 1;
				}
				if(it->first==answer){
					score++;
					printf("\n��ϲ�����ˣ�����,������%d \n\n",score);
				}else{
					cout<<endl<<"����ˡ�"<<it->second<<"����Ӣ����:"<<it->first<<endl<<endl;
				}
				break;
			}
    	}
    	printf("<�س���һ��>");
	       getchar();
	       getchar();
	      system("cls");
			
	}
} 
//��������ѡ��Ӣ�� 
int  choosechinese(){
	system("cls");
	if(English.size()<4){
		printf("\n\n                            ���ʲ������������µĵ��ʣ������ĸ�������\n\n\n");
		printf("<���س������ز˵�>");
		getchar();
		getchar();
		
		return 1;
	} 
 	while(1){
		int book[4];
		int t = random(English.size())-1;
		book[0]=t;
		cout<<"��ѡ�񵥴ʡ�"<<words[t].wchinese<<"����Ӣ����˼������m���ز˵�����";
		
		string wer=words[t].wEnglish;//��ô�; 
		//����˳��ȡ�±� 
		int j=1;
		t++;
		while(1){
			if(t>English.size()-1){
				t=0;
			}
			if(j>=4){
				break;
			}
			book[j++]=t++;
		}
		//���ĸ��±����
		if(t%2){
			swap(book[0],book[random(3)]);
		    swap(book[random(3)],book[random(3)]);
		    swap(book[random(2)],book[0]);
		}else{
			swap(book[0],book[random(1)]);
		    swap(book[random(3)],book[random(3)]);
		    swap(book[random(3)],book[0]);
		}
	
		cout<<endl<<endl;
		for(int i=0;i<4;i++){
			printf("%c.",'A'+i);
			cout<<words[book[i]].wEnglish<<"     ";
		}
		cout<<endl<<"�𰸣�"; 
		//�����
		string answer;
		cin>>answer;
		if(answer=="m"){
			return 1;
		}
		if(answer=="q"){
			printf("\n\n                                �����ܹ���%d��!!!                                \n\n",score);
			exit(0);
		}
		if(answer=="A"){
		        if(words[book[0]].wEnglish==wer){
		        	score++;
					printf("\n��ϲ������!!!,������%d\n\n",score);
				}else{
					printf("\n�𰸴�����ȷ���ǣ�");
					cout<<wer<<endl<<endl; 
				}	
		}else if(answer=="B"){
			    if(words[book[1]].wEnglish==wer){
					score++;
					printf("\n��ϲ������!!!,������%d\n\n",score);
				}else{
					printf("\n�𰸴�����ȷ���ǣ�");
					cout<<wer<<endl<<endl; 
				}	
			
		}else if(answer=="C"){
			    if(words[book[2]].wEnglish==wer){
					score++;
					printf("\n��ϲ������!!!,������%d\n\n",score);
				}else{
					printf("\n�𰸴�����ȷ���ǣ�");
					cout<<wer<<endl<<endl; 
				}	
		}else if(answer=="D"){
			    if(words[book[3]].wEnglish==wer){
					score++;
					printf("\n��ϲ������!!!,������%d\n\n",score);
				}else{
					printf("\n�𰸴�����ȷ���ǣ�");
					cout<<wer<<endl<<endl; 
				}	
		}else{
			printf("\n�������󣡣�\n\n"); 
		}
		printf("\n<�س���һ��>");
		getchar();
		getchar();
		system("cls"); 
	}
	
}
//����Ӣ��ѡ������ 
int chooseEnglish(){
	system("cls"); 
	if(English.size()<4){
		printf("\n\n                            ���ʲ������������µĵ��ʣ������ĸ�������\n\n\n");
		printf("<���س������ز˵�>");
		getchar();
		getchar();
		
		return 1;
	} 
	while(1){
    	int book[4];
		int t = random(English.size())-1;
		book[0]=t;
		cout<<"�����뵥�ʡ�"<<words[t].wEnglish<<"����������˼������m���ز˵�����";
		
		string wer=words[t].wchinese;//��ô�; 
		//����˳��ȡ�±� 
		int j=1;
		t++;
		while(1){
			if(t>English.size()-1){
				t=0;
			}
			if(j>=4){
				break;
			}
			book[j++]=t++;
		}
	//���ĸ��±����
		if(t%2){
			swap(book[0],book[random(3)]);
		    swap(book[random(3)],book[random(3)]);
		    swap(book[random(2)],book[0]);
		}else{
			swap(book[0],book[random(1)]);
		    swap(book[random(3)],book[random(3)]);
		    swap(book[random(3)],book[0]);
		}
	 
		cout<<endl<<endl;
		for(int i=0;i<4;i++){
			printf("%c.",'A'+i);
			cout<<words[book[i]].wchinese<<"     ";
		}
		cout<<endl<<"�𰸣�"; 
		string answer;
		cin>>answer;
		if(answer=="m"){
			return 1;
		}
		if(answer=="q"){
			printf("\n\n                                �����ܹ���%d��!!!                                \n\n",score);
			exit(0);
		}
		if(answer=="A"){
		        if(words[book[0]].wchinese==wer){
					score++;
					printf("\n��ϲ������!!!,������%d\n\n",score);
				}else{
					printf("\n�𰸴�����ȷ���ǣ�");
					cout<<wer<<endl<<endl; 
				}	
		}else if(answer=="B"){
			    if(words[book[1]].wchinese==wer){
					score++;
					printf("\n��ϲ������!!!,������%d\n\n",score);
				}else{
					printf("\n�𰸴�����ȷ���ǣ�");
					cout<<wer<<endl<<endl; 
				}	
			
		}else if(answer=="C"){
			    if(words[book[2]].wchinese==wer){
					score++;
					printf("\n��ϲ������!!!,������%d\n\n",score);
				}else{
					printf("\n�𰸴�����ȷ���ǣ�");
					cout<<wer<<endl<<endl; 
				}	
		}else if(answer=="D"){
			    if(words[book[3]].wchinese==wer){
					score++;
					printf("\n��ϲ������!!!,������%d\n\n",score);
				}else{
					printf("\n�𰸴�����ȷ���ǣ�");
					cout<<wer<<endl<<endl; 
				}	
		}else{
			printf("\n\n�������󣡣�\n\n"); 
		}
		printf("<�س���һ��>");
	 	getchar();
	 	getchar();
		system("cls"); 
	}
}
//����ʿ��ļ�����
int fileline(){
	  FILE *fp;
	  int flag = 0, file_row = 0, count = 0;
	  if((fp = fopen("�ʿ�.txt", "r")) == NULL)return -1;
	  char ch=fgetc(fp);
	  if(ch==EOF)return 0;
	  while(!feof(fp))
	  {
	    flag = fgetc(fp);
	    if(flag == '\n')
	      count++;
	  }
		file_row = count + 1; //�������һ��
	  	fclose(fp);
	  	return file_row;
} 
//�����ļ����ʿ��ж��뵥�ʣ� 
void readfile(){
	FILE *fp = fopen("�ʿ�.txt","r");
	int line=fileline(); 
	for(int i=0;i<line;i++){
			string A,B;
			char a[100],b[100];
			fscanf(fp,"%s",a);
			fscanf(fp,"%s",b);
			English[a]=b;
			chinese[b]=a;
			words[wordnumber].wEnglish=a;
			words[wordnumber++].wchinese=b;
	}
	fclose(fp);
} 
//�鿴�ʿ�
int lookwordlist(){
	system("cls");

	FILE *fp = fopen("�ʿ�.txt","r");
	//int line=wordnumber;
	printf("                            ���ʿ⡷\n\n"); 
	for(int i=0;i<English.size();i++){
			string A,B;
			char a[100],b[100];
			fscanf(fp,"%s",a);
			fscanf(fp,"%s",b);
			printf("                    %-20s%-20s\n",a,b);
	}
	printf("\n                    �ܹ���%d���ʻ㣡\n\n",English.size());
	printf("\n\n<�س������ز˵�>");
	getchar();
	getchar();
	return 1;
}
//���ҵ���
int findword(){
	while(1){
		system("cls");
		printf("\n\n     A.����Ӣ�Ĳ�������         ");
		printf("B.�������Ĳ���Ӣ��\n\n\n");
		printf("     ��ѡ���������(����A,Bѡ��,m���ز˵�)��");
		char r;
		cin>>r; 
		if(r=='m'){
			return 1;
		}else if(r=='q'){
			exit(0);
		}else if(r=='A'){
			system("cls");
			string t1;
			printf("   \n\n������Ӣ�ģ�");
			cin>>t1;
			map<string,string>::iterator it=English.begin() ;
			it=English.find(t1);
			if(it!=English.end()){
				cout<<endl<<endl<<"    "<<t1<<"��������˼�ǡ�"<<it->second<<"��"<<endl<<endl<<endl; 
				cout<<"<�س���������һ��>"; 
			}else{
				printf("\n\n    ��Ǹ���ʿ���û���������!!\n\n\n");
				cout<<"<�س���������һ��>";
			}
		}else if(r=='B'){
			system("cls");
			string t2;
			printf("   \n\n���������ģ�");
			cin>>t2;
			map<string,string>::iterator it=chinese.begin() ;
			it=chinese.find(t2);
			if(it!=chinese.end()){
				cout<<endl<<endl<<"    "<<t2<<"��Ӣ���ǡ�"<<it->second<<"��"<<endl<<endl<<endl; 
				cout<<"<�س���������һ��>"; 
			}else{
				printf("\n\n    ��Ǹ���ʿ���û���������!!\n\n\n");
				cout<<"<�س���������һ��>";
			}
		}else{
			system("cls");
			printf("           ������󣡣�\n\n\n");
			printf("<�س����ز˵�>");
			getchar();
			getchar();
			return 1;
			} 
	
		
		getchar();
		getchar();
    
	}
} 
void addku(string p){
	
}
//��ϰ���쵥�� 
int dayword(){
	system("cls");
	printf("\n�����뵱�����ǵ��ʣ���Ӣ�Ŀո����������m��ʾ��������\n\n"); 
	string wordEnglish[50005];
	string wordchinese[50005];
	string daywordEnglish;
	string daywordchinese;
	int k=1,rigth1=0;
	while(1){
		cin>>daywordEnglish;
		if(daywordEnglish=="m"||daywordEnglish=="q"){
			break;
		}
		cin>>daywordchinese;
		if(daywordchinese=="m"||daywordchinese=="q"){
			break;
		}
		wordEnglish[k]=daywordEnglish;
		wordchinese[k++]=daywordchinese;
	}	
	system("cls");
	if(k==1){
				printf("\n\n      ��û����ӵ��쵥�ʣ���\n\n\n");
				printf("<�س����ز˵�>");
				getchar();
				getchar();
				return 1;
			} 
	printf("��ѡ�������ͣ�\n\n           A.���Ӣ��     B.�������");
	printf("\n\n������ѡ��");
	string t;
	cin>>t;
	system("cls");
	bool vis[50005];//��ǵ����Ƿ���д 
	memset(vis,0,sizeof(vis));
	int count=0;
	while(1){
		if(t=="A"){//��Ӣ�� 
			system("cls");
			printf("\n    Ӣ�ļ�⿪ʼ�����ֹ���%d������,�������λ��ᣬ�������ν��Զ�����ʿ�!!!\n\n\n",k-1); 
			for(int i=1;i<=k;i++){
				int flag=random(k-1);
				if(!vis[flag]){//û�е�� 
					count++;
					vis[flag]=true;
					cout<<"�����뵥�ʡ�"<<wordchinese[flag]<<"����Ӣ����˼(����m�˳����):";
					string answer;
					int chance;
					//���λ��� 
					for(chance=0;chance<3;chance++){
						cin>> answer;
						if(answer=="m"||answer=="q"){ 
							return 1;
						}
						if(answer==wordEnglish[flag]){
							rigth1++;
							chance--;
							printf("         \n\n����ȷ����");
							break;
						}else{
							if(chance==2){
								break;
							}
							printf("\n�𰸴��󣡣��㻹��%d�λ��ᣬ���ٴ����룺",2-chance);
						}
					}
					if(chance>=2){
						FILE *fp=fopen("�ʿ�.txt","a+");
						char e[100],c[100];
						//���ַ���תΪ�ַ����� 
						strncpy(c,wordchinese[flag].c_str(),wordchinese[flag].length()+1);
						strncpy(e,wordEnglish[flag].c_str(),wordEnglish[flag].length()+1);
						//�ж��Ƿ�Ϊ��һ�����ʿ��ƻ��� 
						if(English.size()<=1){
							fprintf(fp,"%s ",e);
					    	fprintf(fp,"%s",c);
						}else{
							fprintf(fp,"\n%s ",e);
					    	fprintf(fp,"%s",c);
						}
						fclose(fp);
						cout<<"\n\n��ȷ���ǡ�"<< wordEnglish[flag]<<"�����Զ�����ʿ�"; 
					}
					printf("\n\n\n<�س�����һ��>"); 
					getchar();
					getchar();
					system("cls");
				
				}else{//��� 
					int v=flag;
					while(++v){
						if(v==k+1){
							v=1;
						}
						if(!vis[v]){
							count++;
							if(count==k)break;
							vis[v]=true;
							
							cout<<"�����뵥�ʡ�"<<wordchinese[v]<<"����Ӣ����˼(����m�˳����):";
							string answer;
							int chance;
							//���λ��� 
							for(chance=0;chance<3;chance++){
								cin>> answer;
								if(answer=="m"||answer=="q"){ 
									return 1;
								}
								if(answer==wordEnglish[v]){
									rigth1++;
									chance--;
									printf("         \n\n����ȷ����");
									break;
								}else{
									if(chance>=2){
										break;
									}
									printf("\n�𰸴��󣡣��㻹��%d�λ��ᣬ���ٴ����룺",2-chance);
								}
							}
							if(chance>=2){
								FILE *fp=fopen("�ʿ�.txt","a+");
								char e[100],c[100];
								//���ַ���תΪ�ַ����� 
								strncpy(c,wordchinese[v].c_str(),wordchinese[v].length()+1);
								strncpy(e,wordEnglish[v].c_str(),wordEnglish[v].length()+1);
								//�ж��Ƿ�Ϊ��һ�����ʿ��ƻ��� 
								if(English.size()<=1){
									fprintf(fp,"%s ",e);
							    	fprintf(fp,"%s",c);
								}else{
									fprintf(fp,"\n%s ",e);
							    	fprintf(fp,"%s",c);
								}
								fclose(fp);
								cout<<"\n\n��ȷ���ǡ�"<< wordEnglish[v]<<"�����Զ�����ʿ�"; 
							}
								printf("\n\n\n<�س�����һ��>"); 
								getchar();
								getchar();
								system("cls");
								break;
						}
					}
				} 
			}
			printf("\n\n���е��ʼ�����,��������ȷ%d���ʻ㣬�ʿ���¼%d���ʻ�!!!\n\n\n",rigth1,k-rigth1-1);
			printf("<�س��˳�>");
			getchar();
			return 1;
		}else if(t=="B"){//������ 
			system("cls");
			printf("\n    ���ļ�⿪ʼ�����ֹ���%d������,�������λ��ᣬ�������ν��Զ�����ʿ�!!!\n\n\n",k-1); 
			for(int i=1;i<=k;i++){
				int flag=random(k-1);
				if(!vis[flag]){//û�е�� 
					count++;
					vis[flag]=true;
					cout<<"�����뵥�ʡ�"<<wordEnglish[flag]<<"����������˼(����m�˳����):";
					string answer;
					int chance;
					//���λ��� 
					for(chance=0;chance<3;chance++){
						cin>> answer;
						if(answer=="m"||answer=="q"){ 
							return 1;
						}
						if(answer==wordchinese[flag]){
							rigth1++;
							chance--;
							printf("         \n\n����ȷ����");
							break;
						}else{
							if(chance==2){
								break;
							}
							printf("\n�𰸴��󣡣��㻹��%d�λ��ᣬ���ٴ����룺",2-chance);
						}
					}
					if(chance>=2){
						FILE *fp=fopen("�ʿ�.txt","a+");
						char e[100],c[100];
						//���ַ���תΪ�ַ����� 
						strncpy(c,wordchinese[flag].c_str(),wordchinese[flag].length()+1);
						strncpy(e,wordEnglish[flag].c_str(),wordEnglish[flag].length()+1);
						//�ж��Ƿ�Ϊ��һ�����ʿ��ƻ��� 
						if(English.size()<=1){
							fprintf(fp,"%s ",e);
					    	fprintf(fp,"%s",c);
						}else{
							fprintf(fp,"\n%s ",e);
					    	fprintf(fp,"%s",c);
						}
						fclose(fp);
						cout<<"\n\n��ȷ���ǡ�"<< wordchinese[flag]<<"�����Զ�����ʿ�"; 
					}
					printf("\n\n\n<�س�����һ��>"); 
					getchar();
					getchar();
					system("cls");
				
				}else{//��� 
					int v=flag;
					while(++v){
						if(v==k+1){
							v=1;
						}
						if(!vis[v]){
							count++;
							if(count==k)break;
							vis[v]=true;
							
							cout<<"�����뵥�ʡ�"<<wordEnglish[v]<<"����������˼(����m�˳����):";
							string answer;
							int chance;
							//���λ��� 
							for(chance=0;chance<3;chance++){
								cin>> answer;
								if(answer=="m"||answer=="q"){ 
									return 1;
								}
								if(answer==wordchinese[v]){
									rigth1++;
									chance--;
									printf("         \n\n����ȷ����");
									break;
								}else{
									if(chance>=2){
										break;
									}
									printf("\n�𰸴��󣡣��㻹��%d�λ��ᣬ���ٴ����룺",2-chance);
								}
							}
							if(chance>=2){
								FILE *fp=fopen("�ʿ�.txt","a+");
								char e[100],c[100];
								//���ַ���תΪ�ַ����� 
								strncpy(c,wordchinese[v].c_str(),wordchinese[v].length()+1);
								strncpy(e,wordEnglish[v].c_str(),wordEnglish[v].length()+1);
								//�ж��Ƿ�Ϊ��һ�����ʿ��ƻ��� 
								if(English.size()<=1){
									fprintf(fp,"%s ",e);
							    	fprintf(fp,"%s",c);
								}else{
									fprintf(fp,"\n%s ",e);
							    	fprintf(fp,"%s",c);
								}
								fclose(fp);
								cout<<"\n\n��ȷ���ǡ�"<< wordchinese[v]<<"�����Զ�����ʿ�"; 
							}
								printf("\n\n\n<�س�����һ��>"); 
								getchar();
								getchar();
								system("cls");
								break;
						}
					}
					
				
				
				} 
			}
			printf("\n\n���е��ʼ�����,��������ȷ%d���ʻ㣬�ʿ���¼%d���ʻ�!!!\n\n\n",rigth1,k-rigth1-1);
			printf("<�س��˳�>");
			getchar();
			return 1;
		}else{
			system("cls");
			printf("\n\n\n�������󣡣�����������:");
			printf("��ѡ�������ͣ�\n\n           A.���Ӣ��     B.�������");
			printf("\n\n������ѡ��");
			cin>>t;
		}
	}
	
	
	
}
//����
int help(){
	system("cls"); 
	printf("                                                                      <<����>>\n"); 
	printf("             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n\n"); 
	printf("                  *����˵��*��"); 
	printf("1.����m�����ز˵�\n\n                              2.����q���˳�\n\n                              3.�س�����һ����߷�����һ�����߷��ز˵�\n\n\n"); 
	printf("                  *���ܽ���*�����������ʵ���û��Լ�¼��ʿ⣬���������ȡ�ʿⵥ�ʵĹ��ܣ������û��������յ���\n");
	printf("\n                              1.����µ��ʣ����뵥�ʵ�Ӣ�� ���ģ������Զ������ʼ���ʿ���"); 
	printf("\n                              2.Ĭд���ģ�����Ӣ�ģ��û��ش����ģ������ж϶Դ������������ȷ��"); 
	printf("\n                              3.ĬдӢ�ģ��������ģ��û��ش�Ӣ�ģ������ж϶Դ������������ȷ��");
	printf("\n                              4.��������ѡ��Ӣ�ģ��������ģ���Ŀ����ABCD�ĸ�Ӣ��ѡ��û�������ȷѡ������ж϶Դ������������ȷ��"); 
	printf("\n                              5.����Ӣ��ѡ�����ģ�����Ӣ���ģ���Ŀ����ABCD�ĸ�������ѡ��û�������ȷѡ������ж϶Դ������������ȷ��");
	printf("\n                              6.�鿴�����б��û����Բ鿴�Լ��ĵ��ʿ�����е��ʼ�����");
	printf("\n                              7.���ҵ��ʣ�������Ӣ�ĴӴʿ��в��ҵ���");
	printf("\n                              7.���츴ϰ�����뵱��ǵĵ��ʣ����и�ϰ����,�����ε��ʽ��Զ�¼��ʿ�");
	printf("\n                              8.ͳ�Ʒ������û���Լӷ֣�����۷�\n\n\n");
	printf("                  *�ʿ��ʹ��*��"); 
	printf("�����ڱ��뻷����¼�뵥�ʲ����㣬�������ṩ�˴ʿ⹦�ܣ����±��ļ����ʿ�.txt�����Ǵʿ⣬��Ҫ��ӻ����޸�ɾ��\n                                ���ʣ�����ֱ���ڱ��ļ�������޸�ɾ��������ע�ⲻҪ���ֶ���Ļس�������ʱ��֤��������һ�����ʵĺ���,�ʿ��\n                                ���ʻ����ñ��棬��Ȼ�ڳ��������Ҳ�����ʿ�");	 
	printf("\n\n\n\n\n\n<���س����ز˵�>");
	getchar();
	getchar();
	return 1;
}
int main(){
	while(1){
		//�ļ����� 
	     readfile();
		if(mark==1)list();//�򿪲˵�;
		scanf("%d",&choose);
		/*if(choose==0){
			printf("\n                                            ������������������<���س�������>!!\n"); 
			getchar();
			getchar();
			getchar();
			continue;	
		}*/
		switch(choose){
			case 1:{
				mark=addwords();
				break;
			}
			case 2:{
		    	mark=writechinese();
				break;
			}
			case 3:{
				mark=writeEnglish();
				break;
			}
			case 4:{
				mark=choosechinese();
				break;
			}
			case 5:{
				mark=chooseEnglish();
				break;
			}
			case 7:{
				mark=findword();
				break;
			} 
			case 6:{
				mark=lookwordlist();
				break;
			}
			case 9:{
				mark=help();
				break;
			}
			case 10:{
				printf("\n\n                                                  �����ܹ���%d��!!!                                \n\n",score);
				return 0;
				break;
			}
			case 0:{
				printf("\n                                            ������������������<���س�������>!!\n"); 
				getchar();
				getchar();
				getchar();
				break;
			}
			case 8:{
				mark=dayword();
				break;
			} 
			default:{
				printf("\n                                            ������������������<���س�������>!!\n"); 
				getchar();
				getchar();
			}
		} 
	}
	return 0;
}
 
