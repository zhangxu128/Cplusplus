import java.util.ArrayList;
import java.util.List;

public class Example02 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
       List list = new ArrayList();
       list.add("I");
       list.add("love");
       list.add("you");
       list.add("!");
       System.out.println(list);
       System.out.println(list.subList(0,3));
       list.add(666);
       System.out.println(list);
       list.set(3, 66666);
       System.out.println(list);
	}

}
	