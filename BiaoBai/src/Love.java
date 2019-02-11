import java.awt.*;
import javax.swing.*;
public class Love {
     public static void main(String[] args) {
    	 JFrame w=new JFrame();
    	 w.setSize(1336,768);
    	 w.setBackground(Color.BLACK);
    	 MyPanel mp=new MyPanel();
    	 mp.setBackground(Color.BLACK);
    	 w.add(mp);
    	 Thread t=new Thread(mp);
    	 t.start();
    	 w.show();
    	 
     }
}
class MyPanel extends JPanel implements Runnable{
    final int len=400;
   @Override
    public void paint(Graphics g) {
	// TODO Auto-generated method stub
	   g.setColor(Color.BLUE);
	   for(int i=0;i<len;i++) {
		   g.drawString("*", (int)(Math.random()*1336),(int)(Math.random()*768) );
	   }
	   g.setColor(Color.BLACK);
	   Font f=new Font("宋体",Font.BOLD,40);
	   g.setFont(f);
	   g.drawString("老婆我爱你，不是说说而已", 450, 600);
	   int[] x1= {800,770,850,750,830};
	   int[] y1= {60,160,100,100,160};
	   g.setColor(Color.BLACK);
	   g.fillPolygon(x1, y1, x1.length);
	   
	   int[] x2= {600,570,650,550,630};
	   int[] y2= {300,400,340,340,460};
	   g.setColor(Color.BLACK);
	   g.fillPolygon(x2, y2, x2.length);
	   
	   int[] x3= {60,30,110,10,90};
	   int[] y3= {60,160,100,100,160};
	   g.setColor(Color.BLACK);
	   g.fillPolygon(x3, y3, x3.length);
	   
	   int[] x4= {1300,1270,1350,1250,1330};
	   int[] y4= {300,400,340,340,400};
	   g.setColor(Color.BLACK);
	   g.fillPolygon(x4, y4, x4.length);
}
	@Override
	public void run() {
		// TODO Auto-generated method stub
	   while(true) {
		   try {
			   Thread.sleep(40);
		   }catch(Exception e) {}
	       repaint();
	   }
	   
	}
	
}