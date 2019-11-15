/*
    PROBLEM: Given a Binary Tree, check if it follows Children-Sum property or not

    I/P:
                10
                /\
               4  6
              /\  /\
             1 3  2 4
               /
              3
    O/P: true

    I/P:
                10
                /
               10
    O/P: true

    I/P: 
                10
    O/P: true

    I/P: 
                9
                /\
               5  1
    O/P: false
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

class BinaryTreeChildrenSum{
    public static void main(String args[]){
        Node root = new Node(10);
		root.left = new Node(4);
		root.right = new Node(6);
		root.left.left = new Node(1);
		root.left.right = new Node(3);
		root.right.left = new Node(2);
		root.right.right = new Node(4);
        root.left.right.left = new Node(2);
        System.out.println(isChildrenSum(root));
    }

    static Boolean isChildrenSum(Node root){
        if(root==null)
            return true;
        if(root.left==null && root.right==null)//Checking for leaf node
            return true;
        int left=0,right=0;
        if(root.left!=null)
            left = root.left.data;
        if(root.right!=null)
            right = root.right.data;
        if(root.data==(left+right) && isChildrenSum(root.left) && isChildrenSum(root.right))
            return true;
        else 
            return false;
    }
}