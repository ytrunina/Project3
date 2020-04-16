package package1;

import java.util.Random;
import java.util.Scanner;

public class Tigers {

    private int hitPoint;
  //  private boolean gameOver = false;
    private String tigersNames = "";
    private Random rand = new Random();
    protected boolean tigerIsNotCaptured = true;
    static int tigerCount;
    int finalCount = 0;
    Tigers (String tigersNames) {
        this.hitPoint = 0;
        this.tigersNames = tigersNames;
        ++tigerCount;
        this.tigersNames = tigersNames+ " "+tigerCount;
    }//end of tigers

    public Tigers() {


    }

    public void setFinalCount()
    {
        this.tigerCount = finalCount;
    }


    public void setTigersNames(String tigersNames) {

        this.tigersNames = tigersNames;
    }
    public String getTigersNames() {
        return this.tigersNames;
    }
    public int setHitPoint(int hitPoint) {
        int intHitPoint=0;
        for (int i=0; i<10;i++)
                 {
                  intHitPoint=getRandomInRange(1,10);

              }
        this.hitPoint = intHitPoint;
       // hitPoint = rand.nextInt(2);
        return hitPoint;
    }//end of set hit pint

    public int getHitPoint() {
        return hitPoint;
    }//end of hitpoint

    public boolean tigerIsNotCaptured() {
        return tigerIsNotCaptured;
    }

    public boolean isTigerIsCaptured(){
        tigerIsNotCaptured =false;
        return false;
    }


    private static int getRandomInRange(int min, int max)
    {
        if (min>=max)
        {
          throw new IllegalArgumentException("max must be greater than min");
     }
     Random rand = new Random();
     return rand.nextInt(((max-min)+1)+min);
     }
}//end of tigers



