//Palindromic Tree
//Complexity : O(n) memory and O(n) time

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005

struct node{
    int Next[26];
    int Len;        //Length of the palindrome represented by current node
    int Count;      //Number of palindromic suffixes of the palindrome represented by current node
    int Occurrence; //Total number of occurrence of this node
    int SuffLink;   //Links such node w such that the palindrome represented by node w is the largest
                    //palindrome which is a proper suffix of the palindrome represented by current node
};

string s;
node Tree[MAX];
int Suff;           // Points to Current (initially previous) node in palindromic tree
int Size;           // Size = Total number of node in palindromic tree
                    // Size = 1 denotes node 1 (root with Len -1)
                    // Size = 2 denotes node 2 (root with Len  0)
bool AddLetter(int pos){
    int Cur=Suff;
    int CurLen=0;
    int Let=s[pos]-'a';

    while(true){
        CurLen=Tree[Cur].Len;
        if(pos-1 >= CurLen && s[pos-1-CurLen]==s[pos]) break;
        Cur=Tree[Cur].SuffLink;
    }
    Tree[Cur].Occurrence++;

    if(Tree[Cur].Next[Let]) {Suff=Tree[Cur].Next[Let]; return false;}
    Size++;
    Suff=Size;
    Tree[Size].Len=Tree[Cur].Len + 2;
    Tree[Cur].Next[Let]=Size;

    if(Tree[Size].Len==1) {Tree[Size].SuffLink=2; Tree[Size].Count=1; return true;}

    while(true){
        Cur=Tree[Cur].SuffLink;
        CurLen=Tree[Cur].Len;
        if(pos-1 >= CurLen && s[pos-1-CurLen]==s[pos]){
            Tree[Size].SuffLink=Tree[Cur].Next[Let];
            break;
        }
    }

    Tree[Size].Count=1+Tree[Tree[Size].SuffLink].Count;
    return true;
}

void InitTree(){
    Size=2; Suff=2;
    Tree[1].Len=-1; Tree[1].SuffLink=1;
    Tree[2].Len=0;  Tree[2].SuffLink=1;
}

int main(){
    //memset(Tree,0,sizeof(Tree));
    //InitTree();
    //for(int i=0;i<n;i++) AddLetter(i);
    //distinct palindrome count = Size - 2
}
