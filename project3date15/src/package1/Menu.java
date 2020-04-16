package package1;

import java.io.IOException;
import java.util.Scanner;
import package1.Attack;
public class Menu {




    public static char readChar() {
        Scanner sc = new Scanner(System.in);
        String res = sc.next();
        char result = res.charAt(0);
        result = Character.toUpperCase(result);
        if (result >= 'A' && result <= 'D') {
            return result;
        } else {
            do {
                do {
                    System.out.println("You can only enter upper and lower case characters between A and B");
                    result = sc.next().charAt(0);
                    result = Character.toUpperCase(result);
                } while(result < 'A');
            } while(result > 'B');

            return result;
        }
    }
    public static void runAPP()  {
        //while(true) {
            System.out.println("\n\nA - Play New Game");
            System.out.println("B - Exit the Game");
            char c = readChar();
            switch(c) {
                case 'A':
                    System.out.println("Welcome! My name is Joe Exotic.");
                    Attack fight = new Attack();
                    fight.fightTigerPack();
                    break;
                case 'B':
                    System.out.println("Thank you for playing this game!");
                    System.exit(0);
                default:

            }
        //}
    }
}
