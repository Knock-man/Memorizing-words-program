/*
项目名：轻松记单词 

项目时间：2020年7月11日

项目人：肖本杰

项目背景：目前市面上的记单词软件无法添加自己的词库，根据词库需求记忆，
          本程序就是实现自己设置词库，程序随机考察词库内的单词的功能，协助单词记忆 
          
操作说明：见程序帮助部分 

第二次修改(2020年7月11日)：增加词库功能，增加可查看词库列表，增加帮助，
                           优化菜单，优化返回操作,解决无A答案bug,增大随机性
						   解决出现空选项空问题的bug，添加查找单词功能，菜单退出功能；
						
第三次修改（2020年7月16日）：增加当日复习测试功能，错误三次单词自动加入词库

第三次修改(2020年7月28日)：词库查看格式化对齐
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
//菜单 
void list(){
	system("cls"); 
	printf("             ||* * * * * * * * * * * * * * * * * * * * * *《菜单》 * * * * * * * * * * * * * *  * * * * * * * * *||\n             ||                                                                                                  ||\n             ");
	printf("||                   1.添加新单词             2.默写中文            3.默写英文                      ||\n             ||                                                                                                  ||\n ");
	printf("            ||                   4.根据中文选择英文       5.根据英文选择中文    6.查看词库列表                  ||\n             ||                                                                                                  ||\n             ||                   7.查找单词               8.当天复习            9.查看帮助                      ||\n" ) ;
	printf("             ||                                                                                                  ||\n             ||                   10.退出程序                                                                    ||\n" ) ;
	printf("             ######################################################################################################\n\n"); 
	printf("                                              请选择操作（输入相应序号）:");
}
//添加新单词
int  addwords(){
	system("cls");
	int k=0;
	printf("请分别输入单词中英文意思用空格隔开,输入m表示结束:\n\n");
	while(1){
		string Englishword;
		string chineseword; 
		//输入单英文 
		cin>>Englishword;
		//退出程序
		if(Englishword=="q"){
			printf("\n\n                                本次总共得%d分!!!                                \n\n",score); 
			exit(0);
		} 
		//打开菜单 
		if(Englishword=="m"){
			system("cls");
			if(k>=1){
				printf("\n              单词导入词库成功，本次共导入%d个单词！！\n\n\n",k);
					
			}else{
				printf("\n               您没有导入任何单词！！\n\n\n");
			}
				printf("<回车键返回菜单>"); 
				getchar();
				getchar(); 
				return 1;
		}
		//输入单词中文 
		cin>>chineseword;
		//退出程序
		if(Englishword=="q"){
			printf("\n\n                                本次总共得%d分!!!                                \n\n",score);
			exit(0);
		} 
		//打开菜单
		if(chineseword=="m"){
			system("cls");
			if(k>=1){
				printf("\n              单词导入词库成功，本次共导入%d个单词！！\n\n\n",k);
					
			}else{
				printf("\n              您没有导入任何单词！！\n\n\n");
			}
			printf("<回车键返回菜单>"); 
			getchar();
			getchar(); 
			return 1;
		}
		//单词添加到map中
		English[Englishword]=chineseword;
		chinese[chineseword]=Englishword;
		words[k].wchinese= chineseword;
		words[k++].wEnglish=Englishword;
		//单词加入词库
		FILE *fp=fopen("词库.txt","a+");
		char e[100],c[100];
		//将字符串转为字符数组 
		strncpy(e,Englishword.c_str(),Englishword.length()+1);
		strncpy(c,chineseword.c_str(),chineseword.length()+1);
		//判断是否为第一个单词控制换行 
		if(English.size()<=1){
			fprintf(fp,"%s ",e);
	    	fprintf(fp,"%s",c);
		}else{
			fprintf(fp,"\n%s ",e);
	    	fprintf(fp,"%s",c);
		}
		fclose(fp);
		wordnumber++;//单词数统计 	
	}
}
//获取随机数 
int random(int num){
	srand(time(NULL));
	int magic=rand()%num+1;
	return magic;
} 
//默写中文
int writechinese(){
	system("cls");
	//保证有单词记 
	if(English.size()==0){
		printf("\n                                   词库为空，请先添加单词！！！\n\n");
		printf("<按回车键返回菜单>");
		getchar();
		getchar();
		return 1;
	}
	while(1){
		string answer;
		map<string,string>::iterator it=English.begin();
		int count=0;
		int suji=random(English.size());
		//确定随机单词位置 
		for(it=English.begin();it!=English.end();++it){
			count++;
			if(count>=suji){
				cout<<"请输入单词“"<<it->first<<"”的中文意思（输入m返回菜单）：";
				cin>>answer;
				if(answer=="q"){
					printf("\n\n                                本次总共得%d分!!!                                \n\n",score);
					exit(0);
				}
				if(answer=="m"){
					return 1;
				}
				if(it->second==answer){
					score++;
					printf("\n恭喜你答对了！！！,分数：%d\n\n",score);
				}else{
					cout<<endl<<"答错了“"<<it->first<<"”的中文意思是:"<<it->second<<endl<<endl;
				}
				break;
			}
		}
		printf("<回车下一题>");
	       getchar();
	       getchar();
	      system("cls");
	}
		
}
//默写英文
int writeEnglish(){
	system("cls");
	string answer;
	//保证有单词记 
	if(English.size()==0){
		printf("\n                                   词库为空，请先添加单词！！！\n\n");
		printf("<按回车键返回菜单>");
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
				cout<<"请输入单词“"<<it->second<<"”的英文意思（输入m返回菜单）：";
				cin>>answer;
				if(answer=="q"){
					printf("\n\n                                本次总共得%d分!!!                                \n\n",score);
					exit(0);
				}
				if(answer=="m"){
					return 1;
				}
				if(it->first==answer){
					score++;
					printf("\n恭喜你答对了！！！,分数：%d \n\n",score);
				}else{
					cout<<endl<<"答错了“"<<it->second<<"”的英文是:"<<it->first<<endl<<endl;
				}
				break;
			}
    	}
    	printf("<回车下一题>");
	       getchar();
	       getchar();
	      system("cls");
			
	}
} 
//根据中文选择英文 
int  choosechinese(){
	system("cls");
	if(English.size()<4){
		printf("\n\n                            单词不够请继续添加新的单词（最少四个）！！\n\n\n");
		printf("<按回车键返回菜单>");
		getchar();
		getchar();
		
		return 1;
	} 
 	while(1){
		int book[4];
		int t = random(English.size())-1;
		book[0]=t;
		cout<<"请选择单词“"<<words[t].wchinese<<"”的英文意思（输入m返回菜单）：";
		
		string wer=words[t].wEnglish;//存好答案; 
		//依次顺序取下标 
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
		//将四个下标打乱
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
		cout<<endl<<"答案："; 
		//输入答案
		string answer;
		cin>>answer;
		if(answer=="m"){
			return 1;
		}
		if(answer=="q"){
			printf("\n\n                                本次总共得%d分!!!                                \n\n",score);
			exit(0);
		}
		if(answer=="A"){
		        if(words[book[0]].wEnglish==wer){
		        	score++;
					printf("\n恭喜你答对了!!!,分数：%d\n\n",score);
				}else{
					printf("\n答案错误，正确答案是：");
					cout<<wer<<endl<<endl; 
				}	
		}else if(answer=="B"){
			    if(words[book[1]].wEnglish==wer){
					score++;
					printf("\n恭喜你答对了!!!,分数：%d\n\n",score);
				}else{
					printf("\n答案错误，正确答案是：");
					cout<<wer<<endl<<endl; 
				}	
			
		}else if(answer=="C"){
			    if(words[book[2]].wEnglish==wer){
					score++;
					printf("\n恭喜你答对了!!!,分数：%d\n\n",score);
				}else{
					printf("\n答案错误，正确答案是：");
					cout<<wer<<endl<<endl; 
				}	
		}else if(answer=="D"){
			    if(words[book[3]].wEnglish==wer){
					score++;
					printf("\n恭喜你答对了!!!,分数：%d\n\n",score);
				}else{
					printf("\n答案错误，正确答案是：");
					cout<<wer<<endl<<endl; 
				}	
		}else{
			printf("\n输入有误！！\n\n"); 
		}
		printf("\n<回车下一题>");
		getchar();
		getchar();
		system("cls"); 
	}
	
}
//根据英文选择中文 
int chooseEnglish(){
	system("cls"); 
	if(English.size()<4){
		printf("\n\n                            单词不够请继续添加新的单词（最少四个）！！\n\n\n");
		printf("<按回车键返回菜单>");
		getchar();
		getchar();
		
		return 1;
	} 
	while(1){
    	int book[4];
		int t = random(English.size())-1;
		book[0]=t;
		cout<<"请输入单词“"<<words[t].wEnglish<<"”的中文意思（输入m返回菜单）：";
		
		string wer=words[t].wchinese;//存好答案; 
		//依次顺序取下标 
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
	//将四个下标打乱
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
		cout<<endl<<"答案："; 
		string answer;
		cin>>answer;
		if(answer=="m"){
			return 1;
		}
		if(answer=="q"){
			printf("\n\n                                本次总共得%d分!!!                                \n\n",score);
			exit(0);
		}
		if(answer=="A"){
		        if(words[book[0]].wchinese==wer){
					score++;
					printf("\n恭喜你答对了!!!,分数：%d\n\n",score);
				}else{
					printf("\n答案错误，正确答案是：");
					cout<<wer<<endl<<endl; 
				}	
		}else if(answer=="B"){
			    if(words[book[1]].wchinese==wer){
					score++;
					printf("\n恭喜你答对了!!!,分数：%d\n\n",score);
				}else{
					printf("\n答案错误，正确答案是：");
					cout<<wer<<endl<<endl; 
				}	
			
		}else if(answer=="C"){
			    if(words[book[2]].wchinese==wer){
					score++;
					printf("\n恭喜你答对了!!!,分数：%d\n\n",score);
				}else{
					printf("\n答案错误，正确答案是：");
					cout<<wer<<endl<<endl; 
				}	
		}else if(answer=="D"){
			    if(words[book[3]].wchinese==wer){
					score++;
					printf("\n恭喜你答对了!!!,分数：%d\n\n",score);
				}else{
					printf("\n答案错误，正确答案是：");
					cout<<wer<<endl<<endl; 
				}	
		}else{
			printf("\n\n输入有误！！\n\n"); 
		}
		printf("<回车下一题>");
	 	getchar();
	 	getchar();
		system("cls"); 
	}
}
//计算词库文件行数
int fileline(){
	  FILE *fp;
	  int flag = 0, file_row = 0, count = 0;
	  if((fp = fopen("词库.txt", "r")) == NULL)return -1;
	  char ch=fgetc(fp);
	  if(ch==EOF)return 0;
	  while(!feof(fp))
	  {
	    flag = fgetc(fp);
	    if(flag == '\n')
	      count++;
	  }
		file_row = count + 1; //加上最后一行
	  	fclose(fp);
	  	return file_row;
} 
//读入文件（词库中读入单词） 
void readfile(){
	FILE *fp = fopen("词库.txt","r");
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
//查看词库
int lookwordlist(){
	system("cls");

	FILE *fp = fopen("词库.txt","r");
	//int line=wordnumber;
	printf("                            《词库》\n\n"); 
	for(int i=0;i<English.size();i++){
			string A,B;
			char a[100],b[100];
			fscanf(fp,"%s",a);
			fscanf(fp,"%s",b);
			printf("                    %-20s%-20s\n",a,b);
	}
	printf("\n                    总共有%d个词汇！\n\n",English.size());
	printf("\n\n<回车键返回菜单>");
	getchar();
	getchar();
	return 1;
}
//查找单词
int findword(){
	while(1){
		system("cls");
		printf("\n\n     A.根据英文查找中文         ");
		printf("B.根据中文查找英文\n\n\n");
		printf("     请选择查找类型(输入A,B选项,m返回菜单)：");
		char r;
		cin>>r; 
		if(r=='m'){
			return 1;
		}else if(r=='q'){
			exit(0);
		}else if(r=='A'){
			system("cls");
			string t1;
			printf("   \n\n请输入英文：");
			cin>>t1;
			map<string,string>::iterator it=English.begin() ;
			it=English.find(t1);
			if(it!=English.end()){
				cout<<endl<<endl<<"    "<<t1<<"的中文意思是“"<<it->second<<"”"<<endl<<endl<<endl; 
				cout<<"<回车键返回上一步>"; 
			}else{
				printf("\n\n    抱歉，词库中没有这个单词!!\n\n\n");
				cout<<"<回车键返回上一步>";
			}
		}else if(r=='B'){
			system("cls");
			string t2;
			printf("   \n\n请输入中文：");
			cin>>t2;
			map<string,string>::iterator it=chinese.begin() ;
			it=chinese.find(t2);
			if(it!=chinese.end()){
				cout<<endl<<endl<<"    "<<t2<<"的英文是“"<<it->second<<"”"<<endl<<endl<<endl; 
				cout<<"<回车键返回上一步>"; 
			}else{
				printf("\n\n    抱歉，词库中没有这个单词!!\n\n\n");
				cout<<"<回车键返回上一步>";
			}
		}else{
			system("cls");
			printf("           输入错误！！\n\n\n");
			printf("<回车返回菜单>");
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
//复习当天单词 
int dayword(){
	system("cls");
	printf("\n请输入当天所记单词（中英文空格隔开，输入m表示结束）：\n\n"); 
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
				printf("\n\n      您没有添加当天单词！！\n\n\n");
				printf("<回车返回菜单>");
				getchar();
				getchar();
				return 1;
			} 
	printf("请选择检测类型：\n\n           A.检测英文     B.检测中文");
	printf("\n\n请输入选择：");
	string t;
	cin>>t;
	system("cls");
	bool vis[50005];//标记单词是否听写 
	memset(vis,0,sizeof(vis));
	int count=0;
	while(1){
		if(t=="A"){//测英文 
			system("cls");
			printf("\n    英文检测开始，本轮共有%d个单词,你有三次机会，错误三次将自动加入词库!!!\n\n\n",k-1); 
			for(int i=1;i<=k;i++){
				int flag=random(k-1);
				if(!vis[flag]){//没有点过 
					count++;
					vis[flag]=true;
					cout<<"请输入单词“"<<wordchinese[flag]<<"”的英文意思(输入m退出检测):";
					string answer;
					int chance;
					//三次机会 
					for(chance=0;chance<3;chance++){
						cin>> answer;
						if(answer=="m"||answer=="q"){ 
							return 1;
						}
						if(answer==wordEnglish[flag]){
							rigth1++;
							chance--;
							printf("         \n\n答案正确！！");
							break;
						}else{
							if(chance==2){
								break;
							}
							printf("\n答案错误！！你还有%d次机会，请再次输入：",2-chance);
						}
					}
					if(chance>=2){
						FILE *fp=fopen("词库.txt","a+");
						char e[100],c[100];
						//将字符串转为字符数组 
						strncpy(c,wordchinese[flag].c_str(),wordchinese[flag].length()+1);
						strncpy(e,wordEnglish[flag].c_str(),wordEnglish[flag].length()+1);
						//判断是否为第一个单词控制换行 
						if(English.size()<=1){
							fprintf(fp,"%s ",e);
					    	fprintf(fp,"%s",c);
						}else{
							fprintf(fp,"\n%s ",e);
					    	fprintf(fp,"%s",c);
						}
						fclose(fp);
						cout<<"\n\n正确答案是“"<< wordEnglish[flag]<<"”已自动加入词库"; 
					}
					printf("\n\n\n<回车键下一题>"); 
					getchar();
					getchar();
					system("cls");
				
				}else{//点过 
					int v=flag;
					while(++v){
						if(v==k+1){
							v=1;
						}
						if(!vis[v]){
							count++;
							if(count==k)break;
							vis[v]=true;
							
							cout<<"请输入单词“"<<wordchinese[v]<<"”的英文意思(输入m退出检测):";
							string answer;
							int chance;
							//三次机会 
							for(chance=0;chance<3;chance++){
								cin>> answer;
								if(answer=="m"||answer=="q"){ 
									return 1;
								}
								if(answer==wordEnglish[v]){
									rigth1++;
									chance--;
									printf("         \n\n答案正确！！");
									break;
								}else{
									if(chance>=2){
										break;
									}
									printf("\n答案错误！！你还有%d次机会，请再次输入：",2-chance);
								}
							}
							if(chance>=2){
								FILE *fp=fopen("词库.txt","a+");
								char e[100],c[100];
								//将字符串转为字符数组 
								strncpy(c,wordchinese[v].c_str(),wordchinese[v].length()+1);
								strncpy(e,wordEnglish[v].c_str(),wordEnglish[v].length()+1);
								//判断是否为第一个单词控制换行 
								if(English.size()<=1){
									fprintf(fp,"%s ",e);
							    	fprintf(fp,"%s",c);
								}else{
									fprintf(fp,"\n%s ",e);
							    	fprintf(fp,"%s",c);
								}
								fclose(fp);
								cout<<"\n\n正确答案是“"<< wordEnglish[v]<<"”已自动加入词库"; 
							}
								printf("\n\n\n<回车键下一题>"); 
								getchar();
								getchar();
								system("cls");
								break;
						}
					}
				} 
			}
			printf("\n\n所有单词检测完毕,您本轮正确%d个词汇，词库收录%d个词汇!!!\n\n\n",rigth1,k-rigth1-1);
			printf("<回车退出>");
			getchar();
			return 1;
		}else if(t=="B"){//测中文 
			system("cls");
			printf("\n    中文检测开始，本轮共有%d个单词,你有三次机会，错误三次将自动加入词库!!!\n\n\n",k-1); 
			for(int i=1;i<=k;i++){
				int flag=random(k-1);
				if(!vis[flag]){//没有点过 
					count++;
					vis[flag]=true;
					cout<<"请输入单词“"<<wordEnglish[flag]<<"”的中文意思(输入m退出检测):";
					string answer;
					int chance;
					//三次机会 
					for(chance=0;chance<3;chance++){
						cin>> answer;
						if(answer=="m"||answer=="q"){ 
							return 1;
						}
						if(answer==wordchinese[flag]){
							rigth1++;
							chance--;
							printf("         \n\n答案正确！！");
							break;
						}else{
							if(chance==2){
								break;
							}
							printf("\n答案错误！！你还有%d次机会，请再次输入：",2-chance);
						}
					}
					if(chance>=2){
						FILE *fp=fopen("词库.txt","a+");
						char e[100],c[100];
						//将字符串转为字符数组 
						strncpy(c,wordchinese[flag].c_str(),wordchinese[flag].length()+1);
						strncpy(e,wordEnglish[flag].c_str(),wordEnglish[flag].length()+1);
						//判断是否为第一个单词控制换行 
						if(English.size()<=1){
							fprintf(fp,"%s ",e);
					    	fprintf(fp,"%s",c);
						}else{
							fprintf(fp,"\n%s ",e);
					    	fprintf(fp,"%s",c);
						}
						fclose(fp);
						cout<<"\n\n正确答案是“"<< wordchinese[flag]<<"”已自动加入词库"; 
					}
					printf("\n\n\n<回车键下一题>"); 
					getchar();
					getchar();
					system("cls");
				
				}else{//点过 
					int v=flag;
					while(++v){
						if(v==k+1){
							v=1;
						}
						if(!vis[v]){
							count++;
							if(count==k)break;
							vis[v]=true;
							
							cout<<"请输入单词“"<<wordEnglish[v]<<"”的中文意思(输入m退出检测):";
							string answer;
							int chance;
							//三次机会 
							for(chance=0;chance<3;chance++){
								cin>> answer;
								if(answer=="m"||answer=="q"){ 
									return 1;
								}
								if(answer==wordchinese[v]){
									rigth1++;
									chance--;
									printf("         \n\n答案正确！！");
									break;
								}else{
									if(chance>=2){
										break;
									}
									printf("\n答案错误！！你还有%d次机会，请再次输入：",2-chance);
								}
							}
							if(chance>=2){
								FILE *fp=fopen("词库.txt","a+");
								char e[100],c[100];
								//将字符串转为字符数组 
								strncpy(c,wordchinese[v].c_str(),wordchinese[v].length()+1);
								strncpy(e,wordEnglish[v].c_str(),wordEnglish[v].length()+1);
								//判断是否为第一个单词控制换行 
								if(English.size()<=1){
									fprintf(fp,"%s ",e);
							    	fprintf(fp,"%s",c);
								}else{
									fprintf(fp,"\n%s ",e);
							    	fprintf(fp,"%s",c);
								}
								fclose(fp);
								cout<<"\n\n正确答案是“"<< wordchinese[v]<<"”已自动加入词库"; 
							}
								printf("\n\n\n<回车键下一题>"); 
								getchar();
								getchar();
								system("cls");
								break;
						}
					}
					
				
				
				} 
			}
			printf("\n\n所有单词检测完毕,您本轮正确%d个词汇，词库收录%d个词汇!!!\n\n\n",rigth1,k-rigth1-1);
			printf("<回车退出>");
			getchar();
			return 1;
		}else{
			system("cls");
			printf("\n\n\n输入有误！！请重新输入:");
			printf("请选择检测类型：\n\n           A.检测英文     B.检测中文");
			printf("\n\n请输入选择：");
			cin>>t;
		}
	}
	
	
	
}
//帮助
int help(){
	system("cls"); 
	printf("                                                                      <<帮助>>\n"); 
	printf("             * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * \n\n"); 
	printf("                  *操作说明*："); 
	printf("1.输入m键返回菜单\n\n                              2.输入q键退出\n\n                              3.回车键下一题或者返回上一步或者返回菜单\n\n\n"); 
	printf("                  *功能介绍*：本程序可以实现用户自己录入词库，并且随机抽取词库单词的功能，帮助用户快速掌握单词\n");
	printf("\n                              1.添加新单词：输入单词的英文 中文，可以自动将单词加入词库中"); 
	printf("\n                              2.默写中文：给出英文，用户回答中文，并且判断对错，若错误给出正确答案"); 
	printf("\n                              3.默写英文：给出中文，用户回答英文，并且判断对错，若错误给出正确答案");
	printf("\n                              4.根据中文选择英文：给出中文，题目给出ABCD四个英文选项，用户输入正确选项，并且判断对错，若错误给出正确答案"); 
	printf("\n                              5.根据英文选择中文：给出英文文，题目给出ABCD四个中文难选项，用户输入正确选项，并且判断对错，若错误给出正确答案");
	printf("\n                              6.查看单词列表：用户可以查看自己的单词库的所有单词及个数");
	printf("\n                              7.查找单词：根据中英文从词库中查找单词");
	printf("\n                              7.当天复习：输入当天记的单词，进行复习测试,错三次单词将自动录入词库");
	printf("\n                              8.统计分数：用户答对加分，答错不扣分\n\n\n");
	printf("                  *词库的使用*："); 
	printf("由于在编译环境中录入单词不方便，所以特提供了词库功能，记事本文件“词库.txt”就是词库，若要添加或者修改删除\n                                单词，可以直接在本文件中添加修改删除，但是注意不要出现多余的回车，保存时保证光标在最后一个单词的后面,词库的\n                                单词会永久保存，当然在程序中添加也会加入词库");	 
	printf("\n\n\n\n\n\n<按回车返回菜单>");
	getchar();
	getchar();
	return 1;
}
int main(){
	while(1){
		//文件读入 
	     readfile();
		if(mark==1)list();//打开菜单;
		scanf("%d",&choose);
		/*if(choose==0){
			printf("\n                                            输入有误，请重新输入<按回车键继续>!!\n"); 
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
				printf("\n\n                                                  本次总共得%d分!!!                                \n\n",score);
				return 0;
				break;
			}
			case 0:{
				printf("\n                                            输入有误，请重新输入<按回车键继续>!!\n"); 
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
				printf("\n                                            输入有误，请重新输入<按回车键继续>!!\n"); 
				getchar();
				getchar();
			}
		} 
	}
	return 0;
}
 
