/*
    Insertion and Search in Trie
*/

import java.util.*;
import java.lang.*;
import java.io.*;
class TrieNode{
    TrieNode[] child = new TrieNode[256];
    boolean isEnd;
}
class GFG{
    public static void main (String[] args)throws IOException{
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(buff.readLine());
        while(t-->0){
            int n = Integer.parseInt(buff.readLine());
            String words[] = buff.readLine().trim().split("\\s+");
            String searchElem = buff.readLine();
            TrieNode root = new TrieNode();
            for(int i=0;i<n;i++){
                TrieNode prev = root;
                String word = words[i];
                int len = words[i].length();
                for(int j=0;j<len;j++){
                    if(prev.child[word.charAt(j)]!=null){
                        prev = prev.child[word.charAt(j)];
                        continue;
                    }
                    TrieNode node = new TrieNode();
                    prev.child[word.charAt(j)] = node;
                    if(j==len-1)
                        prev.isEnd = true;
                    prev = node;
                }
            }
            int ans = 0;
            for(int i=0;i<searchElem.length();i++){
                char ch = searchElem.charAt(i);
                if(root.child[ch]==null){
                    ans = 0;
                    break;
                }
                if(i==searchElem.length()-1 && root.isEnd==true){
                    //System.out.println(root.isEnd);
                    ans = 1;
                    break;
                }
                root = root.child[ch];
            }
            System.out.println(ans);
        }
	}
}