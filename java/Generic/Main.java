public class Main{
    public static void main(String[] args){
        Generics<String> generic = new Generics<String>();

        generic.setObject("hello java world");

        System.out.println(generic.getObject());
    }
}
