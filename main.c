#include <stdio.h>
#include<string.h>
struct customer{
    int cid;
    char phno[20],address[100],cname[20];
}customer[100];


struct item{
    char iname[20];
    int iprice,iid;
}item[100];


struct bill{
    int billno,cid,no_items,total;
    char date[8];
    
    struct items{
        int qty,price,itemid;
    }it[100];
    
}bill[100];

int i,j,nobill=0,cuid=0,ino=0,id;
char output[1000],arr[100];


void customer_creation()
{
    printf("enter your name :");
    scanf("%s",customer[cuid].cname);
    printf("enter your phone number :");
    scanf("%s",customer[cuid].phno);
    printf("enter your address :");
    scanf("%s",customer[cuid].address);
    customer[cuid].cid=cuid;
    printf("your customer id is %d\n",cuid);
    cuid++;
    printf("<------------------------------------response submitted successfully---------------------------------------------->\n");
}


void item_creation()
{
    printf("enter the item name : ");
    scanf("%s",item[ino].iname);
    printf("enter item price :");
    scanf("%d",&item[ino].iprice);
    if(item[ino].iprice<=0)
        printf("\nenter the inputs again with valid price\n");
    else
    {
      item[ino].iid=ino;
      printf("\nthe item id is %d\n",ino);
      ino++;
    }
    printf("<-----------------------------------response submitted successfully----------------------------------->\n");
}


void bill_creation()
{
    printf("\nenter your customer id\n");
    scanf("%d",&bill[nobill].cid);
    
    if(bill[nobill].cid>cuid || bill[nobill].cid<0)
        printf("your customer id does not exist");
        
    else
    {
    printf("\nenter the date\n");
    scanf("%s",bill[nobill].date);
    printf("\nenter number of items you want to purchase\n");
    scanf("%d",&bill[nobill].no_items);
    bill[nobill].billno=nobill;
    for(i=0;i<bill[nobill].no_items;i++)
    {
        printf("\nenter the item id\n");
        scanf("%d",&bill[nobill].it[i].itemid);
        printf("\nenter item quantity\n");
        scanf("%d",&bill[nobill].it[i].qty);
        printf("\nenter price\n");
        scanf("%d",&bill[nobill].it[i].price);
        bill[nobill].total+=bill[nobill].it[i].price*bill[nobill].it[i].qty;
    }
    printf("your bill no is %d\n",nobill);
    nobill++;
    printf("<------------------------------------bill created successfully---------------------------------->\n");
    }
}


char* strconvert(int i,char arr[])
{
    strcpy(arr," ");
    int p=10,temp=0,j=temp+1;
    while(i/p!=0)
    {
        p*=10;
        temp+=1;
    }
    j=temp+1;
    for(;temp>=0;temp--)
    {
        arr[temp]=(i%10)+'0';
        i/=10;    
    }
    arr[j]='\0';
    return arr;    
}


void customer_list(char* opt)
{
    
    {
        
    }
    strcpy(output,"");
    if(cuid==0)
        printf("\nError : 404 Not Found\n");
    else
    {
    printf("<------------------------------------customer list---------------------------------------------->\n");
    if(strcmp(opt,"4")==0)
    {
    printf("\tid\tname\tphno\taddress\n");
    for(i=0;i<cuid;i++)
        printf("\t%d\t %s\t %s\t %s\n",customer[i].cid,customer[i].cname,customer[i].phno,customer[i].address);
    }
    else{
    strcat(output,"{");
    for(i=0;i<cuid;i++)
    {
        strcat(output,"\n{\"Customer id\":\"");
        strcat(output,strconvert(i,arr));
        strcat(output,"\",\n\"Customer Name\":\"");
        strcat(output,customer[i].cname);
        strcat(output,"\",\n\"Phone number\":\"");
        strcat(output,customer[i].phno);
        strcat(output,"\",\n\"address\":\"");
        strcat(output,customer[i].address);
        strcat(output,"\"},");
    }
    strcat(output,"}");
    printf("%s",output);
    }
  }
}


void item_list(char* opt)
{
    strcpy(output,"");
    if(ino==0)
        printf("\nError : 404 Not Found\n");
    else
    {
    printf("<------------------------------------item list-------------------------------------------------->\n");
    if(strcmp(opt,"5")==0)
    {
    printf("\titem id\tname\tprice\n");
    for(i=0;i<ino;i++)
        printf("\t%d\t %s\t %d\n",item[i].iid,item[i].iname,item[i].iprice);
    }
    else
    {
    strcat(output,"{");
    for(i=0;i<ino;i++)
    {
        strcat(output,"\n{\"Item id\":\"");
        strcat(output,strconvert(i,arr));
        strcat(output,"\",\n\"Item Name\":\"");
        strcat(output,item[i].iname);
        strcat(output,"\",\n\"Item price\":\"");
        strcat(output,strconvert(item[i].iprice,arr));
        strcat(output,"\"},");
    }
    strcat(output,"}");
    printf("%s",output);
    }
  } 
}


void bill_list(char* opt)
{
    strcpy(output,"");
    if(nobill==0)
        printf("\nError : 404 Not Found\n");
    else
    {
    printf("<------------------------------------bill list-------------------------------------------------->\n");
    if(strcmp(opt,"6")==0)
    {
        for(i=0;i<nobill;i++)
    {
        
        printf("bill no : %d\ncustomer id : %d\ndate of purchace : %s\nphone number : %s\n",bill[i].billno,bill[i].cid,bill[i].date,customer[bill[i].cid].phno);
        printf("id\tname\t\tquantity\tprice\n");
        for(j=0;j<bill[i].no_items;j++)
        {
            printf("%d\t %s\t %d\t %d\n",bill[i].it[j].itemid,item[bill[i].it[j].itemid].iname,bill[i].it[j].qty,bill[i].it[j].price);    
        }
        printf("The BILL total is %d RS",bill[i].total);
    }
    }
    else
    {
    for(i=0;i<nobill;i++)
    {
        strcat(output,"\n{\"Bill NO\":\"");
        strcat(output,strconvert(bill[i].billno,arr));
        strcat(output,"\",\n\"Customer Id\":\"");
        strcat(output,strconvert(bill[i].cid,arr));
        strcat(output,"\",\n\"Date\":\"");
         strcat(output,strconvert(bill[i].cid,arr));
        strcat(output,"\",\n\"phone number\":\"");
        strcat(output,customer[bill[i].cid].phno);
        strcat(output,"\",\n");
        for(j=0;j<bill[i].no_items;j++)
        {
            strcat(output,"\n[\"Item id\":\"");
            strcat(output,strconvert(bill[i].it[j].itemid,arr));
            strcat(output,"\",\"Item Name\":\"");
            strcat(output,item[bill[i].it[j].itemid].iname);
            strcat(output,"\",\"quantity\":\"");
            strcat(output,strconvert(bill[i].it[j].qty,arr));
            strcat(output,"\",\"Price\":\"");
            strcat(output,strconvert(bill[i].it[j].price,arr));
            strcat(output,"\"],");
        }
    }
    strcat(output,"}");
    printf("%s",output);
}}
}


void item_update()
{
    strcpy(output,"");
    int id,p1;
    char feild[20],p2[20];
    printf("enter item id to update");
    scanf("%d",&id);
    printf("enter feild to update");
    scanf("%s",feild);
    if(strcmp(feild,"price")==0)
    {
        printf("actual price : %d",item[id].iprice);
        printf("update price");
        scanf("%d",&p1);
        item[id].iprice=p1;
    }
    else
    {
        printf("actual name : %s",item[id].iname);
        printf("update item name");
        scanf("%s",p2);
        strcpy(item[id].iname,p2);
    }
    strcat(output,"{\"Item id\":\"");
    strcat(output,strconvert(id,arr));
    strcat(output,"\",\"Item Name\":\"");
    strcat(output,item[id].iname);
    strcat(output,"\",\"Item price\":\"");
    strcat(output,strconvert(item[id].iprice,arr));
    strcat(output,"\"}");
    printf("%s",output);
}


void bill_based_on_billno(char* opt)
{
    int id,n;
    strcpy(output,"");
        if(strcmp(opt,"7")==0)
        {
            printf("\nenter bill no\n");
            scanf("%d",&id);
        for(i=0;i<nobill;i++)
          {
            printf("bill no : %d\ncustomer id : %d\ndate of purchace : %s\nphone number : %s\n",bill[id].billno,bill[id].cid,bill[id].date,customer[bill[id].cid].phno);
            printf("id\tname\t\tquantity\tprice\n");
            for(j=0;j<bill[i].no_items;j++)
                 printf("%d\t %s\t\t\t %d\t %d\n",bill[id].it[j].itemid,item[bill[id].it[j].itemid].iname,bill[id].it[j].qty,bill[id].it[j].price);
            printf("The BILL total is %d RS",bill[id].total);
            
           }
        }
        else{
        n=strlen(opt);
        id=opt[n-1]-'0';
        strcat(output,"\n{\"Bill NO\":\"");
        strcat(output,strconvert(bill[i].billno,arr));
        strcat(output,"\",\n\"Customer Id\":\"");
        strcat(output,strconvert(bill[i].cid,arr));
        strcat(output,"\",\n\"Date\":\"");
         strcat(output,strconvert(bill[i].cid,arr));
        strcat(output,"\",\n\"phone number\":\"");
        strcat(output,customer[bill[i].cid].phno);
        strcat(output,"\",\n");
        for(j=0;j<bill[id].no_items;j++)
            {
            strcat(output,"\n[\"Item id\":\"");
            strcat(output,strconvert(bill[id].it[j].itemid,arr));
            strcat(output,"\",\"Item Name\":\"");
            strcat(output,item[bill[id].it[j].itemid].iname);
            strcat(output,"\",\"quantity\":\"");
            strcat(output,strconvert(bill[id].it[j].qty,arr));
            strcat(output,"\",\"Price\":\"");
            strcat(output,strconvert(bill[id].it[j].price,arr));
            strcat(output,"\"],");
            }
    strcat(output,"}");
    printf("%s",output);
  }
}

//--------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------
int main()
{
    char opt[20],method[20];
    int id,n;
    while(1)
    {
        printf("\n\n\n1.customer creation\n2.item creation\n3.bill creation\n4.customer list\n5.item list\n6.bill list\n7.bill based on billno\n");
        printf("<------------------------------------choose case---------------------------------------------->\n");
        printf("\n enter uri or option \n");
        scanf("%s",opt);
        if(strcmp(opt,"1")==0)
            customer_creation();
            
        else if(strcmp(opt,"2")==0)
            item_creation();
            
        else if(strcmp(opt,"3")==0)
            bill_creation();
            
        else if(strcmp(opt,"4")==0)
            customer_list(opt);
            
        else if(strcmp(opt,"5")==0)
            item_list(opt);
            
        else if(strcmp(opt,"6")==0)
            bill_list(opt);
            
            
        else if(strcmp(opt,"7")==0)
            bill_based_on_billno(opt);
        
        
        
        
        
        
        
        else if(strcmp(opt,"/customers")==0)
        {
               printf("\n enter method \n");
               scanf("%s",method);
               if(strcmp(method,"POST")==0)
                    customer_creation();
                    
               else if(strcmp(method,"GET")==0)
                      customer_list(opt);
        }
        
        
        
        
        else if(strcmp(opt,"/items")==0)
        {
               printf("\nenter method\n");
               scanf("%s",method);
                if(strcmp(method,"POST")==0)
                    item_creation();
                    
                else if(strcmp(method,"GET")==0)
                    item_list(opt);
                    
                else if(strcmp(method,"PATCH")==0)
                    item_update();
         }
         
         
         
         
        else if(strcmp(opt,"/bills")==0)
         {
               printf("\nenter method\n");
               scanf("%s",method);
                if(strcmp(method,"POST")==0)
                    bill_creation();
                    
                else if(strcmp(method,"GET")==0)
                    bill_list(opt);
        
        }
        else
            bill_based_on_billno(opt);
    }
    
    return 0;
}
