
package linearprobing;

public class HashLinearProbing {

    private int[] hashTable;
    private int itemCount;
    private double lambda;
    private final int EMPTY = -1;
    
    public HashLinearProbing(int tableSize,double lambda)
    {
        this.lambda = lambda;
        hashTable = new int[tableSize];
        for (int i = 0; i < hashTable.length; i++)
            hashTable[i] = EMPTY;
        itemCount = 0; 
    }
    
    private int hashFunction(int key)
    {
        return key % hashTable.length;
    }
    
    public boolean insert(int key)
    {
        int index = hashFunction(key);
        if (lambda > getCurrentLoadFactor() ) {
            while(hashTable[index] != EMPTY)
                index = (index + 1) % hashTable.length;
        }
        else{
            rehash();
            return insert(key);
        }
        hashTable[index] = key;
        itemCount++;
        return true;
    }
    
    private void rehash()
    {
        System.out.println("Rehashing completed");
        //Calculate New Table Length
        int currentTableLength = hashTable.length;
        int newTableLength = currentTableLength * 2 + 3;
        //Prepare new Table
        int[] newTable = new int[newTableLength];
        for (int i = 0; i < newTable.length; i++) 
            newTable[i] = EMPTY;
        
        int[] oldTable = hashTable;
        hashTable = newTable;
        itemCount = 0;
        
        for (int i = 0; i < oldTable.length; i++) 
            if (EMPTY != oldTable[i]) 
                insert(oldTable[i]);
            
    }
    
    private double getCurrentLoadFactor()
    {
        return (double)itemCount / hashTable.length;
    }
    
    public boolean contains(int key)
    {
        int index = hashFunction(key);
        
        while(hashTable[index] != EMPTY && hashTable[index] != key)
            index = hashFunction( key + 1 );
        return key == hashTable[index];
    }
    
    public void printHashTable() {
        for (int i = 0; i < hashTable.length; ++i)
            if (EMPTY == hashTable[i])
                System.out.println("table[" + i + "] ..: EMPTY");
            else
                System.out.println("table[" + i + "]..: " + hashTable[i]);
    }

}
