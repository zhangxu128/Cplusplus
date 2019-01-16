import java.awt.*;
import java.awt.event.*;
public class Example01{

	public static void main(String[] args) {
		// TODO Auto-generated method stub
     Frame f = new Frame();
     Button button1=new Button("1");
     f.setLayout(new FlowLayout());
     f.setTitle("流式布局");
	 f.setSize(300, 350);
	 f.setLocation(500, 200);
	 f.setVisible(true);
	 f.add(button1);
	 button1.addMouseListener(new MouseListener() {
		
		@Override
		public void mouseReleased(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
		
		@Override
		public void mousePressed(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
		
		@Override
		public void mouseExited(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
		
		@Override
		public void mouseEntered(MouseEvent e) {
			// TODO Auto-generated method stub
			
		}
		
		@Override
		public void mouseClicked(MouseEvent e) {
			// TODO Auto-generated method stub
			f.add(new Button("新按钮"));
			f.show();
		}
	 });
  }
}
