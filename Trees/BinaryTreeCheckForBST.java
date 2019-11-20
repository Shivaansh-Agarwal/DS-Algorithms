class Node{
    int data;
    Node left,right;
    Node(int data){
        this.data = data;
        this.left = this.right = null;
    }
}

class BinaryTree{
    Node root;
    BinaryTree(){
        this.root = null;
    }
    boolean isBST(Node root){
        if(root==null)
            return true;
        if(isSubTreeLesser(root.left, root.data) && isSubTreeGreater(root.right, root.data) && isBST(root.left) && isBST(root.right))
            return true;
        else
            return false;
    }
    boolean isSubTreeLesser(Node root, int val){
        if(root==null)
            return true;
        if(root.data<=val && isSubTreeLesser(root.left, val) && isSubTreeLesser(root.right, val))
            return true;
        else
            return false;
    }
    boolean isSubTreeGreater(Node root, int val){
        if(root==null)
            return true;
        if(root.data>val && isSubTreeGreater(root.left, val) && isSubTreeGreater(root.right, val))
            return true;
        else
            return false;
    }
    public static void main(String args[]){
        /*
                    7
                    /\
                   3  8
                   /\
                  2  4
        */
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(7);
        tree.root.left = new Node(3);
        tree.root.right = new Node(8);
        tree.root.left.left = new Node(2);
        tree.root.left.right = new Node(4);
        System.out.println(tree.isBST(tree.root));


    }
}