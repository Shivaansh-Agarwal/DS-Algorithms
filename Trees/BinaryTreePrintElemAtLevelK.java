/*
    PROBLEM: Given a Binary Tree, Print all elements at any level(k).

    I/P:
                10
                /\              
               4  6
              /\  /\
             1 3  2 4
               /
              3
    k=1         O/P: 10
    k=2         O/P: 4 6
    k=3         O/P: 1 3 2 4
    k=4         O/P: 3
    k=5         O/P: Invalid Input
    k=51        O/P: Invalid Input
*/

import java.io.*;
import java.util.*;

class Node{
    int data;
    Node left,right;
    Node(int data){
        this.data = data;
        this.left = this.right = null;
    }
}
class BinaryTreePrintElemAtLevelK{
    Node root;
    BinaryTreePrintElemAtLevelK(){
        root = null;
    }
    public static void main(String args[])throws IOException{
        BinaryTreePrintElemAtLevelK tree = new BinaryTreePrintElemAtLevelK();
        tree.root = new Node(10);
        tree.root.left = new Node(4);
		tree.root.right = new Node(6);
		tree.root.left.left = new Node(1);
		tree.root.left.right = new Node(3);
		tree.root.right.left = new Node(2);
		tree.root.right.right = new Node(4);
        tree.root.left.right.left = new Node(3);
        BufferedReader buff = new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the value of k: ");
        int k = Integer.parseInt(buff.readLine());
        printElementAtLevelK(tree.root,k);
    }
    static void printElementAtLevelK(Node root, int k){
        /*
            Now we will use Level Order Traversal and 'null' after every level.
            Then we will count these 'null' and print the level which is being asked for.
        */
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        q.add(null);
        if(k==1){
            System.out.println("Element at Level 1: " + root.data);
        }
        else{
            int level = 1;
            while(!q.isEmpty()){
                Node currNode = q.poll();
                if(currNode!=null){
                    if(level>k)
                        break;
                    if(level==k){
                        System.out.print(currNode.data + " ");
                        continue;
                    }
                    else {
                        if(currNode.left!=null)
                            q.add(currNode.left);
                        if(currNode.right!=null)
                            q.add(currNode.right);
                    }
                } else {
                    if(!q.isEmpty()){
                        q.add(null);
                        level++;
                    }
                    else{
                        break;
                    }
                }
            }
            if(level<k){
                System.out.println("Invalid Input");
            }
        }
    }
}