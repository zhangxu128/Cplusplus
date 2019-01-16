import java.awt.*;
public class Example03 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Frame f=new Frame("Íø¸ñ²¼¾Ö£¡");
		f.setLayout(new GridLayout(4,3));
	    f.setSize(300, 350);
	    f.setLocation(500, 200);
		for(int i=0;i<12;i++) {
			Button button=new Button("button"+i);
			f.add(button);
		}
		f.setVisible(true);
	}

}
