package package1;

import package1.User;
import package1.Zombie;
import java.util.Iterator;
import java.util.List;
import java.util.ArrayList;


public class Attack {

    public boolean isThereLivingZombies(List<Zombie> zombies)
    {
        boolean alive=false;
        for (Zombie zom : zombies)
        {
            if (zom.isAlive())
            {
                alive=true;
                break;
            }//end of if
        }//end of for
        return true;
    }//end of is there any living zombies

    public void fightZombieHorde()
    {

        User user = new User("User", 0.6);
        //Create 10 zombies
        List<Zombie> zombies =new ArrayList<>(9);
        for (int i=0; i<=9; i++)
        {
            zombies.add(new Zombie("Zombie"));
        }

        do{
            if (isThereLivingZombies(zombies)) {

                    for (Iterator<Zombie> iterator = zombies.iterator(); iterator.hasNext(); ) {
                        Zombie nextZombie = iterator.next();
                        if (nextZombie.isAlive() && user.isAlive()) {
                            user.fightZombieHorde(nextZombie);
                            if (nextZombie.isAlive()&& user.isAlive()) {
                                nextZombie.fightZombieHorde(user);
                            }//end if when check if zombie survived
                        }//end of iterator
                    }//end of for
            }//end of if the any more zombies
        }while (!user.userDies());//end of while user is alive

        if (user.isAlive())
        {
            System.out.println(user.getName()+" wins");
        }//end of user is alive
        else if (!user.isAlive())
        {System.out.println("Zombies wins");}

        else if (isThereLivingZombies(zombies))
        {
            System.out.println("Zombies wins");
        }//end of zombie is alive

    }//end of fight


}//end
