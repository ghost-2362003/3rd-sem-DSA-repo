import java.util.*;

public class apseries {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.print("enter the first term of the Series:");
        int firel = sc.nextInt();
        System.out.println("enter the second term of the series");
        int secel = sc.nextInt();
        System.out.println("enter the number of terms to be calculated:");
        int n = sc.nextInt();
        int cd = secel - firel;
        int sum = (n/2)*((2*firel) + (n-1)*cd);
        System.out.println("sum of the A.P series is:");
        System.out.println(sum);
        sc.close();
    }
}
