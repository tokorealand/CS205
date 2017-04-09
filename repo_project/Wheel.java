import java.util.*;
/**
 * Write a description of class Wheel here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Wheel
{

    private int seed;

    /**
     * Constructor for objects of class Wheel
     */
    public Wheel(int aSeed)
    {
        seed=aSeed;
    }

    public Wheel()
    {

    }

    public int spin()
    {
     Random rand = new Random(this.seed);

     return rand.nextInt();//returns random int using seed
    }

    public void setSeed(int newSeed)
    {
        this.seed=newSeed;
    }

    public int getSeed()
    {
        return this.seed;
    }

}
