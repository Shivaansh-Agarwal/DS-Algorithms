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
        return(isBSTUtil(root,Integer.MIN_VALUE,Integer.MAX_VALUE));
    }
    boolean isBSTUtil(Node root, int min, int max){
        if(root==null)
            return true;
        if(root.data>=min 
        && root.data<max 
        && isBSTUtil(root.left,min,root.data) 
        && isBSTUtil(root.right, root.data, max))
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
        /*
                    7
                    /\
                   3  8
                   /\
                  2  12
        */
        BinaryTree tree1 = new BinaryTree();
        tree1.root = new Node(7);
        tree1.root.left = new Node(3);
        tree1.root.right = new Node(8);
        tree1.root.left.left = new Node(2);
        tree1.root.left.right = new Node(12);
        System.out.println(tree1.isBST(tree1.root));
    }
}