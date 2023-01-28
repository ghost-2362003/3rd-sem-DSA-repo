public class myground {
    public static int[] rotate(int[] a , int m){
        int k = m%a.length;
        int[] res = new int[a.length];
        int j = 0;

        for(int i = a.length - k; i<a.length; i++){
            res[j] = a[i];
            j++; 
        }

        for(int i = 0; i<a.length-k; i++){
            res[j] = a[i];
            j++;
        }
        return res;
    }

    public static void main(String[] args){
        int[] arr = {1,2,3,4,5,6,7,89,45,12,36,5};
        int[] arr1 = rotate(arr, 20);

        for(int i = 0; i<arr.length; i++){
            System.out.println(arr1[i]);
        }
    }
}
