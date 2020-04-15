package package1;
import java.util.Random;

public abstract class BraveSoul
{
    protected Random rand = new Random();
    protected boolean isAlive = true;
    protected String name;
    protected double hitPoints;

    public abstract String printString();
    public abstract void fightTigerHorde(BraveSoul bs);

    public boolean isAlive()
    {
        return isAlive;
    }

    public boolean userDies()
    {
        isAlive=false;
        return false;
    }
    public String getName()
    {
        return name;
    }
}//end of bravesoul