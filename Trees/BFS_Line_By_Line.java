/*
    PROBLEM: Given a Binary Tree, print the tree using Level Order Traversal (BFS), such that every level is in new line

    I/P:
                10
                /\
               4  6
              /\  /\
             1 3  2 4
               /
              3

    O/P: 
        10
        4 6
        1 3 2 4
        3
*/

import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left, right;
    Node(int data){
        this.data = data;
        this.left = this.right = null;
    }
}

class BFS_Line_By_Line {
	public static void main (String[] args) throws IOException{
		Node root = new Node(10);
		root.left = new Node(4);
		root.right = new Node(6);
		root.left.left = new Node(1);
		root.left.right = new Node(3);
		root.right.left = new Node(2);
		root.right.right = new Node(4);
		root.left.right.left = new Node(3);
		levelOrderTraversal(root);
	}
	static void levelOrderTraversal(Node root){
	    Queue<Node> q = new LinkedList<Node>();
	    q.add(root);
	    q.add(null);
	    while(!q.isEmpty()){
	        Node currNode = q.poll();
	        if(currNode!=null){
	            System.out.print(currNode.data + " ");
	            if(currNode.left!=null)
	                q.add(currNode.left);
	            if(currNode.right!=null)
	                q.add(currNode.right);
	        } else if(!q.isEmpty()) {
	            System.out.println("");
	            q.add(null);
	        }
	    }
	}
}