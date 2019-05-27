# CS1110_HW1_Problem1
Collection of Homework and other Coding Assignments

//makeCharacter.java

/* makeCharacter.java Demonstrates the no-arg constructor. */

class character{
    String race;
    int lvl;
    String alignment;

    character(){
        race = "Wood Elf";
        lvl = 5;
        alignment = "Neutral";

        System.out.println("New character created: " + race);
    }

    void hide(){
        System.out.println("The " + race + " attempts to hide");
    }

    void int getLvl() {
            System.out.println(race + " Level: " + lvl);
    }

    void setAlignment(){
        System.out.println("The " + race + " is " + alignment);
    }
}//end class character


public class makeCharacter {
    public static void main(String[] args) {

        character bob;
        bob = new character();

        character sue;
        sue = new character();

    }//end main
}//end makeCharacter
