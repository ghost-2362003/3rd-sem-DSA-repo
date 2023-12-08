import java.util.Scanner;

class checker{

    public void isArmstrong(int n){
        int power = power(n);
        int sum = 0;
        int hold = n;

        while(n>0){
            int rem = n%10;
            sum += Math.pow(rem, power);
            n /= 10;
        }
        
        n = hold;
        if(n == sum){
            System.out.println(n + " is an Armstrong number.");
        }
        else{
            System.out.println(n + " is not an Armstrong number.");
        }
    }

    public int power(int n){
        int count = 0;
        while(n>0){
            n /= 10;
            count++;
        }
        return count;
    }
}

public class armstrong {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a number: ");
        int n = sc.nextInt();

        checker obj = new checker();
        obj.isArmstrong(n);

        sc.close();
    }
}