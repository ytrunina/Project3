package package1;

import java.util.Random;

public class Main {

    public static void welcome()
    {
        System.out.println("Welcome to this game!");
        System.out.println("It is an endless wave of zombie hordes, and they are trying to kill you!");
        System.out.println("I see the first zombies coming!");
        System.out.println("Be careful and good luck!\n");
    }//end of welcome

    public static void thankYou()
    {
        System.out.println("Thank you for using this program!");
    }//end of thank you

    public static void main(String[] args)
    {
        welcome();
        Random random = new Random();
        Attack fight1 = new Attack();
        fight1.fightZombieHorde();
        thankYou();
    }// end of main
}
