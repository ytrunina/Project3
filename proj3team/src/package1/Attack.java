package package1;

import package1.User;
import package1.Tiger;
import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;


public class Attack {

    public boolean isThereLivingTigers(List<Tiger> tigers)
    {
        boolean alive=false;
        for (Tiger tig : tigers)
        {
            if (tig.isAlive())
            {
                alive=true;
                break;
            }//end of if
        }//end of for
        return true;
    }//end of is there any living tigers

    public void fightTigerHorde()
    {

        User user = new User("User", 0.6);
        //Create 10 tigers
        List<Tiger> tigers =new ArrayList<>(9);
        for (int i=0; i<=9; i++)
        {
            tigers.add(new Tiger("Tiger"));
        }

        do{
            if (isThereLivingTigers(tigers)) {

                    for (Iterator<Tiger> iterator = tigers.iterator(); iterator.hasNext(); ) {
                        Tiger nextTiger = iterator.next();
                        if (nextTiger.isAlive() && user.isAlive()) {
                            user.fightTigerHorde(nextTiger);
                            if (nextTiger.isAlive()&& user.isAlive()) {
                                nextTiger.fightTigerHorde(user);
                            }//end if when check if tiger survived
                        }//end of iterator
                    }//end of for
            }//end of if the any more tigers
        }while (!user.userDies());//end of while user is alive

        if (user.isAlive())
        {
            System.out.println(user.getName()+" wins");
        }//end of user is alive
        else if (!user.isAlive())
        {System.out.println("Tigers win");}

        else if (isThereLivingTigers(tigers))
        {
            System.out.println("Tigers win");
        }//end of tiger is alive

    }//end of fight


}//end