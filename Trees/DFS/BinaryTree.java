// Implementation of a Simple Binary Tree
class Node {
    int data;
    Node left,right;
    Node(int x) {
        this.data = x;
       this. left = this.right = null;
    }
}
class BinaryTree {
    Node root;
    BinaryTree() {
        root = null;
    }
    void printPreOrder(Node node){
        if(node==null)
            return;
        System.out.print(node.data+" ");
        printPreOrder(node.left);
        printPreOrder(node.right);
    }
    void printInOrder(Node node){
        if(node==null)
            return;
        printInOrder(node.left);
        System.out.print(node.data+" ");
        printInOrder(node.right);
    }
    void printPostOrder(Node node){
        if(node==null)
            return;
        printPostOrder(node.left);
        printPostOrder(node.right);
        System.out.print(node.data+" ");
    }
    public static void main(String args[]){
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(4);
        tree.root.left = new Node(2);
        tree.root.right = new Node(6);
        tree.root.left.left = new Node(1);
        tree.root.left.right = new Node(3);
        tree.root.right.left = new Node(5);
        tree.root.right.right = new Node(7);
        tree.printPreOrder(tree.root);
        System.out.println("");
        tree.printInOrder(tree.root);
        System.out.println("");
        tree.printPostOrder(tree.root);
    }
}