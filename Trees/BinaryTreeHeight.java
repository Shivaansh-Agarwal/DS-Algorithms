/*
    PROBLEM: Given a Binary Tree Calculate it's height.

    I/P:
                10
                /\
               4  6
              /\  /\
             1 3  2 4
               /
              3
    
    O/P: 
        4
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

class BinaryTreeHeight{
    public static void main(String args[]){
        Node root = new Node(10);
		root.left = new Node(4);
		root.right = new Node(6);
		root.left.left = new Node(1);
		root.left.right = new Node(3);
		root.right.left = new Node(2);
		root.right.right = new Node(4);
        root.left.right.left = new Node(3);
        System.out.println(calculateHeight(root));
    }
    static int calculateHeight(Node root){
        if(root==null)
            return 0;
        int left_height = calculateHeight(root.left);
        int right_height = calculateHeight(root.right);
        int height = Math.max(left_height,right_height) + 1;
        return height;
    }
}