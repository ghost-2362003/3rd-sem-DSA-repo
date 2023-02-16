import java.util.*;
public class myGround {

    static class node{
        node left;
        node right;
        int val;
        node(int data){
            this.left = null;
            this.right = null;
            this.val = data;
        }
    }

    static int idx = -1;
     static node BuildTree(int[] arr){
        idx++;
        if(arr[idx] == -1){
            return null;
        }

       node newNode = new node(arr[idx]);
       newNode.left = BuildTree(arr);
        newNode.right = BuildTree(arr);
        return newNode;
    }
    
    // preorder traversal
    static void preOrder(node root){
        if(root == null)
            return;
        
        System.out.print(root.val + " ");
        preOrder(root.left);
        preOrder(root.right);
    }

    // inorder traversal
    static void inOrder(node root){
        if(root == null)
            return;
        
        inOrder(root.left);
        System.out.print(root.val + " ");
        inOrder(root.right);
    }

    // postorder traversal
    static void postOrder(node root){
        if(root == null)
            return;

        postOrder(root.left);
        postOrder(root.right);
        System.out.print(root.val + " ");
    }

    // level order traversal
    static void levelOrder(node root){
        Queue<node> q = new LinkedList<>();
        q.add(root);
        q.add(null);
        
        if(root == null)
            return;

        while(!q.isEmpty()){
            node currNode = q.remove();
            if(currNode != null){
                System.out.print(currNode.val + " ");
                if(currNode.left != null)
                    q.add(currNode.left);
        
                if(currNode.right != null)
                    q.add(currNode.right);
            }
            else{
                System.out.println();
                if(!q.isEmpty())
                    q.add(null); 
            }
        } 
    }

    public static void main(String[] args){
        int[] nodes = {1,2,4,-1,-1,5,-1,-1,3,-1,6,-1,-1};
        node root = BuildTree(nodes);
        System.out.println(root.val);
        preOrder(root);
        System.out.println();
        inOrder(root);
        System.out.println();
        postOrder(root);
        System.out.println();
        levelOrder(root);
    }
}