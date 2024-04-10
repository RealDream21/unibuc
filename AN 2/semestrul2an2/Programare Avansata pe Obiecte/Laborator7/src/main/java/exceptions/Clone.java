package exceptions;

public class Clone {
    @Override
    protected Object clone() throws CloneNotSupportedException{
        //clone the object
        return super.clone();
    }
}

class MyCloneClass implements Cloneable{
    @Override
    protected Object clone() throws CloneNotSupportedException{
        return super.clone();
    }
}


