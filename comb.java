import java.util.*;
public class comb {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("enter the n:");
        int n = sc.nextInt();
        System.out.print("enter the r");
        int r = sc.nextInt();

        // computing the n! of combination
        int temp1 = 1;
        for(int i = 1; i<=n; i++){
            temp1 = temp1*i;
        } 

        // computing the r! of combination
        int temp2 = 1;
        for(int i = 1; i<=r; i++){
            temp2 = temp2*i;
        }

        // computing (n - r)! of combination
        int temp3 = 1;
        for(int i = 1; i<=n-r; i++){
            temp3 = temp3*i;
        }
        
        // final result
        int fin = temp1/(temp3*temp2);
        System.out.println(fin);
    }
}
