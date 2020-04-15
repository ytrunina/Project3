package package1;

public class Tiger extends BraveSoul {


    static int tigerCount;

    @Override
    public String printString()
    {
        return this.name;
    }//end of printstring

    public Tiger(String name)
    {
        ++tigerCount;
        this.name= name + " " + tigerCount;
        System.out.println(this.name + " is created and ready to fight with you!");
        this.hitPoints=0.01;

    }//end of tiger method
    @Override
    public void fightTigerHorde(BraveSoul bs)
    {

        System.out.println(this.name+" tries to attack "+bs.getName());
        Double attemptToHit = this.rand.nextDouble();
        if (attemptToHit<hitPoints)
        {
            bs.userDies();
            System.out.println(bs.printString() + " killed");
            System.exit(0);
        }
    }//end of fight tiger
}//end of tiger