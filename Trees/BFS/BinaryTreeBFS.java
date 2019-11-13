import java.io.*;
import java.util.*;

class Node {
    int data;
    Node left,right;
    Node(int data){
        this.data = data;
        this.left = this.right = null;
    }
}

class BinaryTreeBFS {
    /*
                    25
                    /\
                 12   31
                 /\   /\
                5 17 27 null
               /\
              2  9
    */
    public static void main(String args[]){
        Node root = new Node(25);
        root.left = new Node(12);
        root.right = new Node(31);
        root.left.left = new Node(5);
        root.left.right = new Node(17);
        root.right.left = new Node(27);
        root.left.left.left = new Node(2);
        root.left.left.right = new Node(9);
        breadth_first_search(root);
    }

    static void breadth_first_search(Node root){
        Queue<Node> q = new LinkedList<Node>();
        q.add(root);
        while(!q.isEmpty()){
            Node currNode = q.poll();
            System.out.print(currNode.data + " ");
            if(currNode.left!=null)
                q.add(currNode.left);
            if(currNode.right!=null)
                q.add(currNode.right);
        }
    }
}