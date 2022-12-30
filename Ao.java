import java.util.*;
public class Ao {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = N/2;
        int[][] myArr = new int[M+1][N];
        int ranin = 0;

        for(int i = 0; i<=M; i++){
            for(int j = N/2 - ranin; j<=N/2 + ranin; j+=2){
                myArr[i][j] = 1;
            }
            ranin+=1;
        }

        for(int i = 0; i<=M; i++){
            for(int j = 0; j<N; j++){
                if(myArr[i][j]!=0){
                    System.out.print(myArr[i][j] + " ");
                }
                else{
                    System.out.print("*"+" ");
                }
            }
            System.out.println();
        }
    }    
}
