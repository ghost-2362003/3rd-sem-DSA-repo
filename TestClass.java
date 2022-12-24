import java.util.*;
public class TestClass {
    public static int count(int n, int counter, String[] arr){
        
        for(int q = 0; q<n; q++){
            int count_1 = 0;
            String temp = arr[q];
            for(int l = 0; l<temp.length(); l++){
                if(temp.charAt(l)=='#'){
                    count_1+=1;
                }
            }

            if(count_1>counter){
                counter = count_1;
            }
        }

        return counter;
    }

    public static void main(String args[] ) throws Exception {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int i = 0; i<t; i++){
            int n = sc.nextInt();
            int m = sc.nextInt();
            String[] arr = new String[n];
            int counter = 0;

            for(int j = 0; j<n; j++){
                arr[j] = sc.next();
            }

            int a = count(n, counter, arr);
            System.out.println(a);
        }
 
        sc.close();
    }
}