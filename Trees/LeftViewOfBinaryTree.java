/*This is a function problem.You only need to complete the function given below*/
/* A Binary Tree node
class Node
{
    int data;
    Node left, right;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}*/
class Tree{
    void leftView(Node root){
        // Your code here
        Queue<Node> q = new LinkedList<Node>();
        Node currNode;
        if(root!=null){
            q.add(root);
            q.add(null);
            if(root.left!=null)
                q.add(root.left);
            if(root.right!=null)
                q.add(root.right);
        }
        else{
            System.out.print(root);
            return;
        }
        currNode = q.poll();
        System.out.print(currNode.data + " ");
        
        boolean temp = false;
        while(!q.isEmpty()){
            currNode = q.poll();
            if(currNode==null){
                if(!q.isEmpty()){
                    q.add(null);
                    temp = true;
                }
            } else {
                if(temp==true){
                    System.out.print(currNode.data + " ");
                    temp = false;
                }
                if(currNode.left!=null)
                    q.add(currNode.left);
                if(currNode.right!=null)
                    q.add(currNode.right);
            }
        }
    }
}
