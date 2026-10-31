public import java.util.HashSet;

public class TransactionCheck {

    public static boolean hasDuplicate(String[] transactionIds) {
        HashSet<String> seen = new HashSet<>();
        for (String id : transactionIds) {
            if (seen.contains(id)) {
                return true;
            }
            seen.add(id);
        }
        return false;
    }

    public static void main(String[] args) {
        String[] batch1 = {"TXN1001", "TXN1002", "TXN1003", "TXN1002", "TXN1004"};
        String[] batch2 = {"TXN2001", "TXN2002", "TXN2003"};

        System.out.println(hasDuplicate(batch1)); // true
        System.out.println(hasDuplicate(batch2)); // false
    }
} {
    
}
