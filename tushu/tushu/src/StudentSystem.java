import java.awt.*;
import java.awt.event.*;
import javax.swing.event.*;
import javax.swing.*;
import javax.swing.tree.*;
import javax.xml.parsers.*;
import org.w3c.dom.*;
import java.io.*;
import java.net.*;
public class StudentSystem extends JFrame implements ActionListener{
	DefaultMutableTreeNode[] dmtn={//�����ڵ�����
		new DefaultMutableTreeNode(new NodeValue("ѧ���û�����ϵͳ")),
	    new DefaultMutableTreeNode(new NodeValue("��ѯͼ��")),
	    new DefaultMutableTreeNode(new NodeValue("ԤԼͼ��")),
	    new DefaultMutableTreeNode(new NodeValue("��ʧͼ��")),
	    new DefaultMutableTreeNode(new NodeValue("�˳�"))
	};
    DefaultTreeModel dtm=new DefaultTreeModel(dmtn[0]);//������ģ�ͣ�ָ�����ڵ�Ϊ"ѧ������ϵͳ"
    JTree jt=new JTree(dtm);    //��������dtm��ģ�͵�JTree����
    JScrollPane jsp=new JScrollPane(jt);    //ΪJTree������������    
    private JSplitPane jsplr=new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,true); //�ָ��Ϊ���·���
    Image image=new ImageIcon("tsgl.jpg").getImage();
    ImageIcon ii = new ImageIcon(image);    
    private JLabel jlRoot=new JLabel(ii);//��ǩ�ı��Զ�����
    private JPanel jp=new JPanel();    //����JPanel����
	CardLayout cl=new CardLayout();	//��ȡ��Ƭ���ֹ���������
	public StudentSystem(){
       	this.initJp();
    	jt.addTreeSelectionListener(new TreeSelectionListener(){//���ڲ�����ʾ���ĸ�ѡ��ڵ�
			public void valueChanged(TreeSelectionEvent e){
				DefaultMutableTreeNode cdmtn=
					(DefaultMutableTreeNode)e.getPath().getLastPathComponent();
				NodeValue cnv=(NodeValue)cdmtn.getUserObject();	
				if(cnv.value.equals("ѧ���û�����ϵͳ")){
					cl.show(jp,"root");//��ʾ������
				}
				if(cnv.value.equals("��ѯͼ��")){													
					cl.show(jp,"ts");//��ʾ"��ѯͼ��"����
				}
				else if(cnv.value.equals("ԤԼͼ��")){
					cl.show(jp,"OrderBook");//��ʾ"ԤԼͼ��"����
				}
				else if(cnv.value.equals("��ʧͼ��")){
					cl.show(jp,"GuaShi");//��ʾ"�黹��ʧͼ��"����
				}
				else if(cnv.value.equals("�˳�")){//��ѡ��˵���ʾ�Ƿ��˳�ϵͳ
					int i=JOptionPane.showConfirmDialog(StudentSystem.this,
									"�Ƿ��˳�ϵͳ?","��Ϣ",JOptionPane.YES_NO_OPTION);
					if(i==JOptionPane.YES_OPTION){System.exit(0);}						
				}									
			}
		});
    	for(int i=1;i<dmtn.length;i++){//����ڵ�����ӽڵ�
    		dtm.insertNodeInto(dmtn[i],dmtn[0],i-1);	
    	}
		jt.setEditable(false);//���ø����нڵ��ǲ��ɱ༭��
		this.add(jsplr);//���������Ĺ���������ӽ�����
		jsplr.setLeftComponent(jt);//���������Ĺ���������ӽ���ߵ��Ӵ���
		//Ϊjp���ô�Сλ�ò���ӽ��ұߵ��Ӵ���
		jp.setBounds(200,50,300,400);
		jsplr.setRightComponent(jp);
        jsplr.setDividerLocation(150);//���÷ָ����ĳ�ʼλ��
        jsplr.setDividerSize(4); //���÷ָ����Ŀ��
        jlRoot.setFont(new Font("Courier",Font.PLAIN,30));
		jlRoot.setHorizontalAlignment(JLabel.CENTER);
		jlRoot.setVerticalAlignment(JLabel.CENTER);
		//���ô���Ĺرն��������⣬��С��λ�ü��ɼ���
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//�Ա����logoͼƬ���г�ʼ��	
 		Image image=new ImageIcon("ico.gif").getImage();
 		this.setIconImage(image);
		this.setTitle("ѧ������ϵͳ");
		//���ô����״γ��ֵĴ�С��λ��--�Զ�����
		Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
		int centerX=screenSize.width/2;
		int centerY=screenSize.height/2;
		int w=500;//��������
		int h=400;//������߶�
		this.setBounds(centerX-w/2,centerY-h/2-100,w,h);//���ô����������Ļ����
		this.setExtendedState(JFrame.MAXIMIZED_BOTH);//����ȫ��
		this.setVisible(true);
		jt.setShowsRootHandles(true);//������ʾ���ڵ�Ŀ���ͼ��
    }
    public void initJp(){//�������õķ�����������
    	jp.setLayout(cl);
    	jp.add(jlRoot,"root");
    	jp.add(new SearchBook(),"ts");
    	jp.add(new OrderBook(),"OrderBook");
    	jp.add(new GuaShi(),"GuaShi");
    }
    public void actionPerformed(ActionEvent e){}//ʵ��ActionListener����
	public static void main(String[]args){new StudentSystem();}
}
class NodeValue{//����NodeValue��
	String value;
	public NodeValue(String value){
		this.value=value;
	}
	public String getValue(){//����NodeValue������
		return this.value;
	}
	public String toString(){
		return value;
	}
}