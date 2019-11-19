/*
    PROBLEM: Given a Binary Tree, Determine whether it is balanced or not (Optimal Solution in O(n))

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


*/

class Node{
    int data;
    Node left, right;
    Node(int data) {
        this.data = data;
        this.left = this.right = null;
    }
}

class Height{
    int height;
}

class BinaryTree{
    Node root;
    
    //This method returns true if tree is Balanced else False
    boolean isBalanced(Node root, Height h){
        /* 
            If tree is Empty it's height is 0 and it is balanced 
            This condition will be useful in case of leaf nodes (which have no children),
            OR a Node in which any 1 child is not present.
        */
        if(root==null){
            h.height=0;
            return true;
        }
        // These will be used to get the Height of Left and Right Subtrees
        Height lHeight = new Height();
        Height rHeight = new Height();
        /*
            The following are the recursive calls for the Left and Right Subtree of a Node
            Once the Recursive calls reach the leaf nodes they'll start getting out of Stack.
            After each recursive call gets finished, we'll get to know the whether that node is Balanced or not
            & Also Height of that respective Subtree.
        */
        boolean l = isBalanced(root.left, lHeight);
        boolean r = isBalanced(root.right, rHeight);
        int lh = lHeight.height;
        int rh = rHeight.height;

        // Height of a node is max of heights of left or tight subtree + 1
        h.height = Math.max(lh,rh) + 1;

        if(Math.abs(lh-rh)>1)
            return false;
        else
            return l&&r;
    }
    public static void main(String args[]){
        Height h = new Height();
        
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);
        tree.root.right.left = new Node(6);
        tree.root.left.left.left = new Node(7);

        BinaryTree tree1 = new BinaryTree();
        tree1.root = new Node(1);
        tree1.root.left = new Node(2);
        tree1.root.left.left = new Node(3);

        if(tree.isBalanced(tree.root,h))
            System.out.println("Tree is Balanced");
        else
            System.out.println("Tree is not Balanced");

        if(tree.isBalanced(tree1.root,h))
            System.out.println("Tree is Balanced");
        else
            System.out.println("Tree is not Balanced");
    }
}