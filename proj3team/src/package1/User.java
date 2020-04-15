package package1;

import java.util.Random;

public class User extends BraveSoul
{
    public User(String name, double hitPoints)
    {
        this.name = name;
        this.hitPoints = hitPoints;
    }

    @Override
    public String printString() {
        return name;
    }

    @Override
    public void fightZombieHorde(BraveSoul bs)
    {
         String info = this.name+" "+bs.getName();
        //int intHitPoint=0;
        Double attemptToHit = this.rand.nextDouble();
        //       for (int i=0; i<10;i++)
        //     {
        //      intHitPoint=getRandomInRange(1,10);
        //  }//end of for
        if (attemptToHit<hitPoints)
        {
            bs.userDies();
            System.out.println(bs.printString() + " killed");

        }
    }//end of start attack

    //private static int getRandomInRange(int min, int max)
    //{
    // //    if (min>=max)
    //    {
    //      throw new IllegalArgumentException("max must be greater than min");
    // }
    // Random rand = new Random();
    // return rand.nextInt(((max-min)+1)+min);
    // }

}//end of user
