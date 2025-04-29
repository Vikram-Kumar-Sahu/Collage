import java.util.Scanner;

class l1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a String: ");
        String str = sc.nextLine();
        System.out.println("Enter a Character: ");
        char ch = sc.next().charAt(0);
        System.out.println("The string is " + str + " and the character is: " + ch);

        // Change the case of the string
        System.out.println("String to lower case: " + str.toLowerCase());
        System.out.println("String to upper case: " + str.toUpperCase());

        // Reverse the string
        String str_rev = "";
        for (int i = str.length() - 1; i >= 0; i--) {
            str_rev = str_rev + str.charAt(i);
        }
        System.out.println("The reversed string is: " + str_rev);

        // Compare two strings
        System.out.println("Comparison with reversed string: " + str.compareTo(str_rev));

        // Insert one string into another string assuming the string is "Hello world"
        String s1 = str.substring(0, 5);
        String s2 = str.substring(5);
        String result = s1 + "-" + str_rev + "-" + s2;
        System.out.println("The final string is: " + result);

        // Check if the character is present in the string and at what position
        int c = 0;
        boolean found = false;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == ch) {
                System.out.println("Found at Index: " + i);
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Character not found in the string.");
        }

        // Check if the string is palindrome
        if (str.equalsIgnoreCase(str_rev)) {
            System.out.println("The string is a palindrome.");
        } else {
            System.out.println("The string is not a palindrome.");
        }

        // Check the number of words, vowels, and consonants in the string
        String vowels = "AEIOUaeiou";
        int v = 0, con = 0, word = 1;
        for (int i = 0; i < str.length(); i++) {
            char ch1 = str.charAt(i);
            if (vowels.indexOf(ch1) != -1) {
                v++;
            } else if (ch1 == ' ') {
                word++;
            } else if (Character.isLetter(ch1)) {
                con++;
            }
        }
        System.out.println("The number of words: " + word);
        System.out.println("The number of vowels: " + v);
        System.out.println("The number of consonants: " + con);
    }
}