package linearprobing;

public class LinearProbing {

    public static void main(String[] args) {

        HashLinearProbing hash = new HashLinearProbing(10, 0.5);
        int[] array = {0,11,22,33,44,55,66,77,88,99,1254,25354};
        for (int i = 0; i < array.length; i++) 
            hash.insert(array[i]);
        hash.printHashTable();
        
    }
}
