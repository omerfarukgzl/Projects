/**
* @file			Veri yapilari 1. odev
* @description	Txt deki veriler ile ekle sil komutları çalıştırılması
* @course		1B 
* @date			14/11/2021
* @author		Ömer Faruk Güzel faruk.guzel@ogr.sakarya.edu.tr  Numara :g191210068
*/
#include "Islem.h"
Islem::Islem()
{
	root=NULL;
}
void Islem::NodeEkle(string data ,int index)
{
	int adimSayisi;
	Node* newNode = new Node;
	Node* temp = root;
    newNode->next = NULL;
 
   if (root == NULL) 
   {
	   newNode->prev=root;
	   newNode->data=data;
	   root = newNode;
	   return;
   }

   int dugumSayisi=0;
   
    while (temp->next != NULL)//Sona dugume git 
	{
		dugumSayisi++;
		temp = temp->next;
	}
	
	dugumSayisi++;
	//dugum sona eklendi
    temp->next = newNode;
    newNode->prev = temp;
	
 adimSayisi=(dugumSayisi-index);
	if(index<dugumSayisi)//index varsa
	{
	  temp=newNode;
	    while (adimSayisi!=0)// sola dogru veri kaydırma
	    {
			temp->data=temp->prev->data;
			temp=temp->prev;
			adimSayisi--;
	    }
	  temp->data=data;
	}
	else // index yoksa 
	newNode->data=data;	
}

void Islem::NodeSil(int index)
{
	if(root!=NULL)
	{	
		if(root->next==NULL )
		{
			delete root;
			root=NULL;
		}
		else
		{
			int tempIndex=index;
			Node* temp = root;
			while (tempIndex!=0 && temp->next!=NULL)//Sona dugume git 
			{
				temp = temp->next;
				tempIndex--;
		    }					
			if(tempIndex==0)//index varsa
			{
				while (temp->next!=NULL)// veri kaydırma
				{
					temp->data=temp->next->data;
					temp=temp->next;
				}
				Node * temp2 = temp->prev;
				delete temp;
				temp2->next=NULL;			
			}
			else
			{
				Node * temp2 = temp->prev;
				delete temp;
				temp2->next=NULL;			
			}
		}		
	}
}
void Islem::EkranaYazdir(Node * node)
{
	struct Node* temp;
   while (node != NULL) {
	    
      cout<<node->data;
	  if(node->next != NULL)
	  cout<<"<==>";
      temp = node;
      node = node->next;
   }
   if(root==NULL)
   cout<<"liste bos";
}	
void Islem::DosyaIslemleri()
{
	string satir;
	ifstream dosya;
	dosya.open("Veri.txt", ios::in);
	while(getline(dosya,satir))//dosya sonuna gelene kadar okunan döngü
	{
	    int index;
		string data;
		int indexNum;
		string indexOkunan="";
		if(satir[0]=='E')
		{
			for(int i=1;i<satir.length();i++)
		    {
				if(satir[i]=='#')//# işaretinin indexinin belirlenmesi
				{
					indexNum=i;
				}					
		    }	
            for(int i=2;i<satir.length();i++)
			{
				while(i<indexNum)//index sayısının belirlenmesi
				{
					indexOkunan+=satir[i];
					break;
				}
				if(i>indexNum && satir[i]!=')')
					data+=satir[i];
		    }
			    stringstream ss;  
                ss << indexOkunan;  
                ss >> index;  
			  NodeEkle(data,index);			
		}
		else if(satir[0]=='S')
		{
			for(int i=2;i<satir.length();i++)
		    {
				while(satir[i]!=')')//index sayısının belirlenmesi
				{
					indexOkunan+=satir[i];
					break;
				}					     
		    }
			stringstream ss;  
            ss << indexOkunan;  
            ss >> index;
			NodeSil(index);		
		}
	}
	dosya.close();
	EkranaYazdir(root);
}
Islem::~Islem()
{
	Node* iter = root;
	while (iter)
	{
		root = root->next;
		delete[] iter;
		iter = root;
	}
}
