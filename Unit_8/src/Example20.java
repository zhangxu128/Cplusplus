import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.*;
public class Example20 extends JFrame{
	private JPopupMenu popupMenu;
    public Example20()
    {
    	popupMenu =new JPopupMenu();//����һ���˵�
		//���������˵���
		JMenuItem refreshItem = new JMenuItem("refresh");
		JMenuItem createItem = new JMenuItem("create");
		JMenuItem exitItem = new JMenuItem("exit");
		//Ϊ�˵�����¼�������
		exitItem.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.exit(0);
			}
		});
		//��Ӳ˵���
		popupMenu.add(refreshItem);
		popupMenu.add(createItem);
		popupMenu.addSeparator();
		popupMenu.add(exitItem);
		//���������
		this.addMouseListener(new MouseListener() {
			
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
				if(e.getButton()==e.BUTTON3)
				{
					popupMenu.show(e.getComponent(), e.getX(), e.getY());
				}
			}
		});
	this.setSize(300,300);
	this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	this.setVisible(true);
}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Example20();

  }
}