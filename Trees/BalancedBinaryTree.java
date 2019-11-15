/*
    PROBLEM: Given a Binary Tree, check whether it is Balanced or not.

    I/P:                    O/P:
            10                  true
            /\
           5  6
           /  
          4
    
    I/P:                    O/P:
            10                  false
            /       
           5  
           /
          4

    The Approach used here solves the problem in O(n^2) Time Complexity.
*/
import java.io.*;

class Node{
    int data;
    Node left, right;
    Node(int data){
        this.data = data;
        this.left = this.right = null;
    }
}

class BalancedBinaryTree{
    Node root;
    BalancedBinaryTree(){
        root = null;
    }
    public static void main(String args[]){
        BalancedBinaryTree tree1 = new BalancedBinaryTree();
        BalancedBinaryTree tree2 = new BalancedBinaryTree();
        
        // Example for Balanced Binary Tree
        tree1.root = new Node(10);
        tree1.root.left = new Node(5);
        tree1.root.right = new Node(6);
        tree1.root.left.left = new Node(4);

        // Example for Unbalanced Binary Tree
        tree2.root = new Node(10);
        tree2.root.left = new Node(5);
        tree2.root.left.left = new Node(4);

        System.out.println("Tree 1: " + isBalanced(tree1.root));
        System.out.println("Tree 2: " + isBalanced(tree2.root));
    }
    static boolean isBalanced(Node root){
        if(root==null)  
            return true;
        if(root.left==null && root.right==null)
            return true;
        int lh = height(root.left);
        int rh = height(root.right);
        if(Math.abs(lh-rh)<=1 & isBalanced(root.left) && isBalanced(root.right))
            return true;
        else    
            return false;
    }
    static int height(Node root){
        if(root==null)
            return 0;
        int lh = height(root.left);
        int rh = height(root.right);
        int h = Math.max(lh,rh)+1;
        return h;
    }
}