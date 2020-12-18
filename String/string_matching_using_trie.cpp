#include<iostream>
using namespace std;

struct trie {
  trie *nxt[26];
 
  trie(){
      for(int i=0;i<26;i++) nxt[i] = NULL;
  }

};

trie *root;

void insert(string s){
    trie *cur = root;
    for(int i=0;i<s.size();i++){
       if(cur->nxt[s[i]-'a']==NULL) cur->nxt[s[i]-'a']= new trie();
       	cur =cur->nxt[s[i]-'a'];
    }
   
}

bool in_trie(string s){
  trie *cur = root;

  for(int i=0;i<s.size();i++){
      if(cur->nxt[s[i]-'a']==NULL) return false;
      cur = cur->nxt[s[i]-'a'];
  }

  return true;
}
int main(){

  root = new trie();
  
  string text = "abaacadbacad";
  string pat = "aaca";

  int n = text.size(), m = pat.size();

  for(int i=0;i<n;i++){
       insert(text.substr(i));
  }

  if(in_trie(pat)){
        cout<<"YES\n";
  }
  else{
     cout<<"NO\n";
  }
}