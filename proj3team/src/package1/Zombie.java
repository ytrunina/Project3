package package1;

public class Zombie extends BraveSoul {


    static int zombieCount;

    @Override
    public String printString()
    {
        return this.name;
    }//end of printstring

    public Zombie(String name)
    {
        ++zombieCount;
        this.name= name+" "+zombieCount;
        System.out.println(this.name+" is created and ready to fight with you!");
        this.hitPoints=0.01;

    }//end of zombie method
    @Override
    public void fightZombieHorde(BraveSoul bs)
    {

        System.out.println(this.name+" tries to attack "+bs.getName());
        Double attemptToHit = this.rand.nextDouble();
        if (attemptToHit<hitPoints)
        {
            bs.userDies();
            System.out.println(bs.printString() + " killed");
            System.exit(0);
        }
    }//end of fight zombie
}//end of zombie
