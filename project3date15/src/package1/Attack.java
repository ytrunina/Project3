package package1;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Random;
import package1.Menu;

public class Attack {

    public boolean freeTigers(List<Tigers> tigers)
    {
        boolean captured = false;
        for (Tigers t : tigers)
        {
            if (t.tigerIsNotCaptured())
            {
                captured = true;
                break;
            }
        }
        return true;
    }// end of living

    public void fightTigerPack()
    {
        String name = " ";
        User user = new User();
        System.out.print("Please enter your name: ");
        user.setUserName(name);
        user.getUserName();

        Random random = new Random();

        List<Tigers> tigers = new ArrayList<>(6);
        for (int i=0; i<=6; i++)
        {
            tigers.add(new Tigers("Tiger "));
        }//end of for

        int tigerHit = 0;
        int userHit = 0;
        int count = 0;
        do{

            if (freeTigers(tigers))
            {
                for (Iterator<Tigers> iterator = tigers.iterator(); iterator.hasNext();)
                {

                    Tigers nextTiger = iterator.next();
                    nextTiger.setFinalCount();
                    if(nextTiger.tigerIsNotCaptured && user.isAlive())
                    {
                        nextTiger.setHitPoint(tigerHit);
                        user.setHitPoint(userHit);

                        if (nextTiger.getHitPoint()<user.getHitPoint())
                        {
                            nextTiger.isTigerIsCaptured();
                            System.out.print(nextTiger.getTigersNames() + " is captured.\n");

                            count++;
                        }

                        else if (nextTiger.getHitPoint()>user.getHitPoint())
                        {
                            user.isDead();
                            System.out.print("My friend, "+user.getUserName()+" - you are dead.\n");
                            System.out.print("Total tigers captured: " + count);
                        Menu menu2 = new Menu();
                        menu2.runAPP();
                        }
                        else if (nextTiger.getHitPoint()==user.getHitPoint())
                        {
                            while (nextTiger.getHitPoint()==user.getHitPoint())
                            {
                                nextTiger.getHitPoint();
                                user.getHitPoint();
                            }//end of while
                        }

                    }//end of next
                }//end of for
            }//end of if free tigers
        }while (!user.isAlive());//end of while user alive

        System.out.print("Total tigers captured: " + count);

    }//end of fight
}//end of attack
