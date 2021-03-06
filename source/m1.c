#include<stdio.h> 
#include<stdlib.h> 
#include<string.h>

char *words[200];
float prob[20];
char *output;

struct OBST
{
	struct OBST *left;
	char key[20];
	struct OBST  *right;
}*st_root;


struct OBST*  build_OBST(int i,int j,int **root)
{
	int k;
	k=*(*(root+i)+j);
	struct OBST *p;
	p=(struct OBST*)malloc(sizeof(struct OBST));
	if(i==j)
	{
		p=NULL;		
	}
	else
	{
		strcpy(p->key,words[k-1]);
		p->left=build_OBST(i,k-1,root);
		p->right=build_OBST(k,j,root);
	}
	return p;
}

void display(struct OBST *rt)
{	
	FILE *fp1;
	fp1=fopen(output,"a");
	
	if(rt->left == NULL && rt -> right == NULL)
		return;
	if(rt-> left != NULL)
	{
		fprintf(fp1,"%s is the left child of %s\n", rt -> left -> key , rt -> key);
		display(rt->left);
	}
	else if(rt-> right != NULL)
	{
		fprintf(fp1,"%s is the right child of %s\n", rt -> right -> key , rt -> key);
		display(rt->right);
	}
		
}

int main(int argc, char **argv)
{
	FILE *fp,*fp1;
	int i=0,j=0,p;
	int r,m,c,diagonal,k,cmp;
	float data,min,x;
	float temp_prob[20];
	char ch[20];
	char t[200];
	output=argv[2];
	char *u_words[200];
	char *copy_words[200];
	fp=fopen(argv[1],"r");
	fp1=fopen(output,"a");
	if(fp==NULL)
	{
		printf("Incorrect file name\n");
		return;
	}
	while(fscanf(fp,"%s %f",ch,&data)==2)
	{
		u_words[i]=(char*)malloc(sizeof(ch));
		strcpy(u_words[i],ch);
		temp_prob[i]=data;
		//printf("u_word[%d]=%s temp_prob[%d]=%f\n",i,u_words[i],i,temp_prob[i]);
		i++;
	}
    	for(p=0;p<i;p++)
    	{
        	copy_words[p]=(char*)malloc(sizeof(u_words[i]));
        	strcpy(copy_words[p],u_words[p]);
        	//printf("copy_words[%d]:%s\n",p,copy_words[p]);
    	}
	for(p=1;p<=(i-1);p++)
	{
		for(j=1;j<=(i-1);j++)
		{
			if(strcmp(u_words[j-1],u_words[j])>0)
			{
				strcpy(t,u_words[j-1]);
				strcpy(u_words[j-1],u_words[j]);
				strcpy(u_words[j],t);
			}
		}
	}
	for(p=0;p<i;p++)
    	{
        	words[p]=(char*)malloc(sizeof(u_words[i]));
        	strcpy(words[p],u_words[p]);
        	//printf("words[%d]:%s\n",p,words[p]);
    	}
	for(p=0;p<i;p++)
    	{
        	for(j=0;j<i;j++)
        	{
            		cmp=strcmp(words[p],copy_words[j]);
			if(cmp==0)
            		{
                	prob[p]=temp_prob[j];
			break;
            		}
        	}
    	}
	
	
    	for(p=0;p<i;p++)
            //printf("words[%d]:%s\n",p,words[p]);
	for(p=0;p<i;p++)
            //printf("prob[%d]:%f\n",prob[p]);
	
	r=c=i+1;
	float *arr[r];
	int *root[r];
	float *w[r];
	for(i=0;i<r;i++)
		arr[i]=(float *)calloc(c,sizeof(float));
	for(i=0;i<r;i++)
		root[i]=(int *)calloc(c,sizeof(int));
	for(i=0;i<r;i++)
		w[i]=(float *)calloc(c,sizeof(float));

	for(i=0;i<=r-1;i++)
	{
		*(*(w+i)+i)=0;
		for(j=i+1;j<=r-1;j++)
			*(*(w+i)+j)=*(*(w+i)+(j-1))+prob[j-1];
	}
	for(i=0;i<=r-1;i++)
	{
		*(*(arr+i)+i)=0;
	}
	for(i=0;i<=r-2;i++)
	{
			j=i+1;
			*(*(arr+i)+j)=*(*(w+i)+j);
			*(*(root+i)+j)=j;
	}
	for(diagonal=2;diagonal<=r-1;diagonal++)
	{
		for(i=0;i<=((r-1)-diagonal);i++)
		{
			j=i+diagonal;
			m=*(*(root+i)+(j-1));
			min=(*(*(arr+i)+(m-1)))+(*(*(arr+m)+j));
			//printf("m:%d\n",m);
			//printf("min:%f\n",min);
			for(k=m+1;k<=*(*(root+(i+1))+j);k++)
			{
				x=*(*(arr+i)+(k-1))+(*(*(arr+k)+j));
				if(x<min)
				{
					m=k;
					min=x;
				}
			}
			*(*(arr+i)+j)= *(*(w+i)+j)+min;
			*(*(root+i)+j)=m;
		}
	}
	/*for(i=0;i<=r-1;i++)
	{
		for(j=0;j<=r-1;j++)
		{
			printf("a[%d][%d]:%f  ",i,j,*(*(arr+i)+j));
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<=r-1;i++)
	{
		for(j=0;j<=r-1;j++)
		{
			printf("w[%d][%d]:%f  ",i,j,*(*(w+i)+j));
		}
		printf("\n");
	}
	printf("\n");
	for(i=0;i<=r-1;i++)
	{
		for(j=0;j<=r-1;j++)
		{
			printf("root[%d][%d]:%d  ",i,j,*(*(root+i)+j));
		}
		printf("\n");
	}*/
	st_root=build_OBST(0,r-1,root);
	fprintf(fp1,"%s  is the root of the tree\n",st_root->key);
	display(st_root);
	fclose(fp);
	fclose(fp1);
	free(arr);
	free(root);
	return 0;
}

