package package1;


import java.util.Random;
import java.util.Scanner;

public class User {

    private int hitPoint;
    //private boolean gameOver = false;
    private boolean isAlive = true;
    private Random rand = new Random();

    private String userName = "";

    User(String m_playerName) {

        this.hitPoint = 0;
        this.userName = userName;
    }//end of user

    public User() {

    }

    /**
     * Setter method for the Players Name
     * @param userName
     */

    public void setUserName(String userName) {

        this.userName = userName;
        Scanner keyboard = new Scanner(System.in);
        this.userName = keyboard.nextLine();

    }
    public String getUserName() {
        return this.userName;
    }
    public int setHitPoint(int hitPoint) {
        int intHitPoint=0;
        for (int i=0; i<10;i++)
        {
            intHitPoint=getRandomInRange(1,10);
        }
        this.hitPoint = intHitPoint;
        return hitPoint;
    }
    public int getHitPoint() {
        return hitPoint;
    }//end of hitpoint

    public boolean isAlive()
    {
        return isAlive;
    }// end of is alive

    public boolean isDead()
    {
        isAlive=false;
        return false;
    }//end of is dead

    private static int getRandomInRange(int min, int max)
    {
        if (min>=max)
        {
            throw new IllegalArgumentException("max must be greater than min");
        }
        Random rand = new Random();
        return rand.nextInt(((max-min)+1)+min);
    }
}
