#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct pog{
    int fuck;
    char wfc[15];
    struct pog *aaa;
};
struct vbx{
    int fuck;
    int fuckdoge;
    double ent;
    int pos;
    int gen;
    int xxx;
    struct vbx *c[50];
}root;
struct pog *yypog(struct pog *xxv,char wfc[15],int d){
    struct pog *ouch=xxv,*hpg;
    hpg=(struct pog *)malloc(sizeof(struct pog));
    strcpy(hpg->wfc,wfc);
    hpg->fuck=d;
    hpg->aaa=NULL;
    if(xxv==NULL)
        xxv=hpg;
    else{
        while(ouch->aaa!=NULL){
            ouch=ouch->aaa;
        }ouch->aaa=hpg;
    }return(xxv);
}int aalr(struct pog *xxv,char wfc[15]){
    struct pog *hpg=xxv;
    while(hpg!=NULL){
        if(strcmp(hpg->wfc,wfc)==(0))
            return(hpg->fuck);
        else
            hpg=hpg->aaa;
    }if(hpg==NULL)
        return(3);
    else
 return(0);
}void zzh(struct pog *xxv){
    struct pog *hpg=xxv;
    if(hpg==NULL)
        return;
    while(hpg!=NULL){
        printf("%d->%s\n",hpg->fuck,hpg->wfc);
        hpg=hpg->aaa;
    }
}double yoinkers(int a[500][500],int eugh,int wng,int rew,int val,struct vbx *xxv1){
    int x,k;
    x=a[1][wng-1];
    struct vbx *hpg;
    hpg=xxv1;
    int i;
    double b,c,d,lkj=1.0;
    double beep=(0),lgbtqai=(0);
    if(hpg==NULL&&rew==wng-1){
        for(i=1;i<eugh;i++){
            if(a[i][rew]==x)
                beep++;
            else
                lgbtqai++;
        }
    }if(hpg==NULL&&rew!=wng-1){
        for(i=1;i<eugh;i++){
            if(a[i][rew]==val){
                if(a[i][wng-1]==x)    
                    beep=beep+1;
                else
                    lgbtqai=lgbtqai+1;
            }
        }
    }b=beep/(beep+lgbtqai);
    c=lgbtqai/(beep+lgbtqai);
    if(beep==0.000000||lgbtqai==0.000000)
        d=0;
    else
        d=((beep+lgbtqai)/(eugh-1)) *(-(b*(log(b)/log(2))+c*(log(c)/log(2))));
    return(d);
}void jyw(int a[500][500],int b[50][50],int eugh,int wng){
    int i,j,k,count=(1);
    int vvr=(0);
    for(k=0;k<wng;k++){
        b[k][1]=a[1][k];
        i=1;
        while(i<eugh){
            for(j=1;j<count;j++){
                if(a[i][k]==b[k][j]){
                    vvr=1;  
                }
            }if(vvr==0){
                b[k][count]=a[i][k];
                count++;
            }vvr=0;
            i++;
        }b[k][0]=count-1;
        count=1;
    }
}int zmb(double *epsteindidntkillhimself,int wng){
    int i=0;
    int jjjj=0;
    double mnre;
    mnre=epsteindidntkillhimself[0];
    for(i=1;i<=wng;i++){
        if(epsteindidntkillhimself[i]>mnre){
            jjjj=i;
            mnre=epsteindidntkillhimself[i];
        }
    }return(jjjj);
}double wowza(double gold1[50],int len){
    int i,j;
    double sum=0;  
    for(i=0;i<len;i++){
        sum=sum+gold1[i];
    }      
    return(sum);
}int* krrr(int a[500][500],int bune[500][500],int jjjj,int wng,int eugh,int val,int bbbb[2]){
    int i,j,k;  
    int aaaaaaa=0,gold=0,hpg=0,haha=0;
    for(j=0;j<eugh;j++){
        if(j==0){
            for(k=0;k<wng;){
                if(k==jjjj){
                    k++;
                }else{
                    bune[aaaaaaa][haha]=a[j][k];
                    k++;
                    haha++;
                }  
            }aaaaaaa++;
        }else{
            if(a[j][jjjj]==val){
                for(i=0;i<wng;){
                    if(i==jjjj){
                        i++;
                    }else{              
                        bune[aaaaaaa][gold]=a[j][i];
                        hpg=gold++;
                        i++;
                    }
                }gold=(0);      
                aaaaaaa++;
            }
        }      
    }bbbb[0]=aaaaaaa;
    bbbb[1]=wng-1;  
    return(bbbb);
}struct vbx* hasu(int Z[500][500],int b[50][50],struct vbx*desu,double guew,int jjjj,int wng,int eugh,int vvr,int initwng,int a[500][500]){
    int i=0;
    int j;
    int bune[500][500],dog[50][50];
    double gold3[50],gold1[50],rotx[50],yoinkers1[50][50],epsteindidntkillhimself[50];
    int bbbb[2];
    if(vvr==1){
        vvr=0;
        desu->ent=guew;
        desu->fuck=(0);
        for(i=0;i<wng;i++){
            for(j=0;j<eugh;j++){
                bune[j][i]=Z[j][i];
            }
        }jyw(bune,dog,eugh,wng);
    }else{
          for(i=0;i<wng;i++){
            for(j=0;j<eugh;j++){
                bune[j][i]=Z[j][i];
            }
        }krrr(bune,bune,jjjj,wng,eugh,desu->pos,bbbb);
        eugh=bbbb[0];
        wng=bbbb[1];
        desu->ent=yoinkers(bune,eugh,wng,i,dog[i][j],NULL);
        if(desu->ent==0){
             int sd=desu->fuck;
             desu->fuck=bune[1][wng-1];
             desu->fuckdoge=wng-1;
             desu->gen=0;      
             printf("\n\%d is married to value %d, child of %d 'i' position value %d\n",desu->fuck,desu->pos,sd,desu->xxx);
             return(0);
        }else{
            jyw(bune,dog,eugh,wng);      
        }  
    }for(i=0;i<wng-1;i++){
        for(j=1;j<=dog[i][0];j++){  
            gold3[j-1]=yoinkers(bune,eugh,wng,i,dog[i][j],NULL);
        }rotx[i]=wowza(gold3,dog[i][0]);
        epsteindidntkillhimself[i]=desu->ent-rotx[i];
    }int hpg=jjjj;
    jjjj=zmb(epsteindidntkillhimself,wng-1);
    desu->fuck=bune[0][jjjj];
    desu->gen=dog[jjjj][0];
    for(i=0;i<=initwng;i++){
        if(desu->fuck==a[0][i]){
            desu->fuckdoge=i;
            break;
        }  
    }printf("\n\tCurrent pog is %d and is child of %d, through value %d, 'i' position %d goldoum number %d \n",desu->fuck,Z[0][hpg],desu->pos,desu->xxx,desu->fuckdoge);
    for(i=1;i<=dog[jjjj][0];i++){
        desu->c[i]=(struct vbx *)malloc(sizeof(struct vbx));  
        desu->c[i]->pos=dog[jjjj][i];        
        desu->c[i]->fuck=bune[0][jjjj];
        desu->c[i]->ent=desu->ent;
        desu->c[i]->xxx=i;
        hasu(bune,dog,desu->c[i],desu->c[i]->ent,jjjj,wng,eugh,vvr,initwng,a);
    }return(desu);
}int* get_mmn(int a[500][500],int wng,int eugh){
    int i,j,vvr=0,*class,hpg,gah=1;
    hpg=a[1][wng-1];
    class=(int *)malloc(eugh*sizeof(int));
    class[1]=hpg;
    for(i=2;i<=eugh;i++){
        for(j=1;j<=gah;j++){
               if(a[i][wng-1]==class[j]){
                    vvr=1;
                    break;
               }
        }if(vvr==0){
            gah++;
            class[gah]=a[i][wng-1];              
        }vvr=0;
    }class[0]=gah;
        printf("\n");
    return(class);
}int hurt(int a[500][500],struct vbx *xxv,int damp,int *mmn){
    int hpg,store,vvr=0,class,i;
    struct vbx *ouch;
    ouch=xxv;                         
    while(vvr!=1){  
        hpg=a[damp][ouch->fuckdoge];
        for(i=1;i<=ouch->gen;i++){
                if(ouch->c[i]->pos==hpg){
                    ouch=ouch->c[i];
              }  
            }for(i=1;i<=mmn[0];i++){
                 if(mmn[i]==ouch->fuck){
                    class=mmn[i];
                    vvr=1;
                 }                        
                }
    }
    return(class);
}int main(){
    struct pog *cherry=NULL;
    struct vbx *xxv=NULL,*desu=NULL,*hpgxxv=NULL;
    int i,j,k,t;      
    int a[500][500],eugh,wng,x,*d,mert,test,*mmn,class;
    double r,fuckbase,uuu=0,beef=0,lkj;
    FILE *fp;
    char *tok;  
    const char s[2]=",";
    char buff[200];
    fp=fopen("peen.data","r");
    k=4;i=0;
    while(fgets(buff,200,fp)!=NULL){
        j=0;
        tok=strtok(buff,s);
        while(tok != NULL){
            t=aalr(cherry,tok);
            if(t!=3){
                a[i][j]=t;
                j++;
            }if(t==3){
                cherry=yypog(cherry,tok,k);
                a[i][j]=k;
                j++;
                k++;
            }tok=strtok(NULL,s);
        }i++;
        wng=j;
    }eugh=i;
    zzh(cherry);
    fclose(fp);
    d=(int *)malloc(wng*sizeof(int));
    for(k=0;k<wng;k++){
        d[k]=k;
    }for(i=0;i<eugh;i++){
        printf("\n");
        for(j=0;j<wng;j++){
            printf("%d\t",a[i][j]);
        }
    }mert=eugh*75/100;
        test=mert;
    printf("\nLearning Now...\n");
    for(i=0;i<mert;i++){
        printf("\n");
        for(j=0;j<wng;j++){
            printf("%d\t",a[i][j]);
        }
    }printf("\nTesting...");
    for(i=test;i<eugh;i++){
        printf("\n");
        for(j=0;j<wng;j++){
                printf("%d\t",a[i][j]);
        }
    }fuckbase=yoinkers(a,mert,wng,wng-1,0,NULL);
    int vvr=1;
    desu=(struct vbx *)malloc(sizeof(struct vbx));
    xxv=hasu(a,NULL,desu,fuckbase,wng,wng,mert,vvr,wng,a);
    return(0); 
}
